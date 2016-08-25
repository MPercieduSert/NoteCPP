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
    m_bdd.setFileName(m_config.getVars(DEFAULT_DIRECTORY));
    FenFoundFile fenBdd(&m_bdd,this);
    //QMap<QString,QString> atts;
    //atts.insert("name","main");
    //atts.insert("default","yes");
    fenBdd.openInConf(DATA_BASE);
    //m_bdd.miseAJour();

    //! + Selection de l'année courante
    QString strDiagAn;
    Annee annee;
    if(m_config.varExists(DEFAULT_ANNEE))
    {
        annee.setAn(m_config.getVars(DEFAULT_ANNEE).toInt());
        if(annee.an() != 0 && !m_bdd.getUnique(annee))
        {
            strDiagAn = tr("L'année par défaut enregistrée dans le fichier de configuration n'existe pas. "
                           "Vous devez selectionner une année par défaut ou en créer une.");
        }
    }
    else
    {
        strDiagAn = tr("Aucune année par défaut n'est enregistrée dans le fichier de configuration. "
                       "Vous devez selectionner une année par défaut ou en créer une.");
    }
    if(!strDiagAn.isEmpty())
    {
        QMessageBox::critical(this,tr("Année par défaut invalide"),strDiagAn);
        annee = selectAnnee(Annee(0,0), false, true, true);
        m_config.add(DEFAULT_ANNEE,QString::number(annee.an()));
    }

    setAnnee(annee);

    m_tabModule = new TabModule(this);
    setCentralWidget(m_tabModule);
}

void FenPrincipale::setEnabledCopierColler(bool bb)
{
    m_actionEditColler->setEnabled(bb);
    m_actionEditCopier->setEnabled(bb);
    m_actionEditCouper->setEnabled(bb);
    m_actionEditEffacer->setEnabled(bb);
}



void FenPrincipale::createAction()
{
    m_actionEditColler = new QAction(tr("Coller"),this);
    m_actionEditColler->setShortcut(QKeySequence::Paste);
    m_actionEditColler->setEnabled(false);
    //connect(m_actionEditColler,&QAction::triggered,this,&FenPrincipale::coller);

    m_actionEditCopier = new QAction(tr("Copier"),this);
    m_actionEditCopier->setShortcut(QKeySequence::Copy);
    m_actionEditCopier->setEnabled(false);
    //connect(m_actionEditCopier,&QAction::triggered,this,&FenPrincipale::copier);

    m_actionEditCouper = new QAction(tr("Couper"),this);
    m_actionEditCouper->setShortcut(QKeySequence::Cut);
    m_actionEditCouper->setEnabled(false);
    //connect(m_actionEditCouper,&QAction::triggered,this,&FenPrincipale::couper);

    m_actionEditEffacer = new QAction(tr("Effacer"),this);
    m_actionEditEffacer->setShortcut(QKeySequence::Delete);
    m_actionEditEffacer->setEnabled(false);
    //connect(m_actionEditEffacer,&QAction::triggered,this,&FenPrincipale::effacer);

    m_actionModuleExercice = new QAction(tr("Exercice"),this);
    //connect(m_actionModuleExercice,&QAction::triggered,this,&FenPrincipale::execExo);

    m_actionModuleNote = new QAction(tr("Note"),this);
    //connect(m_actionModuleNote,&QAction::triggered,this,&FenPrincipale::execNote);
    m_actionModuleNote->setEnabled(false);

    m_actionNewAnnee = new QAction(tr("Année"),this);
    connect(m_actionNewAnnee,&QAction::triggered,this,&FenPrincipale::creerAnnee);

    m_actionNewAttribut = new QAction(tr("Attribut"),this);
    m_actionNewAttribut->setEnabled(false);
    m_actionNewBareme = new QAction(tr("Barème"),this);
    m_actionNewBareme->setEnabled(false);
    m_actionNewClasse = new QAction(tr("Classe"),this);
    connect(m_actionNewClasse,&QAction::triggered,this,&FenPrincipale::creerClasse);

    m_actionNewControle = new QAction(tr("Controle"),this);
    m_actionNewControle->setEnabled(false);

    m_actionNewEtablissement = new QAction(tr("Etablissement"),this);
    connect(m_actionNewEtablissement,&QAction::triggered,[=](){this->creerEtablissement();});

    m_actionNewExercice = new QAction(tr("Exercice"),this);
    m_actionNewExercice->setEnabled(false);

    m_actionSauvegarder = new QAction(tr("Sauvegarder"),this);
    m_actionSauvegarder->setShortcut(QKeySequence::Save);
    m_actionSauvegarder->setEnabled(false);
    //connect(m_actionSauvegarder,&QAction::triggered,this,&FenPrincipale::sauvegarder);

    m_actionSelectDefaultAnnee = new QAction(tr("Choisir ou Créer une année de travail par defaut"),this);
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

// Public slots

/*void FenPrincipale::coller()
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
*/
void FenPrincipale::creerAnnee()
{
    NewAnneeDialog diag(this);
    diag.exec();
    int n = diag.result();
    if(n > 0)
    {
        Annee annee(n,0);
        if(m_bdd.existsUnique(annee))
        {
            QMessageBox::critical(this,"Erreur année","L'année "+annee.affiche()+" existe déjà.");
        }
        else
        {
            m_bdd.save(annee);
        }
    }
}

void FenPrincipale::creerClasse()
{
    NewClasseDialog dial(m_anneeDefaut,
                         m_bdd.getVector<Etablissement>(),
                         m_bdd.getVector<EtablissementNiveau>(),
                         m_bdd.getVector<Niveau>(),
                         m_bdd.getVector<Classe>(),
                         this);
    if(dial.exec() == QDialog::Accepted)
    {
        NewClasseDialog::dialogResult value = dial.value();
        if(value.classe.id() == NewClasseDialog::dialogResult::creerEtab)
        {
            creerEtablissement();
            creerClasse();
        }
        else
        {
            Classe classe(dial.value().classe);
            m_bdd.save(classe);
            for(int i = 0; i != dial.value().nbrEleve; ++i)
            {
                Eleve eleve(true,
                      QDate(2000,1,1),
                      QString::number(i)+"nom_classe"+QString::number(classe.id()),
                      QString::number(i)+"prenom_classe"+QString::number(classe.id()));
                m_bdd.save(eleve);
                m_bdd.save(ClasseEleve(classe.id(),eleve.id()));
            }
        }
    }
}

void FenPrincipale::creerEtablissement(const QString & nc, const QString & nom)
{
    NewEtablissementDialog dial(m_bdd.getVector<TypeEtablissement>(), m_bdd.getVector<Niveau>(),nc,nom,this);
    if(dial.exec() == QDialog::Accepted)
    {
        NewEtablissementDialog::dialogResult result = dial.value();
        if(!result.etab.isValid())
        {
            QMessageBox::critical(this,tr("Entrée invalide"),tr("Le nom et le nom abrégé de l'établissement doivent être entrés"));
            creerEtablissement(result.etab.nc(),result.etab.nom());
        }
        else if(m_bdd.existsUnique(result.etab))
        {
            QMessageBox::critical(this,tr("Entrée invalide"),tr("Un établissement de même non existe déjà dans la base de donnée"));
            creerEtablissement(result.etab.nc(),result.etab.nom());
        }
        else
        {
            m_bdd.save(result.etab);
            for(QVector<int>::iterator i = result.types.begin(); i != result.types.end(); ++i)
                m_bdd.save(EtablissementType(result.etab.id(),*i));
            for(QVector<int>::iterator i = result.niveaux.begin(); i != result.niveaux.end(); ++i)
                m_bdd.save(EtablissementNiveau(result.etab.id(),*i));
        }
    }
}

/*void FenPrincipale::execMenu()
{
    FenMenu * fen = new FenMenu(this);
    setCentralWidget(fen);
}*/

/*
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
}*/

Annee FenPrincipale::selectAnnee(Annee preSelect, bool annule, bool creer, bool vide)
{
    VectorEntities<Annee> vecAnnee(m_bdd.getList<Annee>(Annee::anPos));
    if(vide)
    {
        vecAnnee.append(Annee(0,0));
    }
    SelectAnneeDialog diag(vecAnnee,this,preSelect.id(),annule,creer);
    diag.exec();
    if(diag.result() > 0)
    {
        Annee an(diag.result());
        m_bdd.get(an);
        return an;
    }
    if(diag.result() == 0)
        {return Annee(0,0);}
    if(creer && diag.result() == SelectAnneeDialog::Creer)
    {
        NewAnneeDialog diagNew(this);
        diagNew.exec();
        if(diagNew.result() > 0)
        {
            Annee an(diagNew.result(),0);
            if(!m_bdd.existsUnique(an))
                m_bdd.save(an);
            else
                m_bdd.getUnique(an);
            return selectAnnee(an, annule, creer, vide);
        }
        else
        {return selectAnnee(preSelect, annule, creer, vide);}
    }
    else
        {return Annee(-1);}
}


void FenPrincipale::selectDefaultAnnee()
{
    Annee an(selectAnnee(m_anneeDefaut,true,true,true));
    if(an.id() >= 0)
    {
        setAnnee(an);
        m_config.modify(DEFAULT_ANNEE,QString::number(m_anneeDefaut.an()));
    }
}

void FenPrincipale::setAnnee(const Annee & an)
{
    if(an.an() == 0)
    {
        m_anneeDefaut = an;
        m_actionNewClasse->setEnabled(false);
    }
    else if(an.isValid())
    {
        m_anneeDefaut = an;
        m_actionNewClasse->setEnabled(true);
    }
}
