/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/03/2016
 */

#ifndef RELDATE_H
#define RELDATE_H

#include "Entity.h"
#include "RelSimple.h"

// Macro pour les relations datées.

/*! \defgroup groupeMacroRelDate Macros pour les relations datées
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros pour les relations datées
 */

//! \ingroup groupeMacroRelDate
//! Macro de déclaration des deux clés d'une relation et l'attribut date.
#define CLE_DATE(ID1,ID2,NOM1,NOM2) \
    CLE_REL(ID1,ID2,NOM1,NOM2) \
    /*! \brief Attribut : date de la relation */ \
    QDate m_date;

//! \ingroup groupeMacroRelDate
//! Macro implémentant le constructeur à partir des valeurs attributs pour une relation datée.
#define CONSTR_ATT_REL_DATE(ENTITY,ID1,ID2) \
    /*! \brief Constructeur à partir des valeurs attributs. */ \
    ENTITY(int id1,int id2,const QDate & date,int id=0): Entity(id)\
        {setId ## ID1(id1);setId ## ID2(id2);setDate(date);}

//! \ingroup groupeMacroRelDate
//! Macro implémentant la méthode isValid pour une relation datée.
#define ISVALID_REL_DATE(ID1,ID2) \
    /*! \brief Teste si l'entitée est valide.*/ \
    bool isValid() const {return Entity::isValid() && (m_id ## ID1 > 0) && (m_id ## ID2 > 0) && (m_date.isValid());}

//! \ingroup groupeMacroRelDate
//! Macro implémentant la méthode egal pour une relation datée.
#define EGAL_REL_DATE(ENTITY,ID1,ID2) \
    /*! \brief Test d'égalité entre cette entitée et celle transmise en argument.*/ \
    bool egal(const ENTITY & entity) const \
        {return Entity::egal(entity) && (m_id ## ID1 == entity.m_id ## ID1) && (m_id ## ID2 == entity.m_id ## ID2) \
            && (m_date == entity.m_date);}

//! \ingroup groupeMacroRelDate
//! Macro implémentant la méthode set pour une relation datée.
#define SET_REL_DATE(ENTITY,ID1,ID2) \
     /*! \brief Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.*/ \
    void set(const ENTITY & entity) \
        {setId ## ID1(entity.id ## ID1());setId ## ID2(entity.id ## ID2());setDate(entity.date());}

//! \ingroup groupeMacroRelDate
//! Macro Implémentant une clase de relation daté.
#define REL_DATE(ENTITY,ID1,ID2,NOM1,NOM2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
    class ENTITY : public Entity { protected : \
        CLE_DATE(ID1,ID2,NOM1,NOM2) \
        public: \
        NOM_POS_3_ATT(Id ## ID1,Id ## ID2,Date) \
        INCLUCE_METHODE(ENTITY) \
        CONSTR_ATT_REL_DATE(ENTITY,ID1,ID2) \
        CONSTR_CLE_REL(ENTITY,ID1,ID2) \
        GET_SET_ID(ID1) \
        GET_SET_ID(ID2) \
        GET_SET_DATE_VALIDE(date,Date) \
        ISVALID_REL_DATE(ID1,ID2) \
        protected: \
        EGAL_REL_DATE(ENTITY,ID1,ID2) \
        SET_REL_DATE(ENTITY,ID1,ID2)};

REL_DATE(CommentaireClasse,Cm,Cl,Commentaire,Classe)
REL_DATE(CommentaireEleve,Cm,El,Commentaire,Eleve)
REL_DATE(CommentaireGroupe,Cm,Gr,Commentaire,Groupe)

#endif // RELDATE_H
