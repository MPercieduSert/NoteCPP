/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYCIBLE_H
#define ENTITYCIBLE_H

#include "Arbre.h"
#include "AttributMultiple.h"
#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro implémentant une classe de ayant une clé.
#define ID1_ENTITY(ENTITY,TYPE,IDT,ID1) \
    /*! \ingroup groupeEntity \brief Représentation de l'entité ENTITY.*/ \
    class ENTITY : public TYPE##Entity<IDT> \
    {public: \
    using TYPE##Entity<IDT>::TYPE##Entity; \
    using mere = TYPE##Entity<IDT>; \
    using mere::operator ==; \
    ENUM_##TYPE(ID1) \
    BASE_ENTITY(ENTITY) \
    ALIAS_CLE(ID1,1)};

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé étrangère, un parent, un idProg, un nom cours et un nom.
#define ENUM_IdArbreSimpleIdprogNcNomTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, Parent = mere::Parent, Cible = mere::IdProg, Nc == mere::Nc, Nom = mere::Nom, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, parent, idProg, nom cours et nom.
 */
template<class Id1Att, int IDM> class IdArbreSimpleIdprogNcNomEntityTemp : public EntityAttributsID<Attributs<Id1Att,ArbreSimpleAttribut,IdProgAttribut,NcNomAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,IdArbreSimpleIdprogNcNomEntityTemp<Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,IdArbreSimpleIdprogNcNomEntityTemp<Id1Att,IDM>>::Position,
                   Parent = PositionEnum<ArbreSimpleAttribut,IdArbreSimpleIdprogNcNomEntityTemp<Id1Att,IDM>>::Position,
                   IdProg = PositionEnum<IdProgAttribut,IdArbreSimpleIdprogNcNomEntityTemp<Id1Att,IDM>>::Position,
                   Nc = PositionEnum<NcAttribut,IdArbreSimpleIdprogNcNomEntityTemp<Id1Att,IDM>>::Position,
                   Nom = PositionEnum<NomAttribut,IdArbreSimpleIdprogNcNomEntityTemp<Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,ArbreSimpleAttribut,IdProgAttribut,NcNomAttribut>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,ArbreSimpleAttribut,IdProgAttribut,NcNomAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setIdProg;
    using EAID::setNc;
    using EAID::setNom;
    using EAID::setParent;
    BASE_ENTITY(IdArbreSimpleIdprogNcNomEntityTemp)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    IdArbreSimpleIdprogNcNomEntityTemp(int idProg, int id = 0)
        : EAID(id)
        {setIdProg(idProg);}

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    IdArbreSimpleIdprogNcNomEntityTemp(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    IdArbreSimpleIdprogNcNomEntityTemp(int id1, const QString & nc, const QString & nom, int parent, int idProg, int id = 0)
        : EAID(id, nom)
    {
        setId1(id1);
        setIdProg(idProg);
        setNc(nc);
        setParent(parent);
    }
};

template<int IDM> using IdArbreSimpleIdprogNcNomEntity = IdArbreSimpleIdprogNcNomEntityTemp<Id1Attribut,IDM>;
#define ENUM_IdArbreSimpleIdprogNcNom(ID1) ENUM_IdArbreSimpleIdprogNcNomTemp(ID1)

template<int IDM> using IdNullArbreSimpleIdprogNcNomEntity = IdArbreSimpleIdprogNcNomEntityTemp<Id1NullAttribut,IDM>;
#define ENUM_IdNullArbreSimpleIdprogNcNom(ID1) ENUM_IdArbreSimpleIdprogNcNomTemp(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé étrangère, une creation, une modification et un numéro.
#define ENUM_IdCreationModifNumTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, Creation = mere::Creation, Modification = mere::Modification, Num = mere::Num, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, creation, modification, et num.
 */
template<class Id1Att, int IDM> class IdCreationModifNumEntityTemp : public EntityAttributsID<Attributs<Id1Att,CreationAttribut,ModificationAttribut,NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,IdCreationModifNumEntityTemp<Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,IdCreationModifNumEntityTemp<Id1Att,IDM>>::Position,
                   Creation = PositionEnum<CreationAttribut,IdCreationModifNumEntityTemp<Id1Att,IDM>>::Position,
                   Modification = PositionEnum<ModificationAttribut,IdCreationModifNumEntityTemp<Id1Att,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,IdCreationModifNumEntityTemp<Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,CreationAttribut,ModificationAttribut,NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,CreationAttribut,ModificationAttribut,NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setCreation;
    using EAID::setModification;
    using EAID::setNum;
    BASE_ENTITY(IdCreationModifNumEntityTemp)

    //! Constructeur à partir des valeurs attributs.
    IdCreationModifNumEntityTemp(int id1, const QDateTime & creation, const QDateTime & modif, int num, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setCreation(creation);
        setModification(modif);
        setNum(num);
    }
};

template<int IDM> using IdCreationModifNumEntity = IdCreationModifNumEntityTemp<Id1Attribut,IDM>;
#define ENUM_IdCreationModifNum(ID1) ENUM_IdCreationModifNumTemp(ID1)

template<int IDM> using IdNullCreationModifNumEntity = IdCreationModifNumEntityTemp<Id1NullAttribut,IDM>;
#define ENUM_IdNullCreationModifNum(ID1) ENUM_IdCreationModifNumTemp(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, une clé de cible et une cible.
#define ENUM_CibleTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, IdCible = mere::IdCible, Cible = mere::Cible, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, idCible et Cible.
 */
template<class Id1Att, int IDM> class CibleEntityTemp : public EntityAttributsID<Attributs<Id1Att,CibleAttributs>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,CibleEntityTemp<Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,CibleEntityTemp<Id1Att,IDM>>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,CibleEntityTemp<Id1Att,IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,CibleEntityTemp<Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,CibleAttributs>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,CibleAttributs>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setIdCible;
    using EAID::setCible;
    BASE_ENTITY(CibleEntityTemp)

    //! Constructeur à partir des valeurs attributs.
    CibleEntityTemp(int id1, int idCible, int cible, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setIdCible(idCible);
        setCible(cible);
    }
};

template<int IDM> using CibleEntity = CibleEntityTemp<Id1Attribut,IDM>;
#define ENUM_Cible(ID1) ENUM_CibleTemp(ID1)

template<int IDM> using CibleNullEntity = CibleEntityTemp<Id1NullAttribut,IDM>;
#define ENUM_CibleNull(ID1) ENUM_CibleTemp(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, une clé de cible, une cible, un numéro et un type.
#define ENUM_CibleNumTypeTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, IdCible = mere::IdCible, Cible = mere::Cible, Num = mere::Num, Type = mere::Type, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, idCible, Cible, Num et Type.
 */
template<class Id1Att, int IDM> class CibleNumTypeEntityTemp : public EntityAttributsID<Attributs<Id1Att,CibleAttributs,NumAttribut,TypeAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,CibleNumTypeEntityTemp<Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,CibleNumTypeEntityTemp<Id1Att,IDM>>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,CibleNumTypeEntityTemp<Id1Att,IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,CibleNumTypeEntityTemp<Id1Att,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,CibleNumTypeEntityTemp<Id1Att,IDM>>::Position,
                   Type = PositionEnum<TypeAttribut,CibleNumTypeEntityTemp<Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,CibleAttributs,NumAttribut,TypeAttribut>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,CibleAttributs,NumAttribut,TypeAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setIdCible;
    using EAID::setCible;
    using EAID::setNum;
    using EAID::setType;
    BASE_ENTITY(CibleNumTypeEntityTemp)

    //! Constructeur à partir des valeurs attributs.
    CibleNumTypeEntityTemp(int idCible, int cible, int num, int type, int id = 0)
        : EAID(id)
    {
        setIdCible(idCible);
        setCible(cible);
        setNum(num);
        setType(type);
    }

    //! Constructeur à partir des valeurs attributs.
    CibleNumTypeEntityTemp(int id1, int idCible, int cible, int num, int type, int id = 0)
        : CibleNumTypeEntityTemp(idCible, cible, num, type, id)
        {setId1(id1);}
};

template<int IDM> using CibleNumTypeEntity = CibleNumTypeEntityTemp<Id1Attribut,IDM>;
#define ENUM_CibleNumType(ID1) ENUM_CibleNumTypeTemp(ID1)

template<int IDM> using CibleNullNumTypeEntity = CibleNumTypeEntityTemp<Id1NullAttribut,IDM>;
#define ENUM_CibleNullNumType(ID1) ENUM_CibleNumTypeTemp(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, une clé de cible, une cible et une DateTime.
#define ENUM_CibleDateTimeTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, IdCible = mere::IdCible, Cible = mere::Cible, DateTime = mere::DateTime, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, idCible, Cible et DateTime.
 */
template<class DateTimeAtt, class Id1Att, int IDM> class CibleDateTimeEntityTemp : public EntityAttributsID<Attributs<Id1Att,CibleAttributs,DateTimeAtt>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,CibleDateTimeEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,CibleDateTimeEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,CibleDateTimeEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,CibleDateTimeEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,CibleDateTimeEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,CibleAttributs,DateTimeAtt>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,CibleAttributs,DateTimeAtt>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setIdCible;
    using EAID::setCible;
    using EAID::setDateTime;
    BASE_ENTITY(CibleDateTimeEntityTemp)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    CibleDateTimeEntityTemp(int id1, int idCible, int cible, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setIdCible(idCible);
        setCible(cible);
    }

    //! Constructeur à partir des valeurs attributs.
    CibleDateTimeEntityTemp(int id1, int idCible, int cible, const QDateTime & dateTime, int id = 0)
        : CibleDateTimeEntityTemp(id1,idCible,cible,id)
        {setDateTime(dateTime);}
};

template<int IDM> using CibleDateTimeCurrentEntity = CibleDateTimeEntityTemp<DateTimeCurrentAttribut,Id1Attribut,IDM>;
#define ENUM_CibleDateTimeCurrent(ID1) ENUM_CibleDateTimeTemp(ID1)

template<int IDM> using CibleDateTimeValideEntity = CibleDateTimeEntityTemp<DateTimeValideAttribut,Id1Attribut,IDM>;
#define ENUM_CibleDateTimeValide(ID1) ENUM_CibleDateTimeTemp(ID1)

template<int IDM> using CibleNullDateTimeCurrentEntity = CibleDateTimeEntityTemp<DateTimeCurrentAttribut,Id1NullAttribut,IDM>;
#define ENUM_CibleNullDateTimeCurrent(ID1) ENUM_CibleDateTimeTemp(ID1)

template<int IDM> using CibleNullDateTimeValideEntity = CibleDateTimeEntityTemp<DateTimeValideAttribut,Id1NullAttribut,IDM>;
#define ENUM_CibleNullDateTimeValide(ID1) ENUM_CibleDateTimeTemp(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, une clé de cible, une cible et une DateTime.
#define ENUM_CibleDateTimeNumTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, IdCible = mere::IdCible, Cible = mere::Cible, DateTime = mere::DateTime, Num = mere::Num, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, idCible, Cible, DateTime et Num.
 */
template<class DateTimeAtt, class Id1Att, int IDM> class CibleDateTimeNumEntityTemp : public EntityAttributsID<Attributs<Id1Att,CibleAttributs, DateTimeAtt, NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,CibleDateTimeNumEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,CibleDateTimeNumEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,CibleDateTimeNumEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,CibleDateTimeNumEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,CibleDateTimeNumEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,CibleDateTimeNumEntityTemp<DateTimeAtt,Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,CibleAttributs, DateTimeAtt, NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,CibleAttributs, DateTimeAtt, NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setIdCible;
    using EAID::setCible;
    using EAID::setDateTime;
    using EAID::setNum;
    BASE_ENTITY(CibleDateTimeNumEntityTemp)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    CibleDateTimeNumEntityTemp(int id1, int idCible, int cible, int num = 0, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setIdCible(idCible);
        setCible(cible);
        setNum(num);
    }

    //! Constructeur à partir des valeurs attributs.
    CibleDateTimeNumEntityTemp(int id1, int idCible, int cible, const QDateTime & dateTime, int num, int id = 0)
        : CibleDateTimeNumEntityTemp(id1,idCible,cible,num,id)
        {setDateTime(dateTime);}
};

template<int IDM> using CibleDateTimeCurrentNumEntity = CibleDateTimeNumEntityTemp<DateTimeCurrentAttribut,Id1Attribut,IDM>;
#define ENUM_CibleDateTimeCurrentNum(ID1) ENUM_CibleDateTimeNumTemp(ID1)

template<int IDM> using CibleDateTimeValideNumEntity = CibleDateTimeNumEntityTemp<DateTimeValideAttribut,Id1Attribut,IDM>;
#define ENUM_CibleDateTimeValideNum(ID1) ENUM_CibleDateTimeNumTemp(ID1)

template<int IDM> using CibleNullDateTimeCurrentNumEntity = CibleDateTimeNumEntityTemp<DateTimeCurrentAttribut,Id1NullAttribut,IDM>;
#define ENUM_CibleNullDateTimeCurrentNum(ID1) ENUM_CibleDateTimeNumTemp(ID1)

template<int IDM> using CibleNullDateTimeValideNumEntity = CibleDateTimeNumEntityTemp<DateTimeValideAttribut,Id1NullAttribut,IDM>;
#define ENUM_CibleNullDateTimeValideNum(ID1) ENUM_CibleDateTimeNumTemp(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, une clé de cible, une cible, une DateTime et Valeur.
#define ENUM_CibleDateTimeNumValeur(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, IdCible = mere::IdCible, Cible = mere::Cible, DateTime = mere::DateTime, Num = mere::Num, Valeur = mere::Valeur, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut IdCible, cible, datetime, num et valeur.
 */
template<class DateTimeAtt, class AttributValeur, class T, int IDM> class CibleDateTimeNumValeurEntity : public EntityAttributsID<Attributs<Id1Attribut, CibleAttributs, DateTimeAtt, NumAttribut, AttributValeur>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   Valeur = PositionEnum<AttributValeur,CibleDateTimeNumValeurEntity<DateTimeAtt,AttributValeur,T,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Attribut, CibleAttributs, DateTimeAtt, NumAttribut, AttributValeur>,IDM>;
    using EntityAttributsID<Attributs<Id1Attribut, CibleAttributs, DateTimeAtt, NumAttribut, AttributValeur>,IDM>::EntityAttributsID;
    using EAID::setId;
    using EAID::setId1;
    using EAID::setIdCible;
    using EAID::setCible;
    using EAID::setDateTime;
    using EAID::setNum;
    using EAID::setValeur;
    BASE_ENTITY(CibleDateTimeNumValeurEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    CibleDateTimeNumValeurEntity(int id1, int idCible, int cible, int num = 0)
    {
        setId1(id1);
        setIdCible(idCible);
        setCible(cible);
        setNum(num);
    }

    //! Constructeur à partir des valeurs attributs.
    CibleDateTimeNumValeurEntity(int id1, int idCible, int cible, int num, T valeur, int id = 0)
        : CibleDateTimeNumValeurEntity(id1,idCible,cible,num)
    {
        setId(id);
        setValeur(valeur);
    }

    //! Constructeur à partir des valeurs attributs.
    CibleDateTimeNumValeurEntity(int id1, int idCible, int cible, const QDateTime & dateTime, int num, T valeur, int id = 0)
        : CibleDateTimeNumValeurEntity(id1,idCible,cible,num,valeur,id)
        {setDateTime(dateTime);}
};

template<int IDM> using CibleDateTimeCurrentNumValeurDoubleEntity = CibleDateTimeNumValeurEntity<DateTimeCurrentAttribut,ValeurDoubleAttribut,double,IDM>;
#define ENUM_CibleDateTimeCurrentNumValeurDouble(ID1) ENUM_CibleDateTimeNumValeur(ID1)

template<int IDM> using CibleDateTimeCurrentNumValeurIntEntity = CibleDateTimeNumValeurEntity<DateTimeCurrentAttribut,ValeurIntAttribut,int,IDM>;
#define ENUM_CibleDateTimeCurrentNumValeurInt(ID1) ENUM_CibleDateTimeNumValeur(ID1)

template<int IDM> using CibleDateTimeCurrentNumValeurVariantEntity = CibleDateTimeNumValeurEntity<DateTimeCurrentAttribut,ValeurVariantAttribut,const QVariant &,IDM>;
#define ENUM_CibleDateTimeCurrentNumValeurVariant(ID1) ENUM_CibleDateTimeNumValeur(ID1)

template<int IDM> using CibleDateTimeValideNumValeurDoubleEntity = CibleDateTimeNumValeurEntity<DateTimeValideAttribut,ValeurDoubleAttribut,double,IDM>;
#define ENUM_CibleDateTimeValideNumValeurDouble(ID1) ENUM_CibleDateTimeNumValeur(ID1)

template<int IDM> using CibleDateTimeValideNumValeurIntEntity = CibleDateTimeNumValeurEntity<DateTimeValideAttribut,ValeurIntAttribut,int,IDM>;
#define ENUM_CibleDateTimeValideNumValeurInt(ID1) ENUM_CibleDateTimeNumValeur(ID1)

template<int IDM> using CibleDateTimeValideNumValeurVariantEntity = CibleDateTimeNumValeurEntity<DateTimeValideAttribut,ValeurVariantAttribut,const QVariant &,IDM>;
#define ENUM_CibleDateTimeValideNumValeurVariant(ID1) ENUM_CibleDateTimeNumValeur(ID1)

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, num et Valeur.
#define ENUM_IdNumValeur(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id, Id1, Num, Valeur, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé, num et valeur.
 */
template<class AttributValeur, class T, int IDM> class IdNumValeurEntity : public EntityAttributsID<IdNumValeurAttribut<AttributValeur>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,IdNumValeurEntity<AttributValeur,T,IDM>>::Position,
                   Id1 = PositionEnum<Id1Attribut,IdNumValeurEntity<AttributValeur,T,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,IdNumValeurEntity<AttributValeur,T,IDM>>::Position,
                   Valeur = PositionEnum<AttributValeur,IdNumValeurEntity<AttributValeur,T,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<IdNumValeurAttribut<AttributValeur>,IDM>;
    using EntityAttributsID<IdNumValeurAttribut<AttributValeur>,IDM>::EntityAttributsID;
    using EAID::setId;
    using EAID::setId1;
    using EAID::setNum;
    BASE_ENTITY(IdNumValeurEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    IdNumValeurEntity(int id1, int num)
    {
        setId1(id1);
        setNum(num);
    }

    //! Constructeur à partir des valeurs attributs.
    IdNumValeurEntity(int id1, int num, T valeur, int id = 0)
        : IdNumValeurEntity(id1,num)
    {
        setId(id);
        setValeur(valeur);
    }
};

#define ENUM_IdNumValeurDouble(ID1) ENUM_IdNumValeur(ID1)
template<int IDM> using IdNumValeurDoubleEntity = IdNumValeurEntity<ValeurDoubleAttribut,double,IDM>;

//! \ingroup groupeMacroEntity
//! Macro définissant les positions des attributs pour une clé, une cible et un num.
#define ENUM_IdCibleNumTemp(ID1) /*! \brief Positions des attributs */ \
    enum Position {Id = mere::Id, Id1 = mere::Id1, Cible = mere::Cible, NbrAtt, Id ## ID1 = Id1};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut clé étrangère, idCible et Cible.
 */
template<class Id1Att, int IDM> class IdCibleNumEntityTemp : public EntityAttributsID<Attributs<Id1Att,CibleAttribut,NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,IdCibleNumEntityTemp<Id1Att,IDM>>::Position,
                   Id1 = PositionEnum<Id1Att,IdCibleNumEntityTemp<Id1Att,IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,IdCibleNumEntityTemp<Id1Att,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,IdCibleNumEntityTemp<Id1Att,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<Id1Att,CibleAttribut,NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<Id1Att,CibleAttribut,NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setId1;
    using EAID::setCible;
    using EAID::setNum;
    BASE_ENTITY(IdCibleNumEntityTemp)

    //! Constructeur à partir des valeurs attributs.
    IdCibleNumEntityTemp(int id1, int cible, int num, int id = 0)
        : EAID(id)
    {
        setId1(id1);
        setCible(cible);
        setNum(num);
    }
};

template<int IDM> using IdCibleNumEntity = IdCibleNumEntityTemp<Id1Attribut,IDM>;
#define ENUM_IdCibleNum(ID1) ENUM_IdCibleNumTemp(ID1)

template<int IDM> using IdNullCibleNumEntity = IdCibleNumEntityTemp<Id1NullAttribut,IDM>;
#define ENUM_IdNullCibleNum(ID1) ENUM_IdCibleNumTemp(ID1)

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut idCible, cible et num.
 */
template<int IDM> class CibleSimpleNumEntity : public EntityAttributsID<Attributs<IdCibleAttribut,CibleAttribut,NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,CibleSimpleNumEntity<IDM>>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,CibleSimpleNumEntity<IDM>>::Position,
                   Cible = PositionEnum<CibleAttribut,CibleSimpleNumEntity<IDM>>::Position,
                   Num = PositionEnum<NumAttribut,CibleSimpleNumEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<IdCibleAttribut,CibleAttribut,NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<IdCibleAttribut,CibleAttribut,NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setIdCible;
    using EAID::setCible;
    using EAID::setNum;
    BASE_ENTITY(CibleSimpleNumEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    CibleSimpleNumEntity(int idCible, int cible)
    {
        setIdCible(idCible);
        setCible(cible);
    }

    //! Constructeur à partir des valeurs attributs.
    CibleSimpleNumEntity(int idCible, int cible, int num, int id = 0)
        : EAID(id)
    {
        setIdCible(idCible);
        setCible(cible);
        setNum(num);
    }
};

#endif // ENTITYCIBLE_H
