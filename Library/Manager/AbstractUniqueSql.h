/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef ABSTRACTUNIQUESQL_H
#define ABSTRACTUNIQUESQL_H

/*! \defgroup groupeUniqueSql Conditions d'unicités
 * \ingroup groupeManager
 * \brief Ensemble des conditions d'unicités des entités.
 */

/*! \defgroup groupeUniqueSqlBase Conditions d'unicités de base
 * \ingroup groupeUniqueSql
 * \brief Ensemble des classes mères des conditions d'unicités.
 */

/*! \defgroup groupeUniqueSqlSpe Spéciation linkSql
 * \ingroup groupeUniqueSql
 * \brief Spéciations des conditions d'unicités.
 */

#include "Manager.h"
#include "ReqSql.h"
#include "../Entities/EntityRelation.h"

// Définition des conditions d'unicité des entités de type prédéfini.
//! \ingroup groupeUniqueSqlBase
//! Macro définisant les constructeurs et destructeurs des conditions d'unicité.
#define CONSTR_DESTR_UNIQUE_SQL(ENTITY,TYPE) /*! \ingroup groupeUniqueSqlSpe */ \
    /*! \brief Conditions d'unicité de l'entité ENTITY. */ \
    class ENTITY ## UniqueSql: public TYPE<ENTITY>\
    {public:\
        /*! Construteur, transmettre en argument l'objet de requète utilisée par le manageur. */\
        ENTITY ## UniqueSql(const QString & table, const QVector<QMap<int,QString>> & att) : TYPE(table,att){}\
        /*! Destructeur.*/\
        ~ENTITY ## UniqueSql() {}

/*! \ingroup groupeUniqueSqlBase
 * \brief Interface mère des classes conditions d'unicité.
 */
class AbstractUniqueSql : public ReqSql
{
public:
    enum {idUnique = 0};
    //! Constructeur.
    AbstractUniqueSql()
        {}

    //! Construit la chaine coorespondant à la requête sql d'unicité
    QString uniqueString(const QString & table, const QMap<int,QString> & att) const;

    //! Construit la chaine sql de créations des conditions d'unicités.
    virtual QString creer(const QString & table, const QVector<QMap<int,QString>> & atts) const = 0;

    /*
    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual bdd::ExisteUni existsUnique(Ent & entity) = 0;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    virtual bdd::ExisteUni existsUnique(const Ent & entity) = 0;
    */
protected:
    //! Accesseur de l'identifiant.
    int id(int pos = idUnique) const
        {return value<int>(pos);}
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe conditions d'unicité pour les entité ne possédant pas de condition d'unicité.
 */
class NoUniqueSql : public AbstractUniqueSql
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NoUniqueSql(const QString & /*table*/, const QVector<QMap<int,QString>> & /*atts*/)
        {}

    //! Destructeur.
    ~NoUniqueSql()
        {}

    //! Construit la chaine sql de créations des conditions d'unicités.
    QString creer(const QString & /*table*/, const QVector<QMap<int,QString>> & /*atts*/) const
        {return QString();}

    //! L'attribut ne possède pas d'ensemble de valeur unique.
    bdd::ExisteUni existsUnique(Entity & /*entity*/)
        {return bdd::Aucun;}

    //! L'attribut ne possède pas d'ensemble de valeur unique.
    bdd::ExisteUni existsUnique(const Entity & /*entity*/)
    {
        return bdd::Aucun;
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes condition d'unicité pour les entité possédant une condition d'unicité simple.
 */
template<class Ent> class SimpleUniqueSql : public AbstractUniqueSql
{
protected:
    const QString m_unique; //!< Requete Sql sur l'existence d'un ensemble d'attribus uniques.

public:
    //! Construteur.
    SimpleUniqueSql(const QString & table, const QVector<QMap<int,QString>> & att)
        : m_unique(uniqueString(table,att.at(0)))
        {}

    //! Destructeur.
    ~SimpleUniqueSql()
    {}

    //! Construit la chaine sql de créations des conditions d'unicités.
    QString creer(const QString & table, const QVector<QMap<int,QString>> & atts) const;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a un seul ensemble de valeurs unique.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual bdd::ExisteUni existsUnique(Ent & entity)
    {
        prepare(m_unique);
        bindValuesUnique(entity);
        exec();
        if(next())
        {
            entity.setId(id());
            finish();
            return bdd::Tous;
        }
        else
        {
            finish();
            return bdd::Aucun;
        }
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a un seul ensemble de valeurs unique.
    virtual bdd::ExisteUni existsUnique(const Ent & entity)
    {
        prepare(m_unique);
        bindValuesUnique(entity);
        exec();
        if(next())
        {
            finish();
            return bdd::Tous;
        }
        else
        {
            finish();
            return bdd::Aucun;
        }
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    virtual void bindValuesUnique(const Ent & entity) = 0;
};

template<class Ent> QString SimpleUniqueSql<Ent>::creer(const QString & table,const QVector<QMap<int,QString>> & atts) const
{
    using namespace bdd;
    QString sql(",");
    sql.append(createSqlString(createSql::constraint)).append(" UN").append(table).append(" ").append(createSqlString(createSql::unique)).append(" (");
    for(QMap<int,QString>::const_iterator i = atts.at(0).cbegin(); i != atts.at(0).cend(); ++i)
        sql.append(i.value()).append(",");
    sql.chop(1);
    sql.append(")");
    return sql;
}

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes conditions d'unicité pour les entité possédant deux conditions d'unicités.
 */
template<class Ent> class DoubleUniqueSql : public AbstractUniqueSql
{
protected:
    const QString m_unique_1; //!< Requete Sql sur l'existence de l'ensemble d'attribus uniques 1.
    const QString m_unique_2; //!< Requete Sql sur l'existence de l'ensemble d'attribus uniques 2.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    DoubleUniqueSql(const QString & table, const QVector<QMap<int,QString>> & atts)
        : m_unique_1(uniqueString(table,atts.at(0))),
          m_unique_2(uniqueString(table,atts.at(1)))
        {}

    //! Destructeur.
    ~DoubleUniqueSql()
    {}

    //! Construit la chaine sql de créations des conditions d'unicités.
    QString creer(const QString & table, const QVector<QMap<int,QString>> & atts) const;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual bdd::ExisteUni existsUnique(Ent & entity)
    {
        int idUni1 = 0;
        prepare(m_unique_1);
        bindValuesUnique_1(entity);
        exec();
        if(next())
            idUni1 = id();

        int idUni2 = 0;
        prepare(m_unique_2);
        bindValuesUnique_2(entity);
        exec();
        if(next())
            idUni2 = id();
        finish();

        if(idUni1 == idUni2)
        {
            if(idUni1 != 0)
            {
                entity.setId(idUni1);
                return bdd::Tous;
            }
            else
                {return bdd::Aucun;}
        }
        else
        {
            if(idUni1 == 0 || idUni2 == 0)
            {
                if(entity.id() != 0 && (idUni1 == entity.id() || idUni2 == entity.id()))
                    {return bdd::Meme;}
                else
                    {return bdd::Autre;}
            }
            else
                {return bdd::Conflit;}
        }
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    virtual bdd::ExisteUni existsUnique(const Ent & entity)
    {
        int idUni1 = 0;
        prepare(m_unique_1);
        bindValuesUnique_1(entity);
        exec();
        if(next())
            idUni1 = id();

        int idUni2 = 0;
        prepare(m_unique_2);
        bindValuesUnique_2(entity);
        exec();
        if(next())
            idUni2 = id();
        finish();

        if(idUni1 == idUni2)
        {
            if(idUni1 == 0)
                {return bdd::Tous;}
            else
                {return bdd::Aucun;}
        }
        else
        {
            if(idUni1 == 0 || idUni2 == 0)
            {
                if(entity.id() != 0 && (idUni1 == entity.id() || idUni2 == entity.id()))
                    {return bdd::Meme;}
                else
                    {return bdd::Autre;}
            }
            else
                {return bdd::Conflit;}
        }
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 1.
    virtual void bindValuesUnique_1(const Ent & entity) = 0;

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    virtual void bindValuesUnique_2(const Ent & entity) = 0;
};

template<class Ent> QString DoubleUniqueSql<Ent>::creer(const QString & table,const QVector<QMap<int,QString>> & atts) const
{
    using namespace bdd;
    QString sql;
    for(int n = 0; n != atts.size(); ++n)
    {
        sql.append(",");
        sql.append(createSqlString(createSql::constraint)).append(" UN").append(QString::number(n)).append(table).append(" ").append(createSqlString(createSql::unique)).append(" (");
        for(QMap<int,QString>::const_iterator i = atts.at(n).cbegin(); i != atts.at(n).cend(); ++i)
            sql.append(i.value()).append(",");
        sql.chop(1);
        sql.append(")");
    }
    return sql;
}

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes conditions d'unicité pour les entité possédant deux clés avec exactement une non nulle et unique.
 */
template<class Ent> class RelationExactOneNotNullUniqueSqlTemp : public DoubleUniqueSql<Ent>
{
protected:
    using DoubleUniqueSql<Ent>::m_unique_1;
    using DoubleUniqueSql<Ent>::m_unique_2;
    using DoubleUniqueSql<Ent>::bindValue;
    using DoubleUniqueSql<Ent>::exec;
    using DoubleUniqueSql<Ent>::finish;
    using DoubleUniqueSql<Ent>::id;
    using DoubleUniqueSql<Ent>::next;
    using DoubleUniqueSql<Ent>::prepare;

public:
    enum {id1Unique = 0,NbrUnique1,id2Unique = 0,NbrUnique2};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    RelationExactOneNotNullUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : DoubleUniqueSql<Ent>(table,atts)
    {}

    //! Destructeur.
    ~RelationExactOneNotNullUniqueSqlTemp()
    {}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    bdd::ExisteUni existsUnique(Ent & entity)
    {
        if(entity.id1() != 0 && entity.id2() == 0)
        {
            prepare(m_unique_1);
            bindValuesUnique_1(entity);
            exec();
            if(next())
            {
                entity.setId( id());
                finish();
                return bdd::Tous;
            }
            else
            {
                finish();
                return bdd::Aucun;
            }
        }

        if(entity.id1() == 0 && entity.id2() != 0)
        {
            prepare(m_unique_2);
            bindValuesUnique_2(entity);
            exec();
            if(next())
            {
                entity.setId(id());
                finish();
                return bdd::Tous;
            }
            else
            {
                finish();
                return bdd::Aucun;
            }
        }

        return bdd::Conflit;
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    bdd::ExisteUni existsUnique(const Ent & entity)
    {
        if(entity.id1() != 0 && entity.id2() == 0)
        {
            prepare(m_unique_1);
            bindValuesUnique_1(entity);
            exec();
            if(next())
            {
                finish();
                return bdd::Tous;
            }
            else
            {
                finish();
                return bdd::Aucun;
            }
        }

        if(entity.id1() == 0 && entity.id2() != 0)
        {
            prepare(m_unique_2);
            bindValuesUnique_2(entity);
            exec();
            if(next())
            {
                finish();
                return bdd::Tous;
            }
            else
            {
                finish();
                return bdd::Aucun;
            }
        }

        return bdd::Conflit;
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 1.
    void bindValuesUnique_1(const Ent &entity)
    {
        bindValue(id1Unique,entity.id1());
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    void bindValuesUnique_2(const Ent &entity)
    {
        bindValue(id2Unique,entity.id2());
    }
};

typedef RelationExactOneNotNullUniqueSqlTemp<RelationExactOneNotNullEntity> RelationExactOneNotNullUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes conditions d'unicité pour les entité possédant deux clés avec exactement une non nulle et une condition
 * d'unicité sur la clé non nulle et d'autre attributs commums aux deux clés.
 */
template<class Ent> class AttsRelationExactOneNotNullUniqueSql : public RelationExactOneNotNullUniqueSqlTemp<Ent>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    AttsRelationExactOneNotNullUniqueSql(const QString & table, const QVector<QMap<int,QString>> & atts)
        : RelationExactOneNotNullUniqueSqlTemp<Ent>(table,atts)
    {}

    //! Destructeur.
    ~AttsRelationExactOneNotNullUniqueSql()
    {}

protected:
    //! Transmet les valeurs des attributs uniques aux requètes SQL préparées.
    virtual void bindValuesUnique(const Ent & entity) = 0;

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 1.
    void bindValuesUnique_1(const Ent &entity)
    {
        RelationExactOneNotNullUniqueSqlTemp<Ent>::bindValuesUnique_1(entity);
        bindValuesUnique(entity);
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    void bindValuesUnique_2(const Ent &entity)
    {
        RelationExactOneNotNullUniqueSqlTemp<Ent>::bindValuesUnique_2(entity);
        bindValuesUnique(entity);
    }
};

#endif // ABSTRACTUNIQUESQL_H
