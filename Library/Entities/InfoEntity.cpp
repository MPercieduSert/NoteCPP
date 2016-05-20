#include "InfoEntity.h"

#include "Entity.h"
#include "Arbre.h"
#include "EntityDivers.h"
#include "EntityNom.h"
#include "EntityRelation.h"
#include "Relations.h"

#include "Annee.h"
#include "Attribut.h"
#include "Classe.h"
#include "ClasseEleve.h"
#include "Donnee.h"
#include "Eleve.h"
#include "Groupe.h"
#include "Niveau.h"

template<class T> const char Info<T>::Name[] {"Entité"};
template<class T> const std::array<const char *,Info<T>::NbrAtt> Info<T>::Att {{"ID"}};

DEF_ARBRE(AttributArbre)
DEF_ARBRE(CoursArbre)
DEF_ARBRE(DonneeArbre)
DEF_ARBRE(EnonceArbre)
DEF_ARBRE(ExerciceArbre)
DEF_ATT_1(Annee,An)
DEF_ATT_7(Attribut,Nom,PrBareme,PrCommentaire,PrCorrection,PrCours,PrExercice,Nc)
DEF_REL_SIMPLE(AttributCommentaire,At,Cm)
DEF_ATT_4(Classe,IdAn,IdEtab,IdNiv,Num)
DEF_ATT_4(ClasseEleve,IdCl,IdEl,Entree,Sortie)
DEF_TEXTE(Commentaire)
DEF_REL_DATE(CommentaireClasse,Cm,Cl)
DEF_REL_DATE(CommentaireEleve,Cm,El)
DEF_REL_DATE(CommentaireGroupe,Cm,Gr)
DEF_ATT_5(Donnee,Card,Nom,Sur,Type,TpVal)
DEF_REL_DATE_VAL(DonneeClasse,Dn,Cl)
DEF_REL_DATE_VAL(DonneeEleve,Dn,El)
DEF_REL_DATE_VAL(DonneeEtablissement,Dn,Etab)
DEF_REL_DATE_VAL(DonneeNiveau,Dn,Niv)
DEF_REL_DATE_VAL(DonneeSource,Dn,Sr)
DEF_ATT_4(Eleve,Fille,Naissance,Nom,Prenom)
DEF_NC_NOM_TYPE(Etablissement)
DEF_REL_SIMPLE(EtablissementNiveau,Etab,Niv)
DEF_ATT_5(Groupe,IdAn,IdCl,Alpha,Nom,Type)
DEF_REL_NUM(GroupeEleve,Gr,El)
DEF_ATT_3(Niveau,IdTp,Nc,Nom)
DEF_REL_SIMPLE(NiveauPrecedent,Prec,Suiv)
DEF_NOM_TYPE(Source)
DEF_NOM_TYPE(TypeNiveau)
