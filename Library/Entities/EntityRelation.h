/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYRELATION
#define ENTITYRELATION

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro définissant les alias des deux clés d'une relation.
#define RELATION_ALIAS_2_CLE(ID1,ID2) ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation simple.
#define ENUM_RelationEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = RelationEntity::Id, Id ## ID1 = RelationEntity::Id1, Id ## ID2 = RelationEntity::Id2, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation où une des deux clés est inutile.
#define ENUM_RelationExactOneNotNullEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = RelationExactOneNotNullEntity::Id, Id ## ID1 = RelationExactOneNotNullEntity::Id1, Id ## ID2 = RelationExactOneNotNullEntity::Id2, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation datée.
#define ENUM_DateTimeRelationEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = DateTimeRelationEntity::Id, Id ## ID1 = DateTimeRelationEntity::Id1, Id ## ID2 = DateTimeRelationEntity::Id2, DateTime = DateTimeRelationEntity::DateTime, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation datée et valuée.
#define ENUM_ValeurDateTimeRelationEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = ValeurDateTimeRelationEntity::Id, Id ## ID1 = ValeurDateTimeRelationEntity::Id1, \
    Id ## ID2 = ValeurDateTimeRelationEntity::Id2,\
    DateTime = ValeurDateTimeRelationEntity::DateTime, Valeur = ValeurDateTimeRelationEntity::Valeur, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation numéroté.
#define ENUM_NumRelationEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = NumRelationEntity::Id, Id ## ID1 = NumRelationEntity::Id1, Id ## ID2 = NumRelationEntity::Id2, Num = NumRelationEntity::Num,\
    NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation numéroté et daté.
#define ENUM_DateTimeNumRelationEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = DateTimeNumRelationEntity::Id, Id ## ID1 = DateTimeNumRelationEntity::Id1, Id ## ID2 = DateTimeNumRelationEntity::Id2,\
    Num = DateTimeNumRelationEntity::Num, DateTime = DateTimeNumRelationEntity::DateTime, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation numéroté et daté.
#define ENUM_ValeurIntDateTimeNumRelationEntity(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id = ValeurIntDateTimeNumRelationEntity::Id, Id ## ID1 = ValeurIntDateTimeNumRelationEntity::Id1,\
    Id ## ID2 = ValeurIntDateTimeNumRelationEntity::Id2, Num = ValeurIntDateTimeNumRelationEntity::Num,\
    DateTime = ValeurIntDateTimeNumRelationEntity::DateTime, Valeur = ValeurIntDateTimeNumRelationEntity::Valeur, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe de relation.
#define RELATION_ENTITY(ENTITY,MERE,IDT,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public MERE \
    {public: \
    using MERE::MERE; \
    using MERE::operator ==; \
    ENUM_##MERE(ID1,ID2) \
    BASE_ENTITY(ENTITY,IDT) \
    RELATION_ALIAS_2_CLE(ID1,ID2)};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés.
 */
class RelationEntity : public Entity
{
    ATTRIBUT_ENTITY_ID(1)
    ATTRIBUT_ENTITY_ID(2)
public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Id1 = Entity::NbrAtt,
                   Id2,
                   NbrAtt};

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
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Id1 = Entity::NbrAtt,
                   Id2,
                   NbrAtt};

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
    ATTRIBUT_ENTITY_DATETIME(DateTime,dateTime)
public:
    //! Positions des attributs.
    enum Position {Id = RelationEntity::Id,
                   Id1 = RelationEntity::Id1,
                   Id2 = RelationEntity::Id2,
                   DateTime = RelationEntity::NbrAtt,
                   NbrAtt};

    using RelationEntity::RelationEntity;
    BASE_ENTITY_ABS(DateTimeRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    DateTimeRelationEntity(int id1, int id2, const QDateTime & dateTime, int id = 0)
        : RelationEntity(id1, id2, id), m_dateTime(dateTime) {}

    MEMBRE_ATT_1(DateTimeRelationEntity,RelationEntity,DateTime,dateTime)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés et des attributs date valide et valeur.
 */
class ValeurDateTimeRelationEntity : public DateTimeRelationEntity
{
    ATTRIBUT_ENTITY_VARIANT(Valeur,valeur)
public:
    //! Positions des attributs.
    enum Position {Id = DateTimeRelationEntity::Id,
                   Id1 = DateTimeRelationEntity::Id1,
                   Id2 = DateTimeRelationEntity::Id2,
                   DateTime = DateTimeRelationEntity::DateTime,
                   Valeur = DateTimeRelationEntity::NbrAtt,
                   NbrAtt};

    using DateTimeRelationEntity::DateTimeRelationEntity;
    BASE_ENTITY_ABS(ValeurDateTimeRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    ValeurDateTimeRelationEntity(int id1, int id2, const QDateTime & date, const QVariant & valeur, int id = 0)
        : DateTimeRelationEntity(id1, id2, date, id), m_valeur(valeur) {}

    //! Constructeur à partir des valeurs attributs.
    ValeurDateTimeRelationEntity(int id1, int id2, const QVariant & valeur, int id = 0)
        : DateTimeRelationEntity(id1, id2, id), m_valeur(valeur) {}

    MEMBRE_ATT_1(ValeurDateTimeRelationEntity,DateTimeRelationEntity,Valeur,valeur)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités possédant deux clés et un attribut numéro.
 */
class NumRelationEntity : public RelationEntity
{
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    //! Positions des attributs.
    enum Position {Id = RelationEntity::Id,
                   Id1 = RelationEntity::Id1,
                   Id2 = RelationEntity::Id2,
                   Num = RelationEntity::NbrAtt,
                   NbrAtt};

    BASE_ENTITY_ABS(NumRelationEntity)

    //! Constructeur.
    NumRelationEntity(int id)
        : RelationEntity(id) {}

    //! Constructeur à partir des valeurs attributs.
    NumRelationEntity(int id1, int id2, int num = 0, int id = 0)
        : RelationEntity(id1, id2, id), m_num(num) {}

    MEMBRE_ATT_1(NumRelationEntity,RelationEntity,Num,num)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités possédant deux clés, un attribut datetime et numéro.
 */
class DateTimeNumRelationEntity : public NumRelationEntity
{
    ATTRIBUT_ENTITY_DATETIME(DateTime,dateTime)
public:
    //! Positions des attributs.
    enum Position {Id = NumRelationEntity::Id,
                   Id1 = NumRelationEntity::Id1,
                   Id2 = NumRelationEntity::Id2,
                   Num = NumRelationEntity::Num,
                   DateTime = NumRelationEntity::NbrAtt,
                   NbrAtt};
    using NumRelationEntity::NumRelationEntity;
    BASE_ENTITY_ABS(DateTimeNumRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    DateTimeNumRelationEntity(int id1, int id2, const QDateTime & date, int num, int id = 0)
        : NumRelationEntity(id1, id2, num, id), m_dateTime(date) {}

    MEMBRE_ATT_1(DateTimeNumRelationEntity,NumRelationEntity,DateTime,dateTime)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités possédant deux clés, un attribut datetime, numéro et valeur (entier).
 */
class ValeurIntDateTimeNumRelationEntity : public DateTimeNumRelationEntity
{
    ATTRIBUT_ENTITY_INT(Valeur,valeur)
public:
    //! Positions des attributs.
    enum Position {Id = DateTimeNumRelationEntity::Id,
                   Id1 = DateTimeNumRelationEntity::Id1,
                   Id2 = DateTimeNumRelationEntity::Id2,
                   Num = DateTimeNumRelationEntity::Num,
                   DateTime = DateTimeNumRelationEntity::DateTime,
                   Valeur = DateTimeNumRelationEntity::NbrAtt,
                   NbrAtt};

    using DateTimeNumRelationEntity::DateTimeNumRelationEntity;
    BASE_ENTITY_ABS(ValeurIntDateTimeNumRelationEntity)

    //! Constructeur à partir des valeurs attributs.
    ValeurIntDateTimeNumRelationEntity(int id1, int id2, const QDateTime & date, int num, int valeur, int id = 0)
        : DateTimeNumRelationEntity(id1, id2, date, num, id), m_valeur(valeur) {}

    //! Constructeur à partir des valeurs attributs.
    ValeurIntDateTimeNumRelationEntity(int id1, int id2, int num, int valeur, int id = 0)
        : DateTimeNumRelationEntity(id1, id2, num, id), m_valeur(valeur) {}

    MEMBRE_ATT_1(ValeurIntDateTimeNumRelationEntity,DateTimeNumRelationEntity,Valeur,valeur)
};

#endif // ENTITYRELATION
