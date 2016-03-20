/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */

#ifndef RELDATEVAL_H
#define RELDATEVAL_H

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation daté (valide).
#define REL_DATE_VAL(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
class ENTITY : public ValeurDateRelationEntity, public EntityTemp<IdentifiantEntity::ENTITY ## Id,5,ENTITY> \
{public: \
    POS_4_ATT(Id ## ID1,Id ## ID2,Date,Valeur) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):ValeurDateRelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, const QDate & date = QDate(), const QVariant & valeur = QVariant(), int id = 0) \
        :ValeurDateRelationEntity(id ## ID1,id ## ID2,date,valeur,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):ValeurDateRelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {} \
    ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)};

REL_DATE_VAL(Donnee,IdDn,IdCl)
REL_DATE_VAL(DonneeEleve,IdDn,IdEl)
REL_DATE_VAL(DonneeEtablissement,IdDn,IdEtab)
REL_DATE_VAL(DonneeNiveau,IdDn,IdNiv)
REL_DATE_VAL(DonneeSource,IdDn,IdSr)

#endif // RELDATEVAL_H
