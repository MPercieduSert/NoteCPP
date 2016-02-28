#include "FenPrincipale.h"

FenPrincipale::FenPrincipale(QString path, QWidget *parent) :
    QMainWindow(parent),
    m_bdd("QSQLITE"),
    m_config(path+"/confFile.xml")

{
    //! + Création des Menus.
    // et toolbar.
    createAction();
    createMenu();
    //createToolBar();

    //! + Ouverture du fichier de configuration.
    FenFoundFile fenConfig(&m_config,this);
    fenConfig.exists();
    fenConfig.isValid();

    //!  + Ouverture de la base de donnée.
    m_bdd.setFileName(m_config.getVars("conf/directories/default"));
    FenFoundFile fenBdd(&m_bdd,this);
    //QMap<QString,QString> atts;
    //atts.insert("name","main");
    //atts.insert("default","yes");
    fenBdd.openInConf("conf/files/databases/database");
    m_bdd.setBdd();

    //! + Selection de l'année courante
    QVector<Annee> anneeDefaut = ListEntities<Annee>::vector(m_bdd.getList(Entity::AnneeId,Annee::EncoursPos,QVariant(true)));
    if(anneeDefaut.isEmpty())
    {
        QLabel *label = new QLabel(this);
        label->setText(tr("Veulliez selectionner une année de travail."));
        setCentralWidget(label);
    }
    else
    {
        m_bdd.setAnnee(anneeDefaut.at(0));
        m_tabModule = new TabModule(&m_bdd,this);
        setCentralWidget(m_tabModule);
        //exec();
    }
}

void FenPrincipale::setEnabledCopierColler(bool bb)
{
    m_actionEditColler->setEnabled(bb);
    m_actionEditCopier->setEnabled(bb);
    m_actionEditCouper->setEnabled(bb);
    m_actionEditEffacer->setEnabled(bb);
}

// %%%%%%%%%% protected %%%%%%%%%%%%%
void FenPrincipale::changeAnnee(int anneeId)
{
    Annee annee(anneeId);
    if(m_bdd.get(annee))
    {
        annee.setEncours(true);
        m_bdd.save(annee);
        m_bdd.setAnnee(annee);
        emit anneeChanged();
    }

}

void FenPrincipale::createAction()
{
    m_actionEditColler = new QAction(tr("Coller"),this);
    m_actionEditColler->setShortcut(QKeySequence::Paste);
    m_actionEditColler->setEnabled(false);
    connect(m_actionEditColler,&QAction::triggered,this,&FenPrincipale::coller);

    m_actionEditCopier = new QAction(tr("Copier"),this);
    m_actionEditCopier->setShortcut(QKeySequence::Copy);
    m_actionEditCopier->setEnabled(false);
    connect(m_actionEditCopier,&QAction::triggered,this,&FenPrincipale::copier);

    m_actionEditCouper = new QAction(tr("Couper"),this);
    m_actionEditCouper->setShortcut(QKeySequence::Cut);
    m_actionEditCouper->setEnabled(false);
    connect(m_actionEditCouper,&QAction::triggered,this,&FenPrincipale::couper);

    m_actionEditEffacer = new QAction(tr("Effacer"),this);
    m_actionEditEffacer->setShortcut(QKeySequence::Delete);
    m_actionEditEffacer->setEnabled(false);
    connect(m_actionEditEffacer,&QAction::triggered,this,&FenPrincipale::effacer);

    m_actionModuleExercice = new QAction(tr("Exercice"),this);
    connect(m_actionModuleExercice,&QAction::triggered,this,&FenPrincipale::execExo);

    m_actionModuleNote = new QAction(tr("Note"),this);
    connect(m_actionModuleNote,&QAction::triggered,this,&FenPrincipale::execNote);
    m_actionModuleNote->setEnabled(false);

    m_actionNewAnnee = new QAction(tr("Année"),this);
    connect(m_actionNewAnnee,&QAction::triggered,this,&FenPrincipale::creerAnnee);

    m_actionNewAttribut = new QAction(tr("Attribut"),this);
    m_actionNewBareme = new QAction(tr("Barème"),this);
    m_actionNewClasse = new QAction(tr("Classe"),this);
    m_actionNewControle = new QAction(tr("Controle"),this);
    m_actionNewExercice = new QAction(tr("Exercice"),this);

    m_actionSauvegarder = new QAction(tr("Sauvegarder"),this);
    m_actionSauvegarder->setShortcut(QKeySequence::Save);
    m_actionSauvegarder->setEnabled(false);
    connect(m_actionSauvegarder,&QAction::triggered,this,&FenPrincipale::sauvegarder);

    m_actionSelectDefaultAnnee = new QAction(tr("Choisir l'année de travail"),this);
    connect(m_actionSelectDefaultAnnee,&QAction::triggered,this,&FenPrincipale::selectDefaultAnnee);
}

void FenPrincipale::createMenu()
{
    m_menuFichier = menuBar()->addMenu(tr("&Fichier"));
    m_menuNew = m_menuFichier->addMenu(tr("Nouveau"));
    m_menuFichier->addAction(m_actionSelectDefaultAnnee);
    m_menuFichier->addAction(m_actionSauvegarder);

    m_menuNew->addAction(m_actionNewAnnee);
    m_menuNew->addAction(m_actionNewClasse);
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

// Public slots

void FenPrincipale::coller()
{
    m_tabModule->coller();
}

void FenPrincipale::copier()
{
    m_tabModule->copier();
}

void FenPrincipale::couper()
{
    m_tabModule->copier();
    m_tabModule->effacer();
}

void FenPrincipale::effacer()
{
    m_tabModule->effacer();
}

void FenPrincipale::creerAnnee()
{
    NewAnneeDialog dial(this);
    int n = dial.exec();
    QLabel *label = new QLabel(this);
    label->setText("Creer :"+QString::number(n));
    setCentralWidget(label);
    if(n > 0)
    {
        Annee annee(dial.isChecked(),n);
        if(m_bdd.existsUnique(annee))
        {
            QMessageBox::critical(this,"Erreur année","L'année "+annee.affiche()+" existe déjà.");
            creerAnnee();
        }
        else
        {
            m_bdd.creerAnnee(annee);
        }
    }
}

void FenPrincipale::creerClasse()
{
    QVector<Niveau> listeNiveau;
    ListEntities<Niveau>::vector(listeNiveau, m_bdd.getList(Entity::NiveauId));
    QVector<Classe> listeClasse;
    ListEntities<Classe>::vector(listeClasse, m_bdd.getList(Entity::ClasseId,Classe::AnneePos,QVariant(m_bdd.annee().id())));
    NewClasseDialog dial(listeNiveau,m_bdd.annee(),listeClasse,Niveau::Numeric,this);
    if(dial.exec() == QDialog::Accepted)
    {
        Classe classe(dial.value().classe);
        m_bdd.save(classe);
        for(int i = 0; i != dial.value().nbrEleve; ++i)
        {
            Eleve eleve(classe.id(),
                  true,
                  QDate(2000,1,1),
                  QString::number(i)+"nom_classe"+QString::number(classe.id()),
                  QString::number(i)+"prenom_classe"+QString::number(classe.id()));
            m_bdd.save(eleve);
        }
    }
}

/*void FenPrincipale::execMenu()
{
    FenMenu * fen = new FenMenu(this);
    setCentralWidget(fen);
}*/

void FenPrincipale::execNote()
{
    m_actionModuleExercice->setEnabled(true);
    m_actionModuleNote->setEnabled(false);
    FenNote * fen = new FenNote(m_bdd,this);
    setCentralWidget(fen);
}

void FenPrincipale::execExo()
{
    m_actionModuleExercice->setEnabled(false);
    m_actionModuleNote->setEnabled(true);
    FenExo * fen = new FenExo(this);
    setCentralWidget(fen);
}

void FenPrincipale::selectDefaultAnnee()
{
    QVector<Annee> listeAnnee;
    ListEntities<Annee>::vector(listeAnnee, m_bdd.getList(Entity::AnneeId,Annee::EncoursPos,false,Annee::RentreePos));
    SelectAnneeDialog dial(listeAnnee, this, true);
    switch (dial.exec()) {
    case SelectAnneeDialog::Creer:
        creerAnnee();
        break;
    case SelectAnneeDialog::Accepted:
        changeAnnee(dial.value());
        break;
    default:
        break;
    };
}
