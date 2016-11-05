#include "TabAbstractTableau.h"

TabAbstractTableau::TabAbstractTableau(int index, TabModule *parent): TabAbstractModule(index,parent)
    {}

void TabAbstractTableau::coller()
    {m_model->coller(m_view->selectionModel()->selectedIndexes());}

void TabAbstractTableau::copier()
    {m_model->copier(m_view->selectionModel()->selectedIndexes());}

void TabAbstractTableau::couper()
    {m_model->couper(m_view->selectionModel()->selectedIndexes());}

void TabAbstractTableau::effacer()
    {m_model->effacer(m_view->selectionModel()->selectedIndexes());}
