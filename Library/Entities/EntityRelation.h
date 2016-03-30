/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYRELATION
#define ENTITYRELATION

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Définissant les alias des deux clés d'une relation.
#define RELATION_ALIAS_2_CLE(ID1,ID2) ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2) \
    enum {Id1Pos = Id ## ID1 ## Pos, Id2Pos = Id ## ID2 ## Pos};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés.
 */
template<class Ent, class Info> class RelationEntity : public EntityTemp<Ent,Info>, public Id1Attribut, public Id2Attribut
{
public:
    using EntityTemp<Ent,Info>::egal;
    using EntityTemp<Ent,Info>::set;

    //! Constructeur par défaut fixant l'identifiant de l'entité.
    RelationEntity(int id = 0)
        : EntityTemp<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    RelationEntity(int id1, int id2, int id = 0)
        : EntityTemp<Ent,Info>(id),
          Id1Attribut(id1),
          Id2Attribut(id2)
    {}

    //! Constructeur de recopie.
    RelationEntity(const RelationEntity<Ent,Info> & entity)
        : EntityTemp<Ent,Info>(entity),
          Id1Attribut(entity.id1()),
          Id2Attribut(entity.id2())
    {}

    //! Destructeur.
    ~RelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent,Info>::isValid()
                && Id1Attribut::valide()
                && Id2Attribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return Entity::egal(entity)
                && (id1() == entity.id1())
                && (id2() == entity.id2());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        Entity::set(entity);
        setId1(entity.id1());
        setId2(entity.id2());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés et un attribut date valide.
 */
template<class Ent, class Info> class DateRelationEntity : public RelationEntity<Ent,Info>, public DateAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    DateRelationEntity(int id = 0)
        : RelationEntity<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    DateRelationEntity(int id1, int id2, const QDate & date = QDate(), int id = 0)
        : RelationEntity<Ent,Info>(id1, id2, id),
          DateAttribut(date)
    {}

    //! Constructeur de recopie.
    DateRelationEntity(const DateRelationEntity<Ent,Info> & entity)
        : RelationEntity<Ent,Info>(entity),
          DateAttribut(entity.date())
    {}

    //! Destructeur.
    ~DateRelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return RelationEntity<Ent,Info>::isValid()
                && DateAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return RelationEntity<Ent,Info>::egal(entity)
                && (date() == entity.date());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        RelationEntity<Ent,Info>::set(entity);
        setDate(entity.date());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés et des attributs date valide et valeur.
 */
template<class Ent, class Info> class ValeurDateRelationEntity : public DateRelationEntity<Ent,Info>, public ValeurAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    ValeurDateRelationEntity(int id = 0)
        : DateRelationEntity<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    ValeurDateRelationEntity(int id1, int id2, const QDate & date = QDate(), const QVariant & valeur = QVariant(), int id = 0)
        : DateRelationEntity<Ent,Info>(id1, id2, date, id),
          ValeurAttribut(valeur)
    {}

    //! Constructeur de recopie.
    ValeurDateRelationEntity(const ValeurDateRelationEntity<Ent,Info> & entity)
        : DateRelationEntity<Ent,Info>(entity),
          ValeurAttribut(entity.valeur())
    {}

    //! Destructeur.
    ~ValeurDateRelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return DateRelationEntity<Ent,Info>::isValid()
                && ValeurAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return DateRelationEntity<Ent,Info>::egal(entity)
                && (valeur() == entity.valeur());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        DateRelationEntity<Ent,Info>::set(entity);
        setValeur(entity.valeur());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités possédant deux clés et un attribut numéro.
 */
template<class Ent, class Info> class NumRelationEntity : public RelationEntity<Ent,Info>, public NumAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NumRelationEntity(int id = 0)
        : RelationEntity<Ent,Info>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NumRelationEntity(int id1, int id2, int num = 0, int id = 0)
        : RelationEntity<Ent,Info>(id1, id2, id),
          NumAttribut(num)
    {}

    //! Constructeur de recopie.
    NumRelationEntity(const NumRelationEntity<Ent,Info> & entity)
        : RelationEntity<Ent,Info>(entity),
          NumAttribut(entity.num())
    {}

    //! Destructeur.
    ~NumRelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return RelationEntity<Ent,Info>::isValid()
                && NumAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return RelationEntity<Ent,Info>::egal(entity)
                && (num() == entity.num());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        RelationEntity<Ent,Info>::set(entity);
        setNum(entity.num());
    }
};

#endif // ENTITYRELATION
