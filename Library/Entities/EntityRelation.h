/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYRELATION
#define ENTITYRELATION

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Définissant les alias des deux clés d'une relation.
#define RELATION_ALIAS_2_CLE(ID1,ID2,ENTITY) enum {id ## ID1 ## Pos = id1Pos, id ## ID2 ## Pos = id2Pos}; \
    ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)

//! \ingroup groupeMacroEntity
//! Macro Implémentant une classe de relation.
#define RELATION_ENTITY(ENTITY,MERE,IDT,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public MERE \
    {public: \
    using MERE::MERE; \
    BASE_ENTITY(ENTITY,IDT) \
    RELATION_ALIAS_2_CLE(ID1,ID2,ENTITY)};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés.
 */
class RelationEntity : public Entity
{
    ATTRIBUT_ENTITY_ID(1)
    ATTRIBUT_ENTITY_ID(2)
public:
    using Entity::Entity;
    BASE_ENTITY_ABS(RelationEntity)

    //! Constructeur à partir des valeurs attributs.
    RelationEntity(int id1, int id2, int id = 0)
        : Entity(id), m_id1(id1), m_id2(id2) {}

    MEMBRE_ATT_2(RelationEntity,Entity,Id1,id1,Id2,id2)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés dont exactement une non nulle.
 */
class RelationExactOneNotNullEntity : public Entity
{
    ATTRIBUT_ENTITY_ID_NULL(1)
    ATTRIBUT_ENTITY_ID_NULL(2)
public:
    using Entity::Entity;
    BASE_ENTITY_ABS(RelationExactOneNotNullEntity)

    //! Constructeur à partir des valeurs attributs.
    RelationExactOneNotNullEntity(int id1, int id2, int id = 0)
        : Entity(id), m_id1(id1), m_id2(id2) {}

    MEMBRE_ATT_2(RelationExactOneNotNullEntity,Entity,Id1,id1,Id2,id2)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés et un attribut date valide.
 */
class DateTimeRelationEntity : public RelationEntity
{
    ATTRIBUT_ENTITY_DATETIME_VALIDE(Date,date)
public:
    using RelationEntity::RelationEntity;
    BASE_ENTITY_ABS(DateTimeRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    DateTimeRelationEntity(int id1, int id2, const QDateTime & date, int id = 0)
        : RelationEntity(id1, id2, id), m_date(date) {}

    MEMBRE_ATT_1(DateTimeRelationEntity,RelationEntity,Date,date)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés et des attributs date valide et valeur.
 */
class ValeurDateTimeRelationEntity : public DateTimeRelationEntity
{
    ATTRIBUT_ENTITY_VARIANT(Valeur,valeur)
public:
    using DateTimeRelationEntity::DateTimeRelationEntity;
    BASE_ENTITY_ABS(ValeurDateTimeRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    ValeurDateTimeRelationEntity(int id1, int id2, const QDateTime & date, const QVariant & valeur, int id = 0)
        : DateTimeRelationEntity(id1, id2, date, id), m_valeur(valeur) {}

    MEMBRE_ATT_1(ValeurDateTimeRelationEntity,DateTimeRelationEntity,Valeur,valeur)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités possédant deux clés et un attribut numéro.
 */
class NumRelationEntity : public RelationEntity
{
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    using RelationEntity::RelationEntity;
    BASE_ENTITY_ABS(NumRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    NumRelationEntity(int id1, int id2, int num, int id = 0)
        : RelationEntity(id1, id2, id), m_num(num) {}

    MEMBRE_ATT_1(NumRelationEntity,RelationEntity,Num,num)
};

#endif // ENTITYRELATION
