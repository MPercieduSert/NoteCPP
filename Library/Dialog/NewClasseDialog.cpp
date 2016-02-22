#include "NewClasseDialog.h"

NewClasseDialog::NewClasseDialog(QVector<Niveau> niveaux, const Annee & annee, QVector<Classe> classe, Niveau::affiche_alpha alpha, QWidget *parent) : QDialog(parent), m_annee(annee), m_classe(classe)
{
    m_anneeLabel = new QLabel("Creer une classe dans l'année "+m_annee.affiche());
    m_nbrEleveLabel = new QLabel("Nombre d'éléve de la classe :");
    m_nbrPhaseLabel = new QLabel("Nombre de phase de notation dans l'annee :");
    m_niveauLabel = new QLabel("Choix du niveau de la classe");
    m_numLabel = new QLabel("Numéro de la classe :");
    //m_colleLabel = new QLabel("Classe à khôlle");

    m_colleCheckBox = new QCheckBox("Classe à khôlle");

    m_nbrEleveSpinBox = new QSpinBox();
    m_nbrEleveSpinBox->setRange(1, 1000);
    m_nbrEleveSpinBox->setValue(30);

    m_nbrPhaseSpinBox = new QSpinBox();
    m_nbrPhaseSpinBox->setRange(1, 10);
    m_nbrPhaseSpinBox->setValue(2);

    m_niveauComboBox = new QComboBox();
    int niv = niveaux.at(0).id();
    for(QVector<Niveau>::const_iterator i = niveaux.cbegin(); i != niveaux.cend(); ++i)
    {
        m_niveauComboBox->addItem((*i).nom(),QVariant((*i).id()));
    }

    QList<int> liste;

    for(QVector<Classe>::const_iterator i = m_classe.cbegin(); i != m_classe.cend(); ++i)
    {
        if((*i).niveau() == niv)
        {
            liste.append((*i).num());
        }
    }
    m_numSpinBox = new SpinBoxNumClasse(liste,alpha);

    m_cancelBouton = new QPushButton("Annuler");
    m_creerBouton = new QPushButton("Créer");

    m_hLayoutButton = new QHBoxLayout();
    m_hLayoutButton->addWidget(m_creerBouton);
    m_hLayoutButton->addWidget(m_cancelBouton);

    m_hLayoutNbrEleve = new QHBoxLayout();
    m_hLayoutNbrEleve->addWidget(m_nbrEleveLabel);
    m_hLayoutNbrEleve->addWidget(m_nbrEleveSpinBox);

    m_hLayoutNbrPhase = new QHBoxLayout();
    m_hLayoutNbrPhase->addWidget(m_nbrPhaseLabel);
    m_hLayoutNbrPhase->addWidget(m_nbrPhaseSpinBox);

    m_hLayoutNum = new QHBoxLayout();
    m_hLayoutNum->addWidget(m_numLabel);
    m_hLayoutNum->addWidget(m_numSpinBox);

    m_vLayout = new QVBoxLayout(this);
    m_vLayout->addWidget(m_anneeLabel);
    m_vLayout->addWidget(m_niveauLabel);
    m_vLayout->addWidget(m_niveauComboBox);
    m_vLayout->addLayout(m_hLayoutNum);
    m_vLayout->addLayout(m_hLayoutNbrPhase);
    m_vLayout->addWidget(m_colleCheckBox);
    m_vLayout->addLayout(m_hLayoutNbrEleve);
    m_vLayout->addLayout(m_hLayoutButton);

    connect(m_cancelBouton,&QPushButton::clicked,this,&NewClasseDialog::reject);
    connect(m_creerBouton,&QPushButton::clicked,this,&NewClasseDialog::accept);
    connect(m_niveauComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(niveauChangeNum(int)));
}

void NewClasseDialog::niveauChangeNum(int)
{
    QList<int> liste;
    int niv = m_niveauComboBox->currentData().toInt();
    for(QVector<Classe>::const_iterator i = m_classe.cbegin(); i != m_classe.cend(); ++i)
    {
        if((*i).niveau() == niv)
        {
            liste.append((*i).num());
        }
    }
    m_numSpinBox->setListe(liste);
}

NewClasseDialog::dialogResult NewClasseDialog::value() const
{
    Classe classe(m_annee.id(),
                  m_nbrPhaseSpinBox->value(),
                  m_niveauComboBox->currentData().toInt(),
                  m_numSpinBox->value());
    dialogResult value = {classe, m_nbrEleveSpinBox->value()};
    return value;
}
