/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */

#ifndef ETABLISSEMENTLINKSQL_H
#define ETABLISSEMENTLINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/Etablissement.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Etablissement de programation et sa représentation en base de donnée.
 */

class EtablissementLinkSql : public LinkSqlUniqueSimple<Etablissement>
{
    USING_LINKSQL(Etablissement)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    EtablissementLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Etablissement>(requete,writeStringUnique())
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Etablissement & entity)
    {
        m_requete.bindValue(Etablissement::NcPos,entity.nc());
        m_requete.bindValue(Etablissement::NomPos,entity.nom());
        m_requete.bindValue(Etablissement::TypePos,entity.type());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Etablissement & entity)
    {
        entity.setNc(m_requete.value(Etablissement::NcPos).toString());
        entity.setNom(m_requete.value(Etablissement::NomPos).toString());
        entity.setType(m_requete.value(Etablissement::TypePos).toInt());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Etablissement * newFromRequete()
    {
        return new Etablissement(m_requete.value(Etablissement::NcPos).toString(),
                                 m_requete.value(Etablissement::NomPos).toString(),
                                 m_requete.value(Etablissement::TypePos).toInt(),
                                 m_requete.value(Etablissement::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Etablissement & entity)
    {
        m_requete.bindValue(0,entity.nom());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // ETABLISSEMENTLINKSQL_H
