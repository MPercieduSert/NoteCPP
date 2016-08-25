/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef COEFFICIENT_H
#define COEFFICIENT_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Coefficient.
 */

class Coefficient : public Entity
{
protected:
    int m_idCrt;        //!< Clé: Clé du controle à laquelle est ratachée le coefficient.
    int m_indice;       //!< Attribut: indice du coefficient.
    double m_valeur;    //!< Attribut: valeur du coefficient.

public:
    NOM_POS_3_ATT(IdCrt,Indice,Valeur)
    INCLUCE_METHODE(Coefficient)

    //! Constructeur à partir des valeurs attributs.
    Coefficient(int idCrt, int indice, double valeur, int id = 0)
        : Entity(id)
    {
        setIdCrt(idCrt);
        setIndice(indice);
        setValeur(valeur);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Coefficient(int idCrt, int indice)
    {
        setIdCrt(idCrt);
        setIndice(indice);
    }

    GET_SET_ID(Crt)
    GET_SET_INT_SUP(indice,Indice,0)
    GET_SET_DOUBLE(valeur,Valeur)

    //! Teste si l'entité est valide.
    bool isValid() const        {return Entity::isValid() && (m_idCrt > 0) && (m_indice >= 0);}

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Coefficient & entity) const
    {
        return Entity::egal(entity)
                && (m_idCrt == entity.m_idCrt)
                &&(m_indice == entity.m_indice)
                &&(m_valeur == entity.m_valeur);
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Coefficient & entity)
    {
        setIdCrt(entity.idCrt());
        setIndice(entity.indice());
        setValeur(entity.valeur());
    }
};

#endif // COEFFICIENT_H
