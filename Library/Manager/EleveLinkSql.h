/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef ELEVELINKSQL_H
#define ELEVELINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/Eleve.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Eleve de programation et sa représentation en base de donnée.
 */

class EleveLinkSql : public LinkSqlUniqueSimple<Eleve>
{
    USING_LINKSQL(Eleve)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    EleveLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Eleve>(requete,writeStringUnique())
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Eleve & entity)
    {
        m_requete.bindValue(Eleve::FillePos,entity.fille());
        m_requete.bindValue(Eleve::NaissancePos,entity.naissance());
        m_requete.bindValue(Eleve::NomPos,entity.nom());
        m_requete.bindValue(Eleve::PrenomPos,entity.prenom());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Eleve & entity)
    {
        entity.setFille(m_requete.value(Eleve::FillePos).toBool());
        entity.setNaissance(m_requete.value(Eleve::NaissancePos).toDate());
        entity.setNom(m_requete.value(Eleve::NomPos).toString());
        entity.setPrenom(m_requete.value(Eleve::PrenomPos).toString());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Eleve * newFromRequete()
    {
        return new Eleve(m_requete.value(Eleve::FillePos).toBool(),
                         m_requete.value(Eleve::NaissancePos).toDate(),
                         m_requete.value(Eleve::NomPos).toString(),
                         m_requete.value(Eleve::PrenomPos).toString(),
                         m_requete.value(Eleve::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Eleve & entity)
    {
        m_requete.bindValue(0,entity.naissance());
        m_requete.bindValue(1,entity.nom());
        m_requete.bindValue(2,entity.prenom());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // ELEVELINKSQL_H
