/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/08/2017
 */
#ifndef TYPECOURS_H
#define TYPECOURS_H

#include "Arbre.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(EnteteAttribut,AttributString,AttributString,Entete,entete,QString)
SINGLE_ATTRIBUT(PiedAttribut,AttributString,AttributString,Pied,pied,QString)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité TypeCours.
 */
class TypeCours : public EntityAttributsID<Attributs<Id1Attribut,
                                                    Id2Attribut,
                                                    Id3Attribut,
                                                    ArbreSimpleAttribut,
                                                    IdProgAttribut,
                                                    NomAttribut,
                                                    EnteteAttribut,
                                                    PiedAttribut>,
                                            InfoEntity::TypeCoursId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,TypeCours>::Position,
                   Id1 = PositionEnum<Id1Attribut,TypeCours>::Position,
                   Id2 = PositionEnum<Id2Attribut,TypeCours>::Position,
                   Id3 = PositionEnum<Id3Attribut,TypeCours>::Position,
                   Parent = PositionEnum<ArbreSimpleAttribut,TypeCours>::Position,
                   IdProg = PositionEnum<IdProgAttribut,TypeCours>::Position,
                   Entete = PositionEnum<EnteteAttribut,TypeCours>::Position,
                   Nom = PositionEnum<NomAttribut,TypeCours>::Position,
                   Pied = PositionEnum<PiedAttribut,TypeCours>::Position,
                   NbrAtt,
                   Ordre = Nom,
                   IdFE = Id1,
                   IdFC = Id2,
                   IdFP = Id3};

    using EAID = EntityAttributsID<Attributs<Id1Attribut,Id2Attribut,Id3Attribut,ArbreSimpleAttribut,IdProgAttribut,NomAttribut,EnteteAttribut,PiedAttribut>,InfoEntity::TypeCoursId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(TypeCours)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeCours(const QString & nom, int id = 0)
        : EAID(id)
        {setNom(nom);}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeCours(int idProg, int id)
        : EAID(id)
        {setIdProg(idProg);}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    TypeCours(int idFE, int idFC, int idFP, int parent, int idProg, const QString & entete, const QString & nom, const QString & pied, int id = 0)
        : TypeCours(nom,id)
    {
        setId1(idFE);
        setId2(idFC);
        setId3(idFP);
        setParent(parent);
        setIdProg(idProg);
        setEntete(entete);
        setPied(pied);
    }
};

#endif // TYPECOURS_H
