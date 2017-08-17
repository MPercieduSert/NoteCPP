/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYRELATION
#define ENTITYRELATION

#include "AttributMultiple.h"
#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe ayant 2 clé.
#define RELATION_ENTITY(ENTITY,TYPE,IDT,ID1,ID2) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public Relation##TYPE##Entity<IDT> \
    {public: \
    using Relation##TYPE##Entity<IDT>::Relation##TYPE##Entity; \
    using Relation##TYPE##Entity<IDT>::operator ==; \
    ENUM_Relation##TYPE(ID1,ID2)\
    BASE_ENTITY(ENTITY) \
    ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)};


//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation simple.
#define ENUM_Relation(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id, Id1, Id2, NbrAtt, Id ## ID1 = Id1, Id ## ID2 = Id2};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant pour attribut deux clés.
 */
template<int IDM> class RelationEntity : public EntityAttributsID<RelationAttribut,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,RelationEntity<IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,RelationEntity<IDM>>::Position,
                   Id2 = PositionEnum<Id2Attribut,RelationEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<RelationAttribut,IDM>;
    using EntityAttributsID<RelationAttribut,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setId2;
    BASE_ENTITY(RelationEntity)

    //! Constructeur à partir des valeurs attributs.
    RelationEntity(int id1, int id2, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setId2(id2);
    }
};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation simple.
#define ENUM_RelationExactOneNotNull(ID1,ID2) ENUM_(ID1,ID2)

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant pour attribut deux clés.
 */
template<int IDM> class RelationExactOneNotNullEntity : public EntityAttributsID<RelationExactOneNotNullAttribut,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,RelationExactOneNotNullEntity<IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,RelationExactOneNotNullEntity<IDM>>::Position,
                   Id2 = PositionEnum<Id2Attribut,RelationExactOneNotNullEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<RelationExactOneNotNullAttribut,IDM>;
    using EntityAttributsID<RelationExactOneNotNullAttribut,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setId2;
    BASE_ENTITY(RelationExactOneNotNullEntity)

    //! Constructeur à partir des valeurs attributs.
    RelationExactOneNotNullEntity(int id1, int id2, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setId2(id2);
    }
};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation avec un attribut dateTime.
#define ENUM_RelationDateTime(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id, Id1, Id2, DateTime, NbrAtt, Id ## ID1 = Id1, Id ## ID2 = Id2};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant pour attribut deux clés et une dateTime.
 */
template<class DateTimeAtt, int IDM> class RelationDateTimeEntity : public EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,RelationDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,RelationDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   Id2 = PositionEnum<Id2Attribut,RelationDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,RelationDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt>,IDM>;
    using EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setId2;
    using EAID::setDateTime;
    BASE_ENTITY(RelationDateTimeEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    RelationDateTimeEntity(int id1, int id2, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setId2(id2);
    }

    //! Constructeur à partir des valeurs attributs.
    RelationDateTimeEntity(int id1, int id2, const QDateTime & dateTime, int id = 0)
        : RelationDateTimeEntity(id1, id2, id)
        {setDateTime(dateTime);}
};

template<int IDM> using RelationDateTimeCurrentEntity = RelationDateTimeEntity<DateTimeCurrentAttribut,IDM>;
#define ENUM_RelationDateTimeCurrent(ID1,ID2) ENUM_RelationDateTime(ID1,ID2)

template<int IDM> using RelationDateTimeValideEntity = RelationDateTimeEntity<DateTimeValideAttribut,IDM>;
#define ENUM_RelationDateTimeValide(ID1,ID2) ENUM_RelationDateTime(ID1,ID2)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation avec un attribut num.
#define ENUM_RelationNum(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id, Id1, Id2, Num, NbrAtt, Id ## ID1 = Id1, Id ## ID2 = Id2};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant pour attribut deux clés et un numero.
 */
template<int IDM> class RelationNumEntity : public EntityAttributsID<Attributs<RelationAttribut,NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,RelationNumEntity<IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,RelationNumEntity<IDM>>::Position,
                   Id2 = PositionEnum<Id2Attribut,RelationNumEntity<IDM>>::Position,
                   Num = PositionEnum<NumAttribut,RelationNumEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<RelationAttribut,NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<RelationAttribut,NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setId2;
    using EAID::setNum;
    BASE_ENTITY(RelationNumEntity)

    //! Constructeur à partir des valeurs attributs.
    RelationNumEntity(int id1, int id2, int num = 0, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setId2(id2);
        setNum(num);
    }
};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation avec un attribut dateTime et num.
#define ENUM_RelationDateTimeNum(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id, Id1, Id2, DateTime, Num, NbrAtt, Id ## ID1 = Id1, Id ## ID2 = Id2};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant pour attribut deux clés, une dateTime et un numero.
 */
template<class DateTimeAtt,int IDM> class RelationDateTimeNumEntity : public EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt,NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,RelationDateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,RelationDateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   Id2 = PositionEnum<Id2Attribut,RelationDateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,RelationDateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,RelationDateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt,NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt,NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setId2;
    using EAID::setDateTime;
    using EAID::setNum;
    BASE_ENTITY(RelationDateTimeNumEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    RelationDateTimeNumEntity(int id1, int id2, int num = 0, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setId2(id2);
        setNum(num);
    }

    //! Constructeur à partir des valeurs attributs.
    RelationDateTimeNumEntity(int id1, int id2, const QDateTime & dateTime, int num, int id = 0)
        : RelationDateTimeNumEntity(id1, id2, num, id)
        {setDateTime(dateTime);}
};

template<int IDM> using RelationDateTimeCurrentNumEntity = RelationDateTimeNumEntity<DateTimeCurrentAttribut,IDM>;
#define ENUM_RelationDateTimeCurrentNum(ID1,ID2) ENUM_RelationDateTimeNum(ID1,ID2)

template<int IDM> using RelationDateTimeValideNumEntity = RelationDateTimeNumEntity<DateTimeValideAttribut,IDM>;
#define ENUM_RelationDateTimeValideNum(ID1,ID2) ENUM_RelationDateTimeNum(ID1,ID2)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une relation avec un attribut dateTime, num et Valeur.
#define ENUM_RelationDateTimeNumValeur(ID1,ID2) /*! \brief Positions des attributs */ \
    enum Position {Id, Id1, Id2, DateTime, Num, NbrAtt, Id ## ID1 = Id1, Id ## ID2 = Id2};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant pour attribut deux clés, une dateTime et un numero.
 */
template<class DateTimeAtt,class ValeurAttribut,class T,int IDM> class RelationDateTimeNumValeurEntity : public EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt,NumAttribut,ValeurAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,RelationDateTimeNumValeurEntity<DateTimeAtt,ValeurAttribut,T,IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,RelationDateTimeNumValeurEntity<DateTimeAtt,ValeurAttribut,T,IDM>>::Position,
                   Id2 = PositionEnum<Id2Attribut,RelationDateTimeNumValeurEntity<DateTimeAtt,ValeurAttribut,T,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,RelationDateTimeNumValeurEntity<DateTimeAtt,ValeurAttribut,T,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,RelationDateTimeNumValeurEntity<DateTimeAtt,ValeurAttribut,T,IDM>>::Position,
                   Valeur = PositionEnum<ValeurAttribut,RelationDateTimeNumValeurEntity<DateTimeAtt,ValeurAttribut,T,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt,NumAttribut,ValeurAttribut>,IDM>;
    using EntityAttributsID<Attributs<RelationAttribut,DateTimeAtt,NumAttribut,ValeurAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setId2;
    using EAID::setDateTime;
    using EAID::setNum;
    using EAID::setValeur;
    BASE_ENTITY(RelationDateTimeNumValeurEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    RelationDateTimeNumValeurEntity(int id1, int id2, int num = 0, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setId2(id2);
        setNum(num);
    }

    //! Constructeur à partir des valeurs attributs.
    RelationDateTimeNumValeurEntity(int id1, int id2, int num, T valeur, int id = 0)
        : RelationDateTimeNumValeurEntity(id1, id2, num, id)
        {setValeur(valeur);}

    //! Constructeur à partir des valeurs attributs.
    RelationDateTimeNumValeurEntity(int id1, int id2, const QDateTime & dateTime, int num, T valeur, int id = 0)
        : RelationDateTimeNumValeurEntity(id1, id2, num, id)
    {
        setDateTime(dateTime);
        setValeur(valeur);
    }
};

template<int IDM> using RelationDateTimeCurrentNumValeurDoubleEntity = RelationDateTimeNumValeurEntity<DateTimeCurrentAttribut,ValeurDoubleAttribut,double,IDM>;
#define ENUM_RelationDateTimeCurrentNumValeurDouble(ID1,ID2) ENUM_RelationDateTimeNumValeur(ID1,ID2)

template<int IDM> using RelationDateTimeCurrentNumValeurIntEntity = RelationDateTimeNumValeurEntity<DateTimeCurrentAttribut,ValeurIntAttribut,int,IDM>;
#define ENUM_RelationDateTimeCurrentNumValeurInt(ID1,ID2) ENUM_RelationDateTimeNumValeur(ID1,ID2)

template<int IDM> using RelationDateTimeCurrentNumValeurVariantEntity = RelationDateTimeNumValeurEntity<DateTimeCurrentAttribut,ValeurVariantAttribut,const QVariant &,IDM>;
#define ENUM_RelationDateTimeCurrentNumValeurVariant(ID1,ID2) ENUM_RelationDateTimeNumValeur(ID1,ID2)

template<int IDM> using RelationDateTimeValideNumValeurDoubleEntity = RelationDateTimeNumValeurEntity<DateTimeValideAttribut,ValeurDoubleAttribut,double,IDM>;
#define ENUM_RelationDateTimeValideNumValeurDouble(ID1,ID2) ENUM_RelationDateTimeNumValeur(ID1,ID2)

template<int IDM> using RelationDateTimeValideNumValeurIntEntity = RelationDateTimeNumValeurEntity<DateTimeValideAttribut,ValeurIntAttribut,int,IDM>;
#define ENUM_RelationDateTimeValideNumValeurInt(ID1,ID2) ENUM_RelationDateTimeNumValeur(ID1,ID2)

template<int IDM> using RelationDateTimeValideNumValeurVariantEntity = RelationDateTimeNumValeurEntity<DateTimeValideAttribut,ValeurVariantAttribut,const QVariant &,IDM>;
#define ENUM_RelationDateTimeValideNumValeurVariant(ID1,ID2) ENUM_RelationDateTimeNumValeur(ID1,ID2)

#endif // ENTITYRELATION
