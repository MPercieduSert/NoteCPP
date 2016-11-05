/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef MANAGEROF_H
#define MANAGEROF_H

#include "InfoBdd.h"
#include "LinkSql.h"
#include "ManagerOfArbre.h"
#include "ManagerSql.h"
#include "UniqueSql.h"

/*! \defgroup groupeManagerOf Manageur des entités.
 * \ingroup groupeManager
 * \brief Ensemble des manageur des entités.
 */

/*! \ingroup groupeBaseManager
 * \brief Macro spécialisant les ManagerOf pour les entités de type Arbre.
 */
#define MANAGER_OF_ARBRE(ENTITY) template<> class ManagerOf<ENTITY> : public ManagerOfArbre<ENTITY,typename InfoBdd<ENTITY>::EntLinkSql,typename InfoBdd<ENTITY>::EntUniqueSql> \
    {public: \
        /*! Constructeur.*/ \
        ManagerOf(): ManagerOfArbre<ENTITY,typename InfoBdd<ENTITY>::EntLinkSql,typename InfoBdd<ENTITY>::EntUniqueSql> \
(InfoBdd<ENTITY>::table(),InfoBdd<ENTITY>::attribut(),InfoBdd<ENTITY>::attributUnique(),InfoBdd<ENTITY>::tableArbre(),InfoBdd<ENTITY>::attributArbre()) {} \
    /*! Creer la table.*/ \
    void creer() \
    {creerSql(InfoBdd<ENTITY>::creerAttribut(),InfoBdd<ENTITY>::attributUnique(),InfoBdd<ENTITY>::foreignKey());}};


/*! \ingroup groupeBaseManager
 * \brief Classe template permettant d'instancier les différents manageurs.
 */
template<class Ent> class ManagerOf : public ManagerSql<Ent,typename InfoBdd<Ent>::EntLinkSql,typename InfoBdd<Ent>::EntUniqueSql>
{
protected:
    using ManagerSql<Ent,typename InfoBdd<Ent>::EntLinkSql,typename InfoBdd<Ent>::EntUniqueSql>::creerSql;
public:
    //! Constructeur.
    ManagerOf()
        : ManagerSql<Ent,typename InfoBdd<Ent>::EntLinkSql,typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::table(),
                                                                                            InfoBdd<Ent>::attribut(),
                                                                                            InfoBdd<Ent>::attributUnique())
        {}

    //! Creer la table.
    void creer()
    {creerSql(InfoBdd<Ent>::creerAttribut(),InfoBdd<Ent>::attributUnique(),InfoBdd<Ent>::foreignKey());}
};

MANAGER_OF_ARBRE(Attribut)
MANAGER_OF_ARBRE(Donnee)

#endif // MANAGEROF_H
