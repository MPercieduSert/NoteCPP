/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */

#ifndef RELNUM_H
#define RELNUM_H

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation numéroté.
#define REL_NUM(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
class ENTITY : public NumRelationEntity, public EntityTemp<IdentifiantEntity::ENTITY ## Id,4,ENTITY> \
{public: \
    POS_3_ATT(Id ## ID1,Id ## ID2,Num) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):NumRelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, int num = 0, int id = 0):NumRelationEntity(id ## ID1,id ## ID2,num,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):NumRelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {} \
    ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)};

REL_NUM(CompteurTypeControle,idTpCtr,idCl)
REL_NUM(GroupeEleve,idGr,idEl)

#endif // RELNUM_H
