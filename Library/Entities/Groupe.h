/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef GROUPE_H
#define GROUPE_H

#include "AttributEntityAlias.h"
#include "EntityRelation.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Groupe.
 */
class Groupe : public RelationExactOneNotNullEntity<Groupe>,
                    public AlphaAttribut,
                    public NomAttribut,
                    public TypeAttribut
{
public:
    enum grPour {GrAnnee = 0,
                 GrClasse =1};

    //! Constructeur par defaut.
    Groupe(int id = 0)
        :RelationExactOneNotNullEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Groupe(int idAn, int idCl, int alpha, const QString & nom, int type, int id = 0)
        : RelationExactOneNotNullEntity(idAn,idCl,id),
          AlphaAttribut(alpha),
          NomAttribut(nom),
          TypeAttribut(type)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Groupe(int cle, const QString & nom, grPour pr)
        : NomAttribut(nom)
    {
        if(pr == GrClasse)
            {setIdCl(cle);}
        else
            {setIdAn(cle);}
    }

    RELATION_ALIAS_2_CLE(An,Cl,Groupe)

    //! Teste si l'entité est valide.
    bool isValid() const
    {return RelationExactOneNotNullEntity::isValid()
                && AlphaAttribut::valide()
                && NomAttribut::valide()
                && TypeAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Groupe & entity) const
    {
        return RelationExactOneNotNullEntity::egal(entity)
                && (alpha() == entity.alpha())
                && (nom() == entity.nom())
                && (type() == entity.type());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Groupe & entity)
    {
        RelationExactOneNotNullEntity::set(entity);
        setAlpha(entity.alpha());
        setNom(entity.nom());
        setType(entity.type());
    }
};

#endif // GROUPE_H
