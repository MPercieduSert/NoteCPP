/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <array>
#include <QDate>
#include <QDateTime>
#include <QList>
#include <QPair>
#include <QString>
#include <QVariant>
#include <QVector>
#include <string>
#include <stdexcept>

#include "AttributEntityAlias.h"
#include "IdentifiantEntity.h"

/*! \defgroup groupeEntity Entitées
 * \brief Ensemble de classes représentant les entitées de la base de donnée.
 */

// Macro pour les entitées

/*! \defgroup groupeMacroEntity Macros pour les entitées
 * \ingroup groupeEntity
 * \brief Ensemble des macros pour les entitées.
 */

//Enumeration des positions et les variables statiques de EntityTemp

/*! \defgroup groupeNomPosEntity Enumeration des positions et les variables statiques de EntityTemp.
 * \ingroup groupeMacroEntity
 * \brief Ensemble de macrosdéfinissant l'numeration des positions et les variables statiques de EntityTemp.
 */

//! \ingroup groupeNomPosEntity
//! Macro définisant la position d'un attribut.
#define POS_1_ATT(ATT1) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, IdPos = 1};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de deux attributs.
#define POS_2_ATT(ATT1,ATT2) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, IdPos = 2};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de trois attributs.
#define POS_3_ATT(ATT1,ATT2,ATT3) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, IdPos = 3};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de quatre attributs.
#define POS_4_ATT(ATT1,ATT2,ATT3,ATT4) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, IdPos = 4};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de cinq attributs.
#define POS_5_ATT(ATT1,ATT2,ATT3,ATT4,ATT5) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, IdPos = 5};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de six attributs.
#define POS_6_ATT(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, IdPos = 6};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de sept attributs.
#define POS_7_ATT(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, IdPos = 7};

//! \ingroup groupeNomPosEntity
//! Macro définisant la position de huit attributs.
#define POS_8_ATT(ATT1,ATT2,ATT3,ATT4,ATT5,ATT6,ATT7,ATT8) \
    /*! \brief Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.*/ \
    enum position {ATT1 ## Pos = 0, ATT2 ## Pos = 1, ATT3 ## Pos = 2, ATT4 ## Pos = 3, ATT5 ## Pos = 4, ATT6 ## Pos = 5, ATT7 ## Pos = 6, ATT7 ## Pos = 7, IdPos = 8};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées.
 */

class Entity : public IdAttributEntity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {IdPos = 0,
                   PosPos = -1};

    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    Entity(int id = 0)
        : IdAttributEntity(id)
    {}

    //! Constructeur de recopie.
    Entity(const Entity & entity)
        : Entity(entity.id())
    {}

    //! Destructeur.
    ~Entity()
    {}

    //! Teste si l'entitée est nouvelle ou si elle provient de la base de donnée en regardant si elle poséde un identifiant non-nul.
    bool isNew() const
    {return id() == 0;}

    //! Renvoie l'identifiant du type de l'entitée.
    virtual IdentifiantEntity::entityId idEntity() const = 0;

    //! Teste si l'entitée est valide, c'est-à-dire si les attributs de l'entitée sont valides.
    virtual bool isValid() const
    {return IdAttributEntity::valide();}

    //! Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.
    virtual void operator << (const Entity & entity) = 0;

    //! Opérateur testant l'égalité de deux entitées, c'est-à-dire l'égalité de tous les attributs.
    virtual bool operator == (const Entity & entity) const = 0;

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument, c'est-à-dire l'égalité de tous les attributs.
    bool egal(const Entity & entity) const
    {return id() == entity.id();}

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Entity & entity)
    {setId(entity.id());}
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées ayant un attribut nom.
 */

class NomEntity : public Entity, public NomAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    NomEntity(int id = 0)
        : Entity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NomEntity(const QString & nom, int id = 0)
        : Entity(id), NomAttribut(nom)
    {}

    //! Constructeur de recopie.
    NomEntity(const NomEntity & entity)
        : Entity(entity), NomAttribut(entity.nom())
    {}

    //! Destructeur.
    ~NomEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid()
                && NomAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const NomEntity & entity) const
    {
        return Entity::egal(entity)
                && (nom() == entity.nom());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const NomEntity & entity)
    {
        Entity::set(entity);
        setNom(entity.nom());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées ayant un attribut nom et nc.
 */
class NcNomEntity : public NomEntity, public NcAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    NcNomEntity(int id = 0)
        : NomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NcNomEntity(const QString & nc, const QString & nom, int id = 0)
        : NomEntity(nom,id),
          NcAttribut(nc)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    NcNomEntity(const QString & nom)
        : NomEntity(nom)
    {}

    //! Constructeur de recopie.
    NcNomEntity(const NcNomEntity & entity)
        : NomEntity(entity), NcAttribut(entity.nc())
    {}

    //! Destructeur.
    ~NcNomEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return NomEntity::isValid()
                && NcAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const NcNomEntity & entity) const
    {
        return NomEntity::egal(entity)
                && (nc() == entity.nc());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const NcNomEntity & entity)
    {
        NomEntity::set(entity);
        setNc(entity.nc());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées ayant un attribut nom et type.
 */
class TypeNomEntity : public NomEntity, public TypeAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    TypeNomEntity(int id = 0)
        : NomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TypeNomEntity(const QString & nom, int type = 0, int id = 0)
        : NomEntity(nom,id),
          TypeAttribut(type)
    {}

    //! Constructeur de recopie.
    TypeNomEntity(const TypeNomEntity & entity)
        : NomEntity(entity), TypeAttribut(entity.type())
    {}

    //! Destructeur.
    ~TypeNomEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return NomEntity::isValid()
                && TypeAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const TypeNomEntity & entity) const
    {
        return NomEntity::egal(entity)
                && (type() == entity.type());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const TypeNomEntity & entity)
    {
        NomEntity::set(entity);
        setType(entity.type());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées ayant un attribut num.
 */
class NumEntity : public Entity, public NumAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    NumEntity(int id = 0)
        : Entity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NumEntity(int num, int id)
        : Entity(id), NumAttribut(num)
    {}

    //! Constructeur de recopie.
    NumEntity(const NumEntity & entity)
        : Entity(entity), NumAttribut(entity.num())
    {}

    //! Destructeur.
    ~NumEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid()
                && NumAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const NumEntity & entity) const
    {
        return Entity::egal(entity)
                && (num() == entity.num());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const NumEntity & entity)
    {
        Entity::set(entity);
        setNum(entity.num());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées possédant deux clés.
 */
class RelationEntity : public Entity, public Id1Attribut, public Id2Attribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    RelationEntity(int id = 0)
        : Entity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    RelationEntity(int id1, int id2, int id = 0)
        : Entity(id),
          Id1Attribut(id1),
          Id2Attribut(id2)
    {}

    //! Constructeur de recopie.
    RelationEntity(const RelationEntity & entity)
        : Entity(entity),
          Id1Attribut(entity.id1()),
          Id2Attribut(entity.id2())
    {}

    //! Destructeur.
    ~RelationEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid()
                && Id1Attribut::valide()
                && Id2Attribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const RelationEntity & entity) const
    {
        return Entity::egal(entity)
                && (id1() == entity.id1())
                && (id2() == entity.id2());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const RelationEntity & entity)
    {
        Entity::set(entity);
        setId1(entity.id1());
        setId2(entity.id2());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées possédant deux clés et un attribut date valide.
 */
class DateRelationEntity : public RelationEntity, public DateAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    DateRelationEntity(int id = 0)
        : RelationEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    DateRelationEntity(int id1, int id2, const QDate & date = QDate(), int id = 0)
        : RelationEntity(id1, id2, id),
          DateAttribut(date)
    {}

    //! Constructeur de recopie.
    DateRelationEntity(const DateRelationEntity & entity)
        : RelationEntity(entity),
          DateAttribut(entity.date())
    {}

    //! Destructeur.
    ~DateRelationEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return RelationEntity::isValid()
                && DateAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const DateRelationEntity & entity) const
    {
        return RelationEntity::egal(entity)
                && (date() == entity.date());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const DateRelationEntity & entity)
    {
        RelationEntity::set(entity);
        setDate(entity.date());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées possédant deux clés et un attribut date valide.
 */
class ValeurDateRelationEntity : public DateRelationEntity, public ValeurAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    ValeurDateRelationEntity(int id = 0)
        : DateRelationEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    ValeurDateRelationEntity(int id1, int id2, const QDate & date = QDate(), const QVariant & valeur = QVariant(), int id = 0)
        : DateRelationEntity(id1, id2, date, id),
          ValeurAttribut(valeur)
    {}

    //! Constructeur de recopie.
    ValeurDateRelationEntity(const ValeurDateRelationEntity & entity)
        : DateRelationEntity(entity),
          ValeurAttribut(entity.valeur())
    {}

    //! Destructeur.
    ~ValeurDateRelationEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return DateRelationEntity::isValid()
                && ValeurAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const ValeurDateRelationEntity & entity) const
    {
        return DateRelationEntity::egal(entity)
                && (valeur() == entity.valeur());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const ValeurDateRelationEntity & entity)
    {
        DateRelationEntity::set(entity);
        setValeur(entity.valeur());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées possédant deux clés et un attribut numéro.
 */
class NumRelationEntity : public RelationEntity, public NumAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    NumRelationEntity(int id = 0)
        : RelationEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NumRelationEntity(int id1, int id2, int num = 0, int id = 0)
        : RelationEntity(id1, id2, id),
          NumAttribut(num)
    {}

    //! Constructeur de recopie.
    NumRelationEntity(const NumRelationEntity & entity)
        : RelationEntity(entity),
          NumAttribut(entity.num())
    {}

    //! Destructeur.
    ~NumRelationEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return RelationEntity::isValid()
                && NumAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const NumRelationEntity & entity) const
    {
        return NumRelationEntity::egal(entity)
                && (num() == entity.num());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const NumRelationEntity & entity)
    {
        Entity::set(entity);
        setNum(entity.num());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite de base des entitées ayant un attribut texte.
 */

class TexteEntity : public Entity, public TexteAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entitée.
    TexteEntity(int id = 0)
        : Entity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    TexteEntity(const QString & txt, int id = 0)
        : Entity(id), TexteAttribut(txt)
    {}

    //! Constructeur de recopie.
    TexteEntity(const TexteEntity & entity)
        : Entity(entity), TexteAttribut(entity.texte())
    {}

    //! Destructeur.
    ~TexteEntity()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid()
                && TexteAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const TexteEntity & entity) const
    {
        return Entity::egal(entity)
                && (texte() == entity.texte());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const TexteEntity & entity)
    {
        Entity::set(entity);
        setTexte(entity.texte());
    }
};

/*! \ingroup groupeEntity
 * \brief Classe abstraite implémentant les variables statiques des entitées.
 */

template<IdentifiantEntity::entityId ID, int N, class T> class EntityTemp
{
public:
    static const IdentifiantEntity::entityId IdEntity = ID;    //!< Identifiant du type de l'entitée.
    static const int NbrAtt = N;                    //!< Nombre d'attributs de l'entitée.

    //! Constructeur.
    EntityTemp()
    {}

    //! Convertit la référence entity en une référence de type ENTITY, aprés vérification.
    static T * convert(Entity *entity)
    {
        if(verifEntity(entity))
        {
            return (T*) entity;
        }
        else
        {
            throw std::invalid_argument("Mauvaise correspondance des Entity");
        }
    }


    //!  Convertit la référence constante entity en une référence constante de type ENTITY, aprés vérification.
    static T & convert(Entity & entity)
    {
        if(verifEntity(entity))
        {
            return *((T*) &entity);
        }
        else
        {
            throw std::invalid_argument("Mauvaise correspondance des Entity");
        }
    }


    //! Convertit le pointeur entity en un pointeur de type ENTITY, aprés vérification.
    static const T & convert(const Entity & entity)
    {
        if(verifEntity(entity))
        {
            return *((T*) &entity);
        }
        else
        {
            throw std::invalid_argument("Mauvaise correspondance des Entity");
        }
    }

    //! Renvoie l'identifiant de l'entitée.
    IdentifiantEntity::entityId idEntity() const
    {return IdEntity;}

    //! Test si le pointeur entity est aussi un pointeur de ce type d'entitée.
    static bool verifEntity(Entity * entity)
    {return IdEntity == entity->idEntity();}

    //! Test si la référence entity est aussi une référence de ce type d'entitée.
    static bool verifEntity(const Entity & entity)
    {return IdEntity == entity.idEntity();}

    //! Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.
    void operator << (const T & entity)
    {T::set(entity.id());}

    //! Modifient les valeurs des attributs de l'entitée avec celles des attributs de entity.
    void operator << (const Entity & entity)
    {T::set(convert(entity));}
};
#endif // ENTITY_H
