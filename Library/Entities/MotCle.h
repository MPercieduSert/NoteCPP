/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/08/2017
 */
#ifndef MOTCLE_H
#define MOTCLE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité MotCle.
 */
class MotCle : public EntityAttributsID<Attributs<NcNomAttribut,IdProgAttribut>,InfoEntity::MotCleId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,MotCle>::Position,
                   Nc = PositionEnum<NcAttribut,MotCle>::Position,
                   Nom = PositionEnum<NomAttribut,MotCle>::Position,
                   IdProg = PositionEnum<IdProgAttribut,MotCle>::Position,
                   NbrAtt};



    //! Identifiant de programation
    enum prog {NoId,
              ArbreDiff,
              QuestionCoursDiff,
              ExerciceCoursDiff,
              IntermediaireDiff,
              DifficileDiff,
              TresDifficileDiff,
              ImposibleDiff,
              ArbreComp,
              MathComp,
              InfoComp,
              AnalyserComp,
              ModeliserMathComp,
              RepresenterComp,
              ArgumenterComp,
              CalculerComp,
              CommuniquerMathComp,
              ModeliserInfoComp,
              ImaginerComp,
              TraduireComp,
              EvaluerComp,
              SpecifierComp,
              CommuniquerInfoComp,
              SavoirArbre,
              MathSav,
              InfoSav,
              LogiqueSav,
              AlgebreSav,
              AnalyseSav,
              ProbaSav,
              ArbreProg,
              MathProg,
              InfoProg
              };

public:
    using EAID = EntityAttributsID<Attributs<NcNomAttribut,IdProgAttribut>,InfoEntity::MotCleId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(MotCle)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    MotCle(int idProg, int id)
        : EAID(id)
        {setIdProg(idProg);}

    //! Constructeur à partir des valeurs attributs.
    MotCle(const QString & nc, const QString & nom, int idProg = prog::NoId, int id = 0)
        : MotCle(idProg,id)
    {
        setNc(nc);
        setNom(nom);
    }
};

#endif // MOTCLE_H
