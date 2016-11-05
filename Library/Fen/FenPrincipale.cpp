#include "FenPrincipale.h"

FenPrincipale::FenPrincipale(QString path, QWidget *parent) :
    QMainWindow(parent)
{
    m_noyau = new Noyau(path, this);
    // Création de la zone centrale.
    //! + Création des Menus.
    // et toolbar.
    createAction();
    createMenu();
    //createToolBar();
    setCentralWidget(m_noyau->centralZone());
}

void FenPrincipale::createAction()
{
    // Coller
    m_actionEditColler = new QAction(tr("Coller"),this);
    m_actionEditColler->setShortcut(QKeySequence::Paste);
    m_actionEditColler->setEnabled(false);
    connect(m_actionEditColler,&QAction::triggered,m_noyau,&Noyau::coller);
    connect(m_noyau,SIGNAL(collerPermis(bool)),m_actionEditColler,SLOT(setEnabled(bool)));

    // Copier
    m_actionEditCopier = new QAction(tr("Copier"),this);
    m_actionEditCopier->setShortcut(QKeySequence::Copy);
    m_actionEditCopier->setEnabled(false);
    connect(m_actionEditCopier,&QAction::triggered,m_noyau,&Noyau::copier);
    connect(m_noyau,SIGNAL(copierPermis(bool)),m_actionEditCopier,SLOT(setEnabled(bool)));

    // Couper
    m_actionEditCouper = new QAction(tr("Couper"),this);
    m_actionEditCouper->setShortcut(QKeySequence::Cut);
    m_actionEditCouper->setEnabled(false);
    connect(m_actionEditCouper,&QAction::triggered,m_noyau,&Noyau::couper);
    connect(m_noyau,SIGNAL(couperPermis(bool)),m_actionEditCouper,SLOT(setEnabled(bool)));

    // Effacer
    m_actionEditEffacer = new QAction(tr("Effacer"),this);
    m_actionEditEffacer->setShortcut(QKeySequence::Delete);
    m_actionEditEffacer->setEnabled(false);
    connect(m_actionEditEffacer,&QAction::triggered,m_noyau,&Noyau::effacer);
    connect(m_noyau,SIGNAL(effacerPermis(bool)),m_actionEditEffacer,SLOT(setEnabled(bool)));

    m_actionModuleExercice = new QAction(tr("Exercice"),this);
    //connect(m_actionModuleExercice,&QAction::triggered,this,&FenPrincipale::execExo);

    m_actionModuleNote = new QAction(tr("Note"),this);
    //connect(m_actionModuleNote,&QAction::triggered,this,&FenPrincipale::execNote);
    m_actionModuleNote->setEnabled(false);

    m_actionNewAnnee = new QAction(tr("Année"),this);
    connect(m_actionNewAnnee,&QAction::triggered,[this]{this->m_noyau->creerAnnee(this);});

    m_actionNewAttribut = new QAction(tr("Attribut"),this);
    m_actionNewAttribut->setEnabled(false);

    m_actionNewBareme = new QAction(tr("Barème"),this);
    m_actionNewBareme->setEnabled(false);

    m_actionNewClasse = new QAction(tr("Classe"),this);
    connect(m_actionNewClasse,&QAction::triggered,[this]{this->m_noyau->creerClasse(this);});
    connect(m_noyau,SIGNAL(creerClassePermis(bool)),m_actionNewClasse,SLOT(setEnabled(bool)));

    m_actionNewControle = new QAction(tr("Controle"),this);
    m_actionNewControle->setEnabled(false);

    m_actionNewEtablissement = new QAction(tr("Etablissement"),this);
    connect(m_actionNewEtablissement,&QAction::triggered,[this]{this->m_noyau->creerEtablissement(this);});

    m_actionNewExercice = new QAction(tr("Exercice"),this);
    m_actionNewExercice->setEnabled(false);

    // Save
    m_actionSave = new QAction(tr("Sauvegarder"),this);
    m_actionSave->setShortcut(QKeySequence::Save);
    m_actionSave->setEnabled(false);
    connect(m_actionSave,&QAction::triggered,m_noyau,&Noyau::save);
    connect(m_noyau,SIGNAL(savePermis(bool)),m_actionSave,SLOT(setEnabled(bool)));

    m_actionSelectDefaultAnnee = new QAction(tr("Choisir ou Créer une année de travail par defaut"),this);
    connect(m_actionSelectDefaultAnnee,&QAction::triggered,[this]{this->m_noyau->selectDefaultAnnee(this);});
}

void FenPrincipale::createMenu()
{
    m_menuFichier = menuBar()->addMenu(tr("&Fichier"));
    m_menuNew = m_menuFichier->addMenu(tr("&Nouveau"));
    m_menuFichier->addAction(m_actionSelectDefaultAnnee);
    m_menuFichier->addAction(m_actionSave );

    m_menuNew->addAction(m_actionNewAnnee);
    m_menuNew->addAction(m_actionNewClasse);
    m_menuNew->addAction(m_actionNewEtablissement);
    m_menuNew->addAction(m_actionNewControle);
    m_menuNew->addSeparator();
    m_menuNew->addAction(m_actionNewAttribut);
    m_menuNew->addAction(m_actionNewBareme);
    m_menuNew->addAction(m_actionNewExercice);

    m_menuEdit = menuBar()->addMenu("&Edit");
    m_menuEdit->addAction(m_actionEditColler);
    m_menuEdit->addAction(m_actionEditCopier);
    m_menuEdit->addAction(m_actionEditCouper);
    m_menuEdit->addAction(m_actionEditEffacer);
}

void FenPrincipale::createToolBar()
{
    m_toolBar = addToolBar(tr("Module"));
    m_toolBar->addAction(m_actionModuleNote);
    m_toolBar->addAction(m_actionModuleExercice);

}
