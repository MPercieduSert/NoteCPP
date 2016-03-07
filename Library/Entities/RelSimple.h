/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef RELSIMPLE_H
#define RELSIMPLE_H

#include "Entity.h"

// Macro pour les relations simple.

/*! \defgroup groupeMacroRelSimple Macros pour les relations simples
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros pour les relations simples
 */

//! \ingroup groupeMacroRelSimple
//! Macro de déclaration des deux clés d'une relation.
#define CLE_REL(ID1,ID2,NOM1,NOM2) \
    /*! \brief clé : sur NOM1 */ \
    int m_id ## ID1; \
    /*! \brief clé : sur NOM2 */ \
    int m_id ## ID2;

//! \ingroup groupeMacroRelSimple
//! Macro implémentant le constructeur à partir des valeurs attributs pour une relation simple.
#define CONSTR_ATT_REL_SIMPLE(ENTITY,ID1,ID2) \
    /*! \brief Constructeur à partir des valeurs attributs. */ \
    ENTITY(int id1,int id2,int id=0): Entity(id)\
        {setId ## ID1(id1);setId ## ID2(id2);}

//! \ingroup groupeMacroRelNum
//! Macro implémentant le constructeur à partir des valeurs des clés de la relation relation
#define CONSTR_CLE_REL(ENTITY,ID1,ID2) \
    /*! \brief Constructeur à partir des valeurs des clés de la relation relation*/ \
    ENTITY(int id1,int id2)\
        {setId ## ID1(id1);setId ## ID2(id2);}

//! \ingroup groupeMacroRelSimple
//! Macro implémentant la méthode isValid pour une relation simple.
#define ISVALID_REL_SIMPLE(ID1,ID2) \
    /*! \brief Teste si l'entitée est valide.*/ \
    bool isValid() const {return Entity::isValid() && (m_id ## ID1 > 0) && (m_id ## ID2 > 0);}

//! \ingroup groupeMacroRelSimple
//! Macro implémentant la méthode egal pour une relation simple.
#define EGAL_REL_SIMPLE(ENTITY,ID1,ID2) \
    /*! \brief Test d'égalité entre cette entitée et celle transmise en argument.*/ \
    bool egal(const ENTITY & entity) const \
        {return Entity::egal(entity) && (m_id ## ID1 == entity.m_id ## ID1) && (m_id ## ID2 == entity.m_id ## ID2);}

//! \ingroup groupeMacroRelSimple
//! Macro implémentant la méthode set pour une relation simple.
#define SET_REL_SIMPLE(ENTITY,ID1,ID2) \
     /*! \brief Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.*/ \
    void set(const ENTITY & entity) \
        {setId ## ID1(entity.id ## ID1());setId ## ID2(entity.id ## ID2());}

//! \ingroup groupeMacroRelSimple
//! Macro Implémentant une classe de relation simple.
#define REL_SIMPLE(ENTITY,ID1,ID2,NOM1,NOM2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
    class ENTITY : public Entity { protected : \
        CLE_REL(ID1,ID2,NOM1,NOM2) \
        public: \
        NOM_POS_2_ATT(Id ## ID1,Id ## ID2) \
        INCLUCE_METHODE(ENTITY) \
        CONSTR_ATT_REL_SIMPLE(ENTITY,ID1,ID2) \
        GET_SET_ID(ID1) \
        GET_SET_ID(ID2) \
        ISVALID_REL_SIMPLE(ID1,ID2) \
        protected: \
        EGAL_REL_SIMPLE(ENTITY,ID1,ID2) \
        SET_REL_SIMPLE(ENTITY,ID1,ID2)};

//Attribut
REL_SIMPLE(AttributBareme,At,Br,Attribut,Bareme)
REL_SIMPLE(AttributCommentaire,At,Cm,Attribut,Commentaire)
REL_SIMPLE(AttributCorrection,At,Crr,Attribut,Correction)
REL_SIMPLE(AttributCours,At,Crs,Attribut,Cours)
REL_SIMPLE(AttributExercice,At,Ex,Attribut,Exercice)

//Source
REL_SIMPLE(SourceCorrection,Sr,Crr,Source,Correction)
REL_SIMPLE(SourceCours,Sr,Crs,Source,Cours)
REL_SIMPLE(SourceExercice,Sr,Ex,Source,Exercice)

REL_SIMPLE(NiveauPrecedent,Prec,Suiv,Précédent,suivant)

REL_SIMPLE(EtablissementNiveau,Etab,Niv,Etablissement,Niveau)

REL_SIMPLE(ExerciceCorrection,Ex,Crr,Exercice,Correction)
REL_SIMPLE(ExerciceUtilisation,Ex,Ut,Exercice,Utilisation)

#endif // RELSIMPLE_H
