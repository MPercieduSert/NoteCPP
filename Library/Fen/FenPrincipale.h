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
    QAction *m_actionSave;
    QAction *m_actionSelectDefaultAnnee;

    // Menu
    QMenu *m_menuEdit;
    QMenu *m_menuFichier;
    QMenu *m_menuNew;

    // Tools Bar
    QToolBar *m_toolBar;

    // Noyau
    Noyau * m_noyau;

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
