/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */
#ifndef ANNEELINKSQL
#define ANNEELINKSQL

#include "AttributsLinkSql.h"
#include "LinkSql.h"
#include "LinkSqlUnique.h"
#include "AnneeInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Annee de programation et sa représentation en base de donnée.
 */
class AnneeLinkSql : public LinkSqlUniqueSimple<IdLinkSql<Annee,AnneeInfoSql> >, public AnAttributSql<Annee>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    AnneeLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Annee & entity)
    {
        LinkSqlUniqueSimple::bindValues(entity);
        setAn(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Annee & entity) const
    {
        LinkSqlUniqueSimple::fromRequete(entity);
        entity.setAn(an());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Annee * newFromRequete() const
    {
        return new Annee(an(),id());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Annee &entity)
        {setAn(entity,AnUnique);}
};

#endif // ANNEELINKSQL

