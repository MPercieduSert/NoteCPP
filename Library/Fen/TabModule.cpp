#include "TabModule.h"
#include "FenPrincipale.h"
#include "TabAbstractModule.h"
#include "TabClasse.h"
#include "TabListeEleve.h"
#include "TabListeGroupe.h"
#include "TabMenu.h"

TabModule::TabModule(FenPrincipale *parent): QTabWidget(parent), m_parent(parent)
{
    TabMenu * tabMenu = new TabMenu(parent->annee().id(),this);
    m_listeTab[MenuTab].insert(parent->annee().id(),tabMenu);
    addTab(tabMenu, parent->annee().affiche());
    connect(this,&TabModule::currentChanged,this,&TabModule::currentIndexChanged);
}
/*
void TabModule::coller()
{
    static_cast<TabAbstractModule *>(currentWidget())->coller();
}

void TabModule::copier()
{
    static_cast<TabAbstractModule *> (currentWidget())->copier();
}

void TabModule::creerClasse()
{
    m_parent->creerClasse();
}
*/
void TabModule::currentIndexChanged()
{
    static_cast<TabAbstractModule *>(currentWidget())->becomeCurrent();
}
/*
void TabModule::effacer()
{
    static_cast<TabAbstractModule *> (currentWidget())->effacer();
}
*/
void TabModule::newOngletClasse(int idClasse)
{
    if(m_listeTab[ClasseTab].contains(idClasse))
    {
        setCurrentIndex(indexOf(m_listeTab[ClasseTab][idClasse]));
    }
    else
    {
        TabClasse * tabClasse = new TabClasse(idClasse, this);
        m_listeTab[ClasseTab].insert(idClasse,tabClasse);
        setCurrentIndex(addTab(tabClasse, tabClasse->classe().nom()));
    }
}


void TabModule::openListeEleve(int idClasse)
{
    if(m_listeTab[ListeEleveTab].contains(idClasse))
    {
        setCurrentIndex(indexOf(m_listeTab[ListeEleveTab][idClasse]));
    }
    else
    {
        TabListeEleve * tabListeEleve = new TabListeEleve(idClasse, this);
        if(tabListeEleve->classe().isValid())
        {
            m_listeTab[ListeEleveTab].insert(idClasse,tabListeEleve);
            setCurrentIndex(addTab(tabListeEleve, tabListeEleve->classe().nom()+" - Liste des éléves"));
        }
        else
        {
            delete tabListeEleve;
        }
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
/*
void TabModule::sauvegarder() const
{
    static_cast<TabAbstractModule *>(currentWidget())->sauvegarder();
}*/
