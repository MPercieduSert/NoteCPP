/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/08/2016
 */
#ifndef INFOBDDBASE_H
#define INFOBDDBASE_H

#include <QMap>
#include <stdexcept>
#include "LinkSqlBase.h"
#include "UniqueSqlBase.h"
#include "../Entities/Arbre.h"
#include "../Entities/EntityCible.h"
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityNom.h"
#include "../Entities/EntityRelation.h"
#include "../Entities/InfoEntityBase.h"


/*! \defgroup groupeInfoBdd Information sur la structure de la base de données.
 * \ingroup groupeManager
 * \brief Ensemble d'informations sur la structure des entités dans la base de données.
 */

/*! \ingroup groupeInfoBdd
 * \brief Macro de déclaration des fontions statiques attribut et creerAttribut.
 */
#define FONC_CREER_LINK /*! \brief Retourne la liste des caractéristiques sql des attributs.*/ \
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();

/*! \ingroup groupeInfoBdd
 * \brief Macro de déclaration des fontions statiques attribut et creerAttribut.
 */
#define FONC_ATTRIBUT_LINK /*! \brief Retourne la liste des nom sql des attributs.*/ \
    static QMap<int,QString> attribut(); \
    FONC_CREER_LINK

/*! \ingroup groupeInfoBdd
 * \brief Macro de déclaration de la fontion statique attributUnique.
 */
#define FONC_UNIQUE_LINK /*! \brief Retourne la liste des attributs uniques.*/ \
    static QVector<QMap<int,int>> attributUnique();

using namespace bdd;
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd sans condition d'unicité.
 */
class NoUniqueInfoBdd
{public:
    FONC_UNIQUE_LINK};

/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd sans clé étrangère.
 */
class NoKeyInfoBdd
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();
};

// Arbre
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les Arbres.
 */
class ArbreInfoBdd
{
public:
    typedef ArbreUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type noeuds d'arbre.
 */
class NodeInfoBdd
{
public:
    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attributArbre()
        {return ArbreInfoBdd::attribut();}
};

//CibleEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type CibleEntity.
 */
class CibleInfoBdd
{
public:
    typedef CibleUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

//DateTimeCibleEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeCibleEntity.
 */
class DateTimeCibleInfoBdd : public CibleInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// NumDateTimeCibleEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumDateTimeCibleEntity.
 */
class NumDateTimeCibleInfoBdd : public DateTimeCibleInfoBdd
{
public:
    typedef NumDateTimeCibleUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// ValeurNumDateTimeCibleEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurNumDateTimeCibleEntity.
 */
class ValeurNumDateTimeCibleInfoBdd : public NumDateTimeCibleInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// NumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumEntity.
 */
class NumInfoBdd : public NoKeyInfoBdd
{
public:
    typedef NumUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// DateTimeNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeNumEntity.
 */
class DateTimeNumInfoBdd : public NumInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// IdNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type IdNumEntity.
 */
class IdNumInfoBdd : public NumInfoBdd
{
public:
    typedef IdNumUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// ValeurIdNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurIdNumEntity.
 */
class ValeurIdNumInfoBdd : public IdNumInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// ValeurDoubleIdNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurDoubleIdNumEntity.
 */
class ValeurDoubleIdNumInfoBdd : public ValeurIdNumInfoBdd
{
public:
    FONC_CREER_LINK
};

// ValeurIntIdNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurIntIdNumEntity.
 */
class ValeurIntIdNumInfoBdd : public ValeurIdNumInfoBdd
{
public:
    FONC_CREER_LINK
};

// TexteEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TexteEntity.
 */
class TexteInfoBdd : public NoKeyInfoBdd
{
public:
    typedef TexteUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// NomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NomEntity.
 */
class NomInfoBdd : public NoKeyInfoBdd
{
public:
    typedef NomUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// NcNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NcNomEntity.
 */
class NcNomInfoBdd : public NomInfoBdd
{
public:
    typedef NcNomUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// TypeNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TypeNomEntity.
 */
class TypeNomInfoBdd : public NomInfoBdd
{
public:
    typedef TypeNomUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// TypeNcNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TypeNcNomEntity.
 */
class TypeNcNomInfoBdd : public TypeNomInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// RelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type RelationEntity.
 */
class RelationInfoBdd
{
public:
    typedef RelationUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// RelationExactOneNotNullEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type RelationExactOneNotNullEntity.
 */
class RelationExactOneNotNullInfoBdd
{
public:
    typedef RelationExactOneNotNullUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// DateTimeRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeRelationEntity.
 */
class DateTimeRelationInfoBdd : public RelationInfoBdd
{
public:
    typedef DateTimeRelationUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// ValeurDateTimeRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurDateTimeRelationEntity.
 */
class ValeurDateTimeRelationInfoBdd : public DateTimeRelationInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// NumRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumRelationEntity.
 */
class NumRelationInfoBdd : public RelationInfoBdd
{
public:
    typedef NumRelationUniqueSql EntUniqueSql;
    FONC_ATTRIBUT_LINK
    FONC_UNIQUE_LINK
};

// DateTimeNumRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeNumRelationEntity.
 */
class DateTimeNumRelationInfoBdd : public NumRelationInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};

// ValeurIntDateTimeRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurIntDateTimeRelationEntity.
 */
class ValeurIntDateTimeNumRelationInfoBdd : public DateTimeNumRelationInfoBdd
{
public:
    FONC_ATTRIBUT_LINK
};
#endif // INFOBDDBASE_H
