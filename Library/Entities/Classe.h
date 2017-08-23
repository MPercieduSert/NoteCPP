 /*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef CLASSE_H
#define CLASSE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Classe.
 */
class Classe : public EntityAttributsID<Attributs<RelationNumAttribut,Id3Attribut,NomAttribut>,InfoEntity::ClasseId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Classe>::Position,
                   Id1 = PositionEnum<Id1Attribut,Classe>::Position,
                   Id2 = PositionEnum<Id2Attribut,Classe>::Position,
                   Num = PositionEnum<NumAttribut,Classe>::Position,
                   Id3 = PositionEnum<Id3Attribut,Classe>::Position,
                   Nom = PositionEnum<NomAttribut,Classe>::Position,
                   NbrAtt,
                   IdAn = Id1,
                   IdEtab = Id2,
                   IdNiv = Id3};

    using EAID = EntityAttributsID<Attributs<RelationNumAttribut,Id3Attribut,NomAttribut>,InfoEntity::ClasseId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Classe)
    ALIAS_CLE(An,1)
    ALIAS_CLE(Etab,2)
    ALIAS_CLE(Niv,3)

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Classe(int idAn, int idEtab, int idNiv, int num)
    {
          setIdAn(idAn);
          setIdEtab(idEtab);
          setIdNiv(idNiv);
          setNum(num);
    }

    //! Constructeur à partir d'un jeux de valeurs attributs unique.
    Classe(int idAn, int idEtab, const QString & nom)
    {
        setIdAn(idAn);
        setIdEtab(idEtab);
        setNom(nom);

    }

    //! Constructeur à partir des valeurs attributs.
    Classe(int idAn, int idEtab, int idNiv, const QString & nom, int num, int id =0)
        : Classe(idAn,idEtab,idNiv,num)
    {
        setId(id);
        setNom(nom);
    }
};

#endif // CLASSE_H
