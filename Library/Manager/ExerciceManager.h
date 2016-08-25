/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/03/2016
 */

#ifndef EXERCICEMANAGER_H
#define EXERCICEMANAGER_H

#include "ManagerSql.h"
#include "ExerciceLinkSql.h"

/*! \ingroup groupeManager
 * \brief Manager de l'entité Exercice.
 */

class ExerciceManager : public ManagerSql<ExerciceLinkSql>
{
public:
    //! Constructeur, transmettre en argument une référence sur une objet de requete.
    ExerciceManager(QSqlQuery &req);
};

#endif // EXERCICEMANAGER_H
