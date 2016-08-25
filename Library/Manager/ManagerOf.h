/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef MANAGEROF_H
#define MANAGEROF_H

#include "InfoBdd.h"
#include "LinkSql.h"
#include "ManagerSql.h"
#include "UniqueSql.h"

/*! \defgroup groupeManagerOf Manageur des entités.
 * \ingroup groupeManager
 * \brief Ensemble des manageur des entités.
 */

/*! \ingroup groupeBaseManager
 * \brief Classe template permettant d'instancier les différents manageurs.
 */
template<class Ent> class ManagerOf : public ManagerSql<Ent,typename InfoBdd<Ent>::EntLinkSql,typename InfoBdd<Ent>::EntUniqueSql>
{
protected:
    using ManagerSql<Ent,typename InfoBdd<Ent>::EntLinkSql,typename InfoBdd<Ent>::EntUniqueSql>::creerSql;
public:
    // Constructeur.
    ManagerOf()
     : ManagerSql<Ent,typename InfoBdd<Ent>::EntLinkSql,typename InfoBdd<Ent>::EntUniqueSql>(InfoBdd<Ent>::table(),
                                                                                            InfoBdd<Ent>::attribut(),
                                                                                            InfoBdd<Ent>::attributUnique())
        {}

    // Creer la table.
    void creer()
    {creerSql(InfoBdd<Ent>::creerAttribut(),InfoBdd<Ent>::attributUnique(),InfoBdd<Ent>::foreignKey());}
};

#endif // MANAGEROF_H
