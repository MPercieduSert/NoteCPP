/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef MANAGEROF_H
#define MANAGEROF_H

#include "InfoBdd.h"
#include "ManagerOfArbre.h"
#include "ManagerOfArbreModifControle.h"
#include "ManagerOfArbreSimple.h"
#include "ManagerOfArbreSimpleModifControle.h"
#include "ManagerOfModifControle.h"
#include "ManagerSql.h"
#include "UniqueSql.h"

/*! \defgroup groupeManagerOf Manageur des entités.
 * \ingroup groupeManager
 * \brief Ensemble des manageur des entités.
 */

/*! \ingroup groupeBaseManager
 * \brief Trait donnant le type du managerOf en fonction de l'entier bddInfo::TypeManager.
 */
template<class Ent, class Unique, int N> struct TypeManagerOf;
template<class Ent, class Unique> struct TypeManagerOf<Ent,Unique,bddInfo::typeManager::Simple>
    {using ManagerOfType = ManagerSql<Ent,Unique>;};
template<class Ent, class Unique> struct TypeManagerOf<Ent,Unique,bddInfo::typeManager::Arbre>
    {using ManagerOfType = ManagerOfArbre<Ent,Unique>;};
template<class Ent, class Unique> struct TypeManagerOf<Ent,Unique,bddInfo::typeManager::ArbreSimple>
    {using ManagerOfType = ManagerOfArbreSimple<Ent,Unique>;};
template<class Ent, class Unique> struct TypeManagerOf<Ent,Unique,bddInfo::typeManager::ModifControle>
    {using ManagerOfType = ManagerOfModifControle<Ent,Unique>;};
template<class Ent, class Unique> struct TypeManagerOf<Ent,Unique,bddInfo::typeManager::ArbreModifControle>
    {using ManagerOfType = ManagerOfArbreModifControle<Ent,Unique>;};
template<class Ent, class Unique> struct TypeManagerOf<Ent,Unique,bddInfo::typeManager::ArbreSimpleModifControle>
    {using ManagerOfType = ManagerOfArbreSimpleModifControle<Ent,Unique>;};

/*! \ingroup groupeBaseManager
 * \brief Classe template permettant d'instancier les différents manageurs.
 */
template<class Ent, int typeManager> class ManagerOfTemp :
        public TypeManagerOf<Ent,typename InfoBdd<Ent>::EntUniqueSql,typeManager>::ManagerOfType
{
public:
    //! Constructeur.
    ManagerOfTemp()
        : ManagerSql<Ent,typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::table(),
                                                              InfoBdd<Ent>::attribut(),
                                                              InfoBdd<Ent>::attributUnique())
    {}

    //! Creer la table.
    void creer()
    {ManagerSql<Ent,typename InfoBdd<Ent>::EntUniqueSql>::
                creerSql(InfoBdd<Ent>::creerAttribut(),InfoBdd<Ent>::attributUnique(),InfoBdd<Ent>::foreignKey());}
};

template<class Ent> class ManagerOfTemp<Ent,bddInfo::typeManager::Arbre> : public ManagerOfArbre<Ent, typename InfoBdd<Ent>::EntUniqueSql>
{
public:
    //! Constructeur.
    ManagerOfTemp()
        : ManagerSql<Ent, typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::table(),
                                                               InfoBdd<Ent>::attribut(),
                                                               InfoBdd<Ent>::attributUnique()),
          ManagerOfArbre<Ent, typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::tableArbre(),
                                                                   InfoBdd<Ent>::attributArbre())
    {}

    //! Creer la table.
    void creer()
        {ManagerOfArbre<Ent, typename InfoBdd<Ent>::EntUniqueSql>::
                creerSql(InfoBdd<Ent>::creerAttribut(),InfoBdd<Ent>::attributUnique(),InfoBdd<Ent>::foreignKey());}
};

template<class Ent> class ManagerOfTemp<Ent,bddInfo::typeManager::ArbreModifControle> : public ManagerOfArbreModifControle<Ent, typename InfoBdd<Ent>::EntUniqueSql>
{
public:
    //! Constructeur.
    ManagerOfTemp()
        : ManagerSql<Ent, typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::table(),
                                                               InfoBdd<Ent>::attribut(),
                                                               InfoBdd<Ent>::attributUnique()),
          ManagerOfArbreModifControle<Ent, typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::tableArbre(),
                                                                                InfoBdd<Ent>::attributArbre())
    {}

    //! Creer la table.
    void creer()
        {ManagerOfArbreModifControle<Ent, typename InfoBdd<Ent>::EntUniqueSql>::
                creerSql(InfoBdd<Ent>::creerAttribut(),InfoBdd<Ent>::attributUnique(),InfoBdd<Ent>::foreignKey());}
};

template<class Ent> using ManagerOf = ManagerOfTemp<Ent,TypeManager<Ent>::value>;
#endif // MANAGEROF_H
