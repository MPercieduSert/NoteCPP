#include "TabMotCle.h"

TabMotCle::TabMotCle(int index, TabModule *parent): TabAbstractModule(index,parent)
{
    m_treeWidget = new QTreeView;
    m_treeModel = new TreeModelMotCle(bdd(),this);
    m_treeWidget->setModel(m_treeModel);
    m_treeWidget->setItemDelegate(new MotCleDelegate(this));
    m_treeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    connect(m_treeWidget->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this,SLOT(selectionMotcle(QItemSelection,QItemSelection)));
    m_motCleWidget = new MotCleWidget(bdd(),Cible<MotCle>::value);
    m_horizontalSplitter = new QSplitter();
    m_horizontalSplitter->addWidget(m_treeWidget);
    m_horizontalSplitter->addWidget(m_motCleWidget);
    m_mainLayout->addWidget(m_horizontalSplitter);
}

void TabMotCle::becomeCurrent() const
{
    emit noyau()->collerPermis(false);
    emit noyau()->copierPermis(false);
    emit noyau()->couperPermis(false);
    emit noyau()->savePermis(false);
}

void TabMotCle::selectionMotcle(const QItemSelection &selected, const QItemSelection &/*deselected*/)
{
    QModelIndexList indexList = selected.indexes();
    QSet<int> idSet;
    for(QModelIndexList::const_iterator i = indexList.cbegin(); i != indexList.cend(); ++i)
    {
        if((*i).column() == 0 && !idSet.contains(m_treeModel->id(*i)))
            idSet.insert(m_treeModel->id(*i));
    }
    m_motCleWidget->setIdSet(idSet);
}
