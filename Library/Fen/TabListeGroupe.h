#ifndef TABLISTEGROUPE_H
#define TABLISTEGROUPE_H

#include "TabAbstractModule.h"
#include "FenPrincipale.h"

class TabListeGroupe : public TabAbstractModule
{
    Q_OBJECT
protected:
    Classe m_classe;
public:
    explicit TabListeGroupe(int idClasse, Bdd * bdd, TabModule *parent = 0);
    ~TabListeGroupe() {}
    void becomeCurrent() const;
signals:

public slots:
};

#endif // TABLISTEGROUPE_H
