/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef NIVEAU_H
#define NIVEAU_H

#include "AttributEntityAlias.h"
#include "EntityNom.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Niveau.
 */
class Niveau : public NcNomEntity<Niveau>, public IdTpAttribut
{
public:
    //! Constructeur par defaut.
    Niveau(int id = 0)
        :NcNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Niveau(int idTp, const QString & nc, const QString & nom, int id = 0)
        : NcNomEntity(nc,nom,id),
          IdTpAttribut(idTp)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Niveau(const QString & nom)
        : NcNomEntity(nom)
        {}

    //! Constructeur de recopie.
    Niveau(const Niveau & entity)
        : NcNomEntity(entity),
          IdTpAttribut(entity.idTp())
    {}

    //! Destructeur.
    ~Niveau()
    {}

    //! Teste si l'entité est valide.
    bool isValid() const
        {return NcNomEntity::isValid()
                && IdTpAttribut::valide();}

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Niveau & entity) const
    {
        return NcNomEntity::egal(entity)
                && (idTp() == entity.idTp());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Niveau & entity)
    {
        NcNomEntity::set(entity);
        setIdTp(entity.idTp());
    }
};

#endif // NIVEAU_H
