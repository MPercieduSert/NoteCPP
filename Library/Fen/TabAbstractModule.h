#ifndef TABABSTRACTMODULE_H
#define TABABSTRACTMODULE_H

#include <QVBoxLayout>
#include <QWidget>
#include "../Div/Bdd.h"
#include "TabModule.h"

class TabAbstractModule : public QWidget
{
    Q_OBJECT
protected:
    Bdd * m_bdd;
    QVBoxLayout *m_mainLayout;
    TabModule * m_parent;


public:
    explicit TabAbstractModule(Bdd * bdd = 0, TabModule *parent = 0);
    ~TabAbstractModule() {}
    virtual void becomeCurrent() const = 0;
signals:

public slots:
    virtual void coller()   {}
    virtual void copier()   {}
    virtual void effacer()   {}
    virtual void sauvegarder()   {}
};

#endif // TABABSTRACTMODULE_H
