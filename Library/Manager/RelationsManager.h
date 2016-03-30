/*Auteur: PERCIE DU SERT Maxime
 *Date: 30/03/2016
 */
#ifndef RELATIONSMANAGER
#define RELATIONSMANAGER

#include "LinkSqlRelation.h"
#include "LinkSqlUnique.h"
#include "ManagerSql.h"
#include "RelationsInfoSql.h"

#include "../Entities/Relations.h"

// Lien SQL

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité CommentaireClasse de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<DateRelationOnlyLinkSql<CommentaireClasse,CommentaireClasseInfoSql> > CommentaireClasseLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité CommentaireEleve de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<DateRelationOnlyLinkSql<CommentaireEleve,CommentaireEleveInfoSql> > CommentaireEleveLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité CommentaireGroupe de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<DateRelationOnlyLinkSql<CommentaireGroupe,CommentaireGroupeInfoSql> > CommentaireGroupeLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité DonneeClasse de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<ValeurDateRelationOnlyLinkSql<DonneeClasse,DonneeClasseInfoSql> > DonneeClasseLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité DonneeEleve de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<ValeurDateRelationOnlyLinkSql<DonneeEleve,DonneeEleveInfoSql> > DonneeEleveLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité DonneeEtablissement de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<ValeurDateRelationOnlyLinkSql<DonneeEtablissement,DonneeEtablissementInfoSql> > DonneeEtablissementLinkSql;


/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité DonneeNiveau de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<ValeurDateRelationOnlyLinkSql<DonneeNiveau,DonneeNiveauInfoSql> > DonneeNiveauLinkSql;


/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité DonneeSource de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<ValeurDateRelationOnlyLinkSql<DonneeSource,DonneeSourceInfoSql> > DonneeSourceLinkSql;


/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité GroupeEleve de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<NumRelationOnlyLinkSql<GroupeEleve,GroupeEleveInfoSql> > GroupeEleveLinkSql;


/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité AttributCommentaire de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<RelationOnlyLinkSql<AttributCommentaire,AttributCommentaireInfoSql> > AttributCommentaireLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité NiveauPrecedent de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<RelationOnlyLinkSql<NiveauPrecedent,NiveauPrecedentInfoSql> > NiveauPrecedentLinkSql;

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité EtablissementNiveau de programation et sa représentation en base de donnée.
 */
typedef RelationLinkSqlUnique<RelationOnlyLinkSql<EtablissementNiveau,EtablissementNiveauInfoSql> > EtablissementNiveauLinkSql;

// Manager SQL

/*! \ingroup groupeManager
 * \brief Manager de l'entité CommentaireClasse.
 */
typedef ManagerSql<CommentaireClasseLinkSql> CommentaireClasseManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité CommentaireEleve.
 */
typedef ManagerSql<CommentaireEleveLinkSql> CommentaireEleveManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité CommentaireGroupe.
 */
typedef ManagerSql<CommentaireGroupeLinkSql> CommentaireGroupeManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité DonneeClasse.
 */
typedef ManagerSql<DonneeClasseLinkSql> DonneeClasseManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité DonneeEleve.
 */
typedef ManagerSql<DonneeEleveLinkSql> DonneeEleveManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité DonneeEtablissement.
 */
typedef ManagerSql<DonneeEtablissementLinkSql> DonneeEtablissementManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité DonneeNiveau.
 */
typedef ManagerSql<DonneeNiveauLinkSql> DonneeNiveauManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité DonneeSource.
 */
typedef ManagerSql<DonneeSourceLinkSql> DonneeSourceManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité GroupeEleve.
 */
typedef ManagerSql<GroupeEleveLinkSql> GroupeEleveManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité AttributCommentaire.
 */
typedef ManagerSql<AttributCommentaireLinkSql> AttributCommentaireManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité NiveauPrecedent.
 */
typedef ManagerSql<NiveauPrecedentLinkSql> NiveauPrecedentManager;

/*! \ingroup groupeManager
 * \brief Manager de l'entité EtablissementNiveau.
 */
typedef ManagerSql<EtablissementNiveauLinkSql> EtablissementNiveauManager;
#endif // RELATIONSMANAGER

