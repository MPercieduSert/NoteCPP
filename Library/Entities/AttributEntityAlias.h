/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/03/2016
 */
#ifndef ATTRIBUTENTITYALIAS_H
#define ATTRIBUTENTITYALIAS_H

#include "AttributEntityMacroAlias.h"

// Bool
ALIAS_BOOL(Fille,fille)
ALIAS_BOOL(PrBareme,prBareme)
ALIAS_BOOL(PrCommentaire,prCommentaire)
ALIAS_BOOL(PrCorrection,prCorrection)
ALIAS_BOOL(PrCours,prCours)
ALIAS_BOOL(PrExercice,prExercice)

// Date
ALIAS_DATE(Entree,entree)
ALIAS_DATE(Sortie,sortie)

// Date valide
ALIAS_DATE_VALIDE(Naissance,naissance)

// Identifiant
ALIAS_ID(An)
ALIAS_ID(Cl)
ALIAS_ID(Etab)
ALIAS_ID(Niv)
ALIAS_ID(Tp)

// Identifiant pouvant être nulle
ALIAS_ID_NULL(An)
ALIAS_ID_NULL(Cl)

// Int
ALIAS_INT_SUP(An,an,1,0)
ALIAS_INT_SUP(Alpha,alpha,0,0)
ALIAS_INT_SUP(Card,card,-1,-1)
ALIAS_INT_SUP(Sur,sur,0,0)
ALIAS_INT_SUP(TpVal,tpVal,0,0)

// String not null
ALIAS_STR_NOT_EMPTY(Prenom,prenom)

#endif // ATTRIBUTENTITYALIAS_H
