/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/03/2016
 */

#ifndef INFOENTITY_H
#define INFOENTITY_H

#include <array>
#include <QString>
#include <QStringList>

//Enumeration des positions et les variables statiques de EntityTemp

/*! \defgroup groupeNomPosEntity Enumeration des positions et les variables statiques de EntityTemp.
 * \ingroup groupeMacroEntity
 * \brief Ensemble de macrosdéfinissant l'numeration des positions et les variables statiques de EntityTemp.
 */

//! \ingroup groupeNomPosEntity
//! Macro définisant l'identifiant et le nom d'une entité.
#define IDENTIFIANT(ENTITY) \
    /*! \brief Identifiant de l'entité.*/ \
    static const int ID = CaracteristiqueEntity::ENTITY ## Id; \
    /*! \brief Nom de l'entité.*/ \
    static const char Name[]; \
    /*! \brief Tableau des noms des attributs de l'entité.*/ \
    static const std::array<const char *, NbrAtt> Att;

//! \ingroup groupeNomPosEntity
//! Macro rassemblant les parties communes des déclarations des informations pour une entité (penser à refermer la structure).
#define DECL_ENT(ENTITY,N) class ENTITY; \
    /*! \ingroup groupeInfoEntity */ \
    /*! \brief Information sur l'entité ENTITY.*/ \
    template<> struct Info<ENTITY> \
    {/*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = N+1; \
    IDENTIFIANT(ENTITY)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant un attribut.
#define DECL_ATT_1(ATT1) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, IdPos = 1};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant deux attributs.
#define DECL_ATT_2(ATT1,ATT2) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, IdPos = 2};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant trois attributs.
#define DECL_ATT_3(ATT1,ATT2,ATT3) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, IdPos = 3};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant quatre attributs.
#define DECL_ATT_4(ATT1,ATT2,ATT3,ATT4) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, IdPos = 4};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant cinq attributs.
#define DECL_ATT_5(ATT1,ATT2,ATT3,ATT4,ATT5) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, IdPos = 5};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant six attributs.
#define DECL_ATT_6(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, IdPos = 6};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant sept attributs.
#define DECL_ATT_7(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, IdPos = 7};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant huit attributs.
#define DECL_ATT_8(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7,ATT8) /*! \brief Position des attributs dans l'entité, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, ATT8 ## Pos = 7, IdPos = 8};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité .
#define DECL_ID_REL(ID1,ID2) /*! \brief Position des clés parmis les attributs dans l'entité. */ \
    enum clePosition { Id1Pos = Id ## ID1 ## Pos, Id2Pos = Id ## ID2 ## Pos};

//! \ingroup groupeNomPosEntity
//! Macro rassemblant les parties communes des définitions des informations pour une entité.
#define DEF_ENT(ENTITY) constexpr char Info<ENTITY>::Name[] {#ENTITY}; \
    constexpr std::array<const char *, Info<ENTITY>::NbrAtt> Info<ENTITY>::Att

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_1(ENTITY,ATT1) DEF_ENT(ENTITY){{#ATT1,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_2(ENTITY,ATT1,ATT2) DEF_ENT(ENTITY){{#ATT1,#ATT2,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_3(ENTITY,ATT1,ATT2,ATT3) DEF_ENT(ENTITY){{#ATT1,#ATT2,#ATT3,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_4(ENTITY,ATT1,ATT2,ATT3,ATT4) DEF_ENT(ENTITY){{#ATT1,#ATT2,#ATT3,#ATT4,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_5(ENTITY,ATT1,ATT2,ATT3,ATT4,ATT5) DEF_ENT(ENTITY){{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_6(ENTITY,ATT1,ATT2,ATT3,ATT4,ATT5,ATT6) DEF_ENT(ENTITY){{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,#ATT6,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_7(ENTITY,ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7) DEF_ENT(ENTITY){{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,#ATT6,#ATT7,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro définisant le nom de l'entitée et la position des attributs.
#define DEF_ATT_8(ENTITY,ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7,ATT8) DEF_ENT(ENTITY){{#ATT1,#ATT2,#ATT3,#ATT4,#ATT5,#ATT6,#ATT7,#ATT8,"ID"}};

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité d'un type prédéfini.
#define DECL_TYPE(ENTITY,N,TYPE) /*! \ingroup groupeEntity */ \
    /*! \brief Représentation de l'entité ENTITY. */ \
   typedef TYPE<CaracteristiqueEntity::ENTITY ## Id> ENTITY; \
    /*! \ingroup groupeInfoEntity */ \
    /*! \brief Information sur l'entité ENTITY.*/ \
    template<> struct Info<ENTITY> \
    {/*! \brief Nombre d'attribut de l'entité.*/ \
    static const int NbrAtt = N+1; \
    IDENTIFIANT(ENTITY)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité de type arbre.
#define DECL_ARBRE(ENTITY) DECL_TYPE(ENTITY,4,Arbre) DECL_ATT_4(Feuille,Niveau,Num,Parent) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité de type arbre.
#define DEF_ARBRE(ENTITY) DEF_ATT_4(ENTITY,Feuille,Niveau,Num,Parent)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant seulement les attribut nc, nom et type.
#define DECL_NC_NOM_TYPE(ENTITY) DECL_TYPE(ENTITY,3,NcNomTypeOnlyEntity) DECL_ATT_3(Nc,Nom,Type) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité ayant seulement les attribut nc, nom et type.
#define DEF_NC_NOM_TYPE(ENTITY) DEF_ATT_3(ENTITY,Nc,Nom,Type)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant seulement les attribut nom et type.
#define DECL_NOM_TYPE(ENTITY) DECL_TYPE(ENTITY,2,NomTypeOnlyEntity) DECL_ATT_2(Nom,Type) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité ayant seulement les attribut nom et type.
#define DEF_NOM_TYPE(ENTITY) DEF_ATT_2(ENTITY,Nom,Type)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité de type relation datée.
#define DECL_REL_DATE(ENTITY,ID1,ID2) DECL_ENT(ENTITY,3) DECL_ATT_3(Id ## ID1,Id ## ID2,Date) DECL_ID_REL(ID1,ID2) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité de type relation datée.
#define DEF_REL_DATE(ENTITY,ID1,ID2) DEF_ATT_3(ENTITY,Id ## ID1,Id ## ID2,Date)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité de type relation datée et valuée.
#define DECL_REL_DATE_VAL(ENTITY,ID1,ID2) DECL_ENT(ENTITY,4) DECL_ATT_4(Id ## ID1,Id ## ID2,Date,Valeur) DECL_ID_REL(ID1,ID2) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité de type relation datée et valuée.
#define DEF_REL_DATE_VAL(ENTITY,ID1,ID2) DEF_ATT_4(ENTITY,Id ## ID1,Id ## ID2,Date,Valeur)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité de type relation numéroté.
#define DECL_REL_NUM(ENTITY,ID1,ID2) DECL_ENT(ENTITY,3) DECL_ATT_3(Id ## ID1,Id ## ID2,Num) DECL_ID_REL(ID1,ID2) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité de type relation numéroté.
#define DEF_REL_NUM(ENTITY,ID1,ID2) DEF_ATT_3(ENTITY,Id ## ID1,Id ## ID2,Num)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité de type relation simple.
#define DECL_REL_SIMPLE(ENTITY,ID1,ID2) DECL_ENT(ENTITY,2) DECL_ATT_2(Id ## ID1,Id ## ID2) DECL_ID_REL(ID1,ID2) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité de type relation simple.
#define DEF_REL_SIMPLE(ENTITY,ID1,ID2) DEF_ATT_2(ENTITY,Id ## ID1,Id ## ID2)

//! \ingroup groupeNomPosEntity
//! Macro déclarant les informations pour une entité ayant seulement un attribut.
#define DECL_TEXTE(ENTITY) DECL_TYPE(ENTITY,1,TexteOnlyEntity) DECL_ATT_1(Texte) };

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité ayant seulement un attribut.
#define DEF_TEXTE(ENTITY) DEF_ATT_1(ENTITY,Texte)

//! \ingroup groupeNomPosEntity
//! Macro définissant les informations pour une entité ayant seulement un attribut.
#define ENTOFID(ENTITY) /*! \ingroup groupeInfoEntity */ \
    /*! \brief Correspondance entre son identifiant et l'entité de type ENTITY.*/ \
    template<> struct EntOfId<ENTITY::ID> \
    {using Ent = ENTITY;};

class Entity;
template<int N> class Arbre;
template<int N> class NcNomTypeOnlyEntity;
template<int N> class NomTypeOnlyEntity;
template<int N> class TexteOnlyEntity;

/*! \defgroup groupeInfoEntity Informations sur les entités
 * \ingroup groupeEntity
 * \brief Ensemble des informations sur les entités.
 */

/*! \ingroup groupeInfoEntity
 * \brief Espace de noms contenant les enumérations sur les entités.
 */
namespace CaracteristiqueEntity
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

//! Constantes de base contenant les caractéristiques de bases des entités.
enum caracteristique
{NbrAttribut = 1};
};


/*! \ingroup groupeInfoEntity
 * \brief Trait contenant les informations sur les entités.
 */
template<class T> struct Info
{
    static const int ID = CaracteristiqueEntity::EntityId;
    static const char Name[];
    static const int NbrAtt = CaracteristiqueEntity::NbrAttribut;
    static const std::array<const char *,NbrAtt> Att;
};

DECL_ARBRE(AttributArbre)
DECL_ARBRE(CoursArbre)
DECL_ARBRE(DonneeArbre)
DECL_ARBRE(EnonceArbre)
DECL_ARBRE(ExerciceArbre)
DECL_ENT(Annee,1) DECL_ATT_1(An) };
DECL_ENT(Attribut,7) DECL_ATT_7(Nom,PrBareme,PrCommentaire,PrCorrection,PrCours,PrExercice,Nc) };
DECL_REL_SIMPLE(AttributCommentaire,At,Cm)
DECL_ENT(Classe,4) DECL_ATT_4(IdAn,IdEtab,IdNiv,Num) DECL_ID_REL(An,Etab) };
DECL_ENT(ClasseEleve,4) DECL_ATT_4(IdCl,IdEl,Entree,Sortie) DECL_ID_REL(Cl,El) };
DECL_TEXTE(Commentaire)
DECL_REL_DATE(CommentaireClasse,Cm,Cl)
DECL_REL_DATE(CommentaireEleve,Cm,El)
DECL_REL_DATE(CommentaireGroupe,Cm,Gr)
DECL_ENT(Donnee,5) DECL_ATT_5(Card,Nom,Sur,Type,TpVal) };
DECL_REL_DATE_VAL(DonneeClasse,Dn,Cl)
DECL_REL_DATE_VAL(DonneeEleve,Dn,El)
DECL_REL_DATE_VAL(DonneeEtablissement,Dn,Etab)
DECL_REL_DATE_VAL(DonneeNiveau,Dn,Niv)
DECL_REL_DATE_VAL(DonneeSource,Dn,Sr)
DECL_ENT(Eleve,4) DECL_ATT_4(Fille,Naissance,Nom,Prenom) };
DECL_NC_NOM_TYPE(Etablissement)
DECL_REL_SIMPLE(EtablissementNiveau,Etab,Niv)
DECL_ENT(Groupe,5) DECL_ATT_5(IdAn,IdCl,Alpha,Nom,Type) DECL_ID_REL(An,Cl)};
DECL_REL_NUM(GroupeEleve,Gr,El)
DECL_ENT(Niveau,3) DECL_ATT_3(IdTp,Nc,Nom) };
DECL_REL_SIMPLE(NiveauPrecedent,Prec,Suiv)
DECL_NOM_TYPE(Source)
DECL_NOM_TYPE(TypeNiveau)


/*! \ingroup groupeInfoEntity
 * \brief Trait effectuant la correspondance entre l'identifiant et le type d'entités.
 */
/*template<int N = CaracteristiqueEntity::EntityId> struct EntOfId
{
    //using Ent = Entity;
};*/

#endif // INFOENTITY_H
