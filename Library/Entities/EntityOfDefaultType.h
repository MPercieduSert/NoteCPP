/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/08/2016
 */
#ifndef ENTITYOFDEFAULTTYPE_H
#define ENTITYOFDEFAULTTYPE_H

#include "EntityCible.h"
#include "EntityDivers.h"
#include "EntityNom.h"
#include "EntityRelation.h"
#include "InfoEntity.h"

// Cible
CIBLE_ENTITY(CibleAttribut,CibleEntity,InfoEntity::CibleAttributId,At)
CIBLE_ENTITY(CibleCommentaire,DateTimeCibleEntity,InfoEntity::CibleCommentaireId,Cm)
CIBLE_ENTITY(CibleDonnee,ValeurNumDateTimeCibleEntity,InfoEntity::CibleDonneeId,Dn)

// Id, Num et Valeur
VAL_ID_NUM_ENTITY(Coefficient,ValeurDoubleIdNumEntity,InfoEntity::CoefficientId,Ctr)

// Nc et Nom
ENTITY_OF_TYPE(Etablissement,NcNomEntity,InfoEntity::EtablissementId)

// Nc, Nom et Type
ENTITY_OF_TYPE(Attribut,TypeNcNomEntity,InfoEntity::AttributId)

// Nom et Type
ENTITY_OF_TYPE(Source,TypeNcNomEntity,InfoEntity::SourceId)

// Relation daté.

// Relation numéroté.
RELATION_ENTITY(GroupeEleve,NumRelationEntity,InfoEntity::GroupeEleveId,Gr,El)

// Relation numéroté, daté et valué.
RELATION_ENTITY(Note,ValeurIntDateTimeNumRelationEntity,InfoEntity::NoteId,Ctr,El)

//Relation simple.
//RELATION_ENTITY(SourceCorrection,RelationEntity,InfoEntity::SourceCorrectionId,Sr,Crr)
//RELATION_ENTITY(SourceCours,RelationEntity,InfoEntity::SourceCoursId,Sr,Crs)
//RELATION_ENTITY(SourceExercice,RelationEntity,InfoEntity::SourceExerciceId,Sr,Ex)
RELATION_ENTITY(EtablissementNiveau,RelationEntity,InfoEntity::EtablissementNiveauId,Etab,Niv)
RELATION_ENTITY(EtablissementType,RelationEntity,InfoEntity::EtablissementTypeId,Etab,Tp)
RELATION_ENTITY(NiveauPrecedent,RelationEntity,InfoEntity::NiveauPrecedentId,Prec,Suiv)


//RELATION_ENTITY(ExerciceCorrection,RelationEntity,InfoEntity::ExerciceCorrectionId,Ex,Crr)
//RELATION_ENTITY(ExerciceUtilisation,RelationEntity,InfoEntity::ExerciceUtilisationId,Ex,Ut)

// Texte
ENTITY_OF_TYPE(Commentaire,TexteEntity,InfoEntity::CommentaireId)

#endif // ENTITYOFDEFAULTTYPE_H
