/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/03/2016
 */
#ifndef ATTRIBUTLINKSQL
#define ATTRIBUTLINKSQL

#include "AttributsLinkSql.h"
#include "LinkSqlNom.h"
#include "LinkSqlUnique.h"
#include "AttributInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité Attribut de programation et sa représentation en base de donnée.
 */
class AttributLinkSql : public LinkSqlNoUnique<NcNomLinkSql<Attribut,AttributInfoSql> >,
        public PrBaremeAttributSql<Attribut>,
        public PrCommentaireAttributSql<Attribut>,
        public PrCorrectionAttributSql<Attribut>,
        public PrCoursAttributSql<Attribut>,
        public PrExerciceAttributSql<Attribut>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    AttributLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Attribut & entity)
    {
        LinkSqlNoUnique::bindValues(entity);
        setPrBareme(entity);
        setPrCommentaire(entity);
        setPrCorrection(entity);
        setPrCours(entity);
        setPrExercice(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Attribut & entity) const
    {
        LinkSqlNoUnique::fromRequete(entity);
        entity.setPrBareme(prBareme());
        entity.setPrCommentaire(prCommentaire());
        entity.setPrCorrection(prCorrection());
        entity.setPrCours(prCours());
        entity.setPrExercice(prExercice());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Attribut * newFromRequete() const
    {
        return new Attribut(nom(),prBareme(),prCommentaire(),prCorrection(),prCours(),prExercice(),id(),nc());
    }
};

#endif // ATTRIBUTLINKSQL
