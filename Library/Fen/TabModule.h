/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/05/2016
 */
#ifndef TABMODULE_H
#define TABMODULE_H

#include <QMap>
#include <QTabWidget>
#include "../Div/Bdd.h"

class FenPrincipale;
class TabAbstractModule;
//class TabClasse;
//class TabListeEleve;
//class TabListeGroupe;
class TabMenu;

/*! \ingroup groupeFen
 * \brief Fenêtre à onglet
 */
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
    FenPrincipale * m_parent;   //! Pointeur sur la fenêtre principale
    QMap<int,TabAbstractModule *> m_listeTab[NbrTab];       //! Tableau par type des onglets ouverts
    //QList<TabAbstractModule *> m_tabList;
public:
    //! Constructeur
    TabModule(FenPrincipale * parent);

    //! Renvoie le pointeur du parent
    FenPrincipale * parent() const
        {return m_parent;}
signals:

public slots:
    //void coller();
    //void copier();
    //void creerClasse();
    //! Action à effectuer si la fenêtre courante change.
    void currentIndexChanged();
    //void effacer();
    //! Ouvre un nouvel onglet classe
    void newOngletClasse(int idClasse);
    //! Ouvre un onglet liste des éléves
    void openListeEleve(int idClasse);
    //! Ouvre un ouglet liste des groupe
    //void openListeGroupe(int idClasse);
    //void sauvegarder() const;
};

#endif // TABMODULE_H
