#include "TabListeGroupe.h"

TabListeGroupe::TabListeGroupe(int idClasse, Bdd *bdd, TabModule *parent) : TabAbstractModule(bdd,parent), m_classe(idClasse)
{

}

void TabListeGroupe::becomeCurrent() const
{
    m_parent->parent()->setEnabledCopierColler(true);
}
