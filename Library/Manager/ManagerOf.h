/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef MANAGEROF_H
#define MANAGEROF_H

#include "ManagerSql.h"

/*! \defgroup groupeManagerOf Manageur des entitées.
 * \ingroup groupeManager
 * \brief Ensemble des manageur des entitées.
 */

/*! \ingroup groupeBaseManager
 * \brief Classe template permettant d'instancier les différents manageurs.
 */
template<class Ent> class ManagerOf : public ManagerSql<Ent>
{
public:
    //! Constructeur.
    ManagerOf(QSqlQuery * requete = 0)
        : ManagerSql<Ent>(requete)
    {}

    //! Destructeur.
    ~ManagerOf()
    {}

};
#endif // MANAGEROF_H
