/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */

#ifndef NIVEAUINFOSQL
#define NIVEAUINFOSQL

#include "InfoSql.h"
#include "TypeNiveauInfoSql.h"
#include "../Entities/Niveau.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Niveau.
 */
struct NiveauInfoSql : InfoSqlUniqueNom<2>
{
    static constexpr char Table[] {"niv"};
    static const int NbrCleExt = 1;
    static constexpr std::array<const char *, NbrCleExt> CleExt {{TypeNiveauInfoSql::Table}};
    static const int NbrAtt = NiveauInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"IDtp","nc","nm","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 text not null,"
                                       "%4 text not null,"
                                       "constraint UN%1 unique (%4),"
                                       "foreign key (%2) references %5)"};
};

#endif // NIVEAUINFOSQL

