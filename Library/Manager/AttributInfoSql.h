/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef ATTRIBUTINFOSQL
#define ATTRIBUTINFOSQL

#include "ArbresManager.h"
#include "../Entities/Attribut.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Attribut.
 */
struct AttributInfoSql
{
    static constexpr char Table[] {"at"};
    static const int NbrCleExt = 1;
    static constexpr std::array<const char *, NbrCleExt> CleExt {{AttributArbreInfoSql::Table}};
    static const int NbrAtt = AttributInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"nm","prbr","prcm","prcrr","prcrs","prex","nc","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "%3 integer not null,"
                                       "%4 integer not null,"
                                       "%5 integer not null,"
                                       "%6 integer not null,"
                                       "%7 integer not null,"
                                       "%8 text,"
                                       "foreign key (ID) references %9)"};
};

#endif // ATTRIBUTINFOSQL
