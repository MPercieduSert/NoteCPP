/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef LINKSQL_H
#define LINKSQL_H

/*! \defgroup groupeLinkSql Liens
 * \ingroup groupeManager
 * \brief Ensemble des liens entre les entités de programation et les entités en base de donnée.
 */

/*! \defgroup groupeInfoLinkSql Informations SQL
 * \ingroup groupeLinkSql
 * \brief Ensemble des informations sur les entités en base de donnée.
 */

/*! \defgroup groupeBaseLinkSql Classes de base des liens SQL
 * \ingroup groupeLinkSql
 * \brief Ensemble des classes de base des liens.
 */

#include <array>
#include <QSqlQuery>
#include "AttributsMacroLinkSql.h"
#include "Manager.h"

/*! \ingroup groupeBaseLinkSql
 * \brief Interface mère des liens entre les entités de programation et les entités en base de donnée.
 */
template<class T,class Info> class LinkSql : public Info
{       
public:
    using Ent = T;

    static std::array<QString, Info::NbrAtt> AttString;

    //! Construteur.
    LinkSql()
    {
        for(int i = 0; i != Info::NbrAtt; ++i)
        {
            AttString[i] = QString(Info::Att[i]);
            AttString[i].squeeze();
        }
    }

    //! Destructeur.
    ~LinkSql()
     {}

    //! Retourne le nom en base de donnee du n-ième attribut.
    static const QString & attribut(int n)
        {return AttString.at(n);}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    virtual void bindValues(const Ent & entity) = 0;

    //! Hydrate l'entité entity avec à partir de la requète.
    virtual void fromRequete(Ent & entity) const = 0;

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    virtual Ent * newFromRequete() const = 0;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    //! Si le test est positif, l'identitfiant de l'entité entity est remplacé par celui l'entité en base de donnée
    //! ayant les mêmes valeurs d'attributs uniques.
    virtual Manager::ExisteUni existsUnique(Ent & entity) = 0;

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que l'entité entity en base de donnée.
    virtual Manager::ExisteUni existsUnique(const Ent & entity) = 0;
};

/*! \ingroup groupeBaseLinkSql
 * \brief Classe mère des liens entre les entités de programation et les entités en base de donnée.
 */
template<class Ent, class Info> class IdLinkSql : public LinkSql<Ent,Info>, public IdAttributSql<Ent>
{
protected:
    using IdAttributSql<Ent>::id;    

public:
    using IdAttributSql<Ent>::setId;

    //! Constructeur.
    IdLinkSql(QSqlQuery & req)
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

protected:
    //! Constructeur protégé.
    IdLinkSql()
    {}
};

#endif // LINKSQL_H
