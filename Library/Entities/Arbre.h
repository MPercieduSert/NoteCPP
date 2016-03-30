/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef ARBRE_H
#define ARBRE_H

#include "AttributEntityAlias.h"
#include "AttributEntityMacroAlias.h"
#include "EntityDivers.h"

/*! \ingroup groupeBaseEntity
 * \brief Information sur les entités de type Arbre.
 */
struct ArbreInfo
{
    ATTRIBUT_4(Feuille,Niveau,Num,Parent)
};

// Définitions des attributs des arbres.
ALIAS_BOOL(Feuille,feuille)
ALIAS_INT_SUP(Niveau,niveau,0,0)
ALIAS_INT_SUP(Parent,parent,0,0)

/*! \ingroup groupeBaseEntity
 * \brief Classe mère des entités de type arbre.
 */
template<class Info> class Arbre : public NumEntity<Arbre<Info>,Info>,
                  public FeuilleAttribut,
                  public NiveauAttribut,
                  public ParentAttribut
{                                             
public:
    using NumAttribut::num;
    using NumAttribut::setNum;

    //! Constructeur par defaut.
    Arbre(int id = 0)
        : NumEntity<Arbre<Info>,Info>(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Arbre(bool feuille, int niveau, int num, int parent, int id = 0)
        : NumEntity<Arbre<Info>,Info>(num,id),
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
        : NumEntity<Arbre<Info>,Info>(entity),
          FeuilleAttribut(entity.feuille()),
          NiveauAttribut(entity.niveau()),
          ParentAttribut(entity.parent())
        {}

    //! Destructeur.
    ~Arbre()
        {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NumEntity<Arbre<Info>,Info>::isValid()
                && FeuilleAttribut::valide()
                && NiveauAttribut::valide()
                && ParentAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Arbre<Info> & entity) const
    {
        return NumEntity<Arbre<Info>,Info>::egal(entity)
                && (feuille() == entity.feuille())
                && (niveau() == entity.niveau())
                && (parent() == entity.parent());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Arbre<Info> & entity)
    {
        NumEntity<Arbre<Info>,Info>::set(entity);
        setFeuille(entity.feuille());
        setNiveau(entity.niveau());
        setParent(entity.parent());
    }
};
#endif // ARBREENTITY_H
