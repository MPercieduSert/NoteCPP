/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef DONNEELINKSQL_H
#define DONNEELINKSQL_H

#include "LinkSql.h"
#include "../Entities/Donnee.h"

/*! \ingroup groupeLinkSql
 * \brief Lien entre l'entitée Donnee de programation et sa représentation en base de donnée.
 */

class DonneeLinkSql : public LinkSql
{
public:
    typedef Donnee Ent;      //!< Alias de l'entitée employé par le manageur.

    static constexpr char Name[] = "DN";    //!< Nom de l'entitée en base de donnée.
    static const int NbrAtt = Donnee::NbrAtt;                //!< Nombre d'attributs de l'entitée en en base de donnée.
    static constexpr std::array<const char*, NbrAtt> Att {{"cd","nm","sur","tp","tp_vl","ID"}};   //!< Tableau des attributs de l'entitée en base de donnée.

public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    DonneeLinkSql(QSqlQuery & requete)
        : LinkSql(requete)
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Donnee & donnee)
    {
        m_requete.bindValue(Donnee::CardPos,donnee.card());
        m_requete.bindValue(Donnee::NomPos,donnee.nom());
        m_requete.bindValue(Donnee::SurPos,donnee.sur());
        m_requete.bindValue(Donnee::TypePos,donnee.type());
        m_requete.bindValue(Donnee::TypeValeurPos,donnee.typeValeur());
    }

    //! Crée la table en base de donnée et renvoie vrai si la création de la table s'est correctement déroulée.
    void creer();

    //! Renvoie Aucun, car il n'y a pas de condition d'unicité.
    Manager::ExisteUni existsUnique(const Donnee & entity)
    {
        return Manager::Aucun;
    }

    //! Hydrate l'entitée entity avec à partir de la requète.
    void fromRequete(Donnee & donnee)
    {
        donnee.setCard(m_requete.value(Donnee::CardPos).toInt());
        donnee.setNom(m_requete.value(Donnee::NomPos).toString());
        donnee.setSur(m_requete.value(Donnee::SurPos).toInt());
        donnee.setType(m_requete.value(Donnee::TypePos).toInt());
        donnee.setTypeValeur(m_requete.value(Donnee::TypeValeurPos).toInt());
    }

    //! Crée dynamiquement une nouvelle entitée de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entitée.
    Donnee * newFromRequete()
    {
        return new Donnee(m_requete.value(Donnee::CardPos).toInt(),
                         m_requete.value(Donnee::NomPos).toString(),
                         m_requete.value(Donnee::SurPos).toInt(),
                         m_requete.value(Donnee::TypePos).toInt(),
                         m_requete.value(Donnee::TypeValeurPos).toInt(),
                         m_requete.value(Donnee::IdPos).toInt());
    }
};

#endif // DONNEELINKSQL_H
