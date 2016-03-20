/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef RELSIMPLE_H
#define RELSIMPLE_H

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation simple.
#define REL_SIMPLE(ENTITY,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entitée ENTITY.*/ \
class ENTITY : public RelationEntity, public EntityTemp<IdentifiantEntity::ENTITY ## Id,3,ENTITY> \
{public: \
    POS_2_ATT(Id ## ID1,Id ## ID2) \
    /*! \brief Constructeur par defaut.*/ \
    ENTITY(int id = 0):RelationEntity(id) {} \
    /*! \brief Constructeur à partir des valeurs attributs.*/ \
    ENTITY(int id ## ID1, int id ## ID2, int id = 0):RelationEntity(id ## ID1,id ## ID2,id) {} \
    /*! \brief Constructeur de recopie.*/ \
    ENTITY(const ENTITY & entity):RelationEntity(entity) {} \
    /*! \brief Destructeur.*/ \
    ~ENTITY() {} \
    ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)};

//Attribut
REL_SIMPLE(AttributBareme,At,Br)
REL_SIMPLE(AttributCommentaire,At,Cm)
REL_SIMPLE(AttributCorrection,At,Crr)
REL_SIMPLE(AttributCours,At,Crs)
REL_SIMPLE(AttributExercice,At,Ex)

//Source
REL_SIMPLE(SourceCorrection,Sr,Crr)
REL_SIMPLE(SourceCours,Sr,Crs)
REL_SIMPLE(SourceExercice,Sr,Ex)

REL_SIMPLE(NiveauPrecedent,Prec,Suiv)

REL_SIMPLE(EtablissementNiveau,Etab,Niv)

REL_SIMPLE(ExerciceCorrection,Ex,Crr)
REL_SIMPLE(ExerciceUtilisation,Ex,Ut)

#endif // RELSIMPLE_H
