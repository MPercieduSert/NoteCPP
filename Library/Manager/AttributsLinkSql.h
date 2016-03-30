/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ATTRIBUTSLINKSQL
#define ATTRIBUTSLINKSQL

#include "AttributsMacroLinkSql.h"

//Bool
ATTRIBUT_LINK(Fille,fille,Bool,bool)
ATTRIBUT_LINK(PrBareme,prBareme,Bool,bool)
ATTRIBUT_LINK(PrCommentaire,prCommentaire,Bool,bool)
ATTRIBUT_LINK(PrCorrection,prCorrection,Bool,bool)
ATTRIBUT_LINK(PrCours,prCours,Bool,bool)
ATTRIBUT_LINK(PrExercice,prExercice,Bool,bool)

//Date
ATTRIBUT_LINK(Entree,entree,Date,QDate)
ATTRIBUT_LINK(Sortie,sortie,Date,QDate)
ATTRIBUT_LINK(Naissance,naissance,Date,QDate)

//Identifiant
ATTRIBUT_LINK(IdAn,idAn,Int,int)
ATTRIBUT_LINK(IdCl,idCl,Int,int)
ATTRIBUT_LINK(IdNiv,idNiv,Int,int)
ATTRIBUT_LINK(IdTp,idTp,Int,int)

//Int
ATTRIBUT_LINK(An,an,Int,int)
ATTRIBUT_LINK(Alpha,alpha,Int,int)
ATTRIBUT_LINK(Card,card,Int,int)
ATTRIBUT_LINK(Sur,sur,Int,int)
ATTRIBUT_LINK(TpVal,tpVal,Int,int)

//Int: 0 -> null
ATTRIBUT_LINK_NULL_TO_ZERO(IdAn,idAn,Int,int)
ATTRIBUT_LINK_NULL_TO_ZERO(IdCl,idCl,Int,int)

//String

//Variant

#endif // ATTRIBUTSLINKSQL

