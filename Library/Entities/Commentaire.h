/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Commentaire.
 */

class Commentaire : public Entity
{
protected:
    QString m_texte;    //!< Attribut: Texte du commentaire.

public:
    NOM_POS_1_ATT(Texte)
    INCLUCE_METHODE(Commentaire)

    //! Constructeur à partir des valeurs attributs.
    Commentaire(const QString & texte, int id = 0)
        : Entity(id)
    {
        setTexte(texte);
    }

    GET_SET_TEXTE_NOT_NULL(texte,Texte)

    //! Teste si l'entitée est valide.
    bool isValid() const                    {return Entity::isValid() && (m_texte.isEmpty());}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Commentaire & entity) const
    {
        return Entity::egal(entity)
                && (m_texte == entity.m_texte);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Commentaire & entity)
    {
        setTexte(entity.texte());
    }
};

#endif // COMMENTAIRE_H
