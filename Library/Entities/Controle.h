/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/12/2016
 */
#ifndef CONTROLE_H
#define CONTROLE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(BaremeAttribut,AttributBool,AttributBool,Bareme,bareme,bool)
SINGLE_ATTRIBUT(EnonceAttribut,AttributBool,AttributBool,Enonce,enonce,bool)
SINGLE_ATTRIBUT(MinimaAttribut,AttributIntSup,AttributIntSup<0>,Minima,minima,int)


/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Controle.
 */
class Controle : public EntityAttributsID<Attributs<RelationNumAttribut,
                                                    BaremeAttribut,
                                                    DateValideAttribut,
                                                    DecimaleAttribut,
                                                    EnonceAttribut,
                                                    MinimaAttribut,
                                                    NomAttribut,
                                                    SaisieAttribut,
                                                    TotalAttribut>,
                                                    InfoEntity::ControleId>

{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Controle>::Position,
                   Id1 = PositionEnum<Id1Attribut,Controle>::Position,
                   Id2 = PositionEnum<Id2Attribut,Controle>::Position,
                   Num = PositionEnum<NumAttribut,Controle>::Position,
                   Bareme = PositionEnum<BaremeAttribut,Controle>::Position,
                   Date = PositionEnum<DateValideAttribut,Controle>::Position,
                   Decimale = PositionEnum<DecimaleAttribut,Controle>::Position,
                   Enonce = PositionEnum<EnonceAttribut,Controle>::Position,
                   Minima = PositionEnum<MinimaAttribut,Controle>::Position,
                   Nom = PositionEnum<NomAttribut,Controle>::Position,
                   Saisie = PositionEnum<SaisieAttribut,Controle>::Position,
                   Total = PositionEnum<TotalAttribut,Controle>::Position,
                   NbrAtt,
                   IdCl = Id1,
                   IdTp = Id2};

    using EAID =
EntityAttributsID<Attributs<RelationNumAttribut,BaremeAttribut,DateValideAttribut,DecimaleAttribut,EnonceAttribut,MinimaAttribut,NomAttribut,SaisieAttribut,TotalAttribut>,InfoEntity::ControleId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Controle)
    ALIAS_CLE(Cl,1)
    ALIAS_CLE(Tp,2)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Controle(int idCl, int idTp, int num, int id = 0)
        : EAID(id)
    {
        setIdCl(idCl);
        setIdTp(idTp);
        setNum(num);
    }

    //! Constructeur à partir des valeurs attributs.
    Controle(int idCl, int idTp, bool bareme, const QDate &date, int decimale, bool enonce, int minima, const QString &nom, int num, bool saisie, int total, int id = 0)
        : Controle(idCl,idTp,num,id)
    {
        setBareme(bareme);
        setDate(date);
        setDecimale(decimale);
        setEnonce(enonce);
        setMinima(minima);
        setNom(nom);
        setSaisie(saisie);
        setTotal(total);
    }

};

#endif // CONTROLE_H
