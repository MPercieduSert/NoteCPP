/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/03/2016
 */
#ifndef CLASSEELEVE_H
#define CLASSEELEVE_H

#include "AttributEntityAlias.h"
#include "EntityRelation.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité ClasseEleve.
 */

class ClasseEleve : public RelationEntity<ClasseEleve>, public EntreeAttribut, public SortieAttribut
{
public:
    RELATION_ALIAS_2_CLE(Cl,El,ClasseEleve)

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

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return RelationEntity::isValid()
                && EntreeAttribut::valide()
                && SortieAttribut::valide();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const ClasseEleve & entity) const
    {
        return RelationEntity::egal(entity)
                &&(entree() == entity.entree())
                &&(sortie() == entity.sortie());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const ClasseEleve & entity)
    {
        RelationEntity::set(entity);
        setEntree(entity.entree());
        setSortie(entity.sortie());
    }
};

#endif // CLASSEELEVE_H
