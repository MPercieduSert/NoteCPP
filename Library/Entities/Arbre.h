/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef ARBRE_H
#define ARBRE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntityBase.h"

SINGLE_ATTRIBUT(FeuilleAttribut,AttributBool,AttributBool,Feuille,feuille,bool)

/*! \ingroup groupeBaseEntity
 * \brief Classe mère des entités de type arbre simple.
 */

class ArbreSimpleAttribut : public ParentAttribut
{
public:
    enum {Ordre = Entity::Id};
    using ParentAttribut::ParentAttribut;

    CONSTR_DESTR_DEFAUT(ArbreSimpleAttribut)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe mère des entités de type arbre.
 */

class ArbreAttribut : public Attributs<ArbreSimpleAttribut,FeuilleAttribut,NumAttribut>
{
public:
    //! Positions des attributs.
    enum Position {
                   Parent,
                   Feuille,
                   Num,
                   NbrAtt};

    enum Ordre  {OrdreAtt = Num};
    using Attributs<ArbreSimpleAttribut,FeuilleAttribut,NumAttribut>::Attributs;

    CONSTR_DESTR_DEFAUT(ArbreAttribut)
};

class Arbre : public EntityAttributsID<ArbreAttribut,InfoEntity::ArbreId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Arbre>::Position,
                   Parent = PositionEnum<ArbreSimpleAttribut,Arbre>::Position,
                   Feuille = PositionEnum<FeuilleAttribut,Arbre>::Position,
                   Num = PositionEnum<NumAttribut,Arbre>::Position,
                   NbrAtt};

    using EAID = EntityAttributsID<ArbreAttribut,InfoEntity::ArbreId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Arbre)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Arbre(int num, int parent, int id = 0)
        : EAID(id)
    {
        setNum(num);
        setParent(parent);
    }

    //! Constructeur à partir des valeurs attributs.
    Arbre(bool feuille, int num, int parent, int id = 0)
        : Arbre(num,parent,id)
        {setFeuille(feuille);}
};


#endif // ARBREENTITY_H
