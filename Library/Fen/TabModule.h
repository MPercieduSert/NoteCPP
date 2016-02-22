#ifndef TABMODULE_H
#define TABMODULE_H

#include <QMap>
#include <QTabWidget>
#include "../Div/Bdd.h"

class FenPrincipale;
class TabAbstractModule;
class TabClasse;
class TabListeEleve;
class TabListeGroupe;
class TabMenu;

class TabModule : public QTabWidget
{
    Q_OBJECT
public:
    enum typeTab {MenuTab = 0,
                 ClasseTab = 1,
                 ListeEleveTab = 2,
                 GroupeTab = 3,
                 NbrTab = 4};
protected:
    Bdd * m_bdd;
    FenPrincipale * m_parent;
    QMap<int,TabAbstractModule *> m_listeTab[NbrTab];
    //QList<TabAbstractModule *> m_tabList;
public:
    TabModule(Bdd * bdd, FenPrincipale * parent = 0);
    FenPrincipale * parent() const      {return m_parent;}
signals:

public slots:
    void changeAnnee();
    void coller();
    void copier();
    void creerClasse();
    void currentIndexChanged();
    void effacer();
    void newOngletClasse(int idClasse);
    void openListeEleve(int idClasse);
    void openListeGroupe(int idClasse);
    void sauvegarder() const;
};

#endif // TABMODULE_H
