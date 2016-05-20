/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef MANAGERSQL_H
#define MANAGERSQL_H

#include "InfoSql.h"
#include "Manager.h"
#include "ReqSql.h"

#include "LinkSql.h"
#include "UniqueSql.h"

// Macro pour manageur..

//! \ingroup groupeBaseManager
//! Coprs des deux methodes save.
#define SAVE if(entity.isValid()) \
{if(entity.isNew()) \
    {if(existsUnique(entity) == Aucun) \
        {add(entity);} \
     else \
        {throw std::invalid_argument(messageErreursUnique(entity).toStdString());}} \
else \
    {if(!sameInBdd(entity)) \
        {if(existsUnique(entity) <= Meme) \
            {modify(entity);} \
        else \
            {throw std::invalid_argument(messageErreursUnique(entity).toStdString());}}}} \
else \
    {throw std::invalid_argument(messageErreurs(entity).toStdString());}

/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs de type SQL.
 */
class AbstractManagerSql :  public Manager, public ReqSql
{
protected:


public:
    //! Contructeur, transmettre en argument la connexion ouverte à le base de donnée.
    AbstractManagerSql(QSqlQuery * req)
        : ReqSql(req)
        {}

    //! Destructeur.
    ~AbstractManagerSql()  {}

    //! Modifie le pointeur vers l'objet requête.
    virtual void setRequete(QSqlQuery * req)
        {ReqSql::setRequete(req);}
};


/*! \ingroup groupeBaseManager
 * \brief Classe template mère des différents manageurs de type SQL.
 *
 * Classe template permettant d'instancier les différents manageurs.
 * Cette classe implémente les méthodes virtuelles pures de sa classe mère.
 * La classe Ent est la classe d'entité de programmation
 * et la classe Link est le lien avec les entités en base de donnée.
 */
template<class Ent> class ManagerSql : public AbstractManagerSql
{
protected:
    LinkSql<Ent> m_link;        //!< Lien.
    UniqueSql<Ent> m_unique;    //! Condition d'unicité.
    const QString m_sqlAdd;     //!< Requéte sql d'insertion d'une ligne.
    const QString m_sqlDelete;  //!< Requéte sql de suppression d'une ligne
    const QString m_sqlExists;  //!< Requéte sql d'existence d'une ligne d'identifiant donné.
    const QString m_sqlGet;     //!< Requéte sql de lecture d'une ligne d'identifiant donné.
    const QString m_sqlGetList; //!< Requéte sql de lecture de toutes les lignes de la table triées suivant une colonne.
    const QString m_sqlGetList1Where1;  //!< Requéte sql de lecture des lignes de la table vérifiant une condition triées suivant une colonne.
    const QString m_sqlGetList1Where2;  //!< Requéte sql de lecture des lignes de la table vérifiant deux conditions triées suivant une colonne.
    const QString m_sqlGetList2Where1;  //!< Requéte sql de lecture des lignes de la table vérifiant une condition triées suivant deux colonnes.
    const QString m_sqllastId;  //!< Requéte sql de lecture de l'identifiant de la dernière ligne insérée dans la table.
    const QString m_sqlModify;  //!< Requéte sql de mis à jour d'une ligne de la table.

public:
    //! Contructeur, transmettre en argument la connexion ouverte à le base de donnée.
    ManagerSql(QSqlQuery * req);

    //! Destructeur.
    ~ManagerSql()  {}

    //! Crée dans la base de donnée la table associée l'entité du manageur.
    void creer();

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    bool exists(const Entity & entity)
    {
        if(Ent::verifEntity(entity))
        {
            prepare(m_sqlExists);
            m_link.setId(entity,0);
            exec();
            bool bb = next();
            finish();
            return bb;
        }
        else
            {throw std::runtime_error("Mauvaise correspondance des Entity");}
    }

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    bool exists(const Ent & entity)
    {
            prepare(m_sqlExists);
            m_link.setId(entity,0);
            exec();
            bool bb = next();
            finish();
            return bb;
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    Manager::ExisteUni existsUnique(Ent & entity)
        {return m_unique.existsUnique(entity);}

    //! Idem Manager::ExisteUni existsUnique(Ent & entity) avec une conversion de référence.
    Manager::ExisteUni existsUnique(Entity & entity)
        {return existsUnique(Ent::convert(entity));}

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    Manager::ExisteUni existsUnique(const Ent & entity)
        {return m_unique.existsUnique(entity);}

    //! Idem Manager::ExisteUni existsUnique(const Ent & entity) avec une conversion de référence.
    Manager::ExisteUni existsUnique(const Entity & entity)
        {return existsUnique(Ent::convert(entity));}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Entity & entity)
        {return get(Ent::convert(entity));}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Ent & entity)
    {
        prepare(m_sqlGet);
        m_link.setId(entity,0);
        exec();
        if(next())
        {
            m_link.fromRequete(entity);
            finish();
            return true;
        }
        else
        {
            finish();
            return false;
        }
    }

    //! Renvoie la liste des entités de la table ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Ent> getList(int ordre)
    {
        prepare(m_sqlGetList.arg(m_link.attribut(ordre)));
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Ent> getList(int cle, const QVariant & value, int ordre)
    {
        prepare(m_sqlGetList1Where1.arg(m_link.attribut(cle), m_link.attribut(ordre)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    ListEntities<Ent> getList(int cle, const QVariant & value, int ordre1, int ordre2)
    {
        prepare(m_sqlGetList1Where2.arg(m_link.attribut(cle), m_link.attribut(ordre1), m_link.attribut(ordre2)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Ent> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int ordre)
    {
        prepare(m_sqlGetList2Where1.arg(m_link.attribut(cle1), m_link.attribut(cle2), m_link.attribut(ordre)));
        bindValue(0,value1);
        bindValue(1,value2);
        return listFormRequete();
    }

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant les mêmes valeurs pour les attributs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool getUnique(Entity & entity)
        { return getUnique(Ent::convert(entity));}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant les mêmes valeurs pour les attributs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool getUnique(Ent & entity)
    {
        if(existsUnique(entity) == Manager::Tous)
        {
            return get(entity);
        }
        else
        {
            return false;
        }
    }

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes attributs (identifiant compris).
    bool sameInBdd(const Entity &entity)
        {return sameInBdd(Ent::convert(entity));}

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes attributs (identifiant compris).
    bool sameInBdd(const Ent &entity)
    {
        Ent entityT(entity.id());
        if(get(entityT))
        {
            return entityT == entity;
        }
        else
        {
            return false;
        }
    }

    //! Enregistre l'entité entity en base de donnée et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void save(Entity & entity)
        {save(Ent::convert(entity));}

    //! Enregistre l'entité entity en base de donnée.
    void save(const Entity & entity)
        {save(Ent::convert(entity));}

    //! Enregistre l'entité entity en base de donnée et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void save(Ent & entity)
        {SAVE}

    //! Enregistre l'entité entity en base de donnée.
    void save(const Ent & entity)
        {SAVE}

    //! Modifie le pointeur vers l'objet requête.
    void setRequete(QSqlQuery * req);

protected:
    //! Insert la nouvelle entité entity dans la base de donnée
    //! et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void add(Ent & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(entity);
        exec();
        exec(m_sqllastId);
        entity.setId(toInt());
        finish();
    }

    //! Insert la nouvelle entité entity dans la base de donnée.
    void add(const Ent & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(entity);
        execFinish();
    }

    //! Supprime de la table en base de donnée l'entité d'identifiant id.
    void del(int id)
    {
        prepare(m_sqlDelete);
        bindValue(0,id);
        execFinish();
    }

    //! Construit la liste des entités correspondant une requète de type sqlGetList.
    ListEntities<Entity> listFormRequete()
    {
        exec();
        ListEntities<Entity> liste;
        while(next())
        {
            liste.append(m_link.newFromRequete());
        }
        finish();
        return liste;
    }

    //! Message d'erreurs si l'entité entity n'est pas valide.
    QString messageErreurs(const Entity & entity) const;

    //! Message d'erreurs s'il existe déjà en base de donnée une entité ayant les mêmes valeurs d'attributs uniques que entity.
    QString messageErreursUnique(const Entity & entity) const;

    //! Met à jour l'entité entity en base de donnée.
    void modify(const Ent & entity)
    {
        prepare(m_sqlModify);
        m_link.bindValues(entity);
        m_link.setId(entity);
        execFinish();
    }

    //! Renvoie la chaine des noms des attributs séparés par une virgule sans l'identifiant.
    const QString writeColonne() const;

    //! Renvoie la chaine "SELELCT attribut...FROM table WHERE".
    const QString writeSelectWhere() const;

    //! Renvoie la chaine correspondant à la requète d'insertion d'une ligne.
    const QString writeStringAddQuery() const;

    //! Renvoie la chaine correspondant à la requète de suppression d'une ligne.
    const QString writeStringDeleteQuery() const;

    //! Renvoie la chaine correspondant à la requète d'existence d'une ligne.
    const QString writeStringExistsQuery() const;

    //! Renvoie la chaine correspondant à la requète de lecture d'une ligne.
    const QString writeStringGetQuery() const;

    //! Renvoie la chaine correspondant à la requète de lecture d'une table.
    const QString writeStringGetListQuery() const;

    //! Renvoie la chaine correspondant à la requète de lecture d'une liste vérifiant une condition.
    const QString writeStringGetList1Where1Query() const;

    //! Renvoie la chaine correspondant à la requète de lecture d'une liste
    //! vérifiant une condition ordonnée suivant les valeurs de deux attributs.
    const QString writeStringGetList1Where2Query() const;

    //! Renvoie la chaine correspondant à la requète de lecture d'une liste vérifiant deux conditions.
    const QString writeStringGetList2Where1Query() const;

    //! Renvoie la chaine correspondant à la requète demandant l'identifiant de la dernière ligne insérée dans la table.
    const QString writeStringLastIdQuery() const;

    //! Renvoie la chaine correspondant à la requète de mis à jour d'une ligne.
    const QString writeStringModifyQuery() const;
};

template<class Ent> ManagerSql<Ent>::ManagerSql(QSqlQuery * req)
    : AbstractManagerSql(req),
      m_link(req),
      m_unique(req),
      m_sqlAdd(writeStringAddQuery()),
      m_sqlExists(writeStringExistsQuery()),
      m_sqlGet(writeStringGetQuery()),
      m_sqlGetList(writeStringGetListQuery()),
      m_sqlGetList1Where1(writeStringGetList1Where1Query()),
      m_sqlGetList1Where2(writeStringGetList1Where2Query()),
      m_sqlGetList2Where1(writeStringGetList2Where1Query()),
      m_sqllastId(writeStringLastIdQuery()),
      m_sqlModify(writeStringModifyQuery())
{}

template<class Ent> void ManagerSql<Ent>::creer()
{
    QString sql(InfoSql<Ent>::SqlCreate);
    sql = sql.arg(InfoSql<Ent>::Table);
    for(int i = 0; i != InfoSql<Ent>::NbrAtt; ++i)
        sql = sql.arg(InfoSql<Ent>::Att[i]);
    for(int i = 0; i != InfoSql<Ent>::NbrCleExt; ++i)
        sql = sql.arg(InfoSql<Ent>::CleExt[i]);
    execFinish(sql);
}

template<class Ent> QString ManagerSql<Ent>::messageErreurs(const Entity & entity) const
{
    QString message("Entité invalide:");
    message.append(Info<Ent>::Name).append(" d'identifiant:").append(QString::number(entity.id())).append("\n");
    /*if(!entity.erreurs().isEmpty())
    {
        message.append("\n Erreurs :\n");
        QPair<int,int> erreur;
        foreach (erreur, entity.erreurs())
        {
            message.append(QString::number(erreur.second)+" :"+Ent::attribut.at(erreur.second)+"\n");
        }
    }
    else
    {
        message.append("/n pas d'erreurs");
    }*/
    return message;
}

template<class Ent> QString ManagerSql<Ent>::messageErreursUnique(const Entity & entity) const
{
    QString message("Entité ayant les même valeurs d'attributs unique déjà présente dans la base de donnée.\n");
    message.append(Info<Ent>::Name).append(" d'identifiant:").append(QString::number(entity.id())).append("\n");
    if(InfoSql<Ent>::NbrAttUnique != 0)
    {
        message.append("Valeurs Uniques:\n");
        for(int i = 0; i != InfoSql<Ent>::NbrAttUnique; ++i)
            message.append(InfoSql<Ent>::Att[InfoSql<Ent>::AttUnique[i]]).append("\n");
    }
    return message;
}

template<class Ent> void ManagerSql<Ent>::setRequete(QSqlQuery * req)
{
    AbstractManagerSql::setRequete(req);
    m_link.setRequete(req);
    m_unique.setRequete(req);
}

template<class Ent> const QString ManagerSql<Ent>::writeColonne() const
{
    QString colonnes;
    for(int i = 0; i != InfoSql<Ent>::NbrAtt-1; ++i) colonnes.append(InfoSql<Ent>::Att[i]).append(",");
    colonnes.chop(1);
    return colonnes;
}

template<class Ent> const QString ManagerSql<Ent>::writeSelectWhere() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(",ID FROM ").append(InfoSql<Ent>::Table).append(" WHERE");
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringAddQuery() const
{
    QString sql("INSERT INTO ");
    sql.append(InfoSql<Ent>::Table).append(" (").append(writeColonne()).append(") VALUES (");
    for(int i = 0; i != InfoSql<Ent>::NbrAtt-1; ++i) sql.append("?,");
    sql.chop(1);
    sql.append(")");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringDeleteQuery() const
{
    QString sql("DELETE FROM ");
    sql.append(InfoSql<Ent>::Table).append(" WHERE ID=?");
    sql.squeeze();
    return sql;
}


template<class Ent> const QString ManagerSql<Ent>::writeStringExistsQuery() const
{
    QString sql("SELECT 1 FROM ");
    sql.append(InfoSql<Ent>::Table).append(" WHERE ID=? LIMIT 1");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringGetQuery() const
{
    QString sql(writeSelectWhere());
    sql.append(" ID=?");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringGetListQuery() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(",ID FROM ").append(InfoSql<Ent>::Table).append(" ORDER BY %1");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringGetList1Where1Query() const
{
    QString sql(writeSelectWhere());
    sql.append(" %1=? ORDER BY %2");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringGetList1Where2Query() const
{
    QString sql(writeSelectWhere());
    sql.append(" %1=? ORDER BY %2,%3");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringGetList2Where1Query() const
{
    QString sql(writeSelectWhere());
    sql.append(" %1=?,%2=? ORDER BY %3");
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringLastIdQuery() const
{
    QString sql("SELECT last_insert_rowid() FROM ");
    sql.append(InfoSql<Ent>::Table);
    sql.squeeze();
    return sql;
}

template<class Ent> const QString ManagerSql<Ent>::writeStringModifyQuery() const
{
    QString sql("UPDATE ");
    sql.append(InfoSql<Ent>::Table).append(" SET ");
    for(int i = 0; i != InfoSql<Ent>::NbrAtt-1; ++i) sql.append(InfoSql<Ent>::Att[i]).append("=?,");
    sql.chop(1);
    sql.append("WHERE ID=?");
    sql.squeeze();
    return sql;
}

#endif // MANAGERSQL_H
