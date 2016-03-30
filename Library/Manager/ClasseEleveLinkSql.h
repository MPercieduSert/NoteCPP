/*Auteur: PERCIE DU SERT Maxime
 *Date: 25/03/2016
 */
#ifndef CLASSEELEVELINKSQL
#define CLASSEELEVELINKSQL

#include "AttributsLinkSql.h"
#include "LinkSqlRelation.h"
#include "LinkSqlUnique.h"
#include "ClasseEleveInfoSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entité ClasseEleve de programation et sa représentation en base de donnée.
 */
class ClasseEleveLinkSql : public RelationLinkSqlUnique<RelationLinkSql<ClasseEleve,ClasseEleveInfoSql> >,
        public EntreeAttributSql<ClasseEleve>,
        public SortieAttributSql<ClasseEleve>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ClasseEleveLinkSql(QSqlQuery & requete)
        : ReqSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const ClasseEleve & entity)
    {
        LinkSqlUniqueSimple::bindValues(entity);
        setEntree(entity);
        setSortie(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(ClasseEleve & entity) const
    {
        LinkSqlUniqueSimple::fromRequete(entity);
        entity.setEntree(entree());
        entity.setSortie(sortie());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    ClasseEleve * newFromRequete() const
    {
        return new ClasseEleve(id1(),id2(),entree(),sortie(),id());
    }
};

#endif // CLASSEELEVELINKSQL

