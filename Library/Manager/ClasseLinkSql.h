/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */

#ifndef CLASSELINKSQL_H
#define CLASSELINKSQL_H

#include "AttributsLinkSql.h"
#include "LinkSqlRelation.h"
#include "LinkSqlUnique.h"
#include "ClasseInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Classe de programation et sa représentation en base de donnée.
 */
class ClasseLinkSql : public LinkSqlUniqueSimple<NumRelationLinkSql<Classe,ClasseInfoSql> >, public IdNivAttributSql<Classe>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ClasseLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Classe & entity)
    {
        LinkSqlUniqueSimple::bindValues(entity);
        setIdNiv(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Classe & entity) const
    {
        LinkSqlUniqueSimple::fromRequete(entity);
        entity.setIdNiv(idNiv());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Classe * newFromRequete() const
    {
        return new Classe(id1(),id2(),idNiv(),num(),id());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Classe & entity)
    {
        setId1(entity,ClasseInfoSql::IdAnUnique);
        setId2(entity,ClasseInfoSql::IdEtabUnique);
        setIdNiv(entity,ClasseInfoSql::IdNivUnique);
        setNum(entity,ClasseInfoSql::NumUnique);
    }
};

#endif // CLASSELINKSQL_H
