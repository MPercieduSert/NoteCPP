/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/03/2016
 */
#ifndef GROUPEMANAGER_H
#define GROUPEMANAGER_H

#include "ManagerSql.h"
#include "GroupeLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entité Groupe.
 */
class GroupeManager : public ManagerSql<GroupeLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    GroupeManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // GROUPEMANAGER_H
