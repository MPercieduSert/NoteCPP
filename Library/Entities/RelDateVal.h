/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */

#ifndef RELDATEVAL_H
#define RELDATEVAL_H

#include "Entity.h"
#include "RelSimple.h"

// Macro pour les relations valués.

/*! \defgroup groupeMacroRelDateVal Macros pour les relations valuées
 * \ingroup groupeMacroEntity
 * \brief Ensemble des macros pour les relations valuée
 */

//! \ingroup groupeMacroRelDateVal
//! Macro de déclaration des deux clés d'une relation et l'attribut num.
#define CLE_DATE_VAL(ID1,ID2,NOM1,NOM2) \
    CLE_REL(ID1,ID2,NOM1,NOM2) \
    /*! \brief Attribut : date*/ \
    QDateTime m_date; \
    /*! \brief Attribut : valeur*/ \
    QVariant m_valeur;

//! \ingroup groupeMacroRelDateVal
//! Macro implémentant le constructeur à partir des valeurs attributs pour une relation valuées.
#define CONSTR_ATT_REL_DATE_VAL(ENTITY,ID1,ID2) \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id1,int id2,const QDateTime & date, const QVariant & valeur,int id=0): Entity(id)\
        {setId ## ID1(id1);setId ## ID2(id2);setDate(date);setValeur(valeur);}

//! \ingroup groupeMacroRelDateVal
//! Macro implémentant le constructeur à partir des clés et de la date pour une relation valuées.
#define CONSTR_ATT_UN_REL_DATE_VAL(ENTITY,ID1,ID2) \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id1,int id2,const QDateTime & date)\
        {setId ## ID1(id1);setId ## ID2(id2);setDate(date);}

//! \ingroup groupeMacroRelDateVal
//! Macro implémentant la méthode isValid pour une relation valuées.
#define ISVALID_REL_DATE_VAL(ID1,ID2) \
    /*! \brief Teste si l'entitée est valide.*/ \
    bool isValid() const {return Entity::isValid() && (m_id ## ID1 > 0) && (m_id ## ID2 > 0) && (m_date.isValid()) && (!m_valeur.isNull());}

//! \ingroup groupeMacroRelDateVal
//! Macro implémentant la méthode egal pour une relation valuées.
#define EGAL_REL_DATE_VAL(ENTITY,ID1,ID2) \
    /*! \brief Test d'égalité entre cette entitée et celle transmise en argument.*/ \
    bool egal(const ENTITY & entity) const \
        {return Entity::egal(entity) && (m_id ## ID1 == entity.m_id ## ID1) && (m_id ## ID2 == entity.m_id ## ID2) \
            && (m_date == entity.m_date) && (m_valeur == entity.m_valeur);}

//! \ingroup groupeMacroRelDateVal
//! Macro implémentant la méthode set pour une relation valuées.
#define SET_REL_DATE_VAL(ENTITY,ID1,ID2) \
     /*! \brief Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.*/ \
    void set(const ENTITY & entity) \
        {setId ## ID1(entity.id ## ID1());setId ## ID2(entity.id ## ID2());setDate(entity.date());setValeur(entity.valeur());}

//! \ingroup groupeMacroRelDateVal
//! Macro Implémentant une classe de relation valuée.
#define REL_DATE_VAL(ENTITY,ID1,ID2,NOM1,NOM2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
    class ENTITY : public Entity { protected : \
        CLE_DATE_VAL(ID1,ID2,NOM1,NOM2) \
        public: \
        NOM_POS_4_ATT(Id ## ID1,Id ## ID2,Date,Valeur) \
        INCLUCE_METHODE(ENTITY) \
        CONSTR_ATT_REL_DATE_VAL(ENTITY,ID1,ID2) \
        CONSTR_CLE_REL(ENTITY,ID1,ID2) \
        CONSTR_ATT_UN_REL_DATE_VAL(ENTITY,ID1,ID2) \
        GET_SET_ID(ID1) \
        GET_SET_ID(ID2) \
        GET_SET_DATETIME_VALIDE(date,Date) \
        GET_SET_QVARIANT_NOT_NULL(valeur,Valeur) \
        ISVALID_REL_DATE_VAL(ID1,ID2) \
        protected: \
        EGAL_REL_DATE_VAL(ENTITY,ID1,ID2) \
        SET_REL_DATE_VAL(ENTITY,ID1,ID2)};

REL_DATE_VAL(Donnee,IdDn,IdCl,Donnee,Classe)
REL_DATE_VAL(DonneeEleve,IdDn,IdEl,Donnee,Eleve)
REL_DATE_VAL(DonneeEtablissement,IdDn,IdEtab,Donnee,Etablissement)
REL_DATE_VAL(DonneeNiveau,IdDn,IdNiv,Donnee,Niveau)
REL_DATE_VAL(DonneeSource,IdDn,IdSr,Donnee,Source)

#endif // RELDATEVAL_H
