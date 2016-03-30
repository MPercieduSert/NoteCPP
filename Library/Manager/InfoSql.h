/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef INFOSQL
#define INFOSQL

#include <array>

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités ayant une seule condition d'unicité sur un attribut.
 */
template<int Pos = 0> struct InfoSqlUnique1
{
    static constexpr char SqlUnique[] {"SELECT ID FROM %1 WHERE %2=? LIMIT 1"};
    static const int NbrAttUnique = 1;
    static constexpr std::array<const int, NbrAttUnique> AttUnique{{Pos}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités ayant une seule condition d'unicité sur un couple d'attributs.
 */
template<int Pos1 = 0, int Pos2 = 1> struct InfoSqlUnique2
{
    static constexpr char SqlUnique[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? LIMIT 1"};
    static const int NbrAttUnique = 2;
    static constexpr std::array<const int, NbrAttUnique> AttUnique{{Pos1,Pos2}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités ayant une seule condition d'unicité sur un triplet d'attributs.
 */
template<int Pos1 = 0, int Pos2 = 1, int Pos3 = 2> struct InfoSqlUnique3
{
    static constexpr char SqlUnique[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? LIMIT 1"};
    static const int NbrAttUnique = 3;
    static constexpr std::array<const int, NbrAttUnique> AttUnique{{Pos1,Pos2,Pos3}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités ayant une seule condition d'unicité sur 4-upplet d'attributs.
 */
template<int Pos1 = 0, int Pos2 = 1, int Pos3 = 2, int Pos4 = 3> struct InfoSqlUnique4
{
    static constexpr char SqlUnique[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? LIMIT 1"};
    static const int NbrAttUnique = 4;
    static constexpr std::array<const int, NbrAttUnique> AttUnique{{Pos1,Pos2,Pos3,Pos4}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur l'attribut nom.
 */
template<int Pos = 0> struct InfoSqlUniqueNom : InfoSqlUnique1<Pos>
{
    enum unique {NomUnique = 0};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur les couples de clés (id1,id2).
 */
template<int Pos1 = 0, int Pos2 = 1> struct InfoSqlUniqueRealtion : InfoSqlUnique2<Pos1,Pos2>
{
    enum unique {Id1Unique = 0, Id2Unique = 1};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur l'attribut texte.
 */
template<int Pos = 0> struct InfoSqlUniqueTexte : InfoSqlUnique1<Pos>
{
    enum unique {TexteUnique = 0};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entité n'ayant pas de clé étrangère.
 */
struct InfoSqlZeroCleExt
{
    static const int NbrCleExt = 0;
    static constexpr std::array<const char *, NbrCleExt> CleExt {};
};

/*! \ingroup groupeBaseLinkSql
 * \brief Information SQL sur les entités de type Arbre.
 */
struct InfoSqlArbre : InfoSqlZeroCleExt, InfoSqlUnique2<2,3>
{
    static constexpr char SqlCreate[] {"create table %1"
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 integer not null,"
                                       "%5 integer,"
                                       "constraint UN%1 unique (%4, %5),"
                                       "foreign key (%5) references %1"};
    static const int NbrAtt = 5;
    static constexpr std::array<const char *, NbrAtt> Att{{"fl","nv","nm","pt","ID"}};
    enum unique {NumUnique = 0, ParentUnique = 1};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type nom unique.
 */
struct NomInfoSql : InfoSqlUniqueNom<0>, InfoSqlZeroCleExt
{
    static const int NbrAtt = 2;
    static constexpr std::array<const char *, NbrAtt> Att{{"nm","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "constraint UN%1 unique (%2))"}; 
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type nom et type avec nom unique.
 */
struct NomTypeInfoSql : InfoSqlUniqueNom<0>, InfoSqlZeroCleExt
{
    static const int NbrAtt = NomInfoSql::NbrAtt + 1;
    static constexpr std::array<const char *, NbrAtt> Att{{"nm","tp","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "%3 integer not null,"
                                       "constraint UN%1 unique (%2))"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type nc et nom avec nom unique.
 */
struct NcNomInfoSql : InfoSqlUniqueNom<1>, InfoSqlZeroCleExt
{
    static const int NbrAtt = NomInfoSql::NbrAtt + 1;
    static constexpr std::array<const char *, NbrAtt> Att{{"nc","nm","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "%3 text not null,"
                                       "constraint UN%1 unique (%3))"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type nc, nom et type avec nom unique.
 */
struct NcNomTypeInfoSql : InfoSqlUniqueNom<1>, InfoSqlZeroCleExt
{
    static const int NbrAtt = NcNomInfoSql::NbrAtt + 1;
    static constexpr std::array<const char *, NbrAtt> Att{{"nc","nm","tp","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "%3 text not null,"
                                       "%4 integer not null,"
                                       "constraint UN%1 unique (%3))"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur les couples de clés (id1,id2).
 */
template<int Pos1 = 0, int Pos2 = 1> struct InfoSqlRealtion2cle : InfoSqlUniqueRealtion<Pos1,Pos2>
{
    static const int NbrCleExt = 2;
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type relation simple.
 */
struct RelationSimpleInfoSql : InfoSqlRealtion2cle<0,1>
{
    static const int NbrAtt = 3;
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %4,"
                                       "foreign key (%3) references %5)"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type relation daté.
 */
struct DateRelationInfoSql : InfoSqlRealtion2cle<0,1>
{
    static constexpr int NbrAtt = RelationSimpleInfoSql::NbrAtt + 1;
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 text not null,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %5,"
                                       "foreign key (%3) references %6)"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type relation daté et valué.
 */
struct ValeurDateRelationInfoSql : InfoSqlRealtion2cle<0,1>
{
    static constexpr int NbrAtt = DateRelationInfoSql::NbrAtt + 1;
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 text not null,"
                                       "%5 blob,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %6,"
                                       "foreign key (%3) references %7)"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type relation numéroté.
 */
struct NumRelationInfoSql : InfoSqlRealtion2cle<0,1>
{
    static constexpr int NbrAtt = RelationSimpleInfoSql::NbrAtt + 1;
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 integer not null,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %5,"
                                       "foreign key (%3) references %6)"};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur les entités de type texte unique.
 */
struct TexteInfoSql : InfoSqlUniqueTexte<0>, InfoSqlZeroCleExt
{
    static const int NbrAtt = 2;
    static constexpr std::array<const char *, NbrAtt> Att{{"txt","ID"}};
    static constexpr char SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "constraint UN%1 unique (%2))"};
};
#endif // INFOSQL

