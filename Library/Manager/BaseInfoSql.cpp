#include "BaseInfoSql.h"

// Unique
DEF_UNIQUE_CONDITION(InfoSqlUniqueSimple,)
DEF_UNIQUE_CONDITION(InfoSqlUniqueDouble1,1)
DEF_UNIQUE_CONDITION(InfoSqlUniqueDouble2,2)

//Arbre
constexpr char InfoSqlArbre::SqlCreate[] {"create table %1"
    " (ID integer primary key,"
    "%2 integer not null,"
    "%3 integer not null,"
    "%4 integer not null,"
    "%5 integer,"
    "constraint UN%1 unique (%4, %5),"
    "foreign key (%5) references %1"};
constexpr std::array<const char *, InfoSqlArbre::NbrAtt> InfoSqlArbre::Att{{"fl","nv","nm","pt","ID"}};
constexpr std::array<int, InfoSqlArbre::NbrAttUnique> InfoSqlArbre::AttUnique {{2, 3}};

//NoUnique
constexpr std::array<int, InfoSqlNoUnique::NbrAttUnique> InfoSqlNoUnique::AttUnique {};

// Nom
constexpr char NomInfoSql::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 text not null,"
    "constraint UN%1 unique (%2))"};
constexpr std::array<const char *, NomInfoSql::NbrAtt> NomInfoSql::Att{{"nm","ID"}};
constexpr std::array<int, NomInfoSql::NbrAttUnique> NomInfoSql::AttUnique {{0}};

// NomType
constexpr char NomTypeInfoSql::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 text not null,"
    "%3 integer not null,"
    "constraint UN%1 unique (%2))"};
constexpr std::array<const char *, NomTypeInfoSql::NbrAtt> NomTypeInfoSql::Att{{"nm","tp","ID"}};
constexpr std::array<int, NomTypeInfoSql::NbrAttUnique> NomTypeInfoSql::AttUnique {{0}};

// NcNom
constexpr char NcNomInfoSql::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 text not null,"
    "%3 text not null,"
    "constraint UN%1 unique (%3))"};
constexpr std::array<const char *, NcNomInfoSql::NbrAtt> NcNomInfoSql::Att{{"nc","nm","ID"}};

// NcNomType
constexpr char NcNomTypeInfoSql::SqlCreate[] {"create table %1 "
    " (ID integer primary key,"
    "%2 text not null,"
    "%3 text not null,"
    "%4 integer not null,"
    "constraint UN%1 unique (%3))"};
constexpr std::array<const char *, NcNomTypeInfoSql::NbrAtt> NcNomTypeInfoSql::Att{{"nc","nm","tp","ID"}};
constexpr std::array<int, NcNomTypeInfoSql::NbrAttUnique> NcNomTypeInfoSql::AttUnique {{1}};

// Relation
constexpr std::array<int, InfoSqlUniqueRelation::NbrAttUnique> InfoSqlUniqueRelation::AttUnique {{0, 1}};


// RelationSimple
constexpr char RelationSimpleInfoSql::SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %4,"
                                       "foreign key (%3) references %5)"};

// DateRelation
constexpr char DateRelationInfoSql::SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 text not null,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %5,"
                                       "foreign key (%3) references %6)"};

// ValeurDateRelation
constexpr char ValeurDateRelationInfoSql::SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 text not null,"
                                       "%5 blob,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %6,"
                                       "foreign key (%3) references %7)"};

// NumRelation
constexpr char NumRelationInfoSql::SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 integer not null,"
                                       "%3 integer not null,"
                                       "%4 integer not null,"
                                       "constraint UN%1 unique (%2, %3),"
                                       "foreign key (%2) references %5,"
                                       "foreign key (%3) references %6)"};

// TexteInfoSql
constexpr char TexteInfoSql::SqlCreate[] {"create table %1 "
                                       " (ID integer primary key,"
                                       "%2 text not null,"
                                       "constraint UN%1 unique (%2))"};
constexpr std::array<const char *, TexteInfoSql::NbrAtt> TexteInfoSql::Att{{"txt","ID"}};
constexpr std::array<int, TexteInfoSql::NbrAttUnique> TexteInfoSql::AttUnique {{0}};

//ZeroCleExt
constexpr std::array<const char *, InfoSqlZeroCleExt::NbrCleExt> InfoSqlZeroCleExt::CleExt {{}};
