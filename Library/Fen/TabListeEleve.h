/*Auteur: PERCIE DU SERT Maxime
 *Date: 11/07/2016
 */
#ifndef TABLISTEELEVE_H
#define TABLISTEELEVE_H

#include <QTableView>

#include "FenPrincipale.h"
#include "TabAbstractClasse.h"
#include "TabAbstractTableau.h"
#include "../Model/ListeEleveModel.h"
#include "../Delegate/ListeEleveDelegate.h"

/*! \ingroup groupeFen
 * \brief Onglet d'une classe
 */
class TabListeEleve : public TabAbstractClasse
{
    Q_OBJECT
protected:

public:
    //! Constructeur.
    explicit TabListeEleve(int idClasse, TabModule *parent = 0);
    //! Destructeur.
    ~TabListeEleve() {}

signals:

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;
};

#endif // TABLISTEELEVE_H
