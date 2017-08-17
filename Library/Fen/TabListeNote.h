/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/01/2017
 */
#ifndef TABLISTENOTE_H
#define TABLISTENOTE_H

#include "FenPrincipale.h"
#include "TabAbstractClasse.h"
#include "../Delegate/ListeNoteDelegate.h"
#include "../Dialog/ControleGraphDialog.h"
#include "../Dialog/NewControleDialog.h"
#include "../Dialog/NewTypeControleDialog.h"
#include "../Model/ListeNoteModel.h"
#include "../Widget/HeaderView.h"
#include "../Widget/Plotter.h"


/*! \ingroup groupeFen
 * \brief Onglet des notes d'une classe
 */
class TabListeNote : public TabAbstractClasse
{
    Q_OBJECT
protected:
    HeaderView * m_header;

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
    //! Ouvre une fenêtre affichant l'histogramme de l'épreuve.
    void openControleGraph(int section);
};

#endif // TABLISTENOTE_H
