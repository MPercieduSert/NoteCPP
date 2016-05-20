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
#include "InfoSql.h"

// Définition des conditions d'unicité des entités de type prédéfini.
//! \ingroup groupeUniqueSqlBase
//! Macro définisant les conditions d'unicité prédéfinies.
#define UNIQUE_SQL(ENTITY,TYPE) /*! \ingroup groupeUniqueSqlSpe */ \
    /*! \brief Conditions d'unicité de l'entité ENTITY. */ \
    template<> class UniqueSql<ENTITY> : public TYPE ## UniqueSql<ENTITY>\
    {public:\
        /*! Construteur, transmettre en argument l'objet de requète utilisée par le manageur. */\
        UniqueSql<ENTITY>(QSqlQuery * requete) : TYPE ## UniqueSql<ENTITY>(requete){}\
        /*! Destructeur.*/\
        ~UniqueSql<ENTITY>() {}};

/*! \ingroup groupeUniqueSqlBase
 * \brief Interface mère des classes conditions d'unicité.
 */
template<class Ent> class AbstractUniqueSql : public ReqSql
{
public:
    //! Constructeur.
    AbstractUniqueSql(QSqlQuery * requete)
        : ReqSql(requete)
        {}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(Ent & entity) = 0;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    virtual Manager::ExisteUni existsUnique(const Ent & entity) = 0;
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe conditions d'unicité pour les entité ne possédant pas de condition d'unicité.
 */
template<class Ent> class NoUniqueSql : public AbstractUniqueSql<Ent>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NoUniqueSql(QSqlQuery * requete)
        : AbstractUniqueSql<Ent>(requete)
        {}

    //! Destructeur.
    ~NoUniqueSql()
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
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes condition d'unicité pour les entité possédant une condition d'unicité simple.
 */
template<class Ent> class SimpleUniqueSql : public AbstractUniqueSql<Ent>
{
protected:
    const QString m_unique; //!< Requete Sql sur l'existence d'un ensemble d'attribus uniques.
    using AbstractUniqueSql<Ent>::exec;
    using AbstractUniqueSql<Ent>::finish;
    using AbstractUniqueSql<Ent>::next;
    using AbstractUniqueSql<Ent>::prepare;
    using AbstractUniqueSql<Ent>::toInt;

public:
    //! Construteur.
    SimpleUniqueSql(QSqlQuery * requete)
        : AbstractUniqueSql<Ent>(requete),
          m_unique(writeStringUnique())
        {}

    //! Destructeur.
    ~SimpleUniqueSql()
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
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    virtual void bindValuesUnique(const Ent & entity) = 0;

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

template<class Ent> QString SimpleUniqueSql<Ent>::writeStringUnique() const
{
    QString sql(InfoSql<Ent>::SqlUnique);
    sql = sql.arg(InfoSql<Ent>::Table);
    for(int i = 0; i != InfoSql<Ent>::NbrAttUnique; ++i)
        sql = sql.arg(InfoSql<Ent>::Att[InfoSql<Ent>::AttUnique[i]]);
    sql.squeeze();
    return sql;
}

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes conditions d'unicité pour les entité possédant deux conditions d'unicités.
 */
template<class Ent> class DoubleUniqueSql : public AbstractUniqueSql<Ent>
{
protected:
    const QString m_unique_1; //!< Requete Sql sur l'existence de l'ensemble d'attribus uniques 1.
    const QString m_unique_2; //!< Requete Sql sur l'existence de l'ensemble d'attribus uniques 2.
    using AbstractUniqueSql<Ent>::exec;
    using AbstractUniqueSql<Ent>::finish;
    using AbstractUniqueSql<Ent>::next;
    using AbstractUniqueSql<Ent>::prepare;
    using AbstractUniqueSql<Ent>::toInt;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    DoubleUniqueSql(QSqlQuery * requete)
        : AbstractUniqueSql<Ent>(requete),
          m_unique_1(writeStringUnique_1()),
          m_unique_2(writeStringUnique_2())
        {}

    //! Destructeur.
    ~DoubleUniqueSql()
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
            if(idUni1 != 0)
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
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 1.
    virtual void bindValuesUnique_1(const Ent & entity) = 0;

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    virtual void bindValuesUnique_2(const Ent & entity) = 0;

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne 1.
    QString writeStringUnique_1() const;

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne 2.
    QString writeStringUnique_2() const;
};

template<class Ent> QString DoubleUniqueSql<Ent>::writeStringUnique_1() const
{
    QString sql(InfoSql<Ent>::SqlUnique1);
    sql = sql.arg(InfoSql<Ent>::Table);
    for(int i = 0; i != InfoSql<Ent>::NbrAttUnique1; ++i)
        sql = sql.arg(InfoSql<Ent>::Att[InfoSql<Ent>::AttUnique1[i]]);
    sql.squeeze();
    return sql;
}

template<class Ent> QString DoubleUniqueSql<Ent>::writeStringUnique_2() const
{
    QString sql(InfoSql<Ent>::SqlUnique2);
    sql = sql.arg(InfoSql<Ent>::Table);
    for(int i = 0; i != InfoSql<Ent>::NbrAttUnique2; ++i)
        sql = sql.arg(InfoSql<Ent>::Att[InfoSql<Ent>::AttUnique2[i]]);
    sql.squeeze();
    return sql;
}

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (num,parent).
 */
template<class Ent> class NumParentUniqueSql : public SimpleUniqueSql<Ent>
{    
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    NumParentUniqueSql(QSqlQuery * requete)
        :SimpleUniqueSql<Ent>(requete)
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        bindValue(InfoSql<Ent>::NumUnique,entity.num());
        bindValue(InfoSql<Ent>::ParentUnique,entity.parent());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple de clé (id1,id2).
 */
template<class Ent> class RelationUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    RelationUniqueSql(QSqlQuery * requete)
        : SimpleUniqueSql<Ent>(requete)
    {}

    //! Destructeur.
    ~RelationUniqueSql()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        bindValue(InfoSql<Ent>::Id1Unique,entity.id1());
        bindValue(InfoSql<Ent>::Id2Unique,entity.id2());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triplet (id1,id2,date).
 */
template<class Ent> class DateRelationUniqueSql : public RelationUniqueSql<Ent>
{
protected:
    using RelationUniqueSql<Ent>::bindValue;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    DateRelationUniqueSql(QSqlQuery * requete)
        : RelationUniqueSql<Ent>(requete)
    {}

    //! Destructeur.
    ~DateRelationUniqueSql()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        RelationUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(InfoSql<Ent>::DateUnique,entity.date());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes conditions d'unicité pour les entité possédant deux clés avec exactement une non nulle et unique.
 */
template<class Ent> class RelationExactOneNotNullUniqueSql : public DoubleUniqueSql<Ent>
{
protected:
    using DoubleUniqueSql<Ent>::m_unique_1;
    using DoubleUniqueSql<Ent>::m_unique_2;
    using DoubleUniqueSql<Ent>::bindValue;
    using DoubleUniqueSql<Ent>::exec;
    using DoubleUniqueSql<Ent>::finish;
    using DoubleUniqueSql<Ent>::next;
    using DoubleUniqueSql<Ent>::prepare;
    using DoubleUniqueSql<Ent>::toInt;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    RelationExactOneNotNullUniqueSql(QSqlQuery * requete)
        : DoubleUniqueSql<Ent>(requete)
    {}

    //! Destructeur.
    ~RelationExactOneNotNullUniqueSql()
    {}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    Manager::ExisteUni existsUnique(Ent & entity)
    {
        if(entity.id1() != 0 && entity.id2() == 0)
        {
            prepare(m_unique_1);
            bindValuesUnique_1(entity);
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

        if(entity.id1() == 0 && entity.id2() != 0)
        {
            prepare(m_unique_2);
            bindValuesUnique_2(entity);
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

        return Manager::Conflit;
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée,
    //! dans le cas particulier où il y a exactement deux ensembles de valeurs uniques.
    Manager::ExisteUni existsUnique(const Ent & entity)
    {
        if(entity.id1() != 0 && entity.id2() == 0)
        {
            prepare(m_unique_1);
            bindValuesUnique_1(entity);
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

        if(entity.id1() == 0 && entity.id2() != 0)
        {
            prepare(m_unique_2);
            bindValuesUnique_2(entity);
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

        return Manager::Conflit;
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 1.
    void bindValuesUnique_1(const Ent &entity)
    {
        bindValue(InfoSql<Ent>::Id1Unique,entity.id1());
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    void bindValuesUnique_2(const Ent &entity)
    {
        bindValue(InfoSql<Ent>::Id2Unique,entity.id2());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe mère des classes conditions d'unicité pour les entité possédant deux clés avec exactement une non nulle et une condition
 * d'unicité sur la clé non nulle et d'autre attributs commub aux deux clés.
 */
template<class Ent> class AttsRelationExactOneNotNullUniqueSql : public RelationExactOneNotNullUniqueSql<Ent>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    AttsRelationExactOneNotNullUniqueSql(QSqlQuery * requete)
        : RelationExactOneNotNullUniqueSql<Ent>(requete)
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
        RelationExactOneNotNullUniqueSql<Ent>::bindValuesUnique_1(entity);
        bindValuesUnique(entity);
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée 2.
    void bindValuesUnique_2(const Ent &entity)
    {
        RelationExactOneNotNullUniqueSql<Ent>::bindValuesUnique_2(entity);
        bindValuesUnique(entity);
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le nom.
 */
template<class Ent> class NomUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NomUniqueSql(QSqlQuery * requete)
        : SimpleUniqueSql<Ent>(requete)
    {}

    //! Destructeur.
    ~NomUniqueSql()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(InfoSql<Ent>::NomUnique,entity.nom());}
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (nom, type).
 */
template<class Ent> class NomTypeUniqueSql : public NomUniqueSql<Ent>
{
protected:
    using NomUniqueSql<Ent>::bindValue;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NomTypeUniqueSql(QSqlQuery * requete)
        : NomUniqueSql<Ent>(requete)
    {}

    //! Destructeur.
    ~NomTypeUniqueSql()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        NomUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(InfoSql<Ent>::TypeUnique,entity.type());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le texte.
 */
template<class Ent> class TexteUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    TexteUniqueSql(QSqlQuery * requete)
        : SimpleUniqueSql<Ent>(requete)
    {}

    //! Destructeur.
    ~TexteUniqueSql()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(InfoSql<Ent>::TexteUnique,entity.texte());}
};

#endif // ABSTRACTUNIQUESQL_H
