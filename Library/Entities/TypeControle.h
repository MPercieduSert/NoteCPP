/*Auteur: PERCIE DU SERT Maxime
 *Date: 09/01/2017
 */
#ifndef TYPECONTROLE_H
#define TYPECONTROLE_H

#include "Arbre.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(AppreciationAttribut,AttributBool,AttributBool,Appreciation,appreciation,bool)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeControle.
 */
class TypeControle : public EntityAttributsID<Attributs<ArbreSimpleAttribut,NcNomAttribut,AppreciationAttribut,DecimaleAttribut,ModifAttribut,TotalAttribut,TypeAttribut>,InfoEntity::TypeControleId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,TypeControle>::Position,
                   Parent = PositionEnum<ArbreSimpleAttribut,TypeControle>::Position,
                   Nc = PositionEnum<NcAttribut,TypeControle>::Position,
                   Nom = PositionEnum<NomAttribut,TypeControle>::Position,
                   Appreciation = PositionEnum<AppreciationAttribut,TypeControle>::Position,
                   Decimale = PositionEnum<DecimaleAttribut,TypeControle>::Position,
                   Modif = PositionEnum<ModifAttribut,TypeControle>::Position,
                   Total = PositionEnum<TotalAttribut,TypeControle>::Position,
                   Type = PositionEnum<TypeAttribut,TypeControle>::Position,
                   NbrAtt,
                   Ordre = Nom};

    enum Type {Default,
               Lettre};

    using EAID = EntityAttributsID<Attributs<ArbreSimpleAttribut,NcNomAttribut,AppreciationAttribut,DecimaleAttribut,ModifAttribut,TotalAttribut,TypeAttribut>,InfoEntity::TypeControleId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(TypeControle)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeControle(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs attributs.
    TypeControle(bool appreciation, int decimale, bool modif, const QString & nc, const QString & nom, int total, int type = TypeControle::Default, int parent = 0, int id = 0)
         : TypeControle(nom,id)
    {
        setAppreciation(appreciation);
        setDecimale(decimale);
        setModif(modif);
        setNc(nc);
        setParent(parent);
        setTotal(total);
        setType(type);
     }
};

#endif // TYPECONTROLE_H
