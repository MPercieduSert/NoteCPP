/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYDIVERS
#define ENTITYDIVERS

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe ayant les attribut id1, num et valeur.
#define VAL_TYPE_ID_NUM_ENTITY(NOM,TVAL,TYPE) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class Valeur##NOM##IdNumEntity : public IdNumEntity \
    {ATTRIBUT_ENTITY_##TVAL(Valeur,valeur) \
    public: \
    /*! Positions des attributs.*/ \
    enum Position {Id = IdNumEntity::Id, Num = IdNumEntity::Num, Id1 = IdNumEntity::Id1, Valeur = IdNumEntity::NbrAtt,NbrAtt}; \
    using IdNumEntity::IdNumEntity; \
    BASE_ENTITY_ABS(Valeur##NOM##IdNumEntity) \
    /*! Constructeur à partir des valeurs attributs.*/ \
    Valeur##NOM##IdNumEntity(int id1, int num, TYPE valeur, int id = 0) : IdNumEntity(id1,num,id), m_valeur(valeur) {} \
    MEMBRE_ATT_1(Valeur##NOM##IdNumEntity,IdNumEntity,Valeur,valeur)};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une entité de type IdNum.
#define ENUM_IdNum(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = IdNumEntity::Id, Num = IdNumEntity::Num, Id ## ID1 = IdNumEntity::Id1, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une entité de type IdNum.
#define ENUM_ValIdNum(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = IdNumEntity::Id, Num = IdNumEntity::Num, Id ## ID1 = IdNumEntity::Id1, Valeur = IdNumEntity::NbrAtt, NbrAtt};

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe de ayant un identifiant.
#define ID1_ENTITY(ENTITY,MERE,TPENUM,IDT,ID1) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public MERE \
    {public: \
    using MERE::MERE; \
    ENUM_##TPENUM(ID1) \
    BASE_ENTITY(ENTITY,IDT) \
    ALIAS_CLE(ID1,1)};

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe de ayant un identifiant et un num.
#define ID_NUM_ENTITY(ENTITY,IDT,ID1) ID1_ENTITY(ENTITY,IdNumEntity,IdNum,IDT,ID1)

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe de ayant un identifiant, un num et une valeur.
#define VAL_ID_NUM_ENTITY(ENTITY,MERE,IDT,ID1) ID1_ENTITY(ENTITY,MERE,ValIdNum,IDT,ID1)

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut num.
 */
class NumEntity : public Entity
{
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Num = Entity::NbrAtt,
                   NbrAtt};

    using Entity::Entity;
    BASE_ENTITY_ABS(NumEntity)

    //! Constructeur à partir des valeurs attributs.
    NumEntity(int num, int id)
        : Entity(id), m_num(num) {}

    MEMBRE_ATT_1(NumEntity,Entity,Num,num)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut datetime et num.
 */
class DateTimeNumEntity : public NumEntity
{
    ATTRIBUT_ENTITY_DATETIME(DateTime,dateTime)
public:
    //! Positions des attributs.
    enum Position {Id = NumEntity::Id,
                   Num = NumEntity::Num,
                   DateTime = NumEntity::NbrAtt,
                   NbrAtt};

    using NumEntity::NumEntity;
    BASE_ENTITY_ABS(DateTimeNumEntity)

    //! Constructeur à partir des valeurs attributs.
    DateTimeNumEntity(const QDateTime & dateTime, int num, int id = 0)
        : NumEntity(num,id), m_dateTime(dateTime) {}

    MEMBRE_ATT_1(DateTimeNumEntity,NumEntity,DateTime,dateTime)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut identifiant et num.
 */
class IdNumEntity : public NumEntity
{
    ATTRIBUT_ENTITY_ID(1)
public:
    //! Positions des attributs.
    enum Position {Id = NumEntity::Id,
                   Num = NumEntity::Num,
                   Id1 = NumEntity::NbrAtt,
                   NbrAtt};

    BASE_ENTITY_ABS(IdNumEntity)
    //! Constructeur avec identifiant.
    IdNumEntity(int id)
        : NumEntity(id) {}

    //! Constructeur à partir des valeurs attributs.
    IdNumEntity(int id1, int num, int id = 0)
        : NumEntity(num,id), m_id1(id1) {}

    MEMBRE_ATT_1(IdNumEntity,NumEntity,Id1,id1)
};

VAL_TYPE_ID_NUM_ENTITY(Int,INT,int)
VAL_TYPE_ID_NUM_ENTITY(Double,DOUBLE,double)
VAL_TYPE_ID_NUM_ENTITY(,VARIANT,const QVariant &)

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut texte.
 */
class TexteEntity : public Entity
{
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Texte,texte)
public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Texte = Entity::NbrAtt,
                   NbrAtt};

    using Entity::Entity;
    BASE_ENTITY_ABS(TexteEntity)

    //! Constructeur à partir des valeurs attributs.
    TexteEntity(const QString & txt, int id = 0)
        : Entity(id), m_texte(txt) {}

    MEMBRE_ATT_1(TexteEntity,Entity,Texte,texte)
};

#endif // ENTITYDIVERS
