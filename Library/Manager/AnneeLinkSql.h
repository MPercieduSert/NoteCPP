/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ANNEELINKSQL_H
#define ANNEELINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/Annee.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Annee de programation et sa représentation en base de donnée.
 */

class AnneeLinkSql : public LinkSqlUniqueSimple<Annee>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    AnneeLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Annee>(requete,writeStringUnique())
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Annee & entity)
        {m_requete.bindValue(Annee::AnneePos,entity.annee());}

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Annee & entity)
        {entity.setAnnee(m_requete.value(Annee::AnneePos).toInt());}

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Annee * newFromRequete()
    {
        return new Annee(m_requete.value(Annee::AnneePos).toInt(),
                         m_requete.value(Annee::IdPos).toInt());
    }
    
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Annee &entity)
        {m_requete.bindValue(0,entity.annee());}

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // ANNEELINKSQL_H
