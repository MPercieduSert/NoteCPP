/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */

#ifndef CLASSEELEVE_H
#define CLASSEELEVE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée ClasseEleve.
 */

class ClasseEleve : public Entity
{
protected:
    int m_idCl;         //!< Clé: Classe.
    int m_idEl;         //!< Clé: Eléve.
    QDate m_rentree;     //!< Attribut: date de rentrée dans la classe se elle est effectuée après le début du cursus.
    QDate m_sortie;     //!< Attribut: date de sortie de la classe si elle est effectuée avant la fin du cursus.

public:
    NOM_POS_4_ATT(IdCl,IdEl,Rentree,Sortie)
    INCLUCE_METHODE(ClasseEleve)

    //! Constructeur à partir des valeurs attributs.
    ClasseEleve(int idCl, int idEl, const QDate & rentree, const QDate & sortie, int id = 0)
        : Entity(id)
    {
        setIdCl(idCl);
        setIdEl(idEl);
        setRentree(rentree);
        setSortie(sortie);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    ClasseEleve(int idCl, int idEl)
    {
        setIdCl(idCl);
        setIdEl(idEl);
    }

    GET_SET_ID(Cl)
    GET_SET_ID(El)
    GET_SET_DATE(rentree,Rentree)
    GET_SET_DATE(sortie,Sortie)

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid() && (m_idCl > 0) && (m_idEl > 0);
    }

protected:
     //! Test d'égalité entre cette entitée et celle transmise en argument.
     bool egal(const ClasseEleve & entity) const
     {
         return Entity::egal(entity)
                 &&(m_idCl == entity.m_idCl)
                 &&(m_idEl == entity.m_idEl)
                 &&(m_rentree == entity.m_rentree)
                 &&(m_sortie == entity.m_sortie);
     }

     //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
     void set(const ClasseEleve & entity)
     {
         setIdCl(entity.idCl());
         setIdEl(entity.idEl());
         setRentree(entity.rentree());
         setSortie(entity.sortie());
     }
};

#endif // CLASSEELEVE_H
