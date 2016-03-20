/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */

#ifndef CLASSEELEVE_H
#define CLASSEELEVE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée ClasseEleve.
 */

class ClasseEleve : public RelationEntity, public EntityTemp<IdentifiantEntity::ClasseEleveId,4,ClasseEleve>, public EntreeAttribut, public SortieAttribut
{
public:
    POS_4_ATT(IdCl,IdEl,Rentree,Sortie)

    //! Constructeur par defaut.
    ClasseEleve(int id = 0)
        : RelationEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    ClasseEleve(int idCl, int idEl, const QDate & entree = QDate(), const QDate & sortie = QDate(), int id = 0)
        : RelationEntity(idCl, idEl, id),
          EntreeAttribut(entree),
          SortieAttribut(sortie)
    {}

    //! Constructeur de recopie.
    ClasseEleve(const ClasseEleve & entity)
        : RelationEntity(entity),
          EntreeAttribut(entity.entree()),
          SortieAttribut(entity.sortie())
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return RelationEntity::isValid()
                && EntreeAttribut::valide()
                && SortieAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const ClasseEleve & entity) const
    {
        return RelationEntity::egal(entity)
                &&(entree() == entity.entree())
                &&(sortie() == entity.sortie());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const ClasseEleve & entity)
    {
        RelationEntity::set(entity);
        setEntree(entity.entree());
        setSortie(entity.sortie());
    }
};

#endif // CLASSEELEVE_H
