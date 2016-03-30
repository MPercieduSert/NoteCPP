/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef LINKSQLUNIQUE
#define LINKSQLUNIQUE

#include "Manager.h"
#include "ReqSql.h"

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entité ne possédant pas de condition d'unicité.
 */
template<class Link> class LinkSqlNoUnique : public Link
{
public:
    using Ent = typename Link::Ent;

    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    LinkSqlNoUnique(QSqlQuery & requete)
        : Link(requete)
        {}

    //! Destructeur.
    ~LinkSqlNoUnique()
    {}

    //! L'attribut ne possède pas d'ensemble de valeur unique.
    Manager::ExisteUni existsUnique(Ent & /*entity*/)
    {
        return Manager::Aucun;
    }

    //! L'attribut ne possède pas d'ensemble de valeur unique.
    Manager::ExisteUni existsUnique(const Ent & /*entity*/)
    {
        return Manager::Aucun;
    }

protected:
    //! Constructeur protégé.
    LinkSqlNoUnique()
    {}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entité possédant une condition d'unicité simple.
 */
template<class Link> class LinkSqlUniqueSimple : public Link
{
protected:
    USING_REQSQL(Link)

    const QString m_unique; //!< Requete Sql sur l'existence d'un ensemble d'attribus uniques.

public:
    using Ent = typename Link::Ent;

    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    LinkSqlUniqueSimple(QSqlQuery & requete)
        : Link(requete),
          m_unique(writeStringUnique())
        {}

    //! Destructeur.
    ~LinkSqlUniqueSimple()
    {}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a un seul ensemble de valeurs unique.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(Ent & entity)
    {
        prepare(m_unique);
        bindValuesUnique(entity);
        exec();
        if(next())
        {
            entity.setId(toInt());
            finish();
            return Manager::Tous;
        }
        else
        {
            finish();
            return Manager::Aucun;
        }
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a un seul ensemble de valeurs unique.
    virtual Manager::ExisteUni existsUnique(const Ent & entity)
    {
        prepare(m_unique);
        bindValuesUnique(entity);
        exec();
        if(next())
        {
            finish();
            return Manager::Tous;
        }
        else
        {
            finish();
            return Manager::Aucun;
        }
    }

protected:
    //! Construteur.
    LinkSqlUniqueSimple()
        : m_unique(writeStringUnique())
        {}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    virtual void bindValuesUnique(const Ent & entity) = 0;

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

template<class Link> QString LinkSqlUniqueSimple<Link>::writeStringUnique() const
{
    QString sql(Link::SqlUnique);
    sql = sql.arg(Link::Table);
    for(int i = 0; i != Link::NbrAttUnique; ++i)
        sql = sql.arg(Link::Att[Link::AttUnique[i]]);
    sql.squeeze();
    return sql;
}

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entité possédant deux conditions d'unicités.
 */
template<class Link> class LinkSqlUniqueDouble : public Link
{
protected:
    USING_REQSQL(Link)

    const QString m_unique_1; //!< Requete Sql sur l'existence de l'ensemble d'attribus uniques 1.
    const QString m_unique_2; //!< Requete Sql sur l'existence de l'ensemble d'attribus uniques 2.

public:
    using Ent = typename Link::Ent;

    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    LinkSqlUniqueDouble(QSqlQuery & requete)
        : Link(requete),
          m_unique_1(writeStringUnique_1()),
          m_unique_2(writeStringUnique_2())
        {}

    //! Destructeur.
    ~LinkSqlUniqueDouble()
    {}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(Ent & entity)
    {
        int idUni1 = 0;
        prepare(m_unique_1);
        bindValuesUnique_1(entity);
        exec();
        if(next())
            idUni1 = toInt();

        int idUni2 = 0;
        prepare(m_unique_2);
        bindValuesUnique_2(entity);
        exec();
        if(next())
            idUni2 = toInt();
        finish();

        if(idUni1 == idUni2)
        {
            if(idUni1 == 0)
            {
                entity.setId(idUni1);
                return Manager::Tous;
            }
            else
                {return Manager::Aucun;}
        }
        else
        {
            if(idUni1 == 0 || idUni2 == 0)
            {
                if(entity.id() != 0 && (idUni1 == entity.id() || idUni2 == entity.id()))
                    {return Manager::Meme;}
                else
                    {return Manager::Autre;}
            }
            else
                {return Manager::Conflit;}
        }
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    virtual Manager::ExisteUni existsUnique(const Ent & entity)
    {
        int idUni1 = 0;
        prepare(m_unique_1);
        bindValuesUnique_1(entity);
        exec();
        if(next())
            idUni1 = toInt();

        int idUni2 = 0;
        prepare(m_unique_2);
        bindValuesUnique_2(entity);
        exec();
        if(next())
            idUni2 = toInt();
        finish();

        if(idUni1 == idUni2)
        {
            if(idUni1 == 0)
                {return Manager::Tous;}
            else
                {return Manager::Aucun;}
        }
        else
        {
            if(idUni1 == 0 || idUni2 == 0)
            {
                if(entity.id() != 0 && (idUni1 == entity.id() || idUni2 == entity.id()))
                    {return Manager::Meme;}
                else
                    {return Manager::Autre;}
            }
            else
                {return Manager::Conflit;}
        }
    }

protected:
    //! Construteur protégé.
    LinkSqlUniqueDouble()
        : m_unique_1(writeStringUnique_1()),
          m_unique_2(writeStringUnique_2())
        {}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 1.
    virtual void bindValuesUnique_1(const Ent & entity) = 0;

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    virtual void bindValuesUnique_2(const Ent & entity) = 0;

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne 1.
    QString writeStringUnique_1() const;

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne 2.
    QString writeStringUnique_2() const;
};

template<class Link> QString LinkSqlUniqueDouble<Link>::writeStringUnique_1() const
{
    QString sql(Link::SqlUnique1);
    sql = sql.arg(Link::Table);
    for(int i = 0; i != Link::NbrAttUnique1; ++i)
        sql = sql.arg(Link::Att[Link::AttUnique1[i]]);
    sql.squeeze();
    return sql;
}

template<class Link> QString LinkSqlUniqueDouble<Link>::writeStringUnique_2() const
{
    QString sql(Link::SqlUnique2);
    sql = sql.arg(Link::Table);
    for(int i = 0; i != Link::NbrAttUnique2; ++i)
        sql = sql.arg(Link::Att[Link::AttUnique2[i]]);
    sql.squeeze();
    return sql;
}

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant une seule condition d'unicité sur le couple de clé (id1,id2).
 */
template<class Link> class RelationLinkSqlUnique : public LinkSqlUniqueSimple<Link>
{
protected:
    using Link::setId1;
    using Link::setId2;

public:
    using Ent = typename Link::Ent;

    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    RelationLinkSqlUnique(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Link>(requete)
    {}

    //! Destructeur.
    ~RelationLinkSqlUnique()
    {}

protected:
    //! Construteur protégé.
    RelationLinkSqlUnique()
    {}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        setId1(entity,Link::Id1Unique);
        setId2(entity,Link::Id2Unique);
    }
};


/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant une seule condition d'unicité sur le nom.
 */
template<class Link> class NomLinkSqlUnique : public LinkSqlUniqueSimple<Link>
{
protected:
    using Link::setNom;

public:
    using Ent = typename Link::Ent;

    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NomLinkSqlUnique(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Link>(requete)
    {}

    //! Destructeur.
    ~NomLinkSqlUnique()
    {}

protected:
    //! Construteur protégé.
    NomLinkSqlUnique()
    {}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {setNom(entity,Link::NomUnique);}
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens pour les entités possédant une seule condition d'unicité sur le texte.
 */
template<class Link> class TexteLinkSqlUnique : public LinkSqlUniqueSimple<Link>
{
protected:
    using Link::setTexte;

public:
    using Ent = typename Link::Ent;

    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    TexteLinkSqlUnique(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Link>(requete)
    {}

    //! Destructeur.
    ~TexteLinkSqlUnique()
    {}

protected:
    //! Construteur protégé.
    TexteLinkSqlUnique()
    {}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {setTexte(entity,Link::TexteUnique);}
};

#endif // LINKSQLUNIQUE
