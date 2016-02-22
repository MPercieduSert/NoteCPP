#include "TabAbstractModule.h"

TabAbstractModule::TabAbstractModule(Bdd *bdd, TabModule *parent) : m_bdd(bdd), m_parent(parent)
{
    m_mainLayout = new QVBoxLayout(this);
}

