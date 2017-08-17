/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/05/2016
 */
#ifndef VERSIONBDDMANAGER_H
#define VERSIONBDDMANAGER_H

#include "InfoBddBase.h"
#include "ManagerSql.h"
#include "UniqueSqlBase.h"
#include "../Entities/VersionBdd.h"

/*! \ingroup groupeBaseManager
 * \brief Manager de l'entité VersionBdd
 */
class VersionBddManager : public ManagerSql<VersionBdd,NumUniqueSql<VersionBdd>>
{
public:
    using VersionInfoBdd = InfoBddBase<NumUniqueInfoBdd<VersionBdd>,DateTimeInfoBdd<VersionBdd>>;
    // Constructeur.
    VersionBddManager()
     : ManagerSql("vrbdd",
                  VersionInfoBdd::attribut(),
                  VersionInfoBdd::attributUnique())
        {}

    // Creer la table.
    void creer()
    {creerSql(VersionInfoBdd::creerAttribut(),VersionInfoBdd::attributUnique());}
};

#endif // VERSIONBDDMANAGER_H
