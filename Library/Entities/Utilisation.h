/*Auteur: PERCIE DU SERT Maxime
*Date: 22/08/2017
*/
#ifndef UTILISATION_H
#define UTILISATION_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

class Utilisation : public EntityAttributsID<Attributs<Id1Attribut,
                                                    CibleDateTimeNumAttribut,
                                                    OrigineAttributs,
                                                    NomAttribut>,
                                            InfoEntity::UtilisationId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Utilisation>::Position,
                   Id1 = PositionEnum<Id1Attribut,Utilisation>::Position,
                   IdCible = PositionEnum<IdCibleAttribut,Utilisation>::Position,
                   IdOrigine = PositionEnum<IdOrigineAttribut,Utilisation>::Position,
                   Cible = PositionEnum<CibleAttribut,Utilisation>::Position,
                   Origine = PositionEnum<OrigineAttribut,Utilisation>::Position,
                   DateTime = PositionEnum<DateTimeValideAttribut,Utilisation>::Position,
                   Nom = PositionEnum<NomAttribut,Utilisation>::Position,
                   Num = PositionEnum<NumAttribut,Utilisation>::Position,
                   NbrAtt,
                   IdTpUt = Id1};

    using EAID = EntityAttributsID<Attributs<Id1Attribut,CibleDateTimeNumAttribut,OrigineAttributs,NomAttribut>,InfoEntity::UtilisationId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Utilisation)
    ALIAS_CLE(TpUt,1)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Utilisation(int idCible, int idOrigine, int cible, int origine, int num)
    {
        setIdCible(idCible);
        setIdOrigine(idOrigine);
        setCible(cible);
        setOrigine(origine);
        setNum(num);
    }

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Utilisation(const QDateTime & dateTime, const QString & nom)
    {
        setDateTime(dateTime);
        setNom(nom);
    }

    //! Constructeur à partir des valeurs attributs.
    Utilisation(int idTpUt,
                int idCible,
                int idOrigine,
                int cible,
                int origine,
                const QDateTime & dateTime,
                const QString & nom,
                int num,
                int id = 0)
        : EAID(id)
    {
        setIdTpUt(idTpUt);
        setIdCible(idCible);
        setIdOrigine(idOrigine);
        setCible(cible);
        setOrigine(origine);
        setDateTime(dateTime);
        setNom(nom);
        setNum(num);
    }
};

#endif // UTILISATION_H
