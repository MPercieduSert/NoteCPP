/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef GROUPEINFOSQL
#define GROUPEINFOSQL

#include "AnneeInfoSql.h"
#include "ClasseInfoSql.h"
#include "../Entities/Groupe.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Groupe.
 */
struct GroupeInfoSql
{
    static constexpr char Table[] {"gr"};
    static const int NbrCleExt = 2;
    static constexpr std::array<const char *, NbrCleExt> CleExt {{AnneeInfoSql::Table,ClasseInfoSql::Table}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer,"
                                       "%3 integer,"
                                       "%4 interger not null,"
                                       "%5 text not null,"
                                       "%6 interger not null,"
                                       "constraint UNa%1 unique (%2,%5),"
                                       "constraint UNb%1 unique (%3,%5),"
                                       "foreign key (%2) references %7,"
                                       "foreign key (%3) references %8)"};
    static const int NbrAtt = GroupeInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"IDan","IDCl","alp","nm","tp","ID"}};
    static constexpr char SqlUnique1[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? LIMIT 1"};
    static const int NbrAttUnique1 = 2;
    static constexpr std::array<const int, NbrAttUnique1> AttUnique1{{0,3}};
    static constexpr char SqlUnique2[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? LIMIT 1"};
    static const int NbrAttUnique2 = 2;
    static constexpr std::array<const int, NbrAttUnique2> AttUnique2{{1,3}};
    enum unique {IdUnique = 0, NomUnique = 1};
};

#endif // GROUPEINFOSQL

