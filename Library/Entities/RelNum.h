/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */

#ifndef RELNUM_H
#define RELNUM_H

#include "Entity.h"
#include "RelSimple.h"

// Macro pour les relations numérotés.

/*! \defgroup groupeMacroRelNum Macros pour les relations numérotés
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros pour les relations numérotés.
 */

//! \ingroup groupeMacroRelNum
//! Macro de déclaration des deux clés d'une relation et l'attribut num.
#define CLE_NUM(ID1,ID2,NOM1,NOM2) \
    CLE_REL(ID1,ID2,NOM1,NOM2) \
    /*! \brief Attribut : numéro*/ \
    int m_num;

//! \ingroup groupeMacroRelNum
//! Macro implémentant le constructeur à partir des valeurs attributs pour une relation numérotés.
#define CONSTR_ATT_REL_NUM(ENTITY,ID1,ID2) \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id1,int id2,int num,int id=0): Entity(id)\
        {setId ## ID1(id1);setId ## ID2(id2);setNum(num);}

//! \ingroup groupeMacroRelNum
//! Macro implémentant la méthode isValid pour une relation numérotté.
#define ISVALID_REL_NUM(ID1,ID2) \
    /*! \brief Teste si l'entitée est valide.*/ \
    bool isValid() const {return Entity::isValid() && (m_id ## ID1 > 0) && (m_id ## ID2 > 0) && (m_num >= 0);}

//! \ingroup groupeMacroRelNum
//! Macro implémentant la méthode egal pour une relation numérotté.
#define EGAL_REL_NUM(ENTITY,ID1,ID2) \
    /*! \brief Test d'égalité entre cette entitée et celle transmise en argument.*/ \
    bool egal(const ENTITY & entity) const \
        {return Entity::egal(entity) && (m_id ## ID1 == entity.m_id ## ID1) && (m_id ## ID2 == entity.m_id ## ID2) \
            && (m_num == entity.m_num);}

//! \ingroup groupeMacroRelNum
//! Macro implémentant la méthode set pour une relation numérotés.
#define SET_REL_NUM(ENTITY,ID1,ID2) \
     /*! \brief Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.*/ \
    void set(const ENTITY & entity) \
        {setId ## ID1(entity.id ## ID1());setId ## ID2(entity.id ## ID2());setNum(entity.num());}

//! \ingroup groupeMacroRelNum
//! Macro Implémentant une classse de relation numérotés.
#define REL_NUM(ENTITY,ID1,ID2,NOM1,NOM2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
    class ENTITY : public Entity { protected : \
        CLE_NUM(ID1,ID2,NOM1,NOM2) \
        public: \
        NOM_POS_3_ATT(Id ## ID1,Id ## ID2,Num) \
        INCLUCE_METHODE(ENTITY) \
        CONSTR_ATT_REL_NUM(ENTITY,ID1,ID2) \
        CONSTR_CLE_REL(ENTITY,ID1,ID2) \
        GET_SET_ID(ID1) \
        GET_SET_ID(ID2) \
        GET_SET_INT_SUP(num,Num,0) \
        ISVALID_REL_NUM(ID1,ID2) \
        protected: \
        EGAL_REL_NUM(ENTITY,ID1,ID2) \
        SET_REL_NUM(ENTITY,ID1,ID2)};

REL_NUM(CompteurTypeControle,idTpCtr,idCl,Type de controle,Classe)
REL_NUM(GroupeEleve,idGr,idEl,Groupe,Eleve)

#endif // RELNUM_H
