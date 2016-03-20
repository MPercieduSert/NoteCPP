/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */

#ifndef CLASSEMANAGER_H
#define CLASSEMANAGER_H

#include "ManagerSql.h"
#include "ClasseLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entitée Classe.
 */

class ClasseManager : public ManagerSql<ClasseLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    ClasseManager(QSqlQuery & req);
};

#endif // CLASSEMANAGER_H
