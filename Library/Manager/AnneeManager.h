/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/03/2016
 */

#ifndef ANNEEMANAGER_H
#define ANNEEMANAGER_H

#include "ManagerSql.h"
#include "AnneeLinkSql.h"


/*! \ingroup groupeManager
 * \brief Manager de l'entitée Annee.
 */

class AnneeManager : public ManagerSql<AnneeLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    AnneeManager(QSqlQuery & req);

};

#endif // ANNEEMANAGER_H
