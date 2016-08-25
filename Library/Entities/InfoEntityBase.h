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
enum entityBaseId{entityId,
                   ArbreId,
                   DateTimeRelationEntityId,
                   DateTimeNumEntityId,
                   NcNomEntityId,
                   NomEntityId,
                   NumEntityId,
                   NumRelationEntityId,
                   RelationEntityId,
                   RelationExactOneNotNullEntityId,
                   TexteEntityId,
                   TypeNcNomEntityId,
                   TypeNomEntityId,
                   ValeurDateTimeRelationEntityId,
                   VersionBddId};
};

#endif // INFOENTITYBASE_H
