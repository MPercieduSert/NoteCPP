/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef RELATIONSINFOSQL
#define RELATIONSINFOSQL

#include "AttributInfoSql.h"
#include "ClasseInfoSql.h"
#include "CommentaireInfoSql.h"
#include "DonneeInfoSql.h"
#include "EleveInfoSql.h"
#include "EtablissementInfoSql.h"
#include "GroupeInfoSql.h"
#include "NiveauInfoSql.h"
#include "SourceInfoSql.h"

#include "InfoSql.h"

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité CommentaireClasse.
 */
struct CommentaireClasseInfoSql : DateRelationInfoSql
{
    static constexpr char Table[] {"cmcl"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{CommentaireInfoSql::Table,ClasseInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDcm","IDcl","dt","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité CommentaireEleve.
 */
struct CommentaireEleveInfoSql : DateRelationInfoSql
{
    static constexpr char Table[] {"cmel"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{CommentaireInfoSql::Table,EleveInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDcm","IDel","dt","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité CommentaireGroupe.
 */
struct CommentaireGroupeInfoSql : DateRelationInfoSql
{
    static constexpr char Table[] {"cmgr"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{CommentaireInfoSql::Table,GroupeInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDcm","IDgr","dt","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité DonneeClasse.
 */
struct DonneeClasseInfoSql : ValeurDateRelationInfoSql
{
    static constexpr char Table[] {"dncl"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{DonneeInfoSql::Table,ClasseInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDdn","IDcl","dt","vl","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité DonneeEleve.
 */
struct DonneeEleveInfoSql : ValeurDateRelationInfoSql
{
    static constexpr char Table[] {"dnel"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{DonneeInfoSql::Table,EleveInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDdn","IDel","dt","vl","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité DonneeEtablissement.
 */
struct DonneeEtablissementInfoSql : ValeurDateRelationInfoSql
{
    static constexpr char Table[] {"dnel"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{DonneeInfoSql::Table,EtablissementInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDdn","IDetab","dt","vl","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité DonneeNiveau.
 */
struct DonneeNiveauInfoSql : ValeurDateRelationInfoSql
{
    static constexpr char Table[] {"dnniv"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{DonneeInfoSql::Table,NiveauInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDdn","IDniv","dt","vl","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité DonneeSource.
 */
struct DonneeSourceInfoSql : ValeurDateRelationInfoSql
{
    static constexpr char Table[] {"dnsr"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{DonneeInfoSql::Table,SourceInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDdn","IDsr","dt","vl","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité GroupeEleve.
 */
struct GroupeEleveInfoSql : NumRelationInfoSql
{
    static constexpr char Table[] {"grel"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{GroupeInfoSql::Table,EleveInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDgr","IDel","nm","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité AttributCommentaire.
 */
struct AttributCommentaireInfoSql : RelationSimpleInfoSql
{
    static constexpr char Table[] {"atcm"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{AttributInfoSql::Table,CommentaireInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDat","IDcm","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité NiveauPrécédent.
 */
struct NiveauPrecedentInfoSql : RelationSimpleInfoSql
{
    static constexpr char Table[] {"nivpre"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{NiveauInfoSql::Table,NiveauInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDpr","IDsv","ID"}};
};

/*! \ingroup groupeInfoLinkSql
 * \brief Information SQL sur l'entité EtablissementNiveau.
 */
struct EtablissementNiveauInfoSql : RelationSimpleInfoSql
{
    static constexpr char Table[] {"etabniv"};
    static constexpr std::array<const char *, NbrCleExt> CleExt {{EtablissementInfoSql::Table,NiveauInfoSql::Table}};
    static constexpr std::array<const char *, NbrAtt> Att{{"IDetab","IDniv","ID"}};
};
#endif // RELATIONSINFOSQL

