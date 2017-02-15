/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/07/2016
 */
#ifndef TABCLASSE_H
#define TABCLASSE_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../Entities/Classe.h"
#include "FenPrincipale.h"
#include "TabAbstractClasse.h"


/*! \ingroup groupeFen
 * \brief Onglet d'une classe
 */
class TabClasse : public TabAbstractClasse
{
    Q_OBJECT
protected:
    // Widget
    QPushButton * m_listeEleveButton;           //!< Bouton pour ouvrir la liste des éléves
    QPushButton * m_listeGroupeButton;          //!< Bouton pour ouvrir la liste des groupes
    QPushButton * m_listeNoteButton;            //!< Bouton pour ouvrir la liste des notes

    // Layout
    QHBoxLayout * m_bouttonTabLayout;           //!< Calque des boutons.

public:
    //! Constructeur.
    TabClasse(int idClasse, TabModule *parent = 0);

    //! Destructeur.
    ~TabClasse() {}

public slots:
    //! Action à effectuer lorsque l'onglet devient actif.
    void becomeCurrent() const;
    //! Ouvre l'onglet de la liste des éléves.
    void openListeEleve();
    //! Ouvre l'onglet de la liste des groupes.
    void openListeGroupe();
    //! Ouvre l'onglet de la liste des notes.
    void openListeNote();
};

#endif // TABCLASSE_H
