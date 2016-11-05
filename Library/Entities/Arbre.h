/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */
#ifndef ARBRE_H
#define ARBRE_H

#include "AttributEntity.h"
#include "EntityDivers.h"

/*! \ingroup groupeBaseEntity
 * \brief Classe mère des entités de type arbre.
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
