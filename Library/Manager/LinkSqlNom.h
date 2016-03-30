/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef LINKSQLNOM
#define LINKSQLNOM

#include "AttributsMacroLinkSql.h"
#include "LinkSql.h"

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités nommées.
 */
template<class Ent, class Info> class NomLinkSql : public IdLinkSql<Ent,Info>, public NomAttributSql<Ent>
{
protected:
    using NomAttributSql<Ent>::nom;
    using NomAttributSql<Ent>::setNom;

public:
    //! Constructeur.
    NomLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent,Info>::bindValues(entity);
        setNom(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent,Info>::fromRequete(entity);
        entity.setNom(nom());
    }

protected:
    //! Constructeur protégé.
    NomLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités ayant un attribut nom et type.
 */
template<class Ent, class Info> class TypeNomLinkSql : public NomLinkSql<Ent,Info>, public TypeAttributSql<Ent>
{
protected:
    using TypeAttributSql<Ent>::type;
    using TypeAttributSql<Ent>::setType;

public:
    //! Constructeur.
    TypeNomLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~TypeNomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NomLinkSql<Ent,Info>::bindValues(entity);
        setType(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NomLinkSql<Ent,Info>::fromRequete(entity);
        entity.setType(type());
    }

protected:
    //! Constructeur protégé.
    TypeNomLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités ayant un attribut nc et nom.
 */
template<class Ent, class Info> class NcNomLinkSql : public NomLinkSql<Ent,Info>, public NcAttributSql<Ent>
{
protected:
    using NcAttributSql<Ent>::nc;
    using NcAttributSql<Ent>::setNc;

public:
    //! Constructeur.
    NcNomLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NcNomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NomLinkSql<Ent,Info>::bindValues(entity);
        setNc(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NomLinkSql<Ent,Info>::fromRequete(entity);
        entity.setNc(nc());
    }

protected:
    //! Constructeur protégé.
    NcNomLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités ayant des attributs nc, nom et type.
 */
template<class Ent, class Info> class TypeNcNomLinkSql : public NcNomLinkSql<Ent,Info>, public TypeAttributSql<Ent>
{
protected:
    using TypeAttributSql<Ent>::type;
    using TypeAttributSql<Ent>::setType;

public:
    //! Constructeur.
    TypeNcNomLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~TypeNcNomLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        NcNomLinkSql<Ent,Info>::bindValues(entity);
        setType(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        NcNomLinkSql<Ent,Info>::fromRequete(entity);
        entity.setType(type());
    }

protected:
    //! Constructeur protégé.
    TypeNcNomLinkSql()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité ayant seulement un attribut nom.
 */
template<class Ent, class Info> class NomOnlyLinkSql : public NomLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using NomAttributSql<Ent>::nom;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NomOnlyLinkSql(QSqlQuery & requete)
        : NomLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nom(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité ayant seulement les attributs nc et nom.
 */
template<class Ent, class Info> class NcNomOnlyLinkSql : public NcNomLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using NcAttributSql<Ent>::nc;
    using NomAttributSql<Ent>::nom;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NcNomOnlyLinkSql(QSqlQuery & requete)
        : NcNomLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nc,nom(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité ayant seulement les attributs nom et type.
 */
template<class Ent, class Info> class NomTypeOnlyLinkSql : public TypeNomLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using NomAttributSql<Ent>::nom;
    using TypeAttributSql<Ent>::type;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NomTypeOnlyLinkSql(QSqlQuery & requete)
        : TypeNomLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nom(),type(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité ayant seulement les attributs nc, nom et type.
 */
template<class Ent, class Info> class NcNomTypeOnlyLinkSql : public TypeNcNomLinkSql<Ent,Info>
{
protected:
    using TypeNcNomLinkSql<Ent,Info>::id;
    using TypeNcNomLinkSql<Ent,Info>::nc;
    using TypeNcNomLinkSql<Ent,Info>::nom;
    using TypeNcNomLinkSql<Ent,Info>::type;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NcNomTypeOnlyLinkSql(QSqlQuery & requete)
        : TypeNcNomLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(nc(),nom(),type(),id());
    }
};
#endif // LINKSQLNOM

