/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYCIBLE_H
#define ENTITYCIBLE_H

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une Cible.
#define ENUM_CibleEntity(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = CibleEntity::Id, Id ## ID1 = CibleEntity::Id1, IdCible = CibleEntity::IdCible, Cible = CibleEntity::Cible, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une Cible daté.
#define ENUM_DateTimeCibleEntity(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = DateTimeCibleEntity::Id, Id ## ID1 = DateTimeCibleEntity::Id1, IdCible = DateTimeCibleEntity::IdCible,\
    Cible = DateTimeCibleEntity::Cible, DateTime = DateTimeCibleEntity::DateTime, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une Cible daté et numeroté.
#define ENUM_NumDateTimeCibleEntity(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = NumDateTimeCibleEntity::Id, Id ## ID1 = NumDateTimeCibleEntity::Id1, IdCible = NumDateTimeCibleEntity::IdCible,\
    Cible = NumDateTimeCibleEntity::Cible, DateTime = NumDateTimeCibleEntity::DateTime, Num = NumDateTimeCibleEntity::Num, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une Cible daté, numeroté et valué.
#define ENUM_ValeurNumDateTimeCibleEntity(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = ValeurNumDateTimeCibleEntity::Id, Id ## ID1 = ValeurNumDateTimeCibleEntity::Id1,\
    IdCible = ValeurNumDateTimeCibleEntity::IdCible, Cible = ValeurNumDateTimeCibleEntity::Cible, DateTime = ValeurNumDateTimeCibleEntity::DateTime,\
    Num = ValeurNumDateTimeCibleEntity::Num, Valeur = ValeurNumDateTimeCibleEntity::Valeur, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe de relation.
#define CIBLE_ENTITY(ENTITY,MERE,IDT,ID1) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public MERE \
    {public: \
    using MERE::MERE; \
    using MERE::operator ==;\
    ENUM_##MERE(ID1) \
    BASE_ENTITY(ENTITY,IDT) \
    ALIAS_CLE(ID1,1)};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut idCible et cible.
 */
class CibleEntity : public Entity
{
    ATTRIBUT_ENTITY_ID(1)
    ATTRIBUT_ENTITY_ID(Cible)
    ATTRIBUT_ENTITY_INT_SUP(Cible,cible,0)

public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Id1 = Entity::NbrAtt,
                   IdCible,
                   Cible,
                   NbrAtt};

    using Entity::Entity;
    BASE_ENTITY_ABS(CibleEntity)

    //! Constructeur à partir des valeurs attributs.
    CibleEntity(int id1, int idCible, int cible, int id = 0)
        : Entity(id), m_id1(id1), m_idCible(idCible), m_cible(cible) {}

    MEMBRE_ATT_3(CibleEntity,Entity,Id1,id1,IdCible,idCible,Cible,cible)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut IdCible, cible et datetime.
 */
class DateTimeCibleEntity : public CibleEntity
{
    ATTRIBUT_ENTITY_DATETIME(DateTime,dateTime)
public:
    //! Positions des attributs.
    enum Position {Id = CibleEntity::Id,
                   Id1 = CibleEntity::Id1,
                   IdCible = CibleEntity::IdCible,
                   Cible = CibleEntity::Cible,
                   DateTime = CibleEntity::NbrAtt,
                   NbrAtt};

    using CibleEntity::CibleEntity;
    BASE_ENTITY_ABS(DateTimeCibleEntity)

    //! Constructeur à partir des valeurs attributs.
    DateTimeCibleEntity(int id1,int idCible, int cible, const QDateTime & dateTime, int id = 0)
        : CibleEntity(id1,idCible,cible,id), m_dateTime(dateTime) {}

    MEMBRE_ATT_1(DateTimeCibleEntity,CibleEntity,DateTime,dateTime)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut IdCible, cible, datetime et num.
 */
class NumDateTimeCibleEntity : public DateTimeCibleEntity
{
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    //! Positions des attributs.
    enum Position {Id = DateTimeCibleEntity::Id,
                   Id1 = DateTimeCibleEntity::Id1,
                   IdCible = DateTimeCibleEntity::IdCible,
                   Cible = DateTimeCibleEntity::Cible,
                   DateTime = DateTimeCibleEntity::DateTime,
                   Num = DateTimeCibleEntity::NbrAtt,
                   NbrAtt};

    BASE_ENTITY_ABS(NumDateTimeCibleEntity)

    //! Constructeur par l'identifiant.
    NumDateTimeCibleEntity(int id)
        : DateTimeCibleEntity(id) {}

    //! Constructeur à partir des valeurs des attributs uniques.
    NumDateTimeCibleEntity(int id1,int idCible, int cible, int num)
        : DateTimeCibleEntity(id1,idCible,cible), m_num(num) {}

    //! Constructeur à partir des valeurs attributs.
    NumDateTimeCibleEntity(int id1, int idCible, int cible, const QDateTime & dateTime, int num, int id = 0)
        : DateTimeCibleEntity(id1,idCible,cible,dateTime,id), m_num(num) {}

    MEMBRE_ATT_1(NumDateTimeCibleEntity,DateTimeCibleEntity,Num,num)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut IdCible, cible, datetime, num et valeur.
 */
class ValeurNumDateTimeCibleEntity : public NumDateTimeCibleEntity
{
    ATTRIBUT_ENTITY_VARIANT(Valeur,valeur)
public:
    //! Positions des attributs.
    enum Position {Id = NumDateTimeCibleEntity::Id,
                   Id1 = NumDateTimeCibleEntity::Id1,
                   IdCible = NumDateTimeCibleEntity::IdCible,
                   Cible = NumDateTimeCibleEntity::Cible,
                   DateTime = NumDateTimeCibleEntity::DateTime,
                   Num = NumDateTimeCibleEntity::Num,
                   Valeur = NumDateTimeCibleEntity::NbrAtt,
                   NbrAtt};

    using NumDateTimeCibleEntity::NumDateTimeCibleEntity;
    BASE_ENTITY_ABS(ValeurNumDateTimeCibleEntity)

    //! Constructeur à partir des valeurs attributs.
    ValeurNumDateTimeCibleEntity(int id1, int idCible, int cible, const QDateTime & dateTime, int num, const QVariant & val, int id = 0)
        : NumDateTimeCibleEntity(id1,idCible,cible,dateTime,num,id), m_valeur(val) {}

    //! Constructeur à partir des valeurs attributs.
    ValeurNumDateTimeCibleEntity(int id1, int idCible, int cible, int num, const QVariant & val)
        : NumDateTimeCibleEntity(id1,idCible,cible,num), m_valeur(val) {}

    MEMBRE_ATT_1(ValeurNumDateTimeCibleEntity,NumDateTimeCibleEntity,Valeur,valeur)
};
#endif // ENTITYCIBLE_H
