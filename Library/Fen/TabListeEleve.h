#ifndef TABLISTEELEVE_H
#define TABLISTEELEVE_H

#include <QTableView>

#include "FenPrincipale.h"
#include "TabAbstractClasse.h"
#include "TabAbstractTableau.h"
//#include "../Model/ListeEleveModel.h"
//#include "../Delegate/ListeEleveDelegate.h"

class TabListeEleve : public TabAbstractClasse
{
    Q_OBJECT
protected:

public:
    explicit TabListeEleve(int idClasse, Bdd * bdd, TabModule *parent = 0);
    ~TabListeEleve() {}
    void becomeCurrent() const;
signals:

public slots:
};

#endif // TABLISTEELEVE_H
