/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef CLASSE_H
#define CLASSE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Bareme.
 */
class Classe : public NumRelationEntity, public EntityTemp<IdentifiantEntity::ClasseId,5,Classe>,  public IdNivAttribut
{
public:
    POS_4_ATT(IdAn,IdEtab,IdNiv,Num)

    //! Constructeur par defaut.
    Classe(int id = 0)
        : NumRelationEntity(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Classe(int idAn, int idEtab, int idNiv, int num, int id =0)
        : NumRelationEntity(idAn, idEtab, num, id),
          IdNivAttribut(idNiv)
    {}

    //! Constructeur de recopie.
    Classe(const Classe & entity)
        : NumRelationEntity(entity),
          IdNivAttribut(entity.idNiv())
        {}

    //! Destructeur.
    ~Classe()
        {}

    ALIAS_CLE(An,1)
    ALIAS_CLE(Etab,2)

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return NumRelationEntity::isValid()
                && (IdNivAttribut::valide());
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Classe & entity) const
    {
        return NumRelationEntity::egal(entity)
                &&(idNiv() == entity.idNiv());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Classe & entity)
    {
        NumRelationEntity::set(entity);
        setIdNiv(entity.idNiv());
    }
};

#endif // CLASSE_H
