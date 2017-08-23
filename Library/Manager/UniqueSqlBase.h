/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/08/2016
 */
#ifndef UNIQUESQLBASE_H
#define UNIQUESQLBASE_H

#include "AbstractUniqueSql.h"
#include "../Entities/Arbre.h"
#include "../Entities/EntityCible.h"
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityRelation.h"

// Unique Arbre
/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (num,parent).
 */
template<class Ent> class ArbreUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique,ParentUnique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //!Destructeur.
    ~ArbreUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        bindValue(NumUnique,entity.num());
        bindValue(ParentUnique,entity.parent());
    }
};

// Unique CibleSimple
/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (IdCible,Cible).
 */
template<class Ent> class CibleSimpleUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {IdCibleUnique,CibleUnique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //!Destructeur.
    ~CibleSimpleUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        bindValue(IdCibleUnique,entity.idCible());
        bindValue(CibleUnique,entity.cible());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triple (IdCible,Cible,Num).
 */
template<class Ent> class CibleSimpleNumUniqueSql : public CibleSimpleUniqueSql<Ent>
{
protected:
    using CibleSimpleUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique = CibleSimpleUniqueSql<Ent>::NbrUnique, NbrUnique};
    using CibleSimpleUniqueSql<Ent>::CibleSimpleUniqueSql;

    //!Destructeur.
    ~CibleSimpleNumUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        CibleSimpleUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(NumUnique,entity.num());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triple (IdCible,Cible,Num,Type).
 */
template<class Ent> class CibleSimpleNumTypeUniqueSql : public CibleSimpleNumUniqueSql<Ent>
{
protected:
    using CibleSimpleNumUniqueSql<Ent>::bindValue;

public:
    enum {TypeUnique = CibleSimpleNumUniqueSql<Ent>::NbrUnique, NbrUnique};
    using CibleSimpleNumUniqueSql<Ent>::CibleSimpleNumUniqueSql;

    //!Destructeur.
    ~CibleSimpleNumTypeUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        CibleSimpleNumUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(TypeUnique,entity.type());
    }
};

// Unique Cible
/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (Id1,Cible).
 */
template<class Ent> class IdCibleUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {Id1Unique,CibleUnique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //!Destructeur.
    ~IdCibleUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        bindValue(Id1Unique,entity.id1());
        bindValue(CibleUnique,entity.cible());
    }
};


/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triple (Id1,IdCible,Cible).
 */
template<class Ent> class CibleUniqueSql : public IdCibleUniqueSql<Ent>
{
protected:
    using IdCibleUniqueSql<Ent>::bindValue;

public:
    enum {IdCibleUnique = IdCibleUniqueSql<Ent>::NbrUnique, NbrUnique};
    using IdCibleUniqueSql<Ent>::IdCibleUniqueSql;

    //!Destructeur.
    ~CibleUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        IdCibleUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(IdCibleUnique,entity.idCible());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le 4-upplet (Id1,IdCible,Cible,DateTime).
 */
template<class Ent> class DateTimeCibleUniqueSql : public CibleUniqueSql<Ent>
{
protected:
    using CibleUniqueSql<Ent>::bindValue;

public:
    enum {DateTimeUnique = CibleUniqueSql<Ent>::NbrUnique, NbrUnique};
    using CibleUniqueSql<Ent>::CibleUniqueSql;

    //!Destructeur.
    ~DateTimeCibleUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        CibleUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(DateTimeUnique,entity.dateTime());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le 4-upplet (Id1,IdCible,Cible,Num).
 */
template<class Ent> class NumCibleUniqueSql : public CibleUniqueSql<Ent>
{
protected:
    using CibleUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique = CibleUniqueSql<Ent>::NbrUnique, NbrUnique};
    using CibleUniqueSql<Ent>::CibleUniqueSql;

    //!Destructeur.
    ~NumCibleUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        CibleUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(NumUnique,entity.num());
    }
};

// Cible Null

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (IdCible,Cible).
 */
template<class Ent> class CibleNullUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {IdCibleUnique, CibleUnique, NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //!Destructeur.
    ~CibleNullUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        bindValue(IdCibleUnique,entity.idCible());
        bindValue(CibleUnique,entity.cible());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le tripplet (IdCible,Cible,Num).
 */
template<class Ent> class NumCibleNullUniqueSql : public CibleNullUniqueSql<Ent>
{
protected:
    using CibleNullUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique = CibleNullUniqueSql<Ent>::NbrUnique, NbrUnique};
    using CibleNullUniqueSql<Ent>::CibleNullUniqueSql;

    //!Destructeur.
    ~NumCibleNullUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent & entity)
    {
        CibleNullUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(NumUnique,entity.num());
    }
};

// Unique Nom

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le nom.
 */
template<class Ent> class NomUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {NomUnique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //! Destructeur.
    ~NomUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(NomUnique,entity.nom());}
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (nc, nom).
 */
template<class Ent> class NcNomUniqueSql : public NomUniqueSql<Ent>
{
protected:
    using NomUniqueSql<Ent>::bindValue;

public:
    enum {NcUnique = NomUniqueSql<Ent>::NbrUnique};
    using NomUniqueSql<Ent>::NomUniqueSql;

    //! Destructeur.
    ~NcNomUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        NomUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(NcUnique,entity.nc());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (nom, type).
 */
template<class Ent> class TypeNomUniqueSql : public NomUniqueSql<Ent>
{
protected:
    using NomUniqueSql<Ent>::bindValue;

public:
    enum {TypeUnique = NomUniqueSql<Ent>::NbrUnique,NbrUnique};
    using NomUniqueSql<Ent>::NomUniqueSql;

    //! Destructeur.
    ~TypeNomUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        NomUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(TypeUnique,entity.type());
    }
};

// Unique Relation

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple de clé (id1,id2).
 */
template<class Ent> class RelationUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {Id1Unique,Id2Unique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //! Destructeur.
    ~RelationUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        bindValue(Id1Unique,entity.id1());
        bindValue(Id2Unique,entity.id2());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triplet (id1,id2,date).
 */
template<class Ent> class DateTimeRelationUniqueSql : public RelationUniqueSql<Ent>
{
protected:
    using RelationUniqueSql<Ent>::bindValue;

public:
    enum {DateTimeUnique = RelationUniqueSql<Ent>::NbrUnique,NbrUnique};
    using RelationUniqueSql<Ent>::RelationUniqueSql;

    //! Destructeur.
    ~DateTimeRelationUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        RelationUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(DateTimeUnique,entity.dateTime());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le triplet (id1,id2,num).
 */
template<class Ent> class NumRelationUniqueSql : public RelationUniqueSql<Ent>
{
protected:
    using RelationUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique = RelationUniqueSql<Ent>::NbrUnique,NbrUnique};
    using RelationUniqueSql<Ent>::RelationUniqueSql;

    //! Destructeur.
    ~NumRelationUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        RelationUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(NumUnique,entity.num());
    }
};

// Unique Divers

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le num.
 */
template<class Ent> class NumUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {NumUnique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //! Destructeur.
    ~NumUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(NumUnique,entity.num());}
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le couple (id1,num).
 */
template<class Ent> class IdNumUniqueSql : public NumUniqueSql<Ent>
{
protected:
    using NumUniqueSql<Ent>::bindValue;

public:
    enum {Id1Unique = NumUniqueSql<Ent>::NbrUnique,NbrUnique};
    using NumUniqueSql<Ent>::NumUniqueSql;

    //! Destructeur.
    ~IdNumUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
    {
        NumUniqueSql<Ent>::bindValuesUnique(entity);
        bindValue(Id1Unique,entity.id1());
    }
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur l'attribut idProg.
 */
template<class Ent> class IdProgUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {IdProgUnique ,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //! Destructeur.
    ~IdProgUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(IdProgUnique,entity.idProg());}
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant deux conditions d'unicité sur l'attribut idProg et le nom.
 */
template<class Ent> class IdProgNomUniqueSql : public DoubleUniqueSql<Ent>
{
protected:
    using DoubleUniqueSql<Ent>::bindValue;
    using DoubleUniqueSql<Ent>::bindValuesUnique_1;
    using DoubleUniqueSql<Ent>::bindValuesUnique_2;

public:
    enum {IdProgUnique ,NomUnique = IdProgUnique};
    using DoubleUniqueSql<Ent>::DoubleUniqueSql;

    //! Destructeur.
    ~IdProgNomUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_1(const Ent &entity)
        {bindValue(IdProgUnique,entity.idProg());}

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_2(const Ent &entity)
        {bindValue(NomUnique,entity.nom());}
};

/*! \ingroup groupeUniqueSqlBase
 * \brief Classe condition d'unicité pour les entités possédant une seule condition d'unicité sur le texte.
 */
template<class Ent> class TexteUniqueSql : public SimpleUniqueSql<Ent>
{
protected:
    using SimpleUniqueSql<Ent>::bindValue;

public:
    enum {TexteUnique,NbrUnique};
    using SimpleUniqueSql<Ent>::SimpleUniqueSql;

    //! Destructeur.
    ~TexteUniqueSql() {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Ent &entity)
        {bindValue(TexteUnique,entity.texte());}
};
#endif // UNIQUESQLBASE_H
