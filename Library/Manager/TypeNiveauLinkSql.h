/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/03/2016
 */

#ifndef TYPENIVEAULINKSQL_H
#define TYPENIVEAULINKSQL_H

#include "LinkSql.h"
#include "../Entities/TypeNiveau.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée TypeNiveau de programation et sa représentation en base de donnée.
 */

class TypeNiveauLinkSql : public LinkSql
{
public:
    typedef TypeNiveau Ent;      //!< Alias de l'entitée employé par le manageur.

    static constexpr char Name[] = "tp_niv";        //!< Nom de l'entitée en base de donnée
    static const int NbrAtt = TypeNiveau::NbrAtt;                //!< Nombre d'attributs de l'entitée en en base de donnée.
    static constexpr std::array<const char*, NbrAtt> Att {{"nm", "ID"}};   //!< Tableau des attributs de l'entitée en base de donnée.

protected:
    const QString m_unique; //!< Requete Sql sur l'existence d'ensemble d'attribus uniques.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    TypeNiveauLinkSql(QSqlQuery & requete)
        : LinkSql(requete),
          m_unique(writeStringUnique())
    {}

    METHODE_UNIQUE(TypeNiveau)

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const TypeNiveau & typeNiveau)
    {
        m_requete.bindValue(TypeNiveau::NomPos,typeNiveau.nom());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(TypeNiveau & typeNiveau)
    {
        typeNiveau.setNom(m_requete.value(TypeNiveau::NomPos).toString());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    TypeNiveau * newFromRequete()
    {
        return new TypeNiveau(m_requete.value(TypeNiveau::NomPos).toString(),
                              m_requete.value(TypeNiveau::IdPos).toInt());
    }

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const TypeNiveau &typeNiveau)
    {
        m_requete.bindValue(0,typeNiveau.nom());
    }

    //! Renvoie la chaine correspondant à la requète d'unicité d'une ligne.
    QString writeStringUnique() const;
};

#endif // TYPENIVEAULINKSQL_H
