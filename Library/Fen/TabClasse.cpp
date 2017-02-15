#include "TabClasse.h"

TabClasse::TabClasse(int idClasse, TabModule *parent) : TabAbstractClasse(idClasse,parent)
{
    if(m_classe.isValid())
    {
        m_listeEleveButton = new QPushButton(tr("Liste des éléves"));
        connect(m_listeEleveButton,&QPushButton::clicked,this,&TabClasse::openListeEleve);
        m_listeGroupeButton = new QPushButton(tr("Liste de groupes"));
        connect(m_listeGroupeButton,&QPushButton::clicked,this,&TabClasse::openListeGroupe);
        m_listeNoteButton = new QPushButton(tr("Notes"));
        connect(m_listeNoteButton,&QPushButton::clicked,this,&TabClasse::openListeNote);

        m_bouttonTabLayout = new QHBoxLayout();
        m_bouttonTabLayout->addWidget(m_listeEleveButton);
        m_bouttonTabLayout->addWidget(m_listeGroupeButton);
        m_bouttonTabLayout->addWidget(m_listeNoteButton);

        m_mainLayout->addLayout(m_bouttonTabLayout);
    }
}

void TabClasse::becomeCurrent() const
{
    //m_parent->parent()->setEnabledCopierColler(m_classeIsValid);
}

// %%%%%%%%%%%  public slots %%%%%%%%%%
void TabClasse::openListeEleve()
{
    m_parent->openListeEleve(m_classe.id());
}

void TabClasse::openListeGroupe()
{
    //m_parent->openListeGroupe(m_classe.id());
}

void TabClasse::openListeNote()
{
    m_parent->openListeNote(m_classe.id());
}
