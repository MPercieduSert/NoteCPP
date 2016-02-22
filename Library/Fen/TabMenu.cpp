#include "TabMenu.h"

TabMenu::TabMenu(Bdd *bdd, TabModule *parent) : TabAbstractModule(bdd, parent)
{
    if(m_bdd->annee().id() != 0)
    {
        classeLayout();
    }
}

void TabMenu::becomeCurrent() const
{
    m_parent->parent()->setEnabledCopierColler(false);
}

void TabMenu::refreshClasse()
{
    delete m_classeMapper;
    for(QMap<int,QPushButton*>::const_iterator i = m_classeButtonMap.cbegin(); i != m_classeButtonMap.cend(); ++i) delete i.value();
    m_classeButtonMap.clear();
    delete m_classeLayout;
    delete m_newClasseButton;
    classeLayout();
}

// %%%%% protected %%%%%%
void TabMenu::classeLayout()
{
    m_classeLayout = new QGridLayout();
    m_classeMapper = new QSignalMapper(this);

    ListEntities<Classe> listeClasse;
    listeClasse << m_bdd->getList(Entity::ClasseId,Classe::AnneePos,QVariant(m_bdd->annee().id()),Classe::NiveauPos,Classe::NumPos);
    int i = 0;
    int j = 0;
    if(!listeClasse.isEmpty())
    {
        listeClasse.begin();
        int niveau = listeClasse.current().niveau();
        while(listeClasse.next())
        {
            QPushButton * classeButton = new QPushButton(m_bdd->afficheClasse(listeClasse.current()));
            m_classeButtonMap.insert(listeClasse.current().id(),classeButton);
            if(niveau != listeClasse.current().niveau())
            {
                niveau = listeClasse.current().niveau();
                i = 0;
                ++j;
            }
            m_classeLayout->addWidget(classeButton,i,j);
            connect(classeButton,SIGNAL(clicked()),m_classeMapper,SLOT(map()));
            m_classeMapper->setMapping(classeButton,listeClasse.current().id());
            ++i;
        }
        connect(m_classeMapper,SIGNAL(mapped(int)),m_parent,SLOT(newOngletClasse(int)));
    }
    listeClasse.clearAll();
    m_newClasseButton = new QPushButton("Créer une classe");

    m_classeLayout->addWidget(m_newClasseButton,0,j+1);

    m_mainLayout->addLayout(m_classeLayout);
    connect(m_newClasseButton,&QPushButton::clicked,this,&TabMenu::creerClasse);
}

//public slots:
void TabMenu::creerClasse()
{
    m_parent->creerClasse();
    refreshClasse();
}
