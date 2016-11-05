/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */
#ifndef NIVEAU_H
#define NIVEAU_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Niveau.
 */
class Niveau : public NcNomEntity
{
    ATTRIBUT_ENTITY_ID(Tp)
    ATTRIBUT_ENTITY_ID(TpEtab)
public:
    //! Positions des attributs.
    enum Position {Id = NcNomEntity::Id,
                   Nom = NcNomEntity::Nom,
                   Nc = NcNomEntity::Nc,
                   IdTp = NcNomEntity::NbrAtt,
                   IdTpEtab,
                   NbrAtt};

    using NcNomEntity::NcNomEntity;
    BASE_ENTITY(Niveau,InfoEntity::NiveauId)

    //! Constructeur à partir des valeurs attributs.
    Niveau(int idTp, int idTpEtab, const QString & nc, const QString & nom, int id = 0)
        : NcNomEntity(nc,nom,id),
          m_idTp(idTp),
          m_idTpEtab(idTpEtab)
    {}

    MEMBRE_ATT_2(Niveau,NcNomEntity,IdTp,idTp,IdTpEtab,idTpEtab)
};

#endif // NIVEAU_H
