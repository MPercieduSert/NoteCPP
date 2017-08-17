#include "NewControleDialog.h"

NewControleDialog::NewControleDialog(const Tree<TypeControleNum> &treeTpCtr, QWidget* parent) : QDialog(parent)
{
    //Paramètre
    m_labelDate = new QLabel(tr("Date de l'épreuve :"));
    m_labelDecimale = new QLabel(tr("Décimale des notes :"));
    m_labelMinima = new QLabel(tr("Minima de l'épreuve :"));
    m_labelNom = new QLabel(tr("Nom de l'épreuve :"));
    m_labelTotal = new QLabel(tr("Total de l'épreuve :"));

    m_lineAppreciation = new QCheckBox("Appreciation");
    m_lineBareme = new QCheckBox("Bareme");
    m_lineBareme->setEnabled(false);
    m_lineDate = new QDateEdit(QDate::currentDate());
    m_lineDate->setCalendarPopup(true);
    m_lineDecimale = new SpinBoxDecimale();
    m_lineEnonce = new QCheckBox("Enonce");
    connect(m_lineEnonce,&QCheckBox::clicked,m_lineBareme,&QCheckBox::setCheckable);
    connect(m_lineEnonce,&QCheckBox::clicked,m_lineBareme,&QCheckBox::setEnabled);
    m_lineMinima = new QSpinBox();
    m_lineMinima->setAlignment(Qt::AlignRight);
    m_lineNom = new QLineEdit();
    m_lineTotal = new QSpinBox();
    m_lineTotal->setAlignment(Qt::AlignRight);

    m_layoutParametre = new QGridLayout();
    m_layoutParametre->addWidget(m_labelNom,0,0);
    m_layoutParametre->addWidget(m_lineNom,0,1);
    m_layoutParametre->addWidget(m_labelDate,1,0);
    m_layoutParametre->addWidget(m_lineDate,1,1);
    m_layoutParametre->addWidget(m_labelTotal,2,0);
    m_layoutParametre->addWidget(m_lineTotal,2,1);
    m_layoutParametre->addWidget(m_labelDecimale,3,0);
    m_layoutParametre->addWidget(m_lineDecimale,3,1);
    m_layoutParametre->addWidget(m_labelMinima,4,0);
    m_layoutParametre->addWidget(m_lineMinima,4,1);
    m_layoutParametre->addWidget(m_lineAppreciation,5,0);
    m_layoutParametre->addWidget(m_lineEnonce,6,0);
    m_layoutParametre->addWidget(m_lineBareme,7,0);

    // Type
    m_labelType = new QLabel(tr("Type d'épreuve :"));
    m_labelType->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    m_treeModelType = new ReadTreeWidget<TypeControleNum>(treeTpCtr,
                                {TypeControleNum::Nom,TypeControleNum::Nc,
                                 TypeControleNum::Total,TypeControleNum::Num});
    connect(m_treeModelType->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(selectedTypeChange(QModelIndex,QModelIndex)));
    m_treeModelType->select(1);
    m_buttonCreerType = new QPushButton(tr("Créer un nouveau type d'épreuve"));

    m_layoutType = new QVBoxLayout();
    m_layoutType->addWidget(m_labelType);
    m_layoutType->addWidget(m_treeModelType);
    m_layoutType->addWidget(m_buttonCreerType);
    connect(m_buttonCreerType,&QPushButton::clicked,this,&NewControleDialog::creerType);

    // Paramètre et type
    m_layoutChoix = new QHBoxLayout();
    m_layoutChoix->addLayout(m_layoutType);
    m_layoutChoix->addLayout(m_layoutParametre);

    // Bouton
    m_buttonAccepter = new QPushButton(tr("Créer l'épreuve"));
    connect(m_buttonAccepter,&QPushButton::clicked,this,&NewControleDialog::accept);

    m_buttonAnnuler = new QPushButton(tr("Annuler"));
    connect(m_buttonAnnuler,&QPushButton::clicked,this,&NewControleDialog::reject);

    m_layoutButton = new QHBoxLayout();
    m_layoutButton->addWidget(m_buttonAnnuler);
    m_layoutButton->addWidget(m_buttonAccepter);

    // Main layout
    m_LayoutMain = new QVBoxLayout(this);
    m_LayoutMain->addLayout(m_layoutChoix);
    m_LayoutMain->addLayout(m_layoutButton);

}

void NewControleDialog::creerType()
{
    m_creerType = true;
    accept();
}

void NewControleDialog::selectedTypeChange(const QModelIndex &, const QModelIndex &)
{
    TypeControleNum tpCtr = m_treeModelType->value();
    m_lineAppreciation->setChecked(tpCtr.appreciation());
    m_lineAppreciation->setEnabled(tpCtr.modif());
    m_lineDecimale->setValue(tpCtr.decimale());
    m_lineDecimale->setEnabled(tpCtr.modif());
    m_lineNom->setText(tpCtr.nc().append("-").append(QString::number(tpCtr.num()+1)));
    m_lineTotal->setValue(tpCtr.total());
    m_lineTotal->setEnabled(tpCtr.modif());
}

NewControleDialog::dialogResult NewControleDialog::value() const
{
    dialogResult result;
    //controle
    result.controle.setIdTp(m_treeModelType->value().id());
    result.controle.setBareme(m_lineBareme->isChecked());
    result.controle.setDate(m_lineDate->date());
    result.controle.setDecimale(m_lineDecimale->value());
    result.controle.setEnonce(m_lineEnonce->isChecked());
    result.controle.setMinima(m_lineMinima->value());
    result.controle.setNom(m_lineNom->text());
    result.controle.setNum(m_treeModelType->value().num() + 1);
    result.controle.setSaisie(true);
    result.controle.setTotal(m_lineTotal->value());

    result.appreciation = m_lineAppreciation->isChecked();
    result.creerType = m_creerType;
    return result;
}
