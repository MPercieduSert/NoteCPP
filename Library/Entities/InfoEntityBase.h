/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/03/2016
 */
#ifndef INFOENTITYBASE_H
#define INFOENTITYBASE_H

/*! \defgroup groupeInfoEntity Informations sur les entités
 * \ingroup groupeEntity
 * \brief Ensemble des informations sur les entités.
 */

/*! \ingroup groupeInfoEntity
 * \brief Espace de noms contenant les enumérations sur les entités.
 */
namespace InfoEntity
{
//! Liste des identifiants des types d'entités.
enum entityBaseId{entityId = -26,
                   ArbreId,
                   ArbreSimpleId,
                   CibleEntityId,
                   DateTimeCibleEntityId,
                   DateTimeNumEntityId,
                   DateTimeNumRelationEntityId,
                   DateTimeRelationEntityId,
                   IdNumEntityId,
                   NcNomEntityId,
                   NomEntityId,
                   NumDateTimeCibleEntityId,
                   NumEntityId,
                   NumRelationEntityId,
                   RelationEntityId,
                   RelationExactOneNotNullEntityId,
                   TexteEntityId,
                   TypeNcNomEntityId,
                   TypeNomEntityId,
                   ValeurDateTimeRelationEntityId,
                   ValeurIntDateTimeNumRelationEntityId,
                   ValeurDoubleIdNumEntityId,
                   ValeurIdNumEntityId,
                   ValeurIntIdNumEntityId,
                   ValeurNumDateTimeCibleEntityId,
                   VersionBddId};
};

#endif // INFOENTITYBASE_H
