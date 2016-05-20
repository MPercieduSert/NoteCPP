/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef LINKSQLNOM
#define LINKSQLNOM

#include "AttributsMacroLinkSql.h"
#include "AbstractLinkSql.h"

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités nommées.
 */
template<class Ent> class NomLinkSql : public IdLinkSql<Ent>, public NomAttributSql<Ent>
{
protected:
    using NomAttributSql<Ent>::nom;
    using NomAttributSql<Ent>::setNom;

public:
    //! Constructeur.
    NomLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent>::bindValues(entity);
        setNom(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent>::fromRequete(entity);
        entity.setNom(nom());
    }

protected:
    //! Constructeur protégé.
    NomLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités ayant un attribut nom et type.
 */
template<class Ent> class TypeNomLinkSql : public NomLinkSql<Ent>, public TypeAttributSql<Ent>
{
protected:
    using TypeAttributSql<Ent>::type;
    using TypeAttributSql<Ent>::setType;

public:
    //! Constructeur.
    TypeNomLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~TypeNomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NomLinkSql<Ent>::bindValues(entity);
        setType(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NomLinkSql<Ent>::fromRequete(entity);
        entity.setType(type());
    }

protected:
    //! Constructeur protégé.
    TypeNomLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités ayant un attribut nc et nom.
 */
template<class Ent> class NcNomLinkSql : public NomLinkSql<Ent>, public NcAttributSql<Ent>
{
protected:
    using NcAttributSql<Ent>::nc;
    using NcAttributSql<Ent>::setNc;

public:
    //! Constructeur.
    NcNomLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NcNomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NomLinkSql<Ent>::bindValues(entity);
        setNc(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NomLinkSql<Ent>::fromRequete(entity);
        entity.setNc(nc());
    }

protected:
    //! Constructeur protégé.
    NcNomLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités ayant des attributs nc, nom et type.
 */
template<class Ent> class TypeNcNomLinkSql : public NcNomLinkSql<Ent>, public TypeAttributSql<Ent>
{
protected:
    using TypeAttributSql<Ent>::type;
    using TypeAttributSql<Ent>::setType;

public:
    //! Constructeur.
    TypeNcNomLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~TypeNcNomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NcNomLinkSql<Ent>::bindValues(entity);
        setType(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NcNomLinkSql<Ent>::fromRequete(entity);
        entity.setType(type());
    }

protected:
    //! Constructeur protégé.
    TypeNcNomLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité ayant seulement un attribut nom.
 */
template<class Ent> class NomOnlyLinkSql : public NomLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using NomAttributSql<Ent>::nom;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NomOnlyLinkSql(QSqlQuery * requete)
        : NomLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~NomOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nom(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité ayant seulement les attributs nc et nom.
 */
template<class Ent> class NcNomOnlyLinkSql : public NcNomLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using NcAttributSql<Ent>::nc;
    using NomAttributSql<Ent>::nom;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NcNomOnlyLinkSql(QSqlQuery * requete)
        : NcNomLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~NcNomOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nc,nom(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité ayant seulement les attributs nom et type.
 */
template<class Ent> class NomTypeOnlyLinkSql : public TypeNomLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using NomAttributSql<Ent>::nom;
    using TypeAttributSql<Ent>::type;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NomTypeOnlyLinkSql(QSqlQuery * requete)
        : TypeNomLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~NomTypeOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nom(),type(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité ayant seulement les attributs nc, nom et type.
 */
template<class Ent> class NcNomTypeOnlyLinkSql : public TypeNcNomLinkSql<Ent>
{
protected:
    using TypeNcNomLinkSql<Ent>::id;
    using TypeNcNomLinkSql<Ent>::nc;
    using TypeNcNomLinkSql<Ent>::nom;
    using TypeNcNomLinkSql<Ent>::type;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NcNomTypeOnlyLinkSql(QSqlQuery * requete)
        : TypeNcNomLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~NcNomTypeOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nc(),nom(),type(),id());
    }
};
#endif // LINKSQLNOM

