/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/03/2016
 */

#ifndef RELDATE_H
#define RELDATE_H

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation daté.
#define REL_DATE(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
class ENTITY : public DateRelationEntity, public EntityTemp<IdentifiantEntity::ENTITY ## Id,4,ENTITY> \
{public: \
    POS_3_ATT(Id ## ID1,Id ## ID2,Date) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):DateRelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, const QDate & date = QDate(), int id = 0):DateRelationEntity(id ## ID1,id ## ID2,date,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):DateRelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {} \
    ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)};

REL_DATE(CommentaireClasse,Cm,Cl)
REL_DATE(CommentaireEleve,Cm,El)
REL_DATE(CommentaireGroupe,Cm,Gr)

#endif // RELDATE_H
