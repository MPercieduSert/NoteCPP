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
    ATTRIBUT_ENTITY_INT_SUP(Niveau,niveau,0)
    ATTRIBUT_ENTITY_INT_SUP(Parent,parent,0)
public:
    BASE_ENTITY_ABS(Arbre)

    //! Constructeur par defaut.
    Arbre(int id)
        : NumEntity(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Arbre(bool feuille, int niveau, int num, int parent, int id = 0)
        : NumEntity(num,id),
          m_feuille(feuille),
          m_niveau(niveau),
          m_parent(parent)
        {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Arbre(int num, int parent)
        : NumEntity(num,0),
          m_parent(parent)
        {}

    MEMBRE_ATT_3(Arbre,NumEntity,Feuille,feuille,Niveau,niveau,Parent,parent)
};
#endif // ARBREENTITY_H
