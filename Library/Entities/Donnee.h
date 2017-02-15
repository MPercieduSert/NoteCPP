/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef DONNEE_H
#define DONNEE_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Donnee.
 */
class Donnee : public TypeNomEntity
{
    ATTRIBUT_ENTITY_INT_SUP(IdProg,idProg,0)
    ATTRIBUT_ENTITY_BOOL(Modif,modif)
    ATTRIBUT_ENTITY_INT_SUP(TpVal,tpVal,0)
public:
    //! Positions des attributs.
    enum Position {Id = TypeNomEntity::Id,
                   Nom = TypeNomEntity::Nom,
                   Type = TypeNomEntity::Type,
                   IdProg = TypeNomEntity::NbrAtt,
                   Modif,
                   TpVal,
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
    BASE_ENTITY(Donnee,InfoEntity::DonneeId)
    //! Constructeur par defaut.
    Donnee(int id)
        :TypeNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Donnee(bool modif, const QString & nom, int type, int tpVal ,int id = 0, int idProg = prog::NoId)
        : TypeNomEntity(nom, type, id),
          m_idProg(idProg),
          m_modif(modif),
          m_tpVal(tpVal)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Donnee(int idProg, int id)
        : TypeNomEntity(id), m_idProg(idProg)
    {}


    MEMBRE_ATT_3(Donnee,TypeNomEntity,IdProg,idProg,Modif,modif,TpVal,tpVal)
};

#endif // DONNEE_H
