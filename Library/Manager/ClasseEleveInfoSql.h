/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */

#ifndef CLASSEELEVEINFOSQL_H
#define CLASSEELEVEINFOSQL_H

#include "ClasseInfoSql.h"
#include "EleveInfoSql.h"
#include "InfoSql.h"
#include "../Entities/ClasseEleve.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité ClasseEleve.
 */
struct ClasseEleveInfoSql : InfoSqlUniqueRealtion<0,1>
{
    static constexpr char Table[] {"clel"};
    static const int NbrCleExt = 2;
    static constexpr std::array<const char *, NbrCleExt> CleExt {{ClasseInfoSql::Table,EleveInfoSql::Table}};
    static const int NbrAtt = ClasseEleveInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"IDcl","IDel","ent","srt","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 text,"
                                       "%5 text,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %6,"
                                       "foreign key (%3) references %7)"};

};

#endif // CLASSEELEVEINFOSQL_H
