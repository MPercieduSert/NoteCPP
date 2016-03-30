/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/03/2016
 */

#ifndef DONNEEMANAGER_H
#define DONNEEMANAGER_H

#include "ManagerSql.h"
#include "DonneeLinkSql.h"


/*! \ingroup groupeManager
 * \brief Manager de l'entité Donnee.
 */
class DonneeManager : public ManagerSql<DonneeLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    DonneeManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // DONNEEMANAGER_H
