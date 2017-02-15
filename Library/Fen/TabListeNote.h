/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/01/2017
 */
#ifndef TABLISTENOTE_H
#define TABLISTENOTE_H

#include "FenPrincipale.h"
#include "TabAbstractClasse.h"
#include "../Model/ListeNoteModel.h"
#include "../Delegate/ListeNoteDelegate.h"

/*! \ingroup groupeFen
 * \brief Onglet des notes d'une classe
 */
class TabListeNote : public TabAbstractClasse
{
    Q_OBJECT
protected:

public:
    //! Constructeur.
    explicit TabListeNote(int idClasse, TabModule *parent = 0);
    //! Destructeur.
    ~TabListeNote() {}

signals:

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;
    //! Ouvre l'abre des données sur les éléves puis ajoute la colonne correspondand à la donnée séléctionnée.
    void addColumn();
};

#endif // TABLISTENOTE_H
