/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/02/2017
 */
#ifndef ENTITYCOMPLEXE_H
#define ENTITYCOMPLEXE_H

#include "AttributMultiple.h"
#include "AttributSimple.h"

#include "TypeControle.h"
/*! \defgroup groupeEntityComplexe Classes des entités composées
 * \ingroup groupeEntity
 * \brief Ensemble des classes des entités composées avec les entités de la base de donnée.
 */

/*! \ingroup groupeEntityComplexe
 * \brief Entité composé de typeControle et de l'attribut num.
 */
class TypeControleNum : public Attributs<TypeControle,NumAttribut>
{
public:
    enum Position {Id = PositionEnum<IdAttribut,TypeControleNum>::Position,
                   Parent = PositionEnum<ArbreSimpleAttribut,TypeControleNum>::Position,
                   Nc = PositionEnum<NcAttribut,TypeControleNum>::Position,
                   Nom = PositionEnum<NomAttribut,TypeControleNum>::Position,
                   Appreciation = PositionEnum<AppreciationAttribut,TypeControleNum>::Position,
                   Decimale = PositionEnum<DecimaleAttribut,TypeControleNum>::Position,
                   Modif = PositionEnum<ModifAttribut,TypeControleNum>::Position,
                   Total = PositionEnum<TotalAttribut,TypeControleNum>::Position,
                   Type = PositionEnum<TypeAttribut,TypeControleNum>::Position,
                   Num = PositionEnum<NumAttribut,TypeControleNum>::Position,
                   NbrAtt,
                   Ordre = Nom};
    using Attributs<TypeControle,NumAttribut>::Attributs;
    CONSTR_DESTR_DEFAUT(TypeControleNum)

    //! Constructeur.
    TypeControleNum(const TypeControle & tpCtr, int num)
        : Attributs<TypeControle,NumAttribut>(tpCtr)
        {setNum(num);}

};
#endif // ENTITYCOMPLEXE_H
