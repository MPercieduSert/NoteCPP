/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */

#ifndef ARBREMANAGER_H
#define ARBREMANAGER_H

#include "ManagerSql.h"
#include "ArbreLinkSql.h"

template<class T> class ArbreManager : public ManagerSql<ArbreLinkSql<T> >
{
public:
    ArbreManager(QSqlQuery & req);
};

typedef ArbreManager<AttributArbre> AttributArbreManager;
typedef ArbreManager<CoursArbre> CoursArbreManager;
typedef ArbreManager<DonneeArbre> DonneeArbreManager;
typedef ArbreManager<EnonceArbre> EnonceArbreManager;
typedef ArbreManager<ExerciceArbre> ExerciceArbreManager;

template<class T> ArbreManager<T>::ArbreManager(QSqlQuery & req)
    : ManagerSql<ArbreLinkSql<T> >(req)
{

}

#endif // ARBREMANAGER_H
