/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef CLASSE_H
#define CLASSE_H

#include "AttributEntityAlias.h"
#include "EntityRelation.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Bareme.
 */
class Classe : public NumRelationEntity<Classe>, public IdNivAttribut
{
public:
    RELATION_ALIAS_2_CLE(An,Etab,Classe)

    //! Type d'affichage.
    enum affichage {Sans,
                   Numeric,
                   AlphabeticMaj,
                   AlphabeticMin};

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

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return NumRelationEntity::isValid()
                && (IdNivAttribut::valide());
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Classe & entity) const
    {
        return NumRelationEntity::egal(entity)
                &&(idNiv() == entity.idNiv());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Classe & entity)
    {
        NumRelationEntity::set(entity);
        setIdNiv(entity.idNiv());
    }
};

#endif // CLASSE_H
