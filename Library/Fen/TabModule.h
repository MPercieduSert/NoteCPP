/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/05/2016
 */
#ifndef TABMODULE_H
#define TABMODULE_H

#include <QMap>
#include <QTabWidget>
#include "../Div/Noyau.h"

class TabAbstractModule;

/*! \ingroup groupeFen
 * \brief Fenêtre à onglet
 */
class TabModule : public QTabWidget
{
    Q_OBJECT
public:
    //! Type de module.
    enum typeTab {MenuTab,
                 ClasseTab,
                 CoursTab,
                 ListeEleveTab,
                 ListeNoteTab,
                 GroupeTab,
                 MotCleTab,
                 NbrTab};
protected:
    Noyau* m_noyau;         //!< Pointeur sur le noyau.
    QMap<int,TabAbstractModule *> m_listeTab[NbrTab];       //!< Tableau par type des onglets ouverts
    //QList<TabAbstractModule *> m_tabList;
public:
    //! Constructeur
    TabModule(QWidget *parent, Noyau * noyau);

    //! Renvoie un pointeur sur la base de données.
    Bdd * bdd()
        {return m_noyau->bdd();}

    //! Renvoie un pointeur sur le noyau.
    Noyau * noyau()
        {return m_noyau;}

signals:


public slots:
    //! Action à effectuer si la fenêtre courante change.
    void currentIndexChanged();
    //void effacer();
    //! Ouvre un nouvel onglet classe
    void newOngletClasse(int idClasse);
    //! Ouvre un onglet donnant acces au cours
    void openCours();
    //! Ouvre un onglet liste des éléves
    void openListeEleve(int idClasse);
    //! Ouvre un onglet donnant acces au cours
    void openMotCle();
    //! Ouvre un ouglet liste des groupe
    //void openListeGroupe(int idClasse);
    //! Ouvre un onglet liste des notes
    void openListeNote(int idClasse);

};

#endif // TABMODULE_H
