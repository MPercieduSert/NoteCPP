/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ANNEE_H
#define ANNEE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Annee.
 */
class Annee : public Entity, public EntityTemp<IdentifiantEntity::AnneeId,2,Annee>, public AnAttribut
{   
public:
    POS_1_ATT(An)

    //! Constructeur par defaut.
    Annee(int id = 0)
        : Entity(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Annee(int an, int id)
        : Entity(id),
          AnAttribut(an)
        {}

    //! Constructeur de recopie.
    Annee(const Annee & entity)
        : Entity(entity), AnAttribut(entity.an())
        {}

    //! Destructeur.
    ~Annee()
        {}

    //! Renvoie la chaine de caractère "annee-annee+1".
    QString affiche() const
    {return QString::number(an())+"-"+QString::number(an()+1);}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {return Entity::isValid() && AnAttribut::valide();}

    //! Oprérateur d'ordre strictement croissant sur an.
    bool operator < (const Annee & annee) const
    {
        return an() < annee.an();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Annee & entity) const
    {
        return Entity::egal(entity)
                && (an() == entity.an());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Annee & entity)
    {
        Entity::set(entity);
        setAn(entity.an());
    }
};

#endif // ANNEE_H
