/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/08/2017
 */
#ifndef EDITTREEWIDGET_H
#define EDITTREEWIDGET_H


#include "ReadTreeWidget.h"
#include "../Model/TreeModelEditTemp.h"

template<class Ent> class EditTreeWidget : ReadTreeWidget<Ent>
{
public:
    using ReadTreeWidget<Ent>::ReadTreeWidget;

    //! Renvoie un pointeur sur le model
    TreeModelEditTemp<Ent> * model() const
        {return static_cast<TreeModelEditTemp<Ent> *>(QTreeView::model());}
};

#endif // EDITTREEWIDGET_H
