/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef DONNEE_H
#define DONNEE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Donnee.
 */
class Donnee : public EntityAttributsID<Attributs<NomTypeAttribut,IdProgAttribut,TpValAttribut>,InfoEntity::DonneeId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Donnee>::Position,
                   Nom = PositionEnum<NomAttribut,Donnee>::Position,
                   Type = PositionEnum<TypeAttribut,Donnee>::Position,
                   IdProg = PositionEnum<IdProgAttribut,Donnee>::Position,
                   TpVal = PositionEnum<TpValAttribut,Donnee>::Position,
                   NbrAtt};

    //! Différents types d'affichage.
    enum affiche_alpha {Sans = 0,
                        Numeric = 1,
                        AlphabeticMaj = 2,
                        AlphabeticMin = 3};

    //! Différents types de données.
    enum typeDn {Alpha = 0,
                Perso};
    //! Différents types des données
    enum typeVal {Int = 0,
                String = 1,
                Bool = 2,
                Float = 3,
                Date = 4,
                 NoDonnee};

    //! Identifiant de programation
    enum prog {NoId,
              Contact,
              Adresse,
              NumRue,
              Rue,
              CodePostal,
              Ville,
              Pays,
              Tel,
              Mail};

public:
    using EAID = EntityAttributsID<Attributs<NomTypeAttribut,IdProgAttribut,TpValAttribut>,InfoEntity::DonneeId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Donnee)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Donnee(int idProg, int id)
        : EAID(id)
        {setIdProg(idProg);}

    //! Constructeur à partir des valeurs attributs.
    Donnee(const QString & nom, int type, int tpVal, int idProg = prog::NoId, int id = 0)
        : Donnee(idProg,id)
    {
        setNom(nom);
        setType(type);
        setTpVal(tpVal);
    }
};

#endif // DONNEE_H
