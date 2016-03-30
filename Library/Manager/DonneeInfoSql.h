/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */

#ifndef DONNEEINFOSQL
#define DONNEEINFOSQL

#include <array>
#include "ArbresManager.h"
#include "../Entities/Donnee.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Donnee.
 */
struct DonneeInfoSql
{
    static constexpr char Table[] {"dn"};
    static const int NbrCleExt = 1;
    static constexpr std::array<const char *, NbrCleExt> CleExt {{DonneeArbreInfoSql::Table}};
    static const int NbrAtt = DonneeInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"cd","nm","sur","tp","tpvl"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 text not null,"
                                       "%4 integer not null,"
                                       "%5 integer not null,"
                                       "%6 integer not null,"
                                       "foreign key (ID) references %7)"};
};

#endif // DONNEEINFOSQL

