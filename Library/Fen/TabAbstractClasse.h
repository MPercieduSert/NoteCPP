#ifndef TABABSTRACTCLASSE_H
#define TABABSTRACTCLASSE_H

#include "TabAbstractTableau.h"
#include "../Entities/Classe.h"

class TabAbstractClasse : public TabAbstractTableau
{
    Q_OBJECT
protected:
    Classe m_classe;
    bool m_classeIsValid;

public:
    explicit TabAbstractClasse(int idClasse, Bdd * bdd, TabModule *parent = 0);
    ~TabAbstractClasse() {}

signals:

public slots:
};

#endif // TABABSTRACTCLASSE_H
