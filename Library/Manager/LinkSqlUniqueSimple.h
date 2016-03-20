/*Auteur: PERCIE DU SERT Maxime
 *Date: 08/03/2016
 */

#ifndef LINKSQLUNIQUESIMPLE_H
#define LINKSQLUNIQUESIMPLE_H

#include "LinkSql.h"

/*! \ingroup groupeLinkSql
 * \brief Classe mère des liens pour les entitée possédant une condition d'unicité simple.
 */

template<class T> class LinkSqlUniqueSimple : public LinkSql<T>
{
    USING_LINKSQL(T)

protected:
    const QString m_unique; //!< Requete Sql sur l'existence d'un ensemble d'attribus uniques.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur,
    //! le nom de la table associée à l'entitée dans la base de donnée, la liste des noms des colonnes
    //! et la requete sql d'unicité.
    LinkSqlUniqueSimple(QSqlQuery & requete, const QString & unique);

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée,
    //! dans le cas particulier où il y a un ensemble de valeurs unique.
    //! Si le test est positif, l'identitfiant de l'entitée entity est remplacé par celui l'entitée en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(T & entity)
    {
        m_requete.prepare(m_unique);
        bindValuesUnique(entity);
        exec();
        if(m_requete.next())
        {
            entity.setId(m_requete.value(0).toInt());
            m_requete.finish();
            return Manager::Tous;
        }
        else
        {
            m_requete.finish();
            return Manager::Aucun;
        }
    }

    //! Teste s'il existe une entitée ayant les mêmes valeurs d'attributs uniques que l'entitée entity en base de donnée,
    //! dans le cas particulier où il y a un ensemble de valeurs unique.
    virtual Manager::ExisteUni existsUnique(const T & entity)
    {
        m_requete.prepare(m_unique);
        bindValuesUnique(entity);
        exec();
        if(m_requete.next())
        {
            m_requete.finish();
            return Manager::Tous;
        }
        else
        {
            m_requete.finish();
            return Manager::Aucun;
        }
    }

    virtual void bindValuesUnique(const T & entity) = 0;
};

template<class T> LinkSqlUniqueSimple<T>::LinkSqlUniqueSimple(QSqlQuery & requete,
                                                              const QString & unique)
    : LinkSql<T>(requete),
      m_unique(unique)
    {}
#endif // LINKSQLUNIQUESIMPLE_H
