/*Auteur: PERCIE DU SERT Maxime
 *Date: 09/01/2017
 */
#ifndef TYPECONTROLE_H
#define TYPECONTROLE_H

#include "AttributEntity.h"
#include"EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Controle.
 */
class TypeControle : public NcNomEntity
{
    //ATTRIBUT_ENTITY_ID_NULL(SousType)
    ATTRIBUT_ENTITY_BOOL(Appreciation,appreciation)
    ATTRIBUT_ENTITY_INT_SUP(Decimale,decimale,1)
    ATTRIBUT_ENTITY_BOOL(Modif,modif)
    ATTRIBUT_ENTITY_INT_SUP(Total,total,1)

public:
    //! Positions des attributs.
    enum Position {Id = NcNomEntity::Id,
                   Nom = NcNomEntity::Nom,
                   Nc = NcNomEntity::Nc,
                   //IdSousType = NcNomEntity::NbrAtt,
                   Appreciation= NcNomEntity::NbrAtt,
                   Decimale,
                   Modif,
                   Total,
                   NbrAtt};

    using NcNomEntity::NcNomEntity;
    BASE_ENTITY(TypeControle,InfoEntity::TypeControleId)

    //! Constructeur à partir des valeurs attributs.
    TypeControle(bool appreciation, int decimale, bool modif, const QString & nc, const QString & nom, int total, int id = 0)
         : NcNomEntity(nc,nom,id), /*m_idSousType(0),*/ m_appreciation(appreciation), m_decimale(decimale), m_modif(modif), m_total(total)
     {}

    /*//! Constructeur à partir des valeurs attributs.
    TypeControle(int idSousType, bool appreciation, int decimale, bool modif, const QString & nc, const QString & nom, int total, int id = 0)
         : NcNomEntity(nc,nom,id), m_idSousType(idSousType), m_appreciation(appreciation), m_decimale(decimale), m_modif(modif), m_total(total)*/

    //MEMBRE_ATT_5(TypeControle,NcNomEntity,IdSousType,idSousType,Appreciation,appreciation,Decimale,decimale,Modif,modif,Total,total)
    MEMBRE_ATT_4(TypeControle,NcNomEntity,Appreciation,appreciation,Decimale,decimale,Modif,modif,Total,total)
};

#endif // TYPECONTROLE_H
