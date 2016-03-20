/*Auteur: PERCIE DU SERT Maxime
 *Date: 17/03/2016
 */

#ifndef NIVEAULINKSQL_H
#define NIVEAULINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/Niveau.h"
#include "TypeNiveau.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Niveau de programation et sa représentation en base de donnée.
 */

class NiveauLinkSql : public LinkSqlUniqueSimple<Niveau>
{
    USING_LINKSQL(Niveau)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    NiveauLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Niveau>(requete,writeStringUnique())
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Niveau & entity)
    {
        m_requete.bindValue(Niveau::IdTpPos,entity.type());
        m_requete.bindValue(Niveau::NcPos,entity.nc());
        m_requete.bindValue(Niveau::NomPos,entity.nom());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Niveau & entity)
    {
        entity.setType(m_requete.value(Niveau::IdTpPos).toInt());
        entity.setNc(m_requete.value(Niveau::NcPos).toString());
        entity.setNom(m_requete.value(Niveau::NomPos).toString());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Niveau * newFromRequete()
    {
        return new Niveau(m_requete.value(Niveau::IdTpPos).toInt(),
                          m_requete.value(Niveau::NcPos).toString(),
                          m_requete.value(Niveau::NomPos).toString(),
                          m_requete.value(Niveau::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Niveau & entity)
    {
        m_requete.bindValue(0,entity.nom());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // NIVEAULINKSQL_H
