#ifndef TABABSTRACTTABLEAU_H
#define TABABSTRACTTABLEAU_H


#include <QStyledItemDelegate>
#include <QTableView>


#include "TabAbstractModule.h"
#include "../Model/MAbstractTableModel.h"

class TabAbstractTableau : public TabAbstractModule
{
    Q_OBJECT
protected:
    QStyledItemDelegate * m_delegate;
    MAbstractTableModel * m_model;
    QTableView * m_view;
public:
    explicit TabAbstractTableau(Bdd * bdd, TabModule *parent = 0);
    //~TabAbstractTableau() {}

signals:

public slots:
    virtual void coller()   {}
    virtual void copier()   {}
    virtual void effacer()   {}
    virtual void sauvegarder()   {}
};

#endif // TABABSTRACTTABLEAU_H
