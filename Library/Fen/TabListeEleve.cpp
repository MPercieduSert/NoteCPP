#include "TabListeEleve.h"

TabListeEleve::TabListeEleve(int idClasse, TabModule *parent) : TabAbstractClasse(idClasse,parent)
{
    if(m_classe.isValid())
    {
        m_delegate = new ListeEleveDelegate(m_annee);
        m_model = new ListeEleveModel(*m_bdd,m_classe,this);
        m_view = new QTableView();
        m_saveButton = new QPushButton("Sauvegarder");

        m_view->setModel(m_model);
        m_view->setItemDelegate(m_delegate);
        m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        connect(m_saveButton,&QPushButton::clicked,this,&TabAbstractTableau::sauvegarder);

        m_mainLayout->addWidget(m_view);
        m_mainLayout->addWidget(m_saveButton);
    }
}

void TabListeEleve::becomeCurrent() const
{
    m_parent->parent()->setEnabledCopierColler(true);
}
