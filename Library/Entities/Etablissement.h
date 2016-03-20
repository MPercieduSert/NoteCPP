/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/03/2016
 */

#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Etablissement.
 */
class Etablissement : public TypeNomEntity, public EntityTemp<IdentifiantEntity::EtablissementId,4,Etablissement>, public NcAttribut
{
public:
    POS_3_ATT(Nc,Nom,Type)

    //! Constructeur par defaut.
    Etablissement(int id = 0)
        :TypeNomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Etablissement(const QString & nc, const QString & nom, int type, int id=0)
        : TypeNomEntity(nom,type,id),
          NcAttribut(nc)
    {}

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Etablissement(const QString & nom)
        : TypeNomEntity(nom)
    {}

    //! Constructeur de recopie.
    Etablissement(const Etablissement & entity)
        : TypeNomEntity(entity),
          NcAttribut(entity.nc())
    {}

    //! Destructeur.
    ~Etablissement()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return TypeNomEntity::isValid()
                && NcAttribut::valide();}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Etablissement & entity) const
    {
        return TypeNomEntity::egal(entity)
                &&(nc() == entity.nc());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Etablissement & entity)
    {
        TypeNomEntity::set(entity);
        setNc(entity.nc());
    }
};

#endif // ETABLISSEMENT_H
