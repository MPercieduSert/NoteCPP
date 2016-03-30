/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef CLASSEELEVEMANAGER_H
#define CLASSEELEVEMANAGER_H

#include "ManagerSql.h"
#include "ClasseEleveLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entité ClasseEleve.
 */
class ClasseEleveManager : public ManagerSql<ClasseEleveLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    ClasseEleveManager(QSqlQuery & req)
        : ManagerSql(req)
    {}
};

#endif // CLASSEELEVEMANAGER_H
