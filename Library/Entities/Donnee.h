/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef DONNEE_H
#define DONNEE_H

#include "AttributEntityAlias.h"
#include "EntityNom.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Donnee.
 */
class Donnee : public TypeNomEntity<Donnee>, public CardAttribut, public SurAttribut, public TpValAttribut
{
public:
    //! Différent type d'affichage.
    enum affiche_alpha {Sans = 0,
                        Numeric = 1,
                        AlphabeticMaj = 2,
                        AlphabeticMin = 3};

    //! Différent type de données.
    enum typeDn {Alpha = 0};

    enum typeVal {Int = 0,
                String = 1,
                Bool = 2,
                Float = 3,
                Date = 4};

public:
    //! Constructeur par defaut.
    Donnee(int id = 0)
        :TypeNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Donnee(int card, const QString & nom, int sur, int type, int tpVal ,int id = 0)
        : TypeNomEntity(nom, type, id),
          CardAttribut(card),
          SurAttribut(sur),
          TpValAttribut(tpVal)
    {}

    //! Destructeur.
    ~Donnee()
        {}

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return TypeNomEntity::isValid()
                && CardAttribut::valide()
                && SurAttribut::valide()
                && TpValAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Donnee & entity) const
    {
        return TypeNomEntity::egal(entity)
                && (card() == entity.card())
                && (sur() == entity.sur())
                && (tpVal() == entity.tpVal());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Donnee & entity)
    {
        TypeNomEntity::set(entity);
        setCard(entity.card());
        setSur(entity.sur());
        setTpVal(entity.tpVal());
    }
};

#endif // DONNEE_H
