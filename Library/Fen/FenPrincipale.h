/*Auteur: PERCIE DU SERT Maxime
 *Date: 11/02/2016
 */
#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QAction>
#include <QComboBox>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QString>
#include <QToolBar>
#include <QVBoxLayout>
#include <stdexcept>
#include "../Div/Noyau.h"



/*! \ingroup groupeFen
 * \brief Fenêtre principale de l'application.
 *
 * Fenêtre principale:
 *  + Crée les différents menus.
 *  + Affiche les classes de l'année en cours.
 */
class FenPrincipale : public QMainWindow
{
    Q_OBJECT
protected:
    // Action
    QAction *m_actionEditColler;    //!< Action coller.
    QAction *m_actionEditCopier;    //!< Action copier.
    QAction *m_actionEditCouper;    //!< Action couper.
    QAction *m_actionEditEffacer;   //!< Action effacer.
    QAction *m_actionModuleExercice;//!< Action ouverture du module d'exercice.
    QAction *m_actionModuleNote;    //!< Action couverture du module Note.
    QAction *m_actionNewAnnee;      //!< Action création d'une année.
    QAction *m_actionNewAttribut;   //!< Action création d'un attribut.
    QAction *m_actionNewBareme;     //!< Action création d'un barème.
    QAction *m_actionNewClasse;     //!< Action création d'une classe.
    QAction *m_actionNewControle;   //!< Action création d'un controle.
    QAction *m_actionNewEtablissement;  //!< Action création d'un établissement.
    QAction *m_actionNewExercice;       //!< Action création d'un exercice.
    QAction *m_actionSave;          //!< Action sauvegarder.
    QAction *m_actionSelectDefaultAnnee;    //!< Action séléctionner l'année par défaut.

    // Menu
    QMenu *m_menuEdit;              //!< Menu édition.
    QMenu *m_menuFichier;           //!< Menu Fichier.
    QMenu *m_menuNew;               //!< Menu nouveau.

    // Tools Bar
    QToolBar *m_toolBar;            //!< Barre d'outils.

    // Noyau
    Noyau * m_noyau;                //!< Noyau de l'application.

public:
    /*! \brief Constructeur.
     * L'argument path doit contenir le chemin du dossier contenant le fichier de configuration ou
     * l'emplacement où un fichier de configuration par défaut sera créé.
     */
    explicit FenPrincipale(QString path, QWidget *parent = 0);

    //! Destructeur.
    ~FenPrincipale()
        {}

protected:
    //! Crée les différente action des menus et toolbars de la fenêtre principale.
    void createAction();

    //! Crée les menus de la fenêtre principale.
    void createMenu();

    //! Crée les toolbars de la fenêtre principale.
    void createToolBar();
};
#endif // FENPRINCIPALE_H
