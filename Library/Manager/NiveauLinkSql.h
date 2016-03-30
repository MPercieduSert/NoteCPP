/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/03/2016
 */

#ifndef NIVEAULINKSQL_H
#define NIVEAULINKSQL_H

#include "AttributsLinkSql.h"
#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "NiveauInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Niveau de programation et sa représentation en base de donnée.
 */
class NiveauLinkSql : public NomLinkSqlUnique<NcNomLinkSql<Niveau,NiveauInfoSql> >, public IdTpAttributSql<Niveau>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NiveauLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Niveau & entity)
    {
        LinkSqlUniqueSimple::bindValues(entity);
        setIdTp(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Niveau & entity) const
    {
        LinkSqlUniqueSimple::fromRequete(entity);
        entity.setIdTp(idTp());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Niveau * newFromRequete() const
    {
        return new Niveau(idTp(),nc(),nom(),id());
    }
};

#endif // NIVEAULINKSQL_H
