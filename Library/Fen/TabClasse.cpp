#include "TabClasse.h"

TabClasse::TabClasse(int idClasse, Bdd *bdd, TabModule *parent) : TabAbstractClasse(idClasse,bdd,parent)
{
    if(m_classeIsValid)
    {
        m_listeEleveButton = new QPushButton(tr("Liste des éléves"));
        m_listeGroupeButton = new QPushButton(tr("Liste de groupes"));
        connect(m_listeEleveButton,&QPushButton::clicked,this,&TabClasse::openListeEleve);
        connect(m_listeGroupeButton,&QPushButton::clicked,this,&TabClasse::openListeGroupe);

        m_bouttonTabLayout = new QHBoxLayout();
        m_bouttonTabLayout->addWidget(m_listeEleveButton);
        m_bouttonTabLayout->addWidget(m_listeGroupeButton);

        m_mainLayout->addLayout(m_bouttonTabLayout);
    }
}

void TabClasse::becomeCurrent() const
{
    m_parent->parent()->setEnabledCopierColler(m_classeIsValid);
}

// %%%%%%%%%%%  public slots %%%%%%%%%%
void TabClasse::openListeEleve()
{
    m_parent->openListeEleve(m_classe.id());
}

void TabClasse::openListeGroupe()
{
    m_parent->openListeGroupe(m_classe.id());
}
