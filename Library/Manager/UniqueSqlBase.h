/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/08/2016
 */
#ifndef UNIQUESQLBASE_H
#define UNIQUESQLBASE_H

#include "AbstractUniqueSql.h"
#include "../Entities/Arbre.h"
#include "../Entities/EntityCible.h"
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
    enum {NumUnique,ParentUnique,NbrUnique};
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
        bindValue(NumUnique,entity.num());
        bindValue(ParentUnique,entity.parent());
    }
};

typedef ArbreUniqueSqlTemp<Arbre> ArbreUniqueSql;

// Unique Cible
/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triple (Id1,IdCible,Cible).
 */
template<class Ent> class CibleUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {Id1Unique,IdCibleUnique,CibleUnique,NbrUnique};
    //! Constructeur.
    CibleUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : SimpleUniqueSql<Ent>(table,atts)
        {}

    //!Destructeur.
    ~CibleUniqueSqlTemp()
        {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        bindValue(Id1Unique,entity.id1());
        bindValue(IdCibleUnique,entity.idCible());
        bindValue(CibleUnique,entity.cible());
    }
};

typedef CibleUniqueSqlTemp<CibleEntity> CibleUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le 4-upplet (Id1,IdCible,Cible,Num).
 */
template<class Ent> class NumCibleUniqueSqlTemp : public CibleUniqueSqlTemp<Ent>
{
protected:
    using CibleUniqueSqlTemp<Ent>::bindValue;

public:
    enum {NumUnique = CibleUniqueSqlTemp<Ent>::NbrUnique, NbrUnique};
    //! Constructeur.
    NumCibleUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : CibleUniqueSqlTemp<Ent>(table,atts)
        {}

    //!Destructeur.
    ~NumCibleUniqueSqlTemp()
        {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const NumDateTimeCibleEntity & entity)
    {
        CibleUniqueSqlTemp<Ent>::bindValuesUnique(entity);
        bindValue(NumUnique,entity.num());
    }
};

typedef NumCibleUniqueSqlTemp<NumDateTimeCibleEntity> NumDateTimeCibleUniqueSql;

// Unique Nom

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le nom.
 */
template<class Ent> class NomUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {NomUnique,NbrUnique};
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
        {bindValue(NomUnique,entity.nom());}
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
    enum {NcUnique = NomUniqueSqlTemp<Ent>::NbrUnique};
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
        bindValue(NcUnique,entity.nc());
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
    enum {TypeUnique = NomUniqueSqlTemp<Ent>::NbrUnique};
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
        bindValue(TypeUnique,entity.type());
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
    enum {Id1Unique,Id2Unique,NbrUnique};
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
        bindValue(Id1Unique,entity.id1());
        bindValue(Id2Unique,entity.id2());
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
    enum {DateTimeUnique = RelationUniqueSql::NbrUnique,NbrUnique};
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
        bindValue(DateTimeUnique,entity.dateTime());
    }
};

typedef DateTimeRelationUniqueSqlTemp<DateTimeRelationEntity> DateTimeRelationUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triplet (id1,id2,num).
 */
template<class Ent> class NumRelationUniqueSqlTemp : public RelationUniqueSqlTemp<Ent>
{
protected:
    using RelationUniqueSqlTemp<Ent>::bindValue;

public:
    enum {NumUnique = RelationUniqueSql::NbrUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NumRelationUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : RelationUniqueSqlTemp<Ent>(table,atts)
    {}

    //! Destructeur.
    ~NumRelationUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        RelationUniqueSqlTemp<Ent>::bindValuesUnique(entity);
        bindValue(NumUnique,entity.num());
    }
};

typedef NumRelationUniqueSqlTemp<NumRelationEntity> NumRelationUniqueSql;

// Unique Divers

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le num.
 */
template<class Ent> class NumUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    NumUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        :SimpleUniqueSql<Ent>(table,atts)
    {}

    //! Destructeur.
    ~NumUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(NumUnique,entity.num());}
};

typedef NumUniqueSqlTemp<NumEntity> NumUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (id1,num).
 */
template<class Ent> class IdNumUniqueSqlTemp : public NumUniqueSqlTemp<Ent>
{
protected:
    using NumUniqueSqlTemp<Ent>::bindValue;

public:
    enum {Id1Unique = NumUniqueSqlTemp<Ent>::NbrUnique,NbrUnique};
    //! Construteur, transmettre en argument l'objet de requète utilisé par le manageur.
    IdNumUniqueSqlTemp(const QString & table, const QVector<QMap<int,QString>> & atts)
        : NumUniqueSqlTemp<Ent>(table,atts)
    {}

    //! Destructeur.
    ~IdNumUniqueSqlTemp()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const IdNumEntity &entity)
    {
        NumUniqueSqlTemp<Ent>::bindValuesUnique(entity);
        bindValue(Id1Unique,entity.id1());
    }
};

typedef IdNumUniqueSqlTemp<IdNumEntity> IdNumUniqueSql;

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le texte.
 */
template<class Ent> class TexteUniqueSqlTemp : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {TexteUnique,NbrUnique};
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
        {bindValue(TexteUnique,entity.texte());}
};

typedef TexteUniqueSqlTemp<TexteEntity> TexteUniqueSql;
#endif // UNIQUESQLBASE_H
