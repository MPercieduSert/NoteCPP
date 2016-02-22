#include "TabModule.h"
#include "FenPrincipale.h"
#include "TabAbstractModule.h"
#include "TabClasse.h"
#include "TabListeEleve.h"
#include "TabListeGroupe.h"
#include "TabMenu.h"

TabModule::TabModule(Bdd *bdd, FenPrincipale *parent): QTabWidget(parent), m_bdd(bdd), m_parent(parent)
{
    //m_tabMenu = new TabMenu(bdd,this);
    TabMenu * tabMenu = new TabMenu(bdd,this);
    m_listeTab[MenuTab].insert(0,tabMenu);
    addTab(tabMenu, "Menu");
    connect(parent,&FenPrincipale::anneeChanged,this,&TabModule::changeAnnee);
    connect(this,&TabModule::currentChanged,this,&TabModule::currentIndexChanged);
}

void TabModule::changeAnnee()
{
    ((TabMenu*) m_listeTab[MenuTab].first())->refreshClasse();
}

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

void TabModule::currentIndexChanged()
{
    static_cast<TabAbstractModule *>(currentWidget())->becomeCurrent();
}

void TabModule::effacer()
{
    static_cast<TabAbstractModule *> (currentWidget())->effacer();
}

void TabModule::newOngletClasse(int idClasse)
{
    if(m_listeTab[ClasseTab].contains(idClasse))
    {
        setCurrentIndex(indexOf(m_listeTab[ClasseTab][idClasse]));
    }
    else
    {
        TabClasse * tabClasse = new TabClasse(idClasse,m_bdd,this);
        m_listeTab[ClasseTab].insert(idClasse,tabClasse);
        setCurrentIndex(addTab(tabClasse, m_bdd->afficheClasse(idClasse)));
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
        TabListeEleve * tabListeEleve = new TabListeEleve(idClasse,m_bdd,this);
        m_listeTab[ListeEleveTab].insert(idClasse,tabListeEleve);
        setCurrentIndex(addTab(tabListeEleve, m_bdd->afficheClasse(idClasse)+" - Liste des éléves"));
    }
}

void TabModule::openListeGroupe(int idClasse)
{
    if(m_listeTab[GroupeTab].contains(idClasse))
    {
        setCurrentIndex(indexOf(m_listeTab[GroupeTab][idClasse]));
    }
    else
    {
        TabListeGroupe * tabListeGroupe = new TabListeGroupe(idClasse,m_bdd,this);
        m_listeTab[GroupeTab].insert(idClasse, tabListeGroupe );
        setCurrentIndex(addTab(tabListeGroupe , m_bdd->afficheClasse(idClasse)+" - Groupes"));
    }
}
void TabModule::sauvegarder() const
{
    static_cast<TabAbstractModule *>(currentWidget())->sauvegarder();
}
