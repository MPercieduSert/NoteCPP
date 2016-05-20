/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ABSTRACTLINKSQL_H
#define ABSTRACTLINKSQL_H

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

#include <array>
#include <initializer_list>
#include <QSqlQuery>
#include "AttributsMacroLinkSql.h"
#include "InfoSql.h"

// Définition des Liens des entités de type prédéfini.
//! \ingroup groupeLinkSqlBase
//! Macro définisant les Liens des entités de type prédéfini.
#define LINK_SQL(ENTITY,TYPE) /*! \ingroup groupeLinkSqlSpe */ \
    /*! \brief Lien entre l'entité ENTITY de programation et sa représentation en base de donnée. */ \
    template<> class LinkSql<ENTITY> : public TYPE ## OnlyLinkSql<ENTITY>\
    {public:\
        /*! Construteur, transmettre en argument l'objet de requète utilisée par le manageur. */\
        LinkSql<ENTITY>(QSqlQuery * requete) : TYPE ## OnlyLinkSql<ENTITY>(requete){}\
        /*! Destructeur.*/\
        ~LinkSql<ENTITY>() {}};


/*! \ingroup groupeLinkSqlBase
 * \brief Interface mère des liens entre les entités de programation et les entités en base de donnée.
 */
template<class Ent> class AbstractLinkSql
{
protected:
    const QString m_table;
    std::array<QString, InfoSql<Ent>::NbrAtt> m_attString;

public:
    //! Construteur.
    AbstractLinkSql()
        : m_table(InfoSql<Ent>::Table)
    {
        for(int i = 0; i != InfoSql<Ent>::NbrAtt; ++i)
        {
            m_attString[i] = QString(InfoSql<Ent>::Att[i]);
            m_attString[i].squeeze();
        }
    }

    //! Destructeur.
    ~AbstractLinkSql()
     {}

    //! Retourne le nom en base de donnee du n-ième attribut.
    const QString & attribut(int n)
        {return m_attString.at(n);}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    virtual void bindValues(const Ent & entity) = 0;

    //! Hydrate l'entité entity avec à partir de la requète.
    virtual void fromRequete(Ent & entity) const = 0;

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    virtual Ent * newFromRequete() const = 0;
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités de programation et les entités en base de donnée.
 */
template<class Ent> class IdLinkSql : public AbstractLinkSql<Ent>, public IdAttributSql<Ent>
{
public:
    using IdAttributSql<Ent>::id;
    using IdAttributSql<Ent>::setId;

    //! Constructeur.
    IdLinkSql(QSqlQuery * req)
        : ReqSql(req)
    {}

    //! Destructeur.
    ~IdLinkSql()
     {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Ent & entity)
        {setId(entity);}

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Ent & entity) const
        {entity.setId(id());}

    /*//! Modifie le pointeur vers l'objet requête.
    void setRequete(QSqlQuery * req)
        {setRequete(req);}*/

protected:
    //! Constructeur protégé.
    IdLinkSql()
    {}
};

#endif // ABSTRACTLINKSQL_H
