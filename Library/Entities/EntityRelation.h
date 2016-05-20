/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef ENTITYRELATION
#define ENTITYRELATION

#include "Entity.h"

//! \ingroup groupeMacroEntity
//! Macro Définissant les alias des deux clés d'une relation.
#define RELATION_ALIAS_2_CLE(ID1,ID2,ENTITY) ALIAS_CLE(ID1,1) \
    ALIAS_CLE(ID2,2)


/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés.
 */
template<class Ent> class RelationEntity : public EntityTemp<Ent>, public Id1Attribut, public Id2Attribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    RelationEntity(int id = 0)
        : EntityTemp<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    RelationEntity(int id1, int id2, int id = 0)
        : EntityTemp<Ent>(id),
          Id1Attribut(id1),
          Id2Attribut(id2)
    {}

    //! Constructeur de recopie.
    RelationEntity(const RelationEntity<Ent> & entity)
        : EntityTemp<Ent>(entity),
          Id1Attribut(entity.id1()),
          Id2Attribut(entity.id2())
    {}

    //! Destructeur.
    ~RelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent>::isValid()
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
 * \brief Classe de base des entités possédant deux clés dont exactement une non nulle.
 */
template<class Ent> class RelationExactOneNotNullEntity : public EntityTemp<Ent>, public Id1NullAttribut, public Id2NullAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    RelationExactOneNotNullEntity(int id = 0)
        : EntityTemp<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    RelationExactOneNotNullEntity(int id1, int id2, int id = 0)
        : EntityTemp<Ent>(id),
          Id1NullAttribut(id1),
          Id2NullAttribut(id2)
    {}

    //! Constructeur de recopie.
    RelationExactOneNotNullEntity(const RelationEntity<Ent> & entity)
        : EntityTemp<Ent>(entity),
          Id1NullAttribut(entity.id1()),
          Id2NullAttribut(entity.id2())
    {}

    //! Destructeur.
    ~RelationExactOneNotNullEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return EntityTemp<Ent>::isValid()
                    && ((id1() > 0 && id2() == 0) || (id1() == 0 && id2() > 0));
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
template<class Ent> class DateRelationEntity : public RelationEntity<Ent>, public DateAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    DateRelationEntity(int id = 0)
        : RelationEntity<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    DateRelationEntity(int id1, int id2, const QDate & date = QDate(), int id = 0)
        : RelationEntity<Ent>(id1, id2, id),
          DateAttribut(date)
    {}

    //! Constructeur de recopie.
    DateRelationEntity(const DateRelationEntity<Ent> & entity)
        : RelationEntity<Ent>(entity),
          DateAttribut(entity.date())
    {}

    //! Destructeur.
    ~DateRelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return RelationEntity<Ent>::isValid()
                && DateAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return RelationEntity<Ent>::egal(entity)
                && (date() == entity.date());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        RelationEntity<Ent>::set(entity);
        setDate(entity.date());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe de base des entités possédant deux clés et des attributs date valide et valeur.
 */
template<class Ent> class ValeurDateRelationEntity : public DateRelationEntity<Ent>, public ValeurAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    ValeurDateRelationEntity(int id = 0)
        : DateRelationEntity<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    ValeurDateRelationEntity(int id1, int id2, const QDate & date = QDate(), const QVariant & valeur = QVariant(), int id = 0)
        : DateRelationEntity<Ent>(id1, id2, date, id),
          ValeurAttribut(valeur)
    {}

    //! Constructeur de recopie.
    ValeurDateRelationEntity(const ValeurDateRelationEntity<Ent> & entity)
        : DateRelationEntity<Ent>(entity),
          ValeurAttribut(entity.valeur())
    {}

    //! Destructeur.
    ~ValeurDateRelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return DateRelationEntity<Ent>::isValid()
                && ValeurAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return DateRelationEntity<Ent>::egal(entity)
                && (valeur() == entity.valeur());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        DateRelationEntity<Ent>::set(entity);
        setValeur(entity.valeur());
    }
};

/*! \ingroup groupeBaseEntity
 * \brief Classe abstraite de base des entités possédant deux clés et un attribut numéro.
 */
template<class Ent> class NumRelationEntity : public RelationEntity<Ent>, public NumAttribut
{
public:
    //! Constructeur par défaut fixant l'identifiant de l'entité.
    NumRelationEntity(int id = 0)
        : RelationEntity<Ent>(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    NumRelationEntity(int id1, int id2, int num = 0, int id = 0)
        : RelationEntity<Ent>(id1, id2, id),
          NumAttribut(num)
    {}

    //! Constructeur de recopie.
    NumRelationEntity(const NumRelationEntity<Ent> & entity)
        : RelationEntity<Ent>(entity),
          NumAttribut(entity.num())
    {}

    //! Destructeur.
    ~NumRelationEntity()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return RelationEntity<Ent>::isValid()
                && NumAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Ent & entity) const
    {
        return RelationEntity<Ent>::egal(entity)
                && (num() == entity.num());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Ent & entity)
    {
        RelationEntity<Ent>::set(entity);
        setNum(entity.num());
    }
};

#endif // ENTITYRELATION
