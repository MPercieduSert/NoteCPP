/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ABSTRACTLINKSQL_H
#define ABSTRACTLINKSQL_H

#include <QSqlQuery>
#include <stdexcept>
#include "ReqSql.h"
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

//Attribut

//! \ingroup groupeLinkSqlBase
//! Macro définisant les attributs des liens de type différent de QVariant.
#define ATTRIBUT_LINK(ENT,NOM,nom,TYPE) /*! \brief Accesseur. */ \
    TYPE nom (int pos = ENT::NOM) const {return value<TYPE>(pos);} \
    /*! \brief Mutateurs. */ \
    void set ## NOM (const ENT & entity,int pos = ENT::NOM-1) {bindValue(pos,entity.nom());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les attributs des liens de type diférent de QVariant.
#define ATTRIBUT_LINK_NULL_TO_ZERO(ENT,NOM,nom,TYPE) /*! \brief Accesseur. */ \
    TYPE nom (int pos = ENT::NOM) const {return value<TYPE>(pos);} \
    /*! \brief Mutateurs. */ \
    void set ## NOM (const ENT & entity,int pos = ENT::NOM-1) {bindValue(pos,zeroToNull(entity.nom()));}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les attributs des liens de type QVariant.
#define ATTRIBUT_QVARIANT_LINK(ENT,NOM,nom) /*! \brief Accesseur. */ \
    QVariant nom (ENT::Position pos = ENT::NOM) const {return m_requete->value(pos);} \
    /*! \brief Mutateurs. */ \
    void set ## NOM (const ENT & entity,int pos = ENT::NOM-1) {m_requete->bindValue(pos,entity.nom());}

// Membre

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_1(MERE,CLASSE,ENT,NOM,nom) \
    /*! \brief Constructeur.*/\
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM(nom());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_2(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_3(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_4(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity); \
        set ## NOM4(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3()); \
        entity.set ## NOM4(nom4());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_5(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity); \
        set ## NOM4(entity); \
        set ## NOM5(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3()); \
        entity.set ## NOM4(nom4()); \
        entity.set ## NOM5(nom5());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_6(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity); \
        set ## NOM4(entity); \
        set ## NOM5(entity); \
        set ## NOM6(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3()); \
        entity.set ## NOM4(nom4()); \
        entity.set ## NOM5(nom5()); \
        entity.set ## NOM6(nom6());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_7(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6,NOM7,nom7) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity); \
        set ## NOM4(entity); \
        set ## NOM5(entity); \
        set ## NOM6(entity); \
        set ## NOM7(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3()); \
        entity.set ## NOM4(nom4()); \
        entity.set ## NOM5(nom5()); \
        entity.set ## NOM6(nom6()); \
        entity.set ## NOM7(nom7());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_8(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6,NOM7,nom7,NOM8,nom8) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity); \
        set ## NOM4(entity); \
        set ## NOM5(entity); \
        set ## NOM6(entity); \
        set ## NOM7(entity); \
        set ## NOM8(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3()); \
        entity.set ## NOM4(nom4()); \
        entity.set ## NOM5(nom5()); \
        entity.set ## NOM6(nom6()); \
        entity.set ## NOM7(nom7()); \
        entity.set ## NOM8(nom8());}

//! \ingroup groupeLinkSqlBase
//! Macro définisant les membres d'une classe lien ayant un attribut de plus que la classe mère.
#define MEMBRE_LINK_ATT_9(MERE,CLASSE,ENT,NOM1,nom1,NOM2,nom2,NOM3,nom3,NOM4,nom4,NOM5,nom5,NOM6,nom6,NOM7,nom7,NOM8,nom8,NOM9,nom9) \
    /*! \brief Constructeur.*/ \
    CLASSE(const QString & table, const QMap<int,QString> & att) : MERE(table,att) {} \
    /*! \brief Destructeur.*/ \
    ~CLASSE() {} \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée.*/ \
    void bindValues(const ENT & entity) { \
        MERE::bindValues(entity); \
        set ## NOM1(entity); \
        set ## NOM2(entity); \
        set ## NOM3(entity); \
        set ## NOM4(entity); \
        set ## NOM5(entity); \
        set ## NOM6(entity); \
        set ## NOM7(entity); \
        set ## NOM8(entity); \
        set ## NOM9(entity);} \
    /*! Hydrate l'entité entity avec à partir de la requète.*/ \
    void fromRequete(ENT & entity) const{ \
        MERE::fromRequete(entity); \
        entity.set ## NOM1(nom1()); \
        entity.set ## NOM2(nom2()); \
        entity.set ## NOM3(nom3()); \
        entity.set ## NOM4(nom4()); \
        entity.set ## NOM5(nom5()); \
        entity.set ## NOM6(nom6()); \
        entity.set ## NOM7(nom7()); \
        entity.set ## NOM8(nom8()); \
        entity.set ## NOM9(nom9());}

// Only

//! \ingroup groupeLinkSqlBase
//! Macro définisant la base des classes onlyLinkSql.
#define BASE_ONLY_LINK(MERE,CLASSE) /*! \ingroup groupeLinkSqlBase */ \
    /*! \brief Classe mère des liens ayant seulement les attributs de MERE.*/ \
    template<class Ent> class CLASSE : public MERE { \
    public: \
        using MERE::MERE; \
        /*! \brief Destructeur.*/ \
        ~CLASSE() {}

//! \ingroup groupeLinkSqlBase
//! Macro définisant la fin des classes onlyLinkSql.
#define END_ONLY_LINK /*! \brief Crée dynamiquement une nouvelle entité de type Ent, l'hydrate à partir de la requète SQL. Puis retourne un  pointeur vers cette nouvelle entité.*/ \
        Ent * newFromRequete() const

//! \ingroup groupeLinkSqlBase
//! Macro définisant les classes onlyLinkSql.
#define ONLY_LINK(MERE,CLASSE) BASE_ONLY_LINK(MERE,CLASSE) END_ONLY_LINK

//! \ingroup groupeLinkSqlBase
//! Macro définisant les classes onlyLinkSql à date du jour.
#define ONLY_LINK_DATE_CURRENT(MERE,CLASSE) BASE_ONLY_LINK(MERE,CLASSE) \
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée après avoir imposé la date et l'heure courante.*/\
    void bindValues(Ent & entity)\
    {entity.setDateTime(QDateTime::currentDateTime());\
    MERE::bindValues(entity);}\
    /*! \brief Transmet les valeurs des attributs à la requète SQL préparée après avoir imposé la date et l'heure courante.*/\
    void bindValues(const Ent & entity)\
    {Ent entityDt(entity);\
    entityDt.setDateTime(QDateTime::currentDateTime());\
    MERE::bindValues(entityDt);}\
    END_ONLY_LINK



/*! \ingroup groupeLinkSqlBase
 * \brief Interface mère des liens entre les entités de programation et les entités en base de donnée.
 */
class AbstractLinkSql : public ReqSql
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
                                            .append(m_table).append(", attribut: ").append(QString::number(i.key())).append("->").append(i.value()).toStdString());
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

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Entity & /*entity*/)
        {}

    //! Renvoie la requète créant la table correspondant à l'entité dans la base de donnée.
    QString creer(const QMap<int, QPair<bdd::createSql, bool> > &attCaract, const QMap<int,QString> & foreignKey) const;

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Entity & entity) const
        {entity.setId(id());}

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

#endif // ABSTRACTLINKSQL_H
