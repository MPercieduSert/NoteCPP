/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */

#ifndef ELEVE_H
#define ELEVE_H

#include "Entity.h"


/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Eleve.
 */

class Eleve : public Entity
{
protected:
    bool m_fille;           //!< Attribut: Vraie si l'éléve est une fille.
    QDate m_naissance;      //!< Attribut: Date de naissance de l'éléve.
    QString m_nom;          //!< Attribut: Nom de l'éléve.
    QString m_prenom;       //!< Attribut: Prenom de l'éléve.

public:
    NOM_POS_4_ATT(Fille,Naissance,Nom,Prenom)
    INCLUCE_METHODE(Eleve)

    //! Constructeur à partir des valeurs attributs.
    Eleve(bool fille, const QDate & naissance, const QString &nom, const QString &prenom, int id = 0)
        : Entity(id)
    {
        setFille(fille);
        setNaissance(naissance);
        setNom(nom);
        setPrenom(prenom);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Eleve(const QDate & naissance, const QString &nom, const QString &prenom)
    {
        setNaissance(naissance);
        setNom(nom);
        setPrenom(prenom);
    }

    GET_SET_BOOL(fille,Fille)
    GET_SET_DATE_VALIDE(naissance,Naissance)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_TEXTE_NOT_NULL(prenom,Prenom)

    //! Renvoie F si l'éléve est une fille et M sinon.
    QChar afficheFille() const                      {return m_fille ? QChar('F'): QChar('M');}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid() && (m_naissance.isValid()) && (!m_nom.isEmpty()) && (!m_prenom.isEmpty());
    }

protected:
     //! Test d'égalité entre cette entitée et celle transmise en argument.
     bool egal(const Eleve & eleve) const
     {
         return Entity::egal(eleve)
                 &&(m_fille == eleve.m_fille)
                 &&(m_naissance == eleve.m_naissance)
                 &&(m_nom == eleve.m_nom)
                 &&(m_prenom == eleve.m_prenom);
     }

     //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
     void set(const Eleve & entity)
     {
         setFille(entity.fille());
         setNaissance(entity.naissance());
         setNom(entity.nom());
         setPrenom(entity.prenom());
     }
};

#endif // ELEVE_H
