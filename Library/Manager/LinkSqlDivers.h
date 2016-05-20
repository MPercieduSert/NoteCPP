/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/03/2016
 */
#ifndef LINKSQLDIVERS
#define LINKSQLDIVERS

#include "AttributsMacroLinkSql.h"
#include "AbstractLinkSql.h"

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités numérotés.
 */
template<class Ent> class NumLinkSql : public IdLinkSql<Ent>, public NumAttributSql<Ent>
{
protected:
    using NumAttributSql<Ent>::num;
    using NumAttributSql<Ent>::setNum;

public:
    //! Constructeur.
    NumLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NumLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent>::bindValues(entity);
        setNum(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent>::fromRequete(entity);
        entity.setNum(num());
    }

protected:
    //! Constructeur protégé.
    NumLinkSql()
    {}
};


/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités ayant un attribut texte.
 */
template<class Ent> class TexteLinkSql : public IdLinkSql<Ent>, public TexteAttributSql<Ent>
{
protected:
    using TexteAttributSql<Ent>::texte;
    using TexteAttributSql<Ent>::setTexte;

public:
    //! Constructeur.
    TexteLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~TexteLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent>::bindValues(entity);
        setTexte(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent>::fromRequete(entity);
        entity.setTexte(texte());
    }

protected:
    //! Constructeur protégé.
    TexteLinkSql()
    {}
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité ayant seulement l'attribut num.
 */
template<class Ent> class NumOnlyLinkSql : public NumLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using NumAttributSql<Ent>::num;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NumOnlyLinkSql(QSqlQuery * requete)
        : NumLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~NumOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(num(),id());
    }
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre une entité ayant seulement l'attribut texte.
 */
template<class Ent> class TexteOnlyLinkSql : public TexteLinkSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;
    using TexteAttributSql<Ent>::texte;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    TexteOnlyLinkSql(QSqlQuery * requete)
        : TexteLinkSql<Ent>(requete)
        {}

    //!Destructeur.
    ~TexteOnlyLinkSql()
    {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(texte(),id());
    }
};
#endif // LINKSQLDIVERS

