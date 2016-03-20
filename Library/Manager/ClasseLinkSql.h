/*Auteur: PERCIE DU SERT Maxime
 *Date: 16/03/2016
 */

#ifndef CLASSELINKSQL_H
#define CLASSELINKSQL_H

#include "LinkSqlUniqueSimple.h"
#include "../Entities/Classe.h"
#include "AnneeLinkSql.h"
#include "EtablissementLinkSql.h"
#include "NiveauLinkSql.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Classe de programation et sa représentation en base de donnée.
 */

class ClasseLinkSql : public LinkSqlUniqueSimple<Classe>
{
    USING_LINKSQL(Classe)

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    ClasseLinkSql(QSqlQuery & requete)
        : LinkSqlUniqueSimple<Classe>(requete,writeStringUnique())
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Classe & entity)
    {
        m_requete.bindValue(Classe::IdAnPos,entity.idAn());
        m_requete.bindValue(Classe::IdEtabPos,entity.idEtab());
        m_requete.bindValue(Classe::IdNivPos,entity.idNiv());
        m_requete.bindValue(Classe::NumPos,entity.num());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Classe & entity)
    {
        entity.setIdAn(m_requete.value(Classe::IdAnPos).toInt());
        entity.setIdEtab(m_requete.value(Classe::IdEtabPos).toInt());
        entity.setIdNiv(m_requete.value(Classe::IdNivPos).toInt());
        entity.setNum(m_requete.value(Classe::NumPos).toInt());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Classe * newFromRequete()
    {
        return new Classe(m_requete.value(Classe::IdAnPos).toInt(),
                          m_requete.value(Classe::IdEtabPos).toInt(),
                          m_requete.value(Classe::IdNivPos).toInt(),
                          m_requete.value(Classe::NumPos).toInt(),
                          m_requete.value(Classe::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Classe & entity)
    {
        m_requete.bindValue(0,entity.idAn());
        m_requete.bindValue(1,entity.idEtab());
        m_requete.bindValue(2,entity.idNiv());
        m_requete.bindValue(3,entity.num());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // CLASSELINKSQL_H
