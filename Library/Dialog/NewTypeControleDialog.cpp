#include "NewTypeControleDialog.h"

NewTypeControleDialog::NewTypeControleDialog(Tree<TypeControle> && treeTpCtr, QWidget *parent) : QDialog(parent)
{
    // Paramétrage
    m_labelDecimale = new QLabel(tr("Décimale :"));
    m_labelNom = new QLabel(tr("Nom :"));
    m_labelNc = new QLabel(tr("Nom abrégé :"));
    m_labelTotal = new QLabel(tr("Total :"));
    m_labelType = new QLabel(tr("Type particulier :"));

    m_lineAppreciation = new QCheckBox(tr("Appréciation par défaut"));
    m_lineDecimale = new SpinBoxDecimale();
    m_lineModif = new QCheckBox(tr("Paramétrage modifiable"));
    m_lineNc = new QLineEdit();
    m_lineNom = new QLineEdit();
    m_lineTotal = new QSpinBox();
    m_lineTotal->setAlignment(Qt::AlignRight);
    m_lineType = new QComboBox();
    m_lineType->addItem(tr("Defaut"),TypeControle::Default);
    m_lineType->addItem(tr("Evaltuion par lettre"),TypeControle::Lettre);

    m_layoutParametre = new QGridLayout();
    m_layoutParametre->addWidget(m_labelNom,0,0);
    m_layoutParametre->addWidget(m_lineNom,0,1);
    m_layoutParametre->addWidget(m_labelNc,1,0);
    m_layoutParametre->addWidget(m_lineNc,1,1);
    m_layoutParametre->addWidget(m_labelTotal,2,0);
    m_layoutParametre->addWidget(m_lineTotal,2,1);
    m_layoutParametre->addWidget(m_labelDecimale,3,0);
    m_layoutParametre->addWidget(m_lineDecimale,3,1);
    m_layoutParametre->addWidget(m_labelType,4,0);
    m_layoutParametre->addWidget(m_lineType,4,1);
    m_layoutParametre->addWidget(m_lineAppreciation,5,0);
    m_layoutParametre->addWidget(m_lineModif,6,0);

    // Sur Type
    m_labelSurType = new QLabel(tr("Sur Type :"));
    m_labelSurType->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    treeTpCtr.insertChild(0, TypeControle(tr("Aucun"),NewTypeControleDialog::Aucun));
    m_treeModelSurType = new ReadTreeWidget<TypeControle>(treeTpCtr,
                                            {TypeControle::Nom,TypeControle::Nc,
                                             TypeControle::Total,TypeControle::Decimale});
    connect(m_treeModelSurType->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(selectedSurTypeChange(QModelIndex,QModelIndex)));
    m_treeModelSurType->select(NewTypeControleDialog::Aucun);
    m_layoutSurType = new QVBoxLayout();
    m_layoutSurType->addWidget(m_labelSurType);
    m_layoutSurType->addWidget(m_treeModelSurType);

    // Button
    m_buttonAccepter = new QPushButton(tr("Créer le type d'épreuve"));
    connect(m_buttonAccepter,&QPushButton::clicked,this,&NewTypeControleDialog::accept);
    m_buttonAnnuler = new QPushButton(tr("Annuler"));
    connect(m_buttonAnnuler,&QPushButton::clicked,this,&NewTypeControleDialog::reject);

    m_layoutButton = new QHBoxLayout();
    m_layoutButton->addWidget(m_buttonAnnuler);
    m_layoutButton->addWidget(m_buttonAccepter);

    // Main Layout
    m_layoutChoix = new QHBoxLayout();
    m_layoutChoix->addLayout(m_layoutSurType);
    m_layoutChoix->addLayout(m_layoutParametre);

    m_LayoutMain = new QVBoxLayout(this);
    m_LayoutMain->addLayout(m_layoutChoix);
    m_LayoutMain->addLayout(m_layoutButton);
}

void NewTypeControleDialog::selectedSurTypeChange(const QModelIndex &, const QModelIndex &)
{
     TypeControle tpCtr = m_treeModelSurType->value();
    m_lineAppreciation->setChecked(tpCtr.appreciation());
    m_lineDecimale->setValue(tpCtr.decimale());
    m_lineModif->setChecked(tpCtr.modif());
    m_lineNc->setText(tpCtr.nc());
    m_lineNom->setText(tpCtr.nom());
    m_lineTotal->setValue(tpCtr.total());
    m_lineType->setCurrentIndex(tpCtr.type());
}

TypeControle NewTypeControleDialog::value() const
{
    return TypeControle(m_lineAppreciation->isChecked(),
                        m_lineDecimale->value(),
                        m_lineModif->isChecked(),
                        m_lineNc->text(),
                        m_lineNom->text(),
                        m_lineTotal->value(),
                        m_lineType->currentData().toInt(),
                        m_treeModelSurType->value().id());
}
