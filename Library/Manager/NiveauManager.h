/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */

#ifndef NIVEAUMANAGER_H
#define NIVEAUMANAGER_H

#include "ManagerSql.h"
#include "NiveauLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entité Niveau.
 */
class NiveauManager : public ManagerSql<NiveauLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    NiveauManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // NIVEAUMANAGER_H
