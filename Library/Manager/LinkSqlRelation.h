/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/03/2016
 */
#ifndef LINKSQLRELATION
#define LINKSQLRELATION

#include "AttributsMacroLinkSql.h"
#include "AbstractLinkSql.h"

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés.
 */
template<class Ent> class RelationLinkSql : public IdLinkSql<Ent>, public Id1AttributSql<Ent>, public Id2AttributSql<Ent>
{
protected:
    using Id1AttributSql<Ent>::id1;
    using Id1AttributSql<Ent>::setId1;
    using Id2AttributSql<Ent>::id2;
    using Id2AttributSql<Ent>::setId2;

public:
    //! Constructeur.
    RelationLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~RelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent>::bindValues(entity);
        setId1(entity);
        setId2(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent>::fromRequete(entity);
        entity.setId1(id1());
        entity.setId2(id2());
    }

protected:
    //! Constructeur protégé.
    RelationLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut date.
 */
template<class Ent> class DateRelationLinkSql : public RelationLinkSql<Ent>, public DateAttributSql<Ent>
{
protected:
    using DateAttributSql<Ent>::date;
    using DateAttributSql<Ent>::setDate;

public:
    //! Constructeur.
    DateRelationLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~DateRelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        RelationLinkSql<Ent>::bindValues(entity);
        setDate(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        RelationLinkSql<Ent>::fromRequete(entity);
        entity.setDate(date());
    }

protected:
    //! Constructeur protégé.
    DateRelationLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés, un attribut date et un attribut valeur.
 */
template<class Ent> class ValeurDateRelationLinkSql : public DateRelationLinkSql<Ent>, public ValeurAttributSql<Ent>
{
protected:
    using ValeurAttributSql<Ent>::valeur;
    using ValeurAttributSql<Ent>::setValeur;

public:
    //! Constructeur.
    ValeurDateRelationLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~ValeurDateRelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        DateRelationLinkSql<Ent>::bindValues(entity);
        setValeur(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        DateRelationLinkSql<Ent>::fromRequete(entity);
        entity.setValeur(valeur());
    }

protected:
    //! Constructeur protégé.
    ValeurDateRelationLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut num.
 */
template<class Ent> class NumRelationLinkSql : public RelationLinkSql<Ent>, public NumAttributSql<Ent>
{
protected:
    using NumAttributSql<Ent>::num;
    using NumAttributSql<Ent>::setNum;

public:
    //! Constructeur.
    NumRelationLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NumRelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        RelationLinkSql<Ent>::bindValues(entity);
        setNum(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        RelationLinkSql<Ent>::fromRequete(entity);
        entity.setNum(num());
    }

protected:
    //! Constructeur protégé.
    NumRelationLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité étant une relation avec deux clés sans autre attribut.
 */
template<class Ent> class RelationOnlyLinkSql : public RelationLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    RelationOnlyLinkSql(QSqlQuery * requete)
        : RelationLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~RelationOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité étant une relation à deux clés ayant seulement un attribut date.
 */
template<class Ent> class DateRelationOnlyLinkSql : public DateRelationLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;
    using DateAttributSql<Ent>::date;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    DateRelationOnlyLinkSql(QSqlQuery * requete)
        : DateRelationLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~DateRelationOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),date(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité étant une relation
 * à deux clés ayant seulement les attributs date et valeur.
 */
template<class Ent> class ValeurDateRelationOnlyLinkSql : public ValeurDateRelationLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;
    using DateAttributSql<Ent>::date;
    using ValeurAttributSql<Ent>::valeur;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ValeurDateRelationOnlyLinkSql(QSqlQuery * requete)
        : ValeurDateRelationLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~ValeurDateRelationOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),date(),valeur(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité étant une relation à deux clés ayant seulement un attribut num.
 */
template<class Ent> class NumRelationOnlyLinkSql : public NumRelationLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;
    using NumAttributSql<Ent>::num;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NumRelationOnlyLinkSql(QSqlQuery * requete)
        : NumRelationLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~NumRelationOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),num(),id());
    }
};

#endif // LINKSQLRELATION
