#include "TabMotCle.h"

TabMotCle::TabMotCle(int index, TabModule *parent): TabAbstractModule(index,parent)
{
    m_treeWidget = new QTreeView;
    m_treeWidget->setModel(new TreeModelMotCle(bdd(),this));
    m_treeWidget->setItemDelegate(new MotCleDelegate(this));
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
