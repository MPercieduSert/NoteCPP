/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYDIVERS
#define ENTITYDIVERS

#include "AttributMultiple.h"
#include "Entity.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut dateTime et Num.
 */
template<class DateTimeAtt, int IDM> class DateTimeNumEntity : public EntityAttributsID<Attributs<DateTimeAtt,NumAttribut>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,DateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,DateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   Num = PositionEnum<NumAttribut,DateTimeNumEntity<DateTimeAtt,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<DateTimeAtt,NumAttribut>,IDM>;
    using EntityAttributsID<Attributs<DateTimeAtt,NumAttribut>,IDM>::EntityAttributsID;
    using EAID::setDateTime;
    using EAID::setNum;
    BASE_ENTITY(DateTimeNumEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    DateTimeNumEntity(int num, int id)
        : EAID(id)
        {setNum(num);}

    //! Constructeur à partir des valeurs attributs.
    DateTimeNumEntity(const QDateTime & dateTime, int num, int id = 0)
        : DateTimeNumEntity(num, id)
        {setDateTime(dateTime);}
};

template<int IDM> using DateTimeCurrentNumEntity = DateTimeNumEntity<DateTimeCurrentAttribut,IDM>;
template<int IDM> using DateTimeValideNumEntity = DateTimeNumEntity<DateTimeValideAttribut,IDM>;

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et nc.
 */
template<int IDM> class NcNomEntity : public EntityAttributsID<NcNomAttribut,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,NcNomEntity<IDM>>::Position,
                   Nc = PositionEnum<NcAttribut,NcNomEntity<IDM>>::Position,
                   Nom = PositionEnum<NomAttribut,NcNomEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<NcNomAttribut,IDM>;
    using EntityAttributsID<NcNomAttribut,IDM>::EntityAttributsID;
    using EAID::setNc;
    using EAID::setNom;
    BASE_ENTITY(NcNomEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    NcNomEntity(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    NcNomEntity(const QString & nc, const QString & nom, int id = 0)
        : NcNomEntity(nom, id)
        {setNc(nc);}
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant des attributs nc, nom et type.
 */
template<int IDM> class NcNomTypeEntity : public EntityAttributsID<NcNomTypeAttribut,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,NcNomTypeEntity<IDM>>::Position,
                   Nc = PositionEnum<NcAttribut,NcNomTypeEntity<IDM>>::Position,
                   Nom = PositionEnum<NomAttribut,NcNomTypeEntity<IDM>>::Position,
                   Type = PositionEnum<TypeAttribut,NcNomTypeEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<NcNomTypeAttribut,IDM>;
    using EntityAttributsID<NcNomTypeAttribut,IDM>::EntityAttributsID;
    using EAID::setNc;
    using EAID::setNom;
    using EAID::setType;
    BASE_ENTITY(NcNomTypeEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    NcNomTypeEntity(const QString & nom)
        {setNom(nom);}

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    NcNomTypeEntity(const QString & nom, int type)
        : NcNomTypeEntity(nom)
        {setType(type);}

    //! Constructeur à partir des valeurs attributs.
    NcNomTypeEntity(const QString & nc, const QString & nom, int type, int id = 0)
        : EAID(id)
    {
        setNc(nc);
        setNom(nom);
        setType(type);
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom.
 */
template<int IDM> class NomEntity : public EntityAttributsID<NomAttribut,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,NomEntity<IDM>>::Position,
                   Nom = PositionEnum<NomAttribut,NomEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<NomAttribut,IDM>;
    using EntityAttributsID<NomAttribut,IDM>::EntityAttributsID;
    using EAID::setNom;
    BASE_ENTITY(NomEntity)

    //! Constructeur à partir des valeurs attributs.
    NomEntity(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut nom et type.
 */
template<int IDM> class NomTypeEntity : public EntityAttributsID<NomTypeAttribut,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,NomTypeEntity<IDM>>::Position,
                   Nom = PositionEnum<NomAttribut,NomTypeEntity<IDM>>::Position,
                   Type = PositionEnum<TypeAttribut,NomTypeEntity<IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<NomTypeAttribut,IDM>;
    using EntityAttributsID<NomTypeAttribut,IDM>::EntityAttributsID;
    using EAID::setNom;
    using EAID::setType;
    BASE_ENTITY(NomTypeEntity)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    NomTypeEntity(const QString & nom)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    NomTypeEntity(const QString & nom, int type, int id = 0)
        : EAID(id)
    {
        setNom(nom);
        setType(type);
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités ayant un attribut Texte et DateTime.
 */
template<class DateTimeAtt, int IDM> class TexteDateTimeEntity : public EntityAttributsID<Attributs<TexteAttribut,DateTimeAtt>,IDM>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,TexteDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   Texte = PositionEnum<TexteAttribut,TexteDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   DateTime = PositionEnum<DateTimeAtt,TexteDateTimeEntity<DateTimeAtt,IDM>>::Position,
                   NbrAtt};
    using EAID = EntityAttributsID<Attributs<TexteAttribut,DateTimeAtt>,IDM>;
    using EntityAttributsID<Attributs<TexteAttribut,DateTimeAtt>,IDM>::EntityAttributsID;
    using EAID::setDateTime;
    using EAID::setTexte;
    BASE_ENTITY(TexteDateTimeEntity)

    //! Constructeur à partir des valeurs attributs.
    TexteDateTimeEntity(const QString & texte, int id = 0)
        : EAID(id)
        {setTexte(texte);}

    //! Constructeur à partir des valeurs attributs.
    TexteDateTimeEntity(const QDateTime & dateTime, const QString & texte, int id = 0)
        : TexteDateTimeEntity(texte,id)
        {setDateTime(dateTime);}
};

#endif // ENTITYDIVERS
