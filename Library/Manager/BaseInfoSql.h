/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef BASEINFOSQL_H
#define BASEINFOSQL_H

/*! \defgroup groupeInfoSql Informations SQL
 * \ingroup groupeManager
 * \brief Traits contenant les informations des entités en base de données.
 */

/*! \defgroup groupeInfoSqlBase Informations SQL communes
 * \ingroup groupeInfoSql
 * \brief Traits contenant les informations commumes à plusieurs entités en base de données.
 */

/*! \defgroup groupeInfoSqlSpe Spéciation InfoSql
 * \ingroup groupeInfoSql
 * \brief Spéciation des traits contenant les informations entités en base de données.
 */

#include <array>
#include "../Entities/InfoEntity.h"

/*! \ingroup groupeInfoSqlBase
 * \brief Macro définisant les conditions d'unicité.
 */
#define DEF_UNIQUE_CONDITION(NOM,NUM) template<> constexpr char NOM<1>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? LIMIT 1"}; \
template<> constexpr char NOM<2>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? LIMIT 1"}; \
template<> constexpr char NOM<3>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? LIMIT 1"}; \
template<> constexpr char NOM<4>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? LIMIT 1"}; \
template<> constexpr char NOM<5>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? AND %6=? LIMIT 1"}; \
template<> constexpr char NOM<6>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? AND %6=? AND %7=? LIMIT 1"}; \
template<> constexpr char NOM<7>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? AND %6=? AND %7=? AND %8=? LIMIT 1"}; \
template<> constexpr char NOM<8>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? AND %6=? AND %7=? AND %8=? AND %9=? LIMIT 1"}; \
template<> constexpr char NOM<9>::SqlUnique ## NUM[] {"SELECT ID FROM %1 WHERE %2=? AND %3=? AND %4=? AND %5=? AND %6=? AND %7=? AND %8=? AND %9=? AND %10=? LIMIT 1"};

namespace caracteristiqueSQL {
    enum uniqueCondition {NoCondition = 0,
                         SimpleCondition = 1,
                         DoubleCondition = 2,
                         DoubleConditionNull = 2};
}

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités n'ayant pas de condition d'unicité.
 */
struct InfoSqlNoUnique
{
    static const caracteristiqueSQL::uniqueCondition UniCond = caracteristiqueSQL::NoCondition;
    static const int NbrAttUnique = 0;
    static const std::array<int, NbrAttUnique> AttUnique;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités ayant une seule condition d'unicité.
 */
template<int N> struct InfoSqlUniqueSimple
{
    static const caracteristiqueSQL::uniqueCondition UniCond = caracteristiqueSQL::SimpleCondition;
    static const char SqlUnique[];
    static const int NbrAttUnique = N;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités ayant deux conditions d'unicité, contient la premiere condition.
 */
template<int N> struct InfoSqlUniqueDouble1
{
    static const char SqlUnique1[];
    static const int NbrAttUnique1 = N;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités ayant deux conditions d'unicité, , contient la premiere condition..
 */
template<int N> struct InfoSqlUniqueDouble2
{
    static const char SqlUnique2[];
    static const int NbrAttUnique2 = N;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités ayant deux conditions d'unicité.
 */
template<int N1,int N2> struct InfoSqlUniqueDouble : InfoSqlUniqueDouble1<N1>, InfoSqlUniqueDouble2<N2>
{
    static const caracteristiqueSQL::uniqueCondition UniCond = caracteristiqueSQL::DoubleCondition;
    static const int NbrAttUnique = N1+N2;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur l'attribut nom.
 */
struct InfoSqlUniqueNom : InfoSqlUniqueSimple<1>
{
    enum unique {NomUnique = 0, TypeUnique = 1};
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur les couples de clés (id1,id2).
 */
struct InfoSqlUniqueRelation : InfoSqlUniqueSimple<2>
{
    static const int NbrCleExt = 2;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {Id1Unique = 0, Id2Unique = 1};
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur les triplets (id1,id2,date).
 */
template<int DatePos> struct InfoSqlUniqueRelationDate : InfoSqlUniqueSimple<3>
{
    static const int NbrCleExt = 2;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {Id1Unique = 0, Id2Unique = 1, DateUnique = 2};
};

template<int DatePos> constexpr std::array<int, InfoSqlUniqueRelationDate<DatePos>::NbrAttUnique> InfoSqlUniqueRelationDate<DatePos>::AttUnique {{0, 1, DatePos}};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entités possédant une seule condition d'unicité sur l'attribut texte.
 */
struct InfoSqlUniqueTexte : InfoSqlUniqueSimple<1>
{
    enum unique {TexteUnique = 0};
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL mère sur les entité n'ayant pas de clé étrangère.
 */
struct InfoSqlZeroCleExt
{
    static const int NbrCleExt = 0;
    static const std::array<const char *, NbrCleExt> CleExt;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type Arbre.
 */
struct InfoSqlArbre : InfoSqlZeroCleExt, InfoSqlUniqueSimple<2>
{
    static const char SqlCreate[];
    static const int NbrAtt = 5;
    static const std::array<const char *, NbrAtt> Att;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {NumUnique = 0, ParentUnique = 1};
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type nom unique.
 */
struct NomInfoSql : InfoSqlUniqueNom, InfoSqlZeroCleExt
{
    static const int NbrAtt = 2;
    static const std::array<const char *, NbrAtt> Att;
    static const char SqlCreate[];
    static const std::array<int, NbrAttUnique> AttUnique;

};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type nom et type avec nom unique.
 */
struct NomTypeInfoSql : InfoSqlUniqueNom, InfoSqlZeroCleExt
{
    static constexpr int NbrAtt = NomInfoSql::NbrAtt + 1;
    static const std::array<const char *, NbrAtt> Att;
    static const char SqlCreate[];
    static const std::array<int, NbrAttUnique> AttUnique;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type nc et nom avec nom unique.
 */
struct NcNomInfoSql : InfoSqlUniqueNom, InfoSqlZeroCleExt
{
    static constexpr int NbrAtt = NomInfoSql::NbrAtt + 1;
    static const std::array<const char *, NbrAtt> Att;
    static const char SqlCreate[];
    static const std::array<int, NbrAttUnique> AttUnique;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type nc, nom et type avec nom unique.
 */
struct NcNomTypeInfoSql : InfoSqlUniqueNom, InfoSqlZeroCleExt
{
    static constexpr int NbrAtt = NcNomInfoSql::NbrAtt + 1;
    static const std::array<const char *, NbrAtt> Att;
    static const char SqlCreate[];
    static const std::array<int, NbrAttUnique> AttUnique;
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type relation simple.
 */
struct RelationSimpleInfoSql : InfoSqlUniqueRelation
{
    static const int NbrAtt = 3;
    static const char SqlCreate[];
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type relation daté.
 */
struct DateRelationInfoSql : InfoSqlUniqueRelationDate<2>
{
    static constexpr int NbrAtt = RelationSimpleInfoSql::NbrAtt + 1;
    static const char SqlCreate[];
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type relation daté et valué.
 */
struct ValeurDateRelationInfoSql : InfoSqlUniqueRelationDate<2>
{
    static constexpr int NbrAtt = DateRelationInfoSql::NbrAtt + 1;
    static const char SqlCreate[];
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type relation numéroté.
 */
struct NumRelationInfoSql : InfoSqlUniqueRelation
{
    static constexpr int NbrAtt = RelationSimpleInfoSql::NbrAtt + 1;
    static const char SqlCreate[];
};

/*! \ingroup groupeInfoSqlBase
 * \brief Information SQL sur les entités de type texte unique.
 */
struct TexteInfoSql : InfoSqlUniqueTexte, InfoSqlZeroCleExt
{
    static const int NbrAtt = 2;
    static const std::array<const char *, NbrAtt> Att;
    static const char SqlCreate[];
    static const std::array<int, NbrAttUnique> AttUnique;
};

#endif // BASEINFOSQL_H
