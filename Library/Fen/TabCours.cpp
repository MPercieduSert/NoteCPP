#include "TabCours.h"

TabCours::TabCours(int index, TabModule *parent): TabAbstractModule(index,parent)
{

}

void TabCours::becomeCurrent() const
{
    emit noyau()->collerPermis(false);
    emit noyau()->copierPermis(false);
    emit noyau()->couperPermis(false);
    emit noyau()->savePermis(false);
}
