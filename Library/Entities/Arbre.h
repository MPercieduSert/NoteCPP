/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef ARBRE_H
#define ARBRE_H

#include "AttributEntity.h"
#include "EntityDivers.h"


/*! \ingroup groupeBaseEntity
 * \brief Classe mère des entités de type arbre simple.
 */
/*
class ArbreSimple : public Entity
{
    ATTRIBUT_ENTITY_INT_SUP(Parent,parent,0)
public:
    //! Positions des attributs.
    enum Position {Id = Entity::Id,
                   Parent = NumEntity::NbrAtt,
                   NbrAtt};
    enum Ordre  {OrdreAtt = Position::Id};

    BASE_ENTITY(ArbreSimple,InfoEntity::entityBaseId::ArbreSimpleId)

    //! Constructeur à partir des valeurs attributs.
    ArbreSimple(int parent, int id)
        : Entity(id),
          m_parent(parent)
        {}

    MEMBRE_ATT_1(Arbre,Entity,Parent,parent)
};

/*! \ingroup groupeBaseEntity
 * \brief Classe mère des entités de type arbre.
 */
/*
class Arbre : public ArbreSimple
{

    ATTRIBUT_ENTITY_BOOL(Feuille,feuille)
    ATTRIBUT_ENTITY_INT_SUP(Num,num,0)
public:
    //! Positions des attributs.
    enum Position {Id = ArbreSimple::Id,
                   Parent = ArbreSimple::Parent,
                   Feuille = ArbreSimple::NbrAtt,
                   Num,
                   NbrAtt};

    BASE_ENTITY(Arbre,InfoEntity::entityBaseId::ArbreId)

    //! Constructeur par defaut.
    Arbre(int id)
        : ArbreSimple(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Arbre(bool feuille, int num, int parent, int id = 0)
        : ArbreSimple(parent,id),
          m_feuille(feuille),
          m_parent(parent)
        {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Arbre(int num, int parent, int id = 0)
        : NumEntity(num,id),
          m_parent(parent)
        {}

    MEMBRE_ATT_2(Arbre,NumEntity,Feuille,feuille,Parent,parent)
};
*/
class Arbre : public NumEntity
{

    ATTRIBUT_ENTITY_BOOL(Feuille,feuille)
    ATTRIBUT_ENTITY_INT_SUP(Parent,parent,0)
public:
    //! Positions des attributs.
    enum Position {Id = NumEntity::Id,
                   Num = NumEntity::Num,
                   Feuille = NumEntity::NbrAtt,
                   Parent,
                   NbrAtt};

    BASE_ENTITY(Arbre,InfoEntity::entityBaseId::ArbreId)

    //! Constructeur par defaut.
    Arbre(int id)
        : NumEntity(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Arbre(bool feuille, int num, int parent, int id = 0)
        : NumEntity(num,id),
          m_feuille(feuille),
          m_parent(parent)
        {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Arbre(int num, int parent, int id = 0)
        : NumEntity(num,id),
          m_parent(parent)
        {}

    MEMBRE_ATT_2(Arbre,NumEntity,Feuille,feuille,Parent,parent)
};

#endif // ARBREENTITY_H
