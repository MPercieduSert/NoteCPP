/*Auteur: PERCIE DU SERT Maxime
 *Date: 30/04/2016
 */
#ifndef INFOSQL
#define INFOSQL

#include "BaseInfoSql.h"

#include "../Entities/InfoEntity.h"
#include "../Entities/Annee.h"
#include "../Entities/Arbre.h"
#include "../Entities/Attribut.h"
#include "../Entities/Classe.h"
#include "../Entities/ClasseEleve.h"
#include "../Entities/Donnee.h"
#include "../Entities/Eleve.h"
#include "../Entities/Groupe.h"
#include "../Entities/Niveau.h"
#include "../Entities/Relations.h"

/*! \ingroup groupeInfoSqlBase
 * \brief Trait contenant les informations sur les entités et leur représentation en base de donnée.
 */
template<class T> struct InfoSql
{
    static const char Table[];
    static const char SqlCreate[];
    static const int NbrAtt = Info<T>::NbrAtt;
    static const std::array<const char *,NbrAtt> Att;
    static const int NbrCleExt = 0;
    static constexpr std::array<const char *, NbrCleExt> CleExt {};
    static const caracteristiqueSQL::uniqueCondition UniCond;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Annee.
 */
template<> struct InfoSql<Annee> : InfoSqlZeroCleExt, InfoSqlUniqueSimple<1>
{
    static const char Table[];
    static const char SqlCreate[];
    static const int NbrAtt = Info<Annee>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {AnUnique = 0};
};

//Arbre
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité AttributArbre. */
template<> struct InfoSql<AttributArbre> : InfoSqlArbre  {static const char Table[];};
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité CoursArbre. */
template<> struct InfoSql<CoursArbre> : InfoSqlArbre  {static const char Table[];};
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité DonneeArbre. */
template<> struct InfoSql<DonneeArbre> : InfoSqlArbre  {static const char Table[];};
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité EnonceArbre. */
template<> struct InfoSql<EnonceArbre> : InfoSqlArbre  {static const char Table[];};
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité ExerciceArbre. */
template<> struct InfoSql<ExerciceArbre> : InfoSqlArbre  {static const char Table[];};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Attribut.
 */
template<> struct InfoSql<Attribut> : InfoSqlNoUnique
{
    static const char Table[];
    static const int NbrCleExt = 1;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const char SqlCreate[];
    static const int NbrAtt = Info<Attribut>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const caracteristiqueSQL::uniqueCondition UniCond = caracteristiqueSQL::NoCondition;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Classe.
 */
template<> struct InfoSql<Classe> : InfoSqlUniqueSimple<4>
{
    static const char Table[];
    static const int NbrCleExt = 3;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const char SqlCreate[];
    static const int NbrAtt = Info<Classe>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {IdAnUnique = 0, IdEtabUnique = 1, IdNivUnique = 2, NumUnique = 3, Id1Unique = IdAnUnique, Id2Unique = IdEtabUnique};
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité ClasseEleve.
 */
template<> struct InfoSql<ClasseEleve> : InfoSqlUniqueRelation
{
    static const char Table[];
    static const int NbrCleExt = 2;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const char SqlCreate[];
    static const int NbrAtt = Info<ClasseEleve>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Commentaire. */
template<> struct InfoSql<Commentaire> : TexteInfoSql  {static const char Table[];};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Donnee.
 */
template<> struct InfoSql<Donnee> : InfoSqlNoUnique
{
    static const char Table[];
    static const int NbrCleExt = 1;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const char SqlCreate[];
    static const int NbrAtt = Info<Donnee>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const caracteristiqueSQL::uniqueCondition UniCond = caracteristiqueSQL::NoCondition;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Eleve.
 */
template<> struct InfoSql<Eleve> : InfoSqlZeroCleExt, InfoSqlUniqueSimple<3>
{
    static const char Table[];
    static const char SqlCreate[];
    static const int NbrAtt = Info<Eleve>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {NaissanceUnique = 0, NomUnique = 1, PrenomUnique = 2};
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Etablissement. */
template<> struct InfoSql<Etablissement> : NcNomTypeInfoSql  {static const char Table[];};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Groupe.
 */
template<> struct InfoSql<Groupe> : InfoSqlUniqueDouble<2,2>
{
    static const char Table[];
    static const int NbrCleExt = 2;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const char SqlCreate[];
    static const int NbrAtt = Info<Groupe>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const caracteristiqueSQL::uniqueCondition UniCond = caracteristiqueSQL::DoubleConditionNull;
    static const int NbrAttUnique1 = 2;
    static const std::array<const int, NbrAttUnique1> AttUnique1;
    static const int NbrAttUnique2 = 2;
    static const std::array<const int, NbrAttUnique2> AttUnique2;
    static const std::array<int, NbrAttUnique> AttUnique;
    enum unique {Id1Unique = 0, Id2Unique =0, NomUnique = 1};
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Niveau.
 */
template<> struct InfoSql<Niveau> : InfoSqlUniqueNom
{
    static const char Table[];
    static const int NbrCleExt = 1;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const char SqlCreate[];
    static const int NbrAtt = Info<Eleve>::NbrAtt;
    static const std::array<const char *, NbrAtt> Att;
    static const std::array<int, NbrAttUnique> AttUnique;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité Source. */
template<> struct InfoSql<Source> : NomTypeInfoSql  {static const char Table[];};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité TypeNiveau. */
template<> struct InfoSql<TypeNiveau> : NomTypeInfoSql  {static const char Table[];};

// DateRelation
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité CommentaireClasse.
 */
template<> struct InfoSql<CommentaireClasse> : DateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité CommentaireEleve.
 */
template<> struct InfoSql<CommentaireEleve> : DateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité CommentaireGroupe.
 */
template<> struct InfoSql<CommentaireGroupe> : DateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

// ValeurDateRelation
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité DonneeClasse.
 */
template<> struct InfoSql<DonneeClasse> : ValeurDateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité DonneeEleve.
 */
template<> struct InfoSql<DonneeEleve> : ValeurDateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité DonneeEtablissement.
 */
template<> struct InfoSql<DonneeEtablissement> : ValeurDateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité DonneeNiveau.
 */
template<> struct InfoSql<DonneeNiveau> : ValeurDateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité DonneeSource.
 */
template<> struct InfoSql<DonneeSource> : ValeurDateRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

// NumRelation
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité GroupeEleve.
 */
template<> struct InfoSql<GroupeEleve> : NumRelationInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

// RelationSimple
/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité AttributCommentaire.
 */
template<> struct InfoSql<AttributCommentaire> : RelationSimpleInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité NiveauPrécédent.
 */
template<> struct InfoSql<NiveauPrecedent> : RelationSimpleInfoSql
{
    static const char Table[];
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

/*! \ingroup groupeInfoSqlSpe
 * \brief Information SQL sur l'entité EtablissementNiveau.
 */
template<> struct InfoSql<EtablissementNiveau> : RelationSimpleInfoSql
{
    static const char Table[] ;
    static const std::array<const char *, NbrCleExt> CleExt;
    static const std::array<const char *, NbrAtt> Att;
};

#endif // INFOSQL
