/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef DONNEELINKSQL_H
#define DONNEELINKSQL_H

#include "AttributsLinkSql.h"
#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "DonneeInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Donnee de programation et sa représentation en base de donnée.
 */
class DonneeLinkSql : public LinkSqlNoUnique<TypeNomLinkSql<Donnee,DonneeInfoSql> >, public CardAttributSql<Donnee>, public SurAttributSql<Donnee>, public TpValAttributSql<Donnee>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    DonneeLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Donnee & entity)
    {
        LinkSqlNoUnique::bindValues(entity);
        setCard(entity);
        setSur(entity);
        setTpVal(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Donnee & entity) const
    {
        LinkSqlNoUnique::fromRequete(entity);
        entity.setCard(card());
        entity.setSur(sur());
        entity.setTpVal(tpVal());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Donnee * newFromRequete() const
    {
        return new Donnee(card(),nom(),sur(),type(),tpVal(),id());
    }
};

#endif // DONNEELINKSQL_H
