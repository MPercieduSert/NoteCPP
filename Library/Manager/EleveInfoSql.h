/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */

#ifndef ELEVEINFOSQL
#define ELEVEINFOSQL

#include "InfoSql.h"
#include "../Entities/Eleve.h"


/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Eleve.
 */
struct EleveInfoSql : InfoSqlUnique3<1,2,3>, InfoSqlZeroCleExt
{
    static constexpr char Table[] {"el"};
    static const int NbrAtt = EleveInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"fl","ne","nm","pnm","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 text not null,"
                                       "%4 text not null,"
                                       "%5 text not null,"
                                       "constraint UN%1 unique (%3, %4, %5))"};
    enum unique {NaissanceUnique = 0, NomUnique = 1, PrenomUnique = 2};
};


#endif // ELEVEINFOSQL

