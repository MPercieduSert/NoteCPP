/*Auteur: PERCIE DU SERT Maxime
 *Date: 24/03/2016
 */
#ifndef RELATIONS
#define RELATIONS

#include "AttributEntityAlias.h"
#include "Relation.h"

// Relation daté.
REL_DATE(CommentaireClasse,Cm,Cl)
REL_DATE(CommentaireEleve,Cm,El)
REL_DATE(CommentaireGroupe,Cm,Gr)

//Relation daté et valué.
REL_DATE_VAL(DonneeClasse,Dn,Cl)
REL_DATE_VAL(DonneeEleve,Dn,El)
REL_DATE_VAL(DonneeEtablissement,Dn,Etab)
REL_DATE_VAL(DonneeNiveau,Dn,Niv)
REL_DATE_VAL(DonneeSource,Dn,Sr)

// Relation numéroté.
//REL_NUM(CompteurTypeControle,TpCtr,Cl)
REL_NUM(GroupeEleve,Gr,El)

//Relation simple.
//REL_SIMPLE(AttributBareme,At,Br)
REL_SIMPLE(AttributCommentaire,At,Cm)
//REL_SIMPLE(AttributCorrection,At,Crr)
//REL_SIMPLE(AttributCours,At,Crs)
//REL_SIMPLE(AttributExercice,At,Ex)
//REL_SIMPLE(SourceCorrection,Sr,Crr)
//REL_SIMPLE(SourceCours,Sr,Crs)
//REL_SIMPLE(SourceExercice,Sr,Ex)
REL_SIMPLE(NiveauPrecedent,Prec,Suiv)
REL_SIMPLE(EtablissementNiveau,Etab,Niv)
//REL_SIMPLE(ExerciceCorrection,Ex,Crr)
//REL_SIMPLE(ExerciceUtilisation,Ex,Ut)

#endif // RELATIONS

