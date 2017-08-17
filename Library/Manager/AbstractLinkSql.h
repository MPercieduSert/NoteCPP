/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ABSTRACTLINKSQL_H
#define ABSTRACTLINKSQL_H

#include <QSqlQuery>
#include <stdexcept>
#include "ReqSql.h"
#include "../Entities/AttributMultiple.h"
#include "../Entities/Entity.h"

/*! \defgroup groupeLinkSql Liens
 * \ingroup groupeManager
 * \brief Ensemble des liens entre les entités de programation et les entités en base de donnée.
 */

/*! \defgroup groupeLinkSqlBase Classes de base des liens SQL
 * \ingroup groupeLinkSql
 * \brief Ensemble des classes de base des liens.
 */

/*! \defgroup groupeLinkSqlSpe Spéciation linkSql
 * \ingroup groupeLinkSql
 * \brief Spéciations des liens SQL.
 */

/*! \ingroup groupeLinkSqlBase
 * \brief Interface mère des liens entre les entités de programation et les entités en base de donnée.
 */
class AbstractLinkSql : public virtual ReqSql
{
protected:
    int m_nbrAtt;
    QVector<QString> m_attSql;
    QString m_table;

public:
    //! Construteur.
    AbstractLinkSql(const QString & table, const QMap<int,QString> & att)
        : m_nbrAtt(att.size() + 1),
          m_attSql(m_nbrAtt),
          m_table(table)
    {
        m_attSql[Entity::Id] = QString("ID");
        m_attSql[Entity::Id].squeeze();
        for(QMap<int,QString>::const_iterator i = att.cbegin(); i != att.cend(); ++i)
        {
            if(i.key() <= 0 || i.key() >= m_nbrAtt)
                throw std::invalid_argument(QString("Indice d'attribut sql invalide de la table: ")
                                            .append(m_table).append(", attribut: ")
                                            .append(QString::number(i.key())).append("->")
                                            .append(i.value()).toStdString());
            m_attSql[i.key()] = i.value();
            m_attSql[i.key()].squeeze();
        }
    }

    //! Destructeur.
    ~AbstractLinkSql()
     {}

    //! Retourne le nom en base de donnee du n-ième attribut.
    const QString & attribut(int n) const
        {return m_attSql.at(n);}

    //! Renvoie la requète créant la table correspondant à l'entité dans la base de donnée.
    QString creer(const QMap<int, QPair<bdd::createSql, bool> > &attCaract, const QMap<int,QString> & foreignKey) const;

    //! Accesseur de l'identifiant.
    int id(int pos = Entity::Id) const
        {return value<int>(pos);}

    //! Retourne le nombre d'attributs.
    int nbrAtt() const
        {return m_nbrAtt;}

    //! Mutateur de l'identifiant.
    void setId(const Entity & entity, int pos = 0)
        {m_requete->bindValue(pos,entity.id());}

    //! Renvoie le nom de la table.
    const QString & table() const
        {return m_table;} 
};

template<class Attribut, class AttPre, class AttSuiv, int Pos> class LinkSqlDichot;
template<class Attribut, int Pos = 0> using LinkSqlAttribut = LinkSqlDichot<Attribut, typename Attribut::AttPre, typename Attribut::AttSuiv, Pos>;

template<class Attribut, class AttPre, class AttSuiv, int Pos> class LinkSqlDichot :
        public LinkSqlAttribut<AttPre, Pos>,
        public LinkSqlAttribut<AttSuiv, AttPre::NbrAtt + Pos>
{
public:
    enum {PosPre = Pos, PosSuiv = AttPre::NbrAtt + Pos};
    using LinkPre = LinkSqlAttribut<AttPre, PosPre>;
    using LinkSuiv = LinkSqlAttribut<AttSuiv, PosSuiv>;

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Attribut & entity)
    {
        LinkPre::bindValues(entity);
        LinkSuiv::bindValues(entity);
    }

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(Attribut & entity)
    {
        LinkPre::bindValues(entity);
        LinkSuiv::bindValues(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Attribut & entity) const
    {
        LinkPre::fromRequete(entity);
        LinkSuiv::fromRequete(entity);
    }
};

template<class Attribut, int Pos> class LinkSqlDichot<Attribut, NoAttribut, NoAttribut, Pos> : public virtual ReqSql
{
public:
    enum {PosPre = Pos};
    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Attribut & entity)
        {bindValue(PosPre - 1,entity.getToBdd());}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(Attribut & entity)
        {bindValue(PosPre - 1,entity.getToBdd());}

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Attribut & entity) const
        {entity.set(value<typename Attribut::AttType>(PosPre));}
};

template<> class LinkSqlDichot<Entity, NoAttribut, NoAttribut, 0> : public virtual ReqSql
{
public:
    enum {PosPre = 0};
    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Entity & /*entity*/)
        {}

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Entity & entity) const
        {entity.setId(value<Entity::AttType>(PosPre));}
};

template<class ENT> class LinkSql : public AbstractLinkSql,
        public LinkSqlAttribut<ENT>
{
public:
    using AbstractLinkSql::AbstractLinkSql;
    using LinkSqlAttribut<ENT>::fromRequete;

    //! Destructeur.
    ~LinkSql() {}

    //! Crée dynamiquement une nouvelle entité de type Classe, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    ENT * newFromRequete() const
    {
        ENT * entity = new ENT(id());
        fromRequete(*entity);
        return entity;
    }
};

#endif // ABSTRACTLINKSQL_H
