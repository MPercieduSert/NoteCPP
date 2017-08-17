/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */
#ifndef CLASSEELEVE_H
#define CLASSEELEVE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(EntreeAttribut,AttributDateValide,AttributDateValide,Entree,entree,QDate)
SINGLE_ATTRIBUT(SortieAttribut,AttributDateNull,AttributDateNull,Sortie,sortie,QDate)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité ClasseEleve.
 */
class ClasseEleve : public EntityAttributsID<Attributs<RelationAttribut,EntreeAttribut,SortieAttribut>,InfoEntity::ClasseEleveId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,ClasseEleve>::Position,
                   Id1 = PositionEnum<Id1Attribut,ClasseEleve>::Position,
                   Id2 = PositionEnum<Id2Attribut,ClasseEleve>::Position,
                   Entree = PositionEnum<EntreeAttribut,ClasseEleve>::Position,
                   Sortie = PositionEnum<SortieAttribut,ClasseEleve>::Position,
                   NbrAtt,
                   IdCl = Id1,
                   IdEl = Id2};

    using EAID = EntityAttributsID<Attributs<RelationAttribut,EntreeAttribut,SortieAttribut>,InfoEntity::ClasseEleveId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(ClasseEleve)
    ALIAS_CLE(Cl,1)
    ALIAS_CLE(El,2)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    ClasseEleve(int idCl, int idEl, int id = 0)
        : EAID(id)
    {
        setIdCl(idCl);
        setIdEl(idEl);
    }

    //! Constructeur à partir des valeurs attributs.
    ClasseEleve(int idCl, int idEl, const QDate & entree, const QDate & sortie = QDate(), int id = 0)
        : ClasseEleve(idCl, idEl, id)
    {
          setEntree(entree);
          setSortie(sortie);
    }
};

#endif // CLASSEELEVE_H
