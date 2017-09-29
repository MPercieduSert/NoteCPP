#include "TabAbstractModule.h"

TabAbstractModule::TabAbstractModule(int index, TabModule *parent)
    : m_index(index),
      m_mainLayout(new QVBoxLayout(this)),
      m_parent(parent)
    {}

void TabAbstractModule::becomeCurrent() const
{
    emit noyau()->collerPermis(false);
    emit noyau()->copierPermis(false);
    emit noyau()->couperPermis(false);
    emit noyau()->savePermis(false);
}
