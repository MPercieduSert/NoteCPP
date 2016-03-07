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
    //! Différent type d'affichage.
    enum affiche_alpha {Sans = 0,
                        Numeric = 1,
                        AlphabeticMaj = 2,
                        AlphabeticMin = 3};

    //! Différent type de données.
    enum typeDn {Alpha = 0};

    enum typeVal {Int = 0,
                String = 1,
                Bool = 2,
                Float = 3,
                Date = 4};

protected:
    int m_card;         //!< Attribut: Nombre de valeur posible pour une donnée sur cible fixée.
    QString m_nom;      //!< Attribut: Nom de la donnée.
    int m_sur;          //!< Attribut: Identifiant du type de la cible de la donnée.
    int m_type;         //!< Attribut: Identifiant du type de donnée.
    int m_tpVal;     //!< Attribut: Identifiant du type de valeur de la donnée.

public:
    NOM_POS_5_ATT(Card,Nom,Sur,Type,TpVal)
    INCLUCE_METHODE(Donnee)

    //! Constructeur à partir des valeurs attributs.
    Donnee(int card, const QString & nom, int sur, int type, int tpVal ,int id = 0)
        : Entity(id)
    {
        setCard(card);
        setNom(nom);
        setSur(sur);
        setType(type);
        setTpVal(tpVal);
    }

    GET_SET_INT_SUP(card,Card,-1)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_INT(sur,Sur)
    GET_SET_INT(type,Type)
    GET_SET_INT(tpVal,TpVal)

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
                && (m_tpVal == don.m_tpVal);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Donnee & don)
    {
        setCard(don.card());
        setNom(don.nom());
        setSur(don.sur());
        setType(don.type());
        setTpVal(don.tpVal());
    }
};

#endif // DONNEE_H
