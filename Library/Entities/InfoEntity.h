/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/03/2016
 */

#ifndef INFOENTITY_H
#define INFOENTITY_H

#include <array>
#include <QString>
#include <QStringList>
#include "InfoEntityBase.h"

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité ayant seulement un attribut.
#define ENTOFID(ENTITY) /*! \ingroup groupeInfoEntity */ \
    /*! \brief Correspondance entre son identifiant et l'entité de type ENTITY.*/ \
    template<> struct EntOfId<ENTITY::ID> \
    {using Ent = ENTITY;};

namespace InfoEntity
{
//! Liste des identifiants des types d'entités.
enum entityId  {AnneeId,
                CibleCommentaireId,
                CibleDonneeId,
                CibleMotCleId,
                CibleTexteId,
                ClasseId,
                ClasseEleveId,
                CoefficientId,
                CommentaireId,
                ControleId,
                CoursId,
                DonneeId,
                DonneeCardId,
                EleveId,
                EtablissementId,
                EtablissementNiveauId,
                EtablissementTypeId,
                ExerciceId,
                FormeId,
                GroupeId,
                GroupeEleveId,
                MotCleId,
                MotClePermissionId,
                NiveauId,
                NiveauPrecedentId,
                NoteId,
                RestrictionModificationId,
                SourceId,
                TexteId,
                TexteSourceId,
                TypeControleId,
                TypeCoursId,
                TypeEtablissementId,
                TypeExerciceId,
                TypeNiveauId,
                TypeUtilisationId,
                UtilisationId,
                NbrEntity,
                NbrArbre = 4};

/*    AttributCorrectionId,
                AttributCoursId,
                AttributBaremeId,
                AttributExerciceId,
                BaremeId,
                CoefficientId,
                CompteurTypeControleId,
                ControleId,
                CorrectionId,
                CoursId,
                EnonceId,
                ExerciceId,
                ExerciceCorrectionId,
                ExerciceUtilisationId,
                FormeId,
                NoteId,
                PointId,
                SourceExerciceId,
                SourceCorrectionId,
                SourceCoursId,
                TexteId,
                TypeControleId,
                TypeCours,
                TypeUtilisationId,
                Utilisation*/

//! Constantes de base contenant les caractéristiques de bases des entités.
enum caracteristique
{NbrAttribut = 1};
}

/*! \ingroup groupeInfoEntity
 * \brief Trait effectuant la correspondance entre l'identifiant et le type d'entités.
 */
/*template<int N = InfoEntity::EntityId> struct EntOfId
{
    //using Ent = Entity;
};*/

#endif // INFOENTITY_H
