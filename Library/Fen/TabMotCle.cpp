#include "TabMotCle.h"

TabMotCle::TabMotCle(int index, TabModule *parent): TabAbstractModule(index,parent)
{
    m_treeWidget = new ReadTreeWidget<MotCle>(bdd()->getArbre<MotCle>(),QList<MotCle::Position>()<<MotCle::Nom);
    m_mainLayout->addWidget(m_treeWidget);
}

void TabMotCle::becomeCurrent() const
{
    emit noyau()->collerPermis(false);
    emit noyau()->copierPermis(false);
    emit noyau()->couperPermis(false);
    emit noyau()->savePermis(false);
}
