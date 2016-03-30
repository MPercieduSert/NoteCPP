/*Auteur: PERCIE DU SERT Maxime
 *Date: 24/04/2016
 */

#ifndef ARBRESMANAGER
#define ARBRESMANAGER

#include "ArbreManager.h"
#include "InfoSql.h"
#include "../Entities/Arbres.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité AttributArbre.
 */
struct AttributArbreInfoSql : InfoSqlArbre
{
    static constexpr char Table[] {"arbat"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité CoursArbre.
 */
struct CoursArbreInfoSql : InfoSqlArbre
{
    static constexpr char Table[] {"arbcrs"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité DonneeArbre.
 */
struct DonneeArbreInfoSql : InfoSqlArbre
{
    static constexpr char Table[] {"arbdn"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité EnonceArbre.
 */
struct EnonceArbreInfoSql : InfoSqlArbre
{
    static constexpr char Table[] {"arben"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité ExerciceArbre.
 */
struct ExerciceArbreInfoSql : InfoSqlArbre
{
    static constexpr char Table[] {"arbex"};
};


typedef ArbreManager<AttributArbre,AttributArbreInfoSql> AttributArbreManager;
typedef ArbreManager<CoursArbre,CoursArbreInfoSql> CoursArbreManager;
typedef ArbreManager<DonneeArbre,DonneeArbreInfoSql> DonneeArbreManager;
typedef ArbreManager<EnonceArbre,EnonceArbreInfoSql> EnonceArbreManager;
typedef ArbreManager<ExerciceArbre,ExerciceArbreInfoSql> ExerciceArbreManager;

#endif // ARBRESMANAGER

