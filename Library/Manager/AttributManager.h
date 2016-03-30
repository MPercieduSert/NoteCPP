/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef ATTRIBUTMANAGER_H
#define ATTRIBUTMANAGER_H

#include "ManagerSql.h"
#include "AttributLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entité Attribut.
 */
class AttributManager : public ManagerSql<AttributLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    AttributManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // ATTRIBUTMANAGER_H
