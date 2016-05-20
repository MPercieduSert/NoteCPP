/*Auteur: PERCIE DU SERT Maxime
 *Date: 11/02/2016
 */

/*! \defgroup groupeFen Fenêtre
 * \brief Ensemble de classes regroupant les différentes fenêtres de l'application.
 */

/*! \ingroup groupeFen
 * \brief Fenêtre principale et noyau de l'application.
 *
 * Fenêtre principale et noyau de l'application:
 *  + Initialise l'application avec la fenêtre principale.
 *  + Crée les différents menus.
 *  + Ouvre le lien avec le fichier de configuration.
 *  + Ouvre le lien avec la base de donnée.
 *  + Affiche les classes de l'année en cours.
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
#include "../Dialog/NewAnneeDialog.h"
#include "../Dialog/NewClasseDialog.h"
#include "../Dialog/SelectAnneeDialog.h"
#include "../Div/Bdd.h"
#include "../Div/Config.h"
//#include "FenExo.h"
#include "FenFoundFile.h"
//#include "FenMenu.h"
//#include "FenNote.h"
//#include "TabModule.h"

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
protected:
    QAction *m_actionEditColler;
    QAction *m_actionEditCopier;
    QAction *m_actionEditCouper;
    QAction *m_actionEditEffacer;
    QAction *m_actionModuleExercice;
    QAction *m_actionModuleNote;
    QAction *m_actionNewAnnee;
    QAction *m_actionNewAttribut;
    QAction *m_actionNewBareme;
    QAction *m_actionNewClasse;
    QAction *m_actionNewControle;
    QAction *m_actionNewExercice;
    QAction *m_actionSauvegarder;
    QAction *m_actionSelectDefaultAnnee;

    //TabModule *m_tabModule;//!< Zone centrale.

    Bdd m_bdd;//!< Gestionnaire de la Base de donnée.
    Config m_config;//!< Gestionnaire de la configuration.
    //FenPrincipale *m_parent;

    QMenu *m_menuEdit;
    QMenu *m_menuFichier;
    QMenu *m_menuNew;
    QToolBar *m_toolBar;

    Annee m_anneeDefaut;

public:
    /*! \brief Constructeur.
     *
     * L'argument path doit contenir le chemin du dossier contenant le fichier de configuration ou
     * l'emplacement où un fichier de configuration par défaut sera créé.
     *
     * Le constructeur contient les étapes suivantes:
     */
    explicit FenPrincipale(QString path, QWidget *parent = 0);

    //! Destructeur.
    ~FenPrincipale()
        {}

    //! Renvoie un pointeur sur le gestionnaire de configuration.
    Config * config()
        {return &m_config;}

    //! Renvoie un pointeur sur le gestionnaire de Base de donnée.
    Bdd * bdd()
        {return &m_bdd;}

    //void setEnabledCopierColler(bool bb);
protected:
    //void changeAnnee(int anneeId);

    //! Crée les différente action des menus et toolbars de la fenêtre principale.
    void createAction();

    //! Crée les menus de la fenêtre principale.
    void createMenu();

    //! Crée les toolbars de la fenêtre principale.
    void createToolBar();

signals:
    //void anneeChanged();

public slots:
    /*void coller();
    void copier();
    void couper();
    void creerAnnee();
    void creerClasse();
    void effacer();
    void execExo();
    //void execMenu();
    void execNote();
    void sauvegarder()     {m_tabModule->sauvegarder();}
protected slots:
    void selectDefaultAnnee();*/

};
#endif // FENPRINCIPALE_H
