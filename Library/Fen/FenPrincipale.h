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
#include "../Dialog/NewAnneeDialog.h"
#include "../Dialog/NewClasseDialog.h"
#include "../Dialog/NewEtablissementDialog.h"
#include "../Dialog/SelectAnneeDialog.h"
#include "../Div/Bdd.h"
#include "../Div/Config.h"
#include "../Entities/VectorEntities.h"
//#include "FenExo.h"
#include "FenFoundFile.h"
//#include "FenMenu.h"
//#include "FenNote.h"
#include "TabModule.h"

/*! \defgroup groupeFen Fenêtre
 * \brief Ensemble de classes regroupant les différentes fenêtres de l'application.
 */

/*! \ingroup groupeFen
 * \brief Chemin XML du dossier par de l'application par default
 */
#define DEFAULT_DIRECTORY "conf/directories/default"

/*! \ingroup groupeFen
 * \brief Chemin XML de la base de donnée
 */
#define DATA_BASE "conf/files/databases/database"

/*! \ingroup groupeFen
 * \brief Chemin XML de l'année par default
 */
#define DEFAULT_ANNEE "conf/parametre/initialisation/anneeDefaut"

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
    QAction *m_actionNewEtablissement;
    QAction *m_actionNewExercice;
    QAction *m_actionSauvegarder;
    QAction *m_actionSelectDefaultAnnee;

    TabModule *m_tabModule;//!< Zone centrale.

    Bdd m_bdd;//!< Gestionnaire de la Base de donnée.
    Config m_config;//!< Gestionnaire de la configuration.
    //FenPrincipale *m_parent;

    QMenu *m_menuEdit;
    QMenu *m_menuFichier;
    QMenu *m_menuNew;
    QToolBar *m_toolBar;

    Annee m_anneeDefaut;    //! année de travail

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

    //! Renvoie l'année par defaut
    const Annee & annee()
        {return m_anneeDefaut;}

    //! Renvoie un pointeur sur le gestionnaire de configuration.
    Config * config()
        {return &m_config;}

    //! Renvoie un pointeur sur le gestionnaire de Base de donnée.
    Bdd * bdd()
        {return &m_bdd;}

    //! Autorise ou interdit les actions de copier-coller
    void setEnabledCopierColler(bool bb);
protected:
    /*! \brief Ouvre une fenêtre de dialogue demandant de selectionner une année.
     *
     * Ouvre une fenêtre de dialogue demandant de selectionner une année.
     * \param preSelect annee préselectionner dans la liste si présente.
     * \param annule creer un bouton permettant d'annuler.
     * \param creer creer un bouton creer pour creer une nouvelle année.
     * \param vide autorise à selectionner l'annee vide.
     */
    Annee selectAnnee(Annee preSelect = Annee(0,0) ,bool annule = true, bool creer = true, bool vide = true);

    //! Crée les différente action des menus et toolbars de la fenêtre principale.
    void createAction();

    //! Crée les menus de la fenêtre principale.
    void createMenu();

    //! Crée les toolbars de la fenêtre principale.
    void createToolBar();

    //! Modifie l'année par défaut
    void setAnnee(const Annee & an);

signals:
    //void anneeChanged();

public slots:
    /*void coller();
    void copier();
    void couper();*/

    //! Ouvre une fenêtre de création d'année.
    void creerAnnee();

    //! Ouvre une fenêtre de création d'une classe.
    void creerClasse();
    void creerEtablissement(const QString &nc = QString(), const QString &nom = QString());
    /*void effacer();
    void execExo();
    //void execMenu();
    void execNote();
    void sauvegarder()     {m_tabModule->sauvegarder();}*/
protected slots:
    void selectDefaultAnnee();

};
#endif // FENPRINCIPALE_H
