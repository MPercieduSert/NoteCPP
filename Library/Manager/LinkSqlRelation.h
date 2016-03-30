/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/03/2016
 */
#ifndef LINKSQLRELATION
#define LINKSQLRELATION

#include "AttributsMacroLinkSql.h"
#include "LinkSql.h"

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant deux clés.
 */
template<class Ent, class Info> class RelationLinkSql : public IdLinkSql<Ent,Info>, public Id1AttributSql<Ent>, public Id2AttributSql<Ent>
{
protected:
    using Id1AttributSql<Ent>::id1;
    using Id1AttributSql<Ent>::setId1;
    using Id2AttributSql<Ent>::id2;
    using Id2AttributSql<Ent>::setId2;

public:
    //! Constructeur.
    RelationLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~RelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent,Info>::bindValues(entity);
        setId1(entity);
        setId2(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent,Info>::fromRequete(entity);
        entity.setId1(id1());
        entity.setId2(id2());
    }

protected:
    //! Constructeur protégé.
    RelationLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut date.
 */
template<class Ent, class Info> class DateRelationLinkSql : public RelationLinkSql<Ent,Info>, public DateAttributSql<Ent>
{
protected:
    using DateAttributSql<Ent>::date;
    using DateAttributSql<Ent>::setDate;

public:
    //! Constructeur.
    DateRelationLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~DateRelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        RelationLinkSql<Ent,Info>::bindValues(entity);
        setDate(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        RelationLinkSql<Ent,Info>::fromRequete(entity);
        entity.setDate(date());
    }

protected:
    //! Constructeur protégé.
    DateRelationLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant deux clés, un attribut date et un attribut valeur.
 */
template<class Ent, class Info> class ValeurDateRelationLinkSql : public DateRelationLinkSql<Ent,Info>, public ValeurAttributSql<Ent>
{
protected:
    using ValeurAttributSql<Ent>::valeur;
    using ValeurAttributSql<Ent>::setValeur;

public:
    //! Constructeur.
    ValeurDateRelationLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~ValeurDateRelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        DateRelationLinkSql<Ent,Info>::bindValues(entity);
        setValeur(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        DateRelationLinkSql<Ent,Info>::fromRequete(entity);
        entity.setValeur(valeur());
    }

protected:
    //! Constructeur protégé.
    ValeurDateRelationLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut num.
 */
template<class Ent, class Info> class NumRelationLinkSql : public RelationLinkSql<Ent,Info>, public NumAttributSql<Ent>
{
protected:
    using NumAttributSql<Ent>::num;
    using NumAttributSql<Ent>::setNum;

public:
    //! Constructeur.
    NumRelationLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NumRelationLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        RelationLinkSql<Ent,Info>::bindValues(entity);
        setNum(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        RelationLinkSql<Ent,Info>::fromRequete(entity);
        entity.setNum(num());
    }

protected:
    //! Constructeur protégé.
    NumRelationLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité étant une relation avec deux clés sans autre attribut.
 */
template<class Ent, class Info> class RelationOnlyLinkSql : public RelationLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    RelationOnlyLinkSql(QSqlQuery & requete)
        : RelationLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité étant une relation à deux clés ayant seulement un attribut date.
 */
template<class Ent,class Info> class DateRelationOnlyLinkSql : public DateRelationLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;
    using DateAttributSql<Ent>::date;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    DateRelationOnlyLinkSql(QSqlQuery & requete)
        : DateRelationLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),date(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité étant une relation
 * à deux clés ayant seulement les attributs date et valeur.
 */
template<class Ent,class Info> class ValeurDateRelationOnlyLinkSql : public ValeurDateRelationLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;
    using DateAttributSql<Ent>::date;
    using ValeurAttributSql<Ent>::valeur;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ValeurDateRelationOnlyLinkSql(QSqlQuery & requete)
        : ValeurDateRelationLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),date(),valeur(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité étant une relation à deux clés ayant seulement un attribut num.
 */
template<class Ent,class Info> class NumRelationOnlyLinkSql : public NumRelationLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using Id1AttributSql<Ent>::id1;
    using Id2AttributSql<Ent>::id2;
    using NumAttributSql<Ent>::num;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NumRelationOnlyLinkSql(QSqlQuery & requete)
        : NumRelationLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(id1(),id2(),num(),id());
    }
};

#endif // LINKSQLRELATION

