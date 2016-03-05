/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef ELEVELINKSQL_H
#define ELEVELINKSQL_H

#include "LinkSql.h"
#include "../Entities/Eleve.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Eleve de programation et sa représentation en base de donnée.
 */

class EleveLinkSql : public LinkSql
{
public:
    typedef Eleve Ent;      //!< Alias de l'entitée employé par le manageur.

    static constexpr char Name[] = "el";    //!< Nom de l'entitée en base de donnée.
    static const int NbrAtt = Eleve::NbrAtt;                //!< Nombre d'attributs de l'entitée en en base de donnée.
    static constexpr std::array<const char*, NbrAtt> Att {{"fl","ne","nm","pnm","ID"}};   //!< Tableau des attributs de l'entitée en base de donnée.

protected:
    const QString m_unique; //!< Requete Sql sur l'existence d'ensemble d'attribus uniques.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    EleveLinkSql(QSqlQuery & requete)
        : LinkSql(requete),
        m_unique(writeStringUnique())
        {}

    METHODE_UNIQUE(Eleve)

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Eleve & eleve)
    {
        m_requete.bindValue(Eleve::FillePos,eleve.fille());
        m_requete.bindValue(Eleve::NaissancePos,eleve.naissance());
        m_requete.bindValue(Eleve::NomPos,eleve.nom());
        m_requete.bindValue(Eleve::PrenomPos,eleve.prenom());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Eleve & eleve)
    {
        eleve.setFille(m_requete.value(Eleve::FillePos).toBool());
        eleve.setNaissance(m_requete.value(Eleve::NaissancePos).toDate());
        eleve.setNom(m_requete.value(Eleve::NomPos).toString());
        eleve.setPrenom(m_requete.value(Eleve::PrenomPos).toString());
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
    void bindValuesUnique(const Eleve & eleve)
    {
        m_requete.bindValue(0,eleve.naissance());
        m_requete.bindValue(1,eleve.nom());
        m_requete.bindValue(2,eleve.prenom());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // ELEVELINKSQL_H
