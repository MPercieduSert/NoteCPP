/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */

#ifndef ARBRE_H
#define ARBRE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Classe mère des entitées de type arbre.
 */
template<IdentifiantEntity::entityId ID> class Arbre : public NumEntity, public EntityTemp<ID,4,Arbre<ID> >, public FeuilleAttribut, public NiveauAttribut, public ParentAttribut
{
public:
    POS_4_ATT(Feuille,Niveau,Num,Parent)

    //! Constructeur par defaut.
    Arbre(int id = 0)
        : NumEntity(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Arbre(bool feuille, int niveau, int num, int parent, int id = 0)
        : NumEntity(num,id),
          FeuilleAttribut(feuille),
          NiveauAttribut(niveau),
          ParentAttribut(parent)
        {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Arbre(int num, int parent)
        : ParentAttribut(parent)
        {setNum(num);}

    //! Constructeur de recopie.
    Arbre(const Arbre & entity)
        : NumEntity(entity),
          FeuilleAttribut(entity.feuille()),
          NiveauAttribut(entity.niveau()),
          ParentAttribut(entity.parent())
        {}

    //! Destructeur.
    ~Arbre()
        {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return NumEntity::isValid()
                && FeuilleAttribut::valide()
                && NiveauAttribut::valide()
                && ParentAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Arbre<ID> & entity) const
    {
        return NumEntity::egal(entity)
                && (feuille() == entity.feuille())
                && (niveau() == entity.niveau())
                && (parent() == entity.parent());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Arbre<ID> & entity)
    {
        NumEntity::set(entity);
        setFeuille(entity.feuille());
        setNiveau(entity.niveau());
        setParent(entity.parent());
    }
};

typedef Arbre<IdentifiantEntity::AttributArbreId> AttributArbre;
typedef Arbre<IdentifiantEntity::CoursArbreId> CoursArbre;
typedef Arbre<IdentifiantEntity::DonneeArbreId> DonneeArbre;
typedef Arbre<IdentifiantEntity::EnonceArbreId> EnonceArbre;
typedef Arbre<IdentifiantEntity::ExerciceArbreId> ExerciceArbre;


#endif // ARBREENTITY_H
