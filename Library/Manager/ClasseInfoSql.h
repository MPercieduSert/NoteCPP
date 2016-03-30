/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef CLASSEINFOSQL
#define CLASSEINFOSQL

#include "AnneeInfoSql.h"
#include "EtablissementInfoSql.h"
#include "NiveauInfoSql.h"
#include "../Entities/Classe.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité Classe.
 */
struct ClasseInfoSql : InfoSqlUnique4<0,1,2,3>
{
    static constexpr char Table[] {"cl"};
    static const int NbrCleExt = 3;
    static constexpr std::array<const char *, NbrCleExt> CleExt {{AnneeInfoSql::Table,EtablissementInfoSql::Table,NiveauInfoSql::Table}};
    static const int NbrAtt = ClasseInfo::NbrAtt;
    static constexpr std::array<const char *, NbrAtt> Att{{"IDan","IDetab","IDniv","nm","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 integer not null,"
                                       "%5 integer not null,"
                                       "constraint UN%1 unique (%2, %3, %4, %5),"
                                       "foreign key (%2) references %6,"
                                       "foreign key (%3) references %7,"
                                       "foreign key (%4) references %8)"};
    enum unique {IdAnUnique = 0, IdEtabUnique = 1, IdNivUnique = 2, NumUnique = 3};
};

#endif // CLASSEINFOSQL

