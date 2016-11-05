#include "NewClasseDialog.h"

NewClasseDialog::NewClasseDialog(const Annee &annee, VectorPtr<Etablissement> etabs, VectorPtr<EtablissementNiveau> etabNiveaux, VectorPtr<Niveau> niveaux,  VectorPtr<Classe> classes, QWidget *parent)
    : QDialog(parent),
      m_annee(annee),
      m_classes(classes),
      m_creerEtab(false),
      m_etabs(etabs),
      m_etabNiveaux(etabNiveaux),
      m_niveaux(niveaux)
{
    // Titre
    m_anneeLabel = new QLabel(tr("Creer une classe dans l'année ")+m_annee.affiche());

    // Choix etablissement
    m_etabComboBox = new QComboBox();
    for(VectorPtr<Etablissement>::iterator i = m_etabs.begin(); i != m_etabs.end(); ++i)
    {
        m_etabComboBox->addItem((*i).nom(),QVariant((*i).id()));
    }
    connect(m_etabComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(etabChange(int)));

    m_creerEtabBouton = new QPushButton(tr("Créer un établissement"));
    connect(m_creerEtabBouton,&QPushButton::clicked,this,&NewClasseDialog::creerEtab);

    m_hLayoutEtab = new QHBoxLayout();
    m_hLayoutEtab->addWidget(m_etabComboBox);
    m_hLayoutEtab->addWidget(m_creerEtabBouton);

    m_groupeEtab = new QGroupBox(tr("Choix de l'établissement de la classe"));
    m_groupeEtab->setLayout(m_hLayoutEtab);

    // Nom de la classe
    m_nameLabel = new QLabel(tr("Nom de la classe:"));
    m_nameLine = new QLineEdit();

    // Choix du niveau
    m_niveauLabel = new QLabel(tr("Choix du niveau de la classe"));

    m_niveauComboBox = new QComboBox();
    if(m_etabComboBox->count() > 0)
        etabChange(0);
    connect(m_niveauComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(niveauChange(int)));

    // Choix du numero de la classe
    m_numLabel = new QLabel(tr("Numéro de la classe :"));

    m_numSpinBox = new SpinBoxNumClasse();
    if(m_niveauComboBox->count() > 0)
        niveauChange(0);

    connect(m_numSpinBox,SIGNAL(valueChanged(int)),this,SLOT(nameUpdate(int)));

    // Nombre d'éléves
    m_nbrEleveLabel = new QLabel(tr("Nombre d'éléve de la classe :"));

    m_nbrEleveSpinBox = new QSpinBox();
    m_nbrEleveSpinBox->setRange(1, 1000);
    m_nbrEleveSpinBox->setValue(30);

    m_gridLayout = new QGridLayout();
    m_gridLayout->addWidget(m_niveauLabel,0,0);
    m_gridLayout->addWidget(m_niveauComboBox,1,0);
    m_gridLayout->addWidget(m_numLabel,2,0);
    m_gridLayout->addWidget(m_numSpinBox,2,1);
    m_gridLayout->addWidget(m_nameLabel,3,0);
    m_gridLayout->addWidget(m_nameLine,3,1);
    m_gridLayout->addWidget(m_nbrEleveLabel,4,0);
    m_gridLayout->addWidget(m_nbrEleveSpinBox,4,1);

    m_groupePara = new QGroupBox(tr("Paramètres:"));
    m_groupePara->setLayout(m_gridLayout);

    //Bouton
    m_cancelBouton = new QPushButton(tr("Annuler"));
    connect(m_cancelBouton,&QPushButton::clicked,this,&NewClasseDialog::reject);

    m_creerBouton = new QPushButton(tr("Créer"));
    connect(m_creerBouton,&QPushButton::clicked,this,&NewClasseDialog::accept);

    m_hLayoutButton = new QHBoxLayout();
    m_hLayoutButton->addWidget(m_creerBouton);
    m_hLayoutButton->addWidget(m_cancelBouton);

    // Main Layout
    m_vLayout = new QVBoxLayout(this);
    m_vLayout->addWidget(m_anneeLabel);
    m_vLayout->addWidget(m_groupeEtab);
    m_vLayout->addWidget(m_groupePara);
    m_vLayout->addLayout(m_hLayoutButton);

    // Label
    //m_nbrPhaseLabel = new QLabel(tr("Nombre de phase de notation dans l'annee :"));
    //m_colleLabel = new QLabel("Classe à khôlle");
    //m_colleCheckBox = new QCheckBox("Classe à khôlle");

    /*
    // Nombre de phase
    m_nbrPhaseSpinBox = new QSpinBox();
    m_nbrPhaseSpinBox->setRange(1, 10);
    m_nbrPhaseSpinBox->setValue(2);
    */
}

void NewClasseDialog::creerEtab()
{
    m_creerEtab = true;
    accept();
}

void NewClasseDialog::etabChange(int n)
{
    m_niveauComboBox->clear();
    int idEtab = m_etabComboBox->itemData(n).toInt();
    VectorPtr<Niveau>::iterator j;
    for(VectorPtr<EtablissementNiveau>::iterator i = m_etabNiveaux.begin(); i != m_etabNiveaux.end(); ++i)
    {
        if((*i).idEtab() == idEtab)
        {
            j = m_niveaux.begin();
            while(j != m_niveaux.end() && (*j).id() != (*i).idNiv())
                ++j;
            if(j != m_niveaux.end())
                m_niveauComboBox->addItem((*j).nom(),QVariant((*j).id()));
        }
    }
}

void NewClasseDialog::nameUpdate(int num)
{
    if(num > 0 && m_niveauComboBox->currentData().isValid())
    {
        VectorPtr<Niveau>::iterator j = m_niveaux.findId(m_niveauComboBox->currentData().toInt());
        if(j != m_niveaux.end())
            m_nameLine->setText((*j).nc()+QString("-")+QString::number(num));
    }
    else
    {
        m_nameLine->clear();
    }
}


void NewClasseDialog::niveauChange(int n)
{
    QList<int> liste;
    if(m_etabComboBox->currentData().isValid())
    {
        int etab = m_etabComboBox->currentData().toInt();
        int niv = m_niveauComboBox->itemData(n).toInt();
        for(VectorPtr<Classe>::iterator i = m_classes.begin(); i != m_classes.end(); ++i)
        {
            if((*i).idNiv() == niv && (*i).idEtab() == etab)
            {
                liste.append((*i).num());
            }
        }
        m_numSpinBox->setListe(liste);
        nameUpdate(m_numSpinBox->value());
    }
}

NewClasseDialog::dialogResult NewClasseDialog::value() const
{
    dialogResult value;
    if(m_creerEtab)
    {
        value.classe.setId(dialogResult::creerEtab);
    }
    else
    {
        value.classe = Classe(m_annee.id(),
                      m_etabComboBox->currentData().toInt(),
                      //m_nbrPhaseSpinBox->value(),
                      m_niveauComboBox->currentData().toInt(),
                      m_nameLine->text(),
                      m_numSpinBox->value());
        value.nbrEleve = m_nbrEleveSpinBox->value();
    }
    return value;
}
