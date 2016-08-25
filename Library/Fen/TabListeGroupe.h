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

signals:

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;
};

#endif // TABLISTEGROUPE_H
