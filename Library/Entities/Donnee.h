/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef DONNEE_H
#define DONNEE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Donnee.
 */

class Donnee : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {CardPos = 0,
                   NomPos = 1,
                   SurPos = 2,
                   TypePos = 3,
                   TypeValeurPos = 4,
                   IdPos = 5};

    //! Différent type de données.
    enum typeDn {};

    enum tpVal {Int = 0,
                String = 1,
                Bool = 2,
                Float = 3,
                Date = 4};


    static const entityId IdEntity = DonneeId;   //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "Donnee";     //!< Nom de l'entitée.
    static const int NbrAtt = 6;                 //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*,NbrAtt> Att {{"card","nom","sur","type","type_valeur","ID"}};  //!< Tableau des attributs de l'entitée.

protected:
    int m_card;         //!< Attribut: Nombre de valeur posible pour une donnée sur cible fixée.
    QString m_nom;      //!< Attribut: Nom de la donnée.
    int m_sur;          //!< Attribut: Identifiant du type de la cible de la donnée.
    int m_type;         //!< Attribut: Identifiant du type de donnée.
    int m_typeValeur;   //!< Attribut: Identifiant du type de valeur de la donnée.

public:
    INCLUCE_METHODE(Donnee)

    //! Constructeur à partir des valeurs attributs.
    Donnee(int card, const QString & nom, int sur, int type, int typeVal ,int id = 0)
        : Entity(id)
    {
        setCard(card);
        setNom(nom);
        setSur(sur);
        setType(type);
        setTypeValeur(typeVal);
    }

    GET_SET_INT_SUP(card,Card,-1)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_INT(sur,Sur)
    GET_SET_INT(type,Type)
    GET_SET_INT(typeValeur,TypeValeur)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (m_card >= -1) && (!m_nom.isEmpty());}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Donnee & don) const
    {
        return Entity::egal(don)
                && (m_card == don.m_card)
                && (m_nom == don.m_nom)
                && (m_sur == don.m_sur)
                && (m_type == don.m_type)
                && (m_typeValeur == don.m_typeValeur);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Donnee & don)
    {
        setCard(don.card());
        setNom(don.nom());
        setSur(don.sur());
        setType(don.type());
        setTypeValeur(don.typeValeur());
    }
};

#endif // DONNEE_H
