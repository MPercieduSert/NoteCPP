/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef ELEVELINKSQL_H
#define ELEVELINKSQL_H

#include "AttributsLinkSql.h"
#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "EleveInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Eleve de programation et sa représentation en base de donnée.
 */
class EleveLinkSql : public LinkSqlUniqueSimple<NomLinkSql<Eleve,EleveInfoSql> >, public FilleAttributSql<Eleve>, public NaissanceAttributSql<Eleve>, public PrenomAttributSql<Eleve>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    EleveLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Eleve & entity)
    {
        LinkSqlUniqueSimple::bindValues(entity);
        setFille(entity);
        setNaissance(entity);
        setPrenom(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Eleve & entity) const
    {
        LinkSqlUniqueSimple::fromRequete(entity);
        entity.setFille(fille());
        entity.setNaissance(naissance());
        entity.setPrenom(prenom());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Eleve * newFromRequete() const
    {
        return new Eleve(fille(),naissance(),nom(),prenom(),id());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Eleve & entity)
    {
        setNaissance(entity,EleveInfoSql::NaissanceUnique);
        setNom(entity,EleveInfoSql::NomUnique);
        setPrenom(entity,EleveInfoSql::PrenomUnique);
    }
};

#endif // ELEVELINKSQL_H
