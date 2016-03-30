/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/03/2016
 */
#ifndef LINKSQLDIVERS
#define LINKSQLDIVERS

#include "AttributsMacroLinkSql.h"
#include "LinkSql.h"

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre les entités numérotés.
 */
template<class Ent, class Info> class NumLinkSql : public IdLinkSql<Ent,Info>, public NumAttributSql<Ent>
{
protected:
    using NumAttributSql<Ent>::num;
    using NumAttributSql<Ent>::setNum;

public:
    //! Constructeur.
    NumLinkSql()
    {}

    //! Constructeur.
    NumLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~NumLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent,Info>::bindValues(entity);
        setNum(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent,Info>::fromRequete(entity);
        entity.setNum(num());
    }
};


/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre les entités ayant un attribut texte.
 */
template<class Ent, class Info> class TexteLinkSql : public IdLinkSql<Ent,Info>, public TexteAttributSql<Ent>
{
protected:
    using TexteAttributSql<Ent>::texte;
    using TexteAttributSql<Ent>::setTexte;

public:
    //! Constructeur.
    TexteLinkSql()
    {}

    //! Constructeur.
    TexteLinkSql(QSqlQuery & req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~TexteLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
    {
        IdLinkSql<Ent,Info>::bindValues(entity);
        setTexte(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
    {
        IdLinkSql<Ent,Info>::fromRequete(entity);
        entity.setTexte(texte());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité ayant seulement l'attribut num.
 */
template<class Ent,class Info> class NumOnlyLinkSql : public NumLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using NumAttributSql<Ent>::num;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NumOnlyLinkSql(QSqlQuery & requete)
        : NumLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(num(),id());
    }
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre une entité ayant seulement l'attribut texte.
 */
template<class Ent,class Info> class TexteOnlyLinkSql : public TexteLinkSql<Ent,Info>
{
protected:
    using IdAttributSql<Ent>::id;
    using TexteAttributSql<Ent>::texte;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    TexteOnlyLinkSql(QSqlQuery & requete)
        : TexteLinkSql<Ent,Info>(requete)
        {}

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Ent * newFromRequete() const
    {
        return new Ent(texte(),id());
    }
};
#endif // LINKSQLDIVERS

