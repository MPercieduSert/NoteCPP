#include "TabModule.h"
#include "TabAbstractModule.h"
#include "TabClasse.h"
#include "TabCours.h"
#include "TabGestionBdd.h"
#include "TabListeEleve.h"
#include "TabListeGroupe.h"
#include "TabListeNote.h"
#include "TabMenu.h"
#include "TabMotCle.h"

TabModule::TabModule(QWidget *parent, Noyau *noyau): QTabWidget(parent), m_noyau(noyau)
{
    TabMenu * tabMenu = new TabMenu(noyau->annee().id(),this);
    m_listeTab[MenuTab].insert(noyau->annee().id(),tabMenu);
    addTab(tabMenu, noyau->annee().affiche());
    connect(this,&TabModule::currentChanged,this,&TabModule::currentIndexChanged);
}

void TabModule::currentIndexChanged()
    {static_cast<TabAbstractModule *>(currentWidget())->becomeCurrent();}

void TabModule::newOngletClasse(int idClasse)
{
    if(m_listeTab[ClasseTab].contains(idClasse))
        setCurrentIndex(indexOf(m_listeTab[ClasseTab][idClasse]));
    else
    {
        TabClasse * tabClasse = new TabClasse(idClasse, this);
        m_listeTab[ClasseTab].insert(idClasse,tabClasse);
        setCurrentIndex(addTab(tabClasse, tabClasse->classe().nom()));
    }
}

void TabModule::openCours()
{
    if(!m_listeTab[CoursTab].isEmpty())
        setCurrentIndex(indexOf(m_listeTab[CoursTab].first()));
    else
    {
        TabCours * tabCours = new TabCours(0,this);
        m_listeTab[CoursTab].insert(0,tabCours);
        setCurrentIndex(addTab(tabCours,tr("Cours")));
    }
}

void TabModule::openGestionBdd()
{
    if(!m_listeTab[GestionBddTab].isEmpty())
        setCurrentIndex(indexOf(m_listeTab[GestionBddTab].first()));
    else
    {
        TabGestionBdd * tabGestionBdd = new TabGestionBdd(bdd()->db(),0,this);
        m_listeTab[GestionBddTab].insert(0,tabGestionBdd);
        setCurrentIndex(addTab(tabGestionBdd,tr("Base de données")));
    }
}

void TabModule::openListeEleve(int idClasse)
{
    if(m_listeTab[ListeEleveTab].contains(idClasse))
        setCurrentIndex(indexOf(m_listeTab[ListeEleveTab][idClasse]));
    else
    {
        TabListeEleve * tabListeEleve = new TabListeEleve(idClasse, this);
        if(tabListeEleve->classe().isValid())
        {
            m_listeTab[ListeEleveTab].insert(idClasse,tabListeEleve);
            setCurrentIndex(addTab(tabListeEleve, tabListeEleve->classe().nom()+" - Liste des éléves"));
        }
        else
            delete tabListeEleve;
    }
}

void TabModule::openMotCle()
{
    if(!m_listeTab[MotCleTab].isEmpty())
        setCurrentIndex(indexOf(m_listeTab[MotCleTab].first()));
    else
    {
        TabMotCle * tabMotCle = new TabMotCle(0,this);
        m_listeTab[MotCleTab].insert(0,tabMotCle);
        setCurrentIndex(addTab(tabMotCle,tr("Mots Clés")));
    }
}

/*
void TabModule::openListeGroupe(int idClasse)
{
    if(m_listeTab[GroupeTab].contains(idClasse))
    {
        setCurrentIndex(indexOf(m_listeTab[GroupeTab][idClasse]));
    }
    else
    {
        TabListeGroupe * tabListeGroupe = new TabListeGroupe(idClasse, this);
        m_listeTab[GroupeTab].insert(idClasse, tabListeGroupe );
        setCurrentIndex(addTab(tabListeGroupe , parent()->bdd()->afficheClasse(idClasse)+" - Groupes"));
    }
}*/
void TabModule::openListeNote(int idClasse)
{
    if(m_listeTab[ListeNoteTab].contains(idClasse))
        setCurrentIndex(indexOf(m_listeTab[ListeNoteTab][idClasse]));
    else
    {
        TabListeNote * tabListeNote = new TabListeNote(idClasse, this);
        if(tabListeNote->classe().isValid())
        {
            m_listeTab[ListeNoteTab].insert(idClasse,tabListeNote);
            setCurrentIndex(addTab(tabListeNote, tabListeNote->classe().nom()+" - Liste des notes"));
        }
        else
            delete tabListeNote;
    }
}
