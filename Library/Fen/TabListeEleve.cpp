#include "TabListeEleve.h"

TabListeEleve::TabListeEleve(int idClasse, Bdd *bdd, TabModule *parent) : TabAbstractClasse(idClasse,bdd,parent)
{
    if(m_classeIsValid)
    {
        m_delegate = new ListeEleveDelegate(m_bdd->annee());
        m_model = new ListeEleveModel(*m_bdd,m_classe,this);
        m_view = new QTableView();
        m_view->setModel(m_model);
        m_view->setItemDelegate(m_delegate);
        m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_view->setDragEnabled(true);
        m_view->setAcceptDrops(true);
        m_view->setDropIndicatorShown(true);

        m_mainLayout->addWidget(m_view);
    }
}

void TabListeEleve::becomeCurrent() const
{
    m_parent->parent()->setEnabledCopierColler(m_classeIsValid);
}
