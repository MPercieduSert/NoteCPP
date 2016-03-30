/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/03/2016
 */

#ifndef INFOENTITY_H
#define INFOENTITY_H

/*! \defgroup groupeInfoEntity Informations sur les entités
 * \ingroup groupeEntity
 * \brief Ensemble des informations sur les entités.
 */

/*! \ingroup groupeInfoEntity
 * \brief Structure contenant les informations sur les entités.
 */
struct InfoEntity
{    
    //! Liste des identifiants des types d'entités.
    enum entityId  {EntityId = -1,
                    ArbreEntityId = -2,
                    AttributArbreId = 0,
                    CoursArbreId,
                    DonneeArbreId,
                    EnonceArbreId ,
                    ExerciceArbreId ,
                    AnneeId,
                    AttributId,
                    AttributCommentaireId,
                    ClasseId,
                    ClasseEleveId,
                    CommentaireId,
                    CommentaireClasseId,
                    CommentaireEleveId,
                    CommentaireGroupeId,
                    DonneeId,
                    DonneeClasseId,
                    DonneeEleveId,
                    DonneeEtablissementId,
                    DonneeNiveauId,
                    DonneeSourceId,
                    EleveId,
                    EtablissementId ,
                    EtablissementNiveauId,
                    GroupeId,
                    GroupeEleveId,
                    NiveauId,
                    NiveauPrecedentId,
                    SourceId,
                    TypeNiveauId,
                    NbrEntity};


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
};

#endif // INFOENTITY_H
