/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/08/2016
 */
#ifndef UNIQUESQLBASE_H
#define UNIQUESQLBASE_H

#include "AbstractUniqueSql.h"
#include "../Entities/Arbre.h"
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityNom.h"
#include "../Entities/EntityRelation.h"

// Unique Arbre
/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (num,parent).
 */
template<class Ent> class ArbreUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {numUnique,parentUnique,NbrUnique};
    //! Constructeur.
    ArbreUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        :SimpleUniqueSql<Ent>(table,atts)
        {}

    //!Destructeur.
    ~ArbreUniqueSqlTemp()
        {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Arbre & entity)
    {
        bindValue(numUnique,entity.num());
        bindValue(parentUnique,entity.parent());
    }
};

typedef ArbreUniqueSqlTemp<Arbre> ArbreUniqueSql;

// Unique Nom

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le nom.
 */
template<class Ent> class NomUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {nomUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NomUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        :SimpleUniqueSql<Ent>(table,atts)
    {}

    //! Destructeur.
    ~NomUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(nomUnique,entity.nom());}
};

typedef NomUniqueSqlTemp<NomEntity> NomUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (nc, nom).
 */
template<class Ent> class NcNomUniqueSqlTemp : public NomUniqueSqlTemp<Ent>
{
protected:
    using NomUniqueSqlTemp<Ent>::bindValue;

public:
    enum {ncUnique = NomUniqueSqlTemp<Ent>::NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NcNomUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : NomUniqueSqlTemp<Ent>(table,atts)
        {}

    //! Destructeur.
    ~NcNomUniqueSqlTemp()
        {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const NcNomEntity &entity)
    {
        NomUniqueSqlTemp<Ent>::bindValuesUnique(entity);
        bindValue(ncUnique,entity.nc());
    }
};

typedef NcNomUniqueSqlTemp<NcNomEntity> NcNomUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (nom, type).
 */
template<class Ent> class TypeNomUniqueSqlTemp : public NomUniqueSqlTemp<Ent>
{
protected:
    using NomUniqueSqlTemp<Ent>::bindValue;

public:
    enum {typeUnique = NomUniqueSqlTemp<Ent>::NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    TypeNomUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : NomUniqueSqlTemp<Ent>(table,atts)
        {}

    //! Destructeur.
    ~TypeNomUniqueSqlTemp()
        {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const TypeNomEntity &entity)
    {
        NomUniqueSqlTemp<Ent>::bindValuesUnique(entity);
        bindValue(typeUnique,entity.type());
    }
};

typedef TypeNomUniqueSqlTemp<TypeNomEntity> TypeNomUniqueSql;

// Unique Relation

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple de clé (id1,id2).
 */
template<class Ent> class RelationUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {id1Unique,id2Unique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    RelationUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        :SimpleUniqueSql<Ent>(table,atts)
    {}

    //! Destructeur.
    ~RelationUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        bindValue(id1Unique,entity.id1());
        bindValue(id2Unique,entity.id2());
    }
};

typedef RelationUniqueSqlTemp<RelationEntity> RelationUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triplet (id1,id2,date).
 */
template<class Ent> class DateTimeRelationUniqueSqlTemp : public RelationUniqueSqlTemp<Ent>
{
protected:
    using RelationUniqueSqlTemp<Ent>::bindValue;

public:
    enum {dateUnique = RelationUniqueSql::NbrUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    DateTimeRelationUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : RelationUniqueSqlTemp<Ent>(table,atts)
    {}

    //! Destructeur.
    ~DateTimeRelationUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        RelationUniqueSqlTemp<Ent>::bindValuesUnique(entity);
        bindValue(dateUnique,entity.date());
    }
};

typedef DateTimeRelationUniqueSqlTemp<DateTimeRelationEntity> DateTimeRelationUniqueSql;

// Unique Divers

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le num.
 */
template<class Ent> class NumUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {numUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NumUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        :SimpleUniqueSql<Ent>(table,atts)
    {}

    //! Destructeur.
    ~NumUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const NumEntity &entity)
        {bindValue(numUnique,entity.num());}
};

typedef NumUniqueSqlTemp<NumEntity> NumUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le texte.
 */
template<class Ent> class TexteUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {texteUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    TexteUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : SimpleUniqueSql<Ent>(table,atts)
    {}

    //! Destructeur.
    ~TexteUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const TexteEntity &entity)
        {bindValue(texteUnique,entity.texte());}
};

typedef TexteUniqueSqlTemp<TexteEntity> TexteUniqueSql;
#endif // UNIQUESQLBASE_H
