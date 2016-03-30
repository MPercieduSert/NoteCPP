/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/03/2016
 */

#ifndef ELEVEMANAGER_H
#define ELEVEMANAGER_H

#include "ManagerSql.h"
#include "EleveLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entité Eleve.
 */
class EleveManager : public ManagerSql<EleveLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    EleveManager(QSqlQuery & req)
        :ManagerSql(req)
    {}
};

#endif // ELEVEMANAGER_H
