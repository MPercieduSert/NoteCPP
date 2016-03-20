/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/03/2016
 */

#ifndef IDENTIFIANTENTITY_H
#define IDENTIFIANTENTITY_H

/*! \ingroup groupeEntity
 * \brief Classe contenant les identifiants des entitées.
 */
class IdentifiantEntity
{
public:
    //! Liste des identifiants des types d'entitées.
    enum entityId  {EntityId = -1,
                    ArbreEntityId = -2,
                    AttributArbreId = 0,
                    CoursArbreId = 1,
                    DonneeArbreId = 2,
                    EnonceArbreId = 3,
                    ExerciceArbreId = 4,
                    AnneeId = 5,

                    AttributId,
                    AttributCommentaireId,
                    AttributCorrectionId,
                    AttributCoursId,
                    AttributBaremeId,
                    AttributExerciceId,
                    BaremeId,
                    ClasseId,
                    ClasseEleveId,
                    CoefficientId,
                    CommentaireId,
                    CommentaireClasseId,
                    CommentaireEleveId,
                    CommentaireGroupeId,
                    CompteurTypeControleId,
                    ControleId,
                    CorrectionId,
                    CoursId,
                    DonneeId,
                    DonneeClasseId,
                    DonneeEleveId,
                    DonneeEtablissementId,
                    DonneeNiveauId,
                    DonneeSourceId,
                    EleveId,
                    EnonceId,
                    EtablissementId ,
                    EtablissementNiveauId,
                    ExerciceId,
                    ExerciceCorrectionId,
                    ExerciceUtilisationId,
                    FormeId,
                    GroupeId,
                    GroupeEleveId,
                    NiveauId,
                    NiveauPrecedentId,
                    NoteId,
                    PointId,
                    SourceId,
                    SourceExerciceId,
                    SourceCorrectionId,
                    SourceCoursId,
                    TexteId,
                    TypeControleId,
                    TypeCours,
                    TypeNiveauId,
                    TypeUtilisationId,
                    Utilisation
                   };

    IdentifiantEntity()
    {}
};

#endif // IDENTIFIANTENTITY_H
