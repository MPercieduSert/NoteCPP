/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ANNEELINKSQL_H
#define ANNEELINKSQL_H

#include "LinkSql.h"
#include "../Entities/Annee.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Annee de programation et sa représentation en base de donnée.
 */

class AnneeLinkSql : public LinkSql
{
public:
    static constexpr char Name[] = "an";        //!< Nom de l'entitée en base de donnée.
    static const int NbrAtt = 2;                //!< Nombre d'attributs de l'entitée en en base de donnée.
    static constexpr std::array<const char*, NbrAtt> Att {{"an", "ID"}};   //!< Tableau des attributs de l'entitée en base de donnée.
    //static const int NbrEnsUni = 1;             //!< Nombre d'ensemble d'attributs uniques de l'entitée autre que l'identifiant.
    //static constexpr std::array<const char*, NbrEnsUni> EnsUni {{"an=?"}}; //!< Tableau des chaines des ensembles d'attributs uniques de l'entitée.

protected:
    const QString m_unique;


public:
    //! Construteur, transmettre en argument la requète utilisée par le manageur.
    AnneeLinkSql(QSqlQuery & requete)
        : LinkSql(requete),
        m_unique(writeStringUnique())
        {}

    METHODE_UNIQUE(Annee)

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Annee & annee)
    {
        m_requete.bindValue(Annee::AnneePos,annee.annee());
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Annee &annee)
    {
        m_requete.bindValue(0,annee.annee());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    bool creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Annee & annee)
    {
        annee.setAnnee(m_requete.value(Annee::AnneePos).toInt());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Annee * newFromRequete()
    {
        return new Annee(m_requete.value(Annee::AnneePos).toInt(),
                         m_requete.value(Annee::IdPos).toInt());
    }
    
protected:
    QString writeStringUnique() const;
};

#endif // ANNEELINKSQL_H
