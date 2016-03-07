/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/02/2016
 */

#ifndef TYPE_NIVEAU_H
#define TYPE_NIVEAU_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée TypeNiveau.
 */

class TypeNiveau : public Entity
{
public:
    //! Numéro des types de niveaux.
    enum num {Primaire = 1,
              College = 2,
              Lycee = 3,
              Prepa = 4,
              Licence =5};

protected:
    QString m_nom;

public:
    NOM_POS_1_ATT(Nom)
    INCLUCE_METHODE(TypeNiveau)

    //! Constructeur à partir des valeurs attributs.
    TypeNiveau(const QString & nom, int id = 0)
        : Entity(id)
        {setNom(nom);}

    GET_SET_TEXTE_NOT_NULL(nom,Nom)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (!m_nom.isEmpty());}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const TypeNiveau & entity) const
    {
        return Entity::egal(entity)
                && (m_nom == entity.m_nom);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const TypeNiveau & entity)
    {
        setNom(entity.nom());
    }
};

#endif // TYPE_NIVEAU_H
