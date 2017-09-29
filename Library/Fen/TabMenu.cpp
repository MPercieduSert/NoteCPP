#include "TabMenu.h"

TabMenu::TabMenu(int idAn, TabModule *parent)
    : TabAbstractModule(idAn, parent),
      m_annee(idAn),
      m_classeLayout(0)
{
    if(m_annee.id() == 0)
    {
        QLabel * label = new QLabel("Année sélectionnée invalide",this);
        m_classeLayout = new QHBoxLayout();
        m_classeLayout->addWidget(label);
        m_mainLayout->addLayout(m_classeLayout);
    }
    else if(bdd()->get(m_annee))
    {
        classeLayout();       
        m_coursButton = new QPushButton(tr("Cours"));
        m_gestionBddButton = new QPushButton(tr("Base de Données"));
        m_motCleButton = new QPushButton(tr("Mots Clés"));
        m_newClasseButton = new QPushButton(tr("Créer une classe"));
        m_mainLayout->addWidget(m_newClasseButton);
        m_mainLayout->addWidget(m_coursButton);
        m_mainLayout->addWidget(m_motCleButton);
        m_mainLayout->addWidget(m_gestionBddButton);
        connect(m_newClasseButton,&QPushButton::clicked,this,&TabMenu::creerClasse);
        connect(m_coursButton,&QPushButton::clicked,[this](){m_parent->openCours();});
        connect(m_motCleButton,&QPushButton::clicked,[this](){m_parent->openMotCle();});
        connect(m_gestionBddButton,&QPushButton::clicked,[this](){m_parent->openGestionBdd();});
    }
    else
        throw std::invalid_argument(QString("L'année d'identifiant ")
                                    .append(QString::number(idAn))
                                    .append(" n'existe dans la base de donnée.")
                                    .toStdString());
}

// %%%%% protected %%%%%%
void TabMenu::classeLayout()
{
    if(m_classeLayout != 0)
    {
        m_mainLayout->removeItem(m_classeLayout);
        delete m_classeMapper;
        delete m_classeLayout;
        for(QList<QGroupBox *>::const_iterator i = m_listeGroupeEtab.cbegin(); i != m_listeGroupeEtab.cend(); ++i)
            delete *i;
        m_listeGroupeEtab.clear();
    }

    m_classeLayout = new QHBoxLayout();
    m_classeMapper = new QSignalMapper(this);

    VectorPtr<Classe> listeClasse(bdd()->getList<Classe>(Classe::IdAn, m_annee.id(),
                                                              Classe::IdEtab,
                                                              Classe::IdNiv,
                                                              Classe::Num));

    if(!listeClasse.isEmpty())
    {   
        VectorPtr<Classe>::iterator it = listeClasse.begin();

        int idEtab = 0;
        int idNiv;
        int i;
        int j;
        QGridLayout *etabLayout = 0;
        for(; it != listeClasse.cend(); ++it)
        {
            if(idEtab != (*it).idEtab())
            {
                if(etabLayout != 0)
                    etabLayout->setRowStretch(etabLayout->rowCount(),1);
                etabLayout = new QGridLayout();
                Etablissement etab((*it).idEtab());
                bdd()->get(etab);
                QGroupBox *groupeBox = new QGroupBox(etab.nom());
                m_listeGroupeEtab.append(groupeBox);
                groupeBox->setLayout(etabLayout);
                m_classeLayout->addWidget(groupeBox);

                idEtab = (*it).idEtab();
                idNiv = (*it).idNiv();
                i = 0;
                j = 0;
            }

            QPushButton * classeButton = new QPushButton((*it).nom());
            //m_classeButtonMap.insert((*it).id(),classeButton);
            if(idNiv != (*it).idNiv())
            {
                idNiv = (*it).idNiv();
                i = 0;
                ++j;
            }
            etabLayout->addWidget(classeButton,i,j);
            connect(classeButton,SIGNAL(clicked()),m_classeMapper,SLOT(map()));
            m_classeMapper->setMapping(classeButton,(*it).id());
            ++i;
        }
        if(etabLayout != 0)
            etabLayout->setRowStretch(etabLayout->rowCount(),1);
        connect(m_classeMapper,SIGNAL(mapped(int)),m_parent,SLOT(newOngletClasse(int)));
    }
    m_mainLayout->insertLayout(position::classe,m_classeLayout);
}

//public slots:
void TabMenu::creerClasse()
{
    noyau()->creerClasse(this);
    classeLayout();
}


