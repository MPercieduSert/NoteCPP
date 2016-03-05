/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ARBRELINKSQL_H
#define ARBRELINKSQL_H

#include "LinkSql.h"
#include "../Entities/ArbreEntity.h"

/*! \ingroup groupeLinkSql
 * \brief Classe mère des lien entre les entitées de type arbre de programation et leurs représentations en base de donnée.
 */

class ArbreLinkSql : public LinkSql
{
public:
    typedef ArbreEntity Ent;      //!< Alias de l'entitée employé par le manageur.

    static constexpr char Name[] = "arb";        //!< Nom de l'entitée en base de donnée.
    static const int NbrAtt = ArbreEntity::NbrAtt;                //!< Nombre d'attributs de l'entitée en en base de donnée.
    static constexpr std::array<const char*, NbrAtt> Att {{"fl", "nv", "nm", "pr", "ID"}};   //!< Tableau des attributs de l'entitée en base de donnée.

    //static const int NbrEnsUni = 1;             //!< Nombre d'ensemble d'attributs uniques de l'entitée autre que l'identifiant.
    //static constexpr std::array<const char*, NbrEnsUni> EnsUni {{"nm=? AND pr=?"}}; //!< Tableau des chaines des ensembles d'attributs uniques de l'entitée.

protected:
    const QString m_unique; //!< Requete Sql sur l'existence d'ensemble d'attribus uniques.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    ArbreLinkSql(QSqlQuery & requete)
        : LinkSql(requete),
        m_unique(writeStringUnique())
        {}

    METHODE_UNIQUE(ArbreEntity)

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const ArbreEntity & arbre)
    {
        m_requete.bindValue(ArbreEntity::FeuillePos, arbre.feuille());
        m_requete.bindValue(ArbreEntity::NiveauPos, arbre.niveau());
        m_requete.bindValue(ArbreEntity::NumPos, arbre.num());
        m_requete.bindValue(ArbreEntity::ParentPos, zeroToNull(arbre.parent()));
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer(const QString & name);

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(ArbreEntity & arbre)
    {
        arbre.setFeuille(m_requete.value(ArbreEntity::FeuillePos).toBool());
        arbre.setNiveau(m_requete.value(ArbreEntity::NiveauPos).toInt());
        arbre.setNum(m_requete.value(ArbreEntity::NumPos).toInt());
        arbre.setParent(m_requete.value(ArbreEntity::ParentPos).toInt());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    ArbreEntity * newFromRequete()
    {
        return new ArbreEntity(m_requete.value(ArbreEntity::FeuillePos).toBool(),
                               m_requete.value(ArbreEntity::NiveauPos).toInt(),
                               m_requete.value(ArbreEntity::NumPos).toInt(),
                               m_requete.value(ArbreEntity::ParentPos).toInt(),
                               m_requete.value(ArbreEntity::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const ArbreEntity & arbre)
    {
        m_requete.bindValue(0, arbre.num());
        m_requete.bindValue(1, zeroToNull(arbre.parent()));
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // ARBRELINKSQL_H
