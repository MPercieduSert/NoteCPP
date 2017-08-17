/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/08/2016
 */
#ifndef ENTITYOFDEFAULTTYPE_H
#define ENTITYOFDEFAULTTYPE_H

#include "EntityCible.h"
#include "EntityDivers.h"
#include "EntityRelation.h"
#include "InfoEntity.h"

// Cible
ID1_ENTITY(CibleMotCle,Cible,InfoEntity::CibleMotCleId,MC)
ID1_ENTITY(CibleCommentaire,CibleNullDateTimeCurrentNum,InfoEntity::CibleCommentaireId,Cm)
ID1_ENTITY(CibleDonnee,CibleDateTimeCurrentNumValeurVariant,InfoEntity::CibleDonneeId,Dn)
ID1_ENTITY(MotClePermission,IdCibleNum,InfoEntity::MotClePermissionId,MC)
using RestrictionModification = CibleSimpleNumEntity<InfoEntity::RestrictionModificationId>;

// Id, Num et Valeur
ID1_ENTITY(Coefficient,IdNumValeurDouble,InfoEntity::CoefficientId,Ctr)

// Nc et Nom
using Etablissement = NcNomEntity<InfoEntity::EtablissementId>;

// Nc, Nom et Type
using Source = NcNomTypeEntity<InfoEntity::SourceId>;

// Relation daté.

// Relation numéroté.
RELATION_ENTITY(GroupeEleve,Num,InfoEntity::GroupeEleveId,Gr,El)

// Relation numéroté, daté et valué.
RELATION_ENTITY(Note,DateTimeCurrentNumValeurInt,InfoEntity::NoteId,Ctr,El)

//Relation simple.
//RELATION_ENTITY(SourceCorrection,RelationEntity,InfoEntity::SourceCorrectionId,Sr,Crr)
//RELATION_ENTITY(SourceCours,RelationEntity,InfoEntity::SourceCoursId,Sr,Crs)
//RELATION_ENTITY(SourceExercice,RelationEntity,InfoEntity::SourceExerciceId,Sr,Ex)
RELATION_ENTITY(EtablissementNiveau,,InfoEntity::EtablissementNiveauId,Etab,Niv)
RELATION_ENTITY(EtablissementType,,InfoEntity::EtablissementTypeId,Etab,Tp)
RELATION_ENTITY(NiveauPrecedent,,InfoEntity::NiveauPrecedentId,Prec,Suiv)

//RELATION_ENTITY(ExerciceCorrection,RelationEntity,InfoEntity::ExerciceCorrectionId,Ex,Crr)
//RELATION_ENTITY(ExerciceUtilisation,RelationEntity,InfoEntity::ExerciceUtilisationId,Ex,Ut)

// Texte
using Commentaire = TexteDateTimeEntity<DateTimeCurrentAttribut,InfoEntity::CommentaireId>;

#endif // ENTITYOFDEFAULTTYPE_H
