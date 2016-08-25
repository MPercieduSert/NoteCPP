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
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityNom.h"
#include "../Entities/EntityRelation.h"
#include "../Entities/InfoEntityBase.h"

/*! \defgroup groupeInfoBdd Information sur la structure de la base de données.
 * \ingroup groupeManager
 * \brief Ensemble d'informations sur la structure des entités dans la base de données.
 */

using namespace bdd;
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd sans condition d'unicité.
 */
class NoUniqueInfoBdd
{
public:
    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();
};

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
 * \brief Classe mère des InfoBdd pour les entités de type Arbre.
 */
class ArbreInfoBdd
{
public:
    typedef ArbreUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// NumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumEntity.
 */
class NumInfoBdd : public NoKeyInfoBdd
{
public:
    typedef NumUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// DateTimeNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeNumEntity.
 */
class DateTimeNumInfoBdd : public NumInfoBdd
{
public:
    typedef NumUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// TexteEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TexteEntity.
 */
class TexteInfoBdd : public NoKeyInfoBdd
{
public:
    typedef TexteUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// NomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NomEntity.
 */
class NomInfoBdd : public NoKeyInfoBdd
{
public:
    typedef NomUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// NcNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NcNomEntity.
 */
class NcNomInfoBdd : public NomInfoBdd
{
public:
    typedef NcNomUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// TypeNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TypeNomEntity.
 */
class TypeNomInfoBdd : public NomInfoBdd
{
public:
    typedef TypeNomUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// TypeNcNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TypeNcNomEntity.
 */
class TypeNcNomInfoBdd : public TypeNomInfoBdd
{
public:
    typedef TypeNomUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// RelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type RelationEntity.
 */
class RelationInfoBdd
{
public:
    typedef RelationUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// RelationExactOneNotNullEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type RelationExactOneNotNullEntity.
 */
class RelationExactOneNotNullInfoBdd
{
public:
    typedef RelationExactOneNotNullUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// NumRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumRelationEntity.
 */
class NumRelationInfoBdd : public RelationInfoBdd
{
public:
    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// DateTimeRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeRelationEntity.
 */
class DateTimeRelationInfoBdd : public RelationInfoBdd
{
public:
    typedef DateTimeRelationUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

// ValeurDateTimeRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type ValeurDateTimeRelationEntity.
 */
class ValeurDateTimeRelationInfoBdd : public DateTimeRelationInfoBdd
{
public:
    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};
#endif // INFOBDDBASE_H
