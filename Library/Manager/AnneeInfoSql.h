/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/02/2016
 */
#ifndef ANNEEINFOSQL
#define ANNEEINFOSQL

#include "InfoSql.h"
#include "../Entities/Annee.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Annee.
 */
struct AnneeInfoSql : InfoSqlZeroCleExt, InfoSqlUnique1<0>
{
    static constexpr char Table[] {"an"};   
    static const int NbrAtt = AnneeInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"an","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "constraint UN%1 unique (%2))"};
    enum unique {AnUnique = 0};
};

#endif // ANNEEINFOSQL
