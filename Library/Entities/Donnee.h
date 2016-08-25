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
    ATTRIBUT_ENTITY_INT_SUP(Card,card,-1)
    ATTRIBUT_ENTITY_INT_SUP(Sur,sur,0)
    ATTRIBUT_ENTITY_INT_SUP(TpVal,tpVal,0)
public:
    //! Différents types d'affichage.
    enum affiche_alpha {Sans = 0,
                        Numeric = 1,
                        AlphabeticMaj = 2,
                        AlphabeticMin = 3};

    //! Différents types de données.
    enum typeDn {Alpha = 0};
    //! Différents types des données
    enum typeVal {Int = 0,
                String = 1,
                Bool = 2,
                Float = 3,
                Date = 4};

public:
    BASE_ENTITY(Donnee,InfoEntity::DonneeId)
    //! Constructeur par defaut.
    Donnee(int id = 0)
        :TypeNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Donnee(int card, const QString & nom, int sur, int type, int tpVal ,int id = 0)
        : TypeNomEntity(nom, type, id),
          m_card(card),
          m_sur(sur),
          m_tpVal(tpVal)
    {}

    MEMBRE_ATT_3(Donnee,TypeNomEntity,Card,card,Sur,sur,TpVal,tpVal)
};

#endif // DONNEE_H
