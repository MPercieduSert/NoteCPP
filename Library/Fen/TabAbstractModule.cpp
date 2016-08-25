#include "TabAbstractModule.h"

TabAbstractModule::TabAbstractModule(int index, TabModule *parent)
    : m_bdd(parent->parent()->bdd()),
      m_index(index),    
      m_mainLayout(new QVBoxLayout(this)),
      m_parent(parent)
    {}

