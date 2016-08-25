/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/08/2016
 */
#ifndef ENTITYOFDEFAULTTYPE_H
#define ENTITYOFDEFAULTTYPE_H

#include "Arbre.h"
#include "EntityDivers.h"
#include "EntityNom.h"
#include "EntityRelation.h"
#include "InfoEntity.h"

// Arbre
ENTITY_OF_TYPE(AttributArbre,Arbre,InfoEntity::AttributArbreId)
ENTITY_OF_TYPE(CoursArbre,Arbre,InfoEntity::CoursArbreId)
ENTITY_OF_TYPE(DonneeArbre,Arbre,InfoEntity::DonneeArbreId)
ENTITY_OF_TYPE(EnonceArbre,Arbre,InfoEntity::EnonceArbreId)
ENTITY_OF_TYPE(ExerciceArbre,Arbre,InfoEntity::ExerciceArbreId)

// Nc et Nom
ENTITY_OF_TYPE(Etablissement,NcNomEntity,InfoEntity::EtablissementId)

// Nom et Type
ENTITY_OF_TYPE(Source,TypeNcNomEntity,InfoEntity::SourceId)

// Relation daté.
RELATION_ENTITY(CommentaireClasse,DateTimeRelationEntity,InfoEntity::CommentaireClasseId,Cm,Cl)
RELATION_ENTITY(CommentaireEleve,DateTimeRelationEntity,InfoEntity::CommentaireEleveId,Cm,El)
RELATION_ENTITY(CommentaireGroupe,DateTimeRelationEntity,InfoEntity::CommentaireGroupeId,Cm,Gr)

//Relation daté et valué.
RELATION_ENTITY(DonneeClasse,ValeurDateTimeRelationEntity,InfoEntity::DonneeClasseId,Dn,Cl)
RELATION_ENTITY(DonneeEleve,ValeurDateTimeRelationEntity,InfoEntity::DonneeEleveId,Dn,El)
RELATION_ENTITY(DonneeEtablissement,ValeurDateTimeRelationEntity,InfoEntity::DonneeEtablissementId,Dn,Etab)
RELATION_ENTITY(DonneeNiveau,ValeurDateTimeRelationEntity,InfoEntity::DonneeNiveauId,Dn,Niv)
RELATION_ENTITY(DonneeSource,ValeurDateTimeRelationEntity,InfoEntity::DonneeSourceId,Dn,Sr)

// Relation numéroté.
//RELATION_ENTITY(CompteurTypeControle,NumRelationEntity,InfoEntity::CompteurTypeControleId,TpCtr,Cl)
RELATION_ENTITY(GroupeEleve,NumRelationEntity,InfoEntity::GroupeEleveId,Gr,El)

//Relation simple.
//RELATION_ENTITY(AttributBareme,RelationEntity,InfoEntity::AttributBaremeId,At,Br)
RELATION_ENTITY(AttributCommentaire,RelationEntity,InfoEntity::AttributCommentaireId,At,Cm)
//RELATION_ENTITY(AttributCorrection,RelationEntity,InfoEntity::AttributCorrectionId,At,Crr)
//RELATION_ENTITY(AttributCours,RelationEntity,InfoEntity::AttributCoursId,At,Crs)
//RELATION_ENTITY(AttributExercice,RelationEntity,InfoEntity::AttributExerciceId,At,Ex)
//RELATION_ENTITY(SourceCorrection,RelationEntity,InfoEntity::SourceCorrectionId,Sr,Crr)
//RELATION_ENTITY(SourceCours,RelationEntity,InfoEntity::SourceCoursId,Sr,Crs)
//RELATION_ENTITY(SourceExercice,RelationEntity,InfoEntity::SourceExerciceId,Sr,Ex)
RELATION_ENTITY(NiveauPrecedent,RelationEntity,InfoEntity::NiveauPrecedentId,Prec,Suiv)
RELATION_ENTITY(EtablissementNiveau,RelationEntity,InfoEntity::EtablissementNiveauId,Etab,Niv)
RELATION_ENTITY(EtablissementType,RelationEntity,InfoEntity::EtablissementTypeId,Etab,Tp)
//RELATION_ENTITY(ExerciceCorrection,RelationEntity,InfoEntity::ExerciceCorrectionId,Ex,Crr)
//RELATION_ENTITY(ExerciceUtilisation,RelationEntity,InfoEntity::ExerciceUtilisationId,Ex,Ut)

// Texte
ENTITY_OF_TYPE(Commentaire,TexteEntity,InfoEntity::CommentaireId)

#endif // ENTITYOFDEFAULTTYPE_H
