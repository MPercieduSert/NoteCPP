/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef MANAGERSQL_H
#define MANAGERSQL_H

#include "Manager.h"
#include "ReqSql.h"


/*! \ingroup groupeBaseManager
 * \brief Classe template permettant d'instancier les différents manageurs.
 *
 * Classe template permettant d'instancier les différents manageurs.
 * Cette classe implémente les méthodes virtuelles pures de sa classe mère.
 * La classe Ent est la classe d'entité de programmation
 * et la classe Link est le lien avec les entités en base de donnée.
 */
template<class Link> class ManagerSql : public Manager, public ReqSql
{
public:
    typedef typename Link::Ent Ent;

protected:
    Link m_link;             //!< Lien.
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
    ManagerSql(QSqlQuery & req);

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
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    Manager::ExisteUni existsUnique(Entity & entity)
    {
        return m_link.existsUnique(Ent::convert(entity));
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    Manager::ExisteUni existsUnique(const Entity & entity)
    {
        return m_link.existsUnique(Ent::convert(entity));
    }

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrée en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Entity & entity)
    {
        prepare(m_sqlGet);
        m_link.setId(entity,0);
        exec();
        if(next())
        {
            m_link.fromRequete(Ent::convert(entity));
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
    ListEntities<Entity> getList(int ordre)
    {
        prepare(m_sqlGetList.arg(Link::attribut(ordre)));
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(int cle, const QVariant & value, int ordre)
    {
        prepare(m_sqlGetList1Where1.arg(Link::attribut(cle), Link::attribut(ordre)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    ListEntities<Entity> getList(int cle, const QVariant & value, int ordre1, int ordre2)
    {
        prepare(m_sqlGetList1Where2.arg(Link::attribut(cle), Link::attribut(ordre1), Link::attribut(ordre2)));
        bindValue(0,value);
        return listFormRequete();
    }

    //! Renvoie la liste des entités de la table vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int ordre)
    {
        prepare(m_sqlGetList2Where1.arg(Link::attribut(cle1), Link::attribut(cle2), Link::attribut(ordre)));
        bindValue(0,value1);
        bindValue(1,value2);
        return listFormRequete();
    }

    //! Teste s'il y a dans la base de donnée une entité ayant exactement les mêmes attributs (identifiant compris).
    bool sameInBdd(const Entity &entity)
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

protected:
    //! Insert la nouvelle entité entity dans la base de donnée
    //! et assigne l'identifiant de l'entité insérée en base de donnée à entity.
    void add(Entity & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(Ent::convert(entity));
        exec();
        exec(m_sqllastId);
        entity.setId(toInt());
        finish();
    }

    //! Insert la nouvelle entité entity dans la base de donnée.
    void add(const Entity & entity)
    {
        prepare(m_sqlAdd);
        m_link.bindValues(Ent::convert(entity));
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
    void modify(const Entity & entity)
    {
        prepare(m_sqlModify);
        m_link.bindValues(Ent::convert(entity));
        m_link.setId(entity);
        execFinish();
    }

    //! Renvoie la chaine des noms des attributs séparés par une virgule sans l'identifiant.
    const QString writeColonne() const;

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

template<class Link> ManagerSql<Link>::ManagerSql(QSqlQuery & req)
: ReqSql(req),
  m_link(req),
  m_sqlAdd(writeStringAddQuery()),
  m_sqlExists(writeStringExistsQuery()),
  m_sqlGet(writeStringGetQuery()),
  m_sqlGetList(writeStringGetListQuery()),
  m_sqlGetList1Where1(writeStringGetList1Where1Query()),
  m_sqlGetList1Where2(writeStringGetList1Where2Query()),
  m_sqlGetList2Where1(writeStringGetList2Where1Query()),
  m_sqllastId(writeStringLastIdQuery()),
  m_sqlModify(writeStringModifyQuery())
{
    m_requete.setForwardOnly(true);
}

template<class Link> void ManagerSql<Link>::creer()
{
    QString sql(Link::SqlCreate);
    sql = sql.arg(Link::Table);
    for(int i = 0; i != Link::NbrAtt; ++i)
        sql = sql.arg(Link::attribut(i));
    for(int i = 0; i != Link::NbrCleExt; ++i)
        sql = sql.arg(Link::CleExt[i]);
    execFinish(sql);
}

template<class Link> QString ManagerSql<Link>::messageErreurs(const Entity & /*entity*/) const
{
    QString message("Entité invalide:");
    /*message.append(Ent::Name).append(" d'identifiant:").append(QString::number(entity.idEntity())).append("\n");
    if(!entity.erreurs().isEmpty())
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

template<class Link> QString ManagerSql<Link>::messageErreursUnique(const Entity & entity) const
{
    QString message("Entité ayant les même valeurs d'attributs unique déjà présente dans la base de donnée.\n");
    message.append(Ent::name()).append(" d'identifiant:").append(QString::number(entity.idEntity())).append("\n");
    //message.append("Valeurs Uniques:\n");
    //for(int i = 0; i != Ent::NbrAttUn; ++i)
    //    message.append(Ent::attribut[Ent::attributUn[i]]).append("\n");
    return message;
}

template<class Link> const QString ManagerSql<Link>::writeColonne() const
{
    QString colonnes;
    for(int i = 1; i != Link::NbrAtt; ++i) colonnes.append(Link::attribut(i)).append(",");
    colonnes.chop(1);
    return colonnes;
}

template<class Link> const QString ManagerSql<Link>::writeStringAddQuery() const
{
    QString sql("INSERT INTO ");
    sql.append(Link::Table).append(" (").append(writeColonne()).append(") VALUES (");
    for(int i = 1; i != Link::NbrAtt; ++i) sql.append("?,");
    sql.chop(1);
    sql.append(")");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringDeleteQuery() const
{
    QString sql("DELETE FROM ");
    sql.append(Link::Table).append(" WHERE ID=?");
    sql.squeeze();
    return sql;
}


template<class Link> const QString ManagerSql<Link>::writeStringExistsQuery() const
{
    QString sql("SELECT 1 FROM ");
    sql.append(Link::Table).append(" WHERE ID=? LIMIT 1");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringGetQuery() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(",ID FROM ").append(Link::Table).append(" WHERE ID=?");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringGetListQuery() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(",ID FROM ").append(Link::Table).append(" ORDER BY %1");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringGetList1Where1Query() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(",ID FROM ").append(Link::Table).append(" WHERE %1=? ORDER BY %2");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringGetList1Where2Query() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(",ID FROM ").append(Link::Table).append(" WHERE %1=? ORDER BY %2,%3");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringGetList2Where1Query() const
{
    QString sql("SELECT ");
    sql.append(writeColonne()).append(" FROM ").append(Link::Table).append(",ID WHERE %1=?,%2=? ORDER BY %3");
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringLastIdQuery() const
{
    QString sql("SELECT last_insert_rowid() FROM ");
    sql.append(Link::Table);
    sql.squeeze();
    return sql;
}

template<class Link> const QString ManagerSql<Link>::writeStringModifyQuery() const
{
    QString sql("UPDATE ");
    sql.append(Link::Table).append(" SET ");
    for(int i = 0; i != Link::NbrAtt-1; ++i) sql.append(Link::attribut(i)).append("=?,");
    sql.chop(1);
    sql.append("WHERE ID=?");
    sql.squeeze();
    return sql;
}

#endif // MANAGERSQL_H
