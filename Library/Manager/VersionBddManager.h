/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/05/2016
 */
#ifndef VERSIONBDDMANAGER_H
#define VERSIONBDDMANAGER_H

#include "InfoBddBase.h"
#include "LinkSqlBase.h"
#include "ManagerSql.h"
#include "UniqueSqlBase.h"
#include "../Entities/VersionBdd.h"

/*! \ingroup groupeBaseManager
 * \brief Manager de l'entité VersionBdd
 */
class VersionBddManager : public ManagerSql<VersionBdd,DateTimeNumOnlyLinkSql<VersionBdd>,NumUniqueSql>
{
public:
    // Constructeur.
    VersionBddManager()
     : ManagerSql("vrbdd",
                  DateTimeNumInfoBdd::attribut(),
                  NumInfoBdd::attributUnique())
        {}

    // Creer la table.
    void creer()
    {creerSql(DateTimeNumInfoBdd::creerAttribut(),NumInfoBdd::attributUnique());}
};

#endif // VERSIONBDDMANAGER_H
