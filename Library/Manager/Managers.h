/*Auteur: PERCIE DU SERT Maxime
 *Date: 12/03/2016
 */
#ifndef MANAGERS
#define MANAGERS

#include "ManagerSql.h"

#include "AnneeLinkSql.h"
#include "ArbreLinkSql.h"



typedef ManagerSql<AnneeLinkSql> AnneeManager;

typedef ManagerSql<ArbreLinkSql<AttributArbre> > AttributArbreManager;
typedef ManagerSql<ArbreLinkSql<CoursArbre> > CoursArbreManager;
typedef ManagerSql<ArbreLinkSql<DonneeArbre> > DonneeArbreManager;
typedef ManagerSql<ArbreLinkSql<ExerciceArbre> > ExerciceArbreManager;
typedef ManagerSql<ArbreLinkSql<EnonceArbre> > EnonceArbreManager;


#endif // MANAGERS

