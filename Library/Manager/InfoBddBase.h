/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/08/2016
 */
#ifndef INFOBDDBASE_H
#define INFOBDDBASE_H

#include <QMap>
#include <stdexcept>
#include "UniqueSqlBase.h"
#include "../Entities/Arbre.h"
#include "../Entities/EntityCible.h"
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityRelation.h"
#include "../Entities/InfoEntityBase.h"


/*! \defgroup groupeInfoBddBase Information sur la structure de la base de données.
 * \ingroup groupeManager
 * \brief Ensemble d'informations sur la structure des entités dans la base de données.
 */

/*! \ingroup groupeInfoBddBase
 * \brief Macro de déclaration de la fontion statique attributUnique.
 */
#define FONC_UNIQUE_LINK /*! \brief Retourne la liste des attributs uniques.*/ \
    static QVector<QMap<int,int>> attributUnique();

/*! \ingroup groupeInfoBddBase
 * \brief Macro de déclaration de classe d'information sur la base de données.
 */
#define SINGLE_INFOBDD(NOM,nom,nombd,type,notnull) /*! \ingroup groupeInfoBddBase \brief Information sur NOM dans la base de données.*/ \
    template<class Ent> class NOM##InfoBdd {public: \
    /*! \brief Retourne la liste des nom sql des attributs.*/ \
    static QMap<int,QString> attribut(); \
    /*! \brief Retourne la liste des caractéristiques sql des attributs.*/ \
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();}; \
    template<class Ent> QMap<int,QString> NOM##InfoBdd<Ent>::attribut() { \
        QMap<int,QString> att; \
        att.insert(Ent::nom,#nombd); \
        return att;} \
    template<class Ent> QMap<int, QPair<bdd::createSql,bool>> NOM##InfoBdd<Ent>::creerAttribut() { \
        QMap<int,QPair<bdd::createSql,bool>> att; \
        att.insert(Ent::nom,QPair<bdd::createSql,bool>(createSql::type,notnull)); \
        return att;}

namespace bddInfo {
    enum typeManager {
        Simple,
        Arbre,
        ArbreModifControle,
        ArbreSimple,
        ArbreSimpleModifControle,
        ModifControle,
        ModifControlePermission,
        Permission
    };
}

using namespace bdd;

/*! \ingroup groupeInfoBddBase
 * \brief Classe template des informations sur la base de données.
 */
template<class... Att> class InfoBddBase;

template<class Att> class InfoBddBase<Att> : public Att
{
public:
    using Att::attribut;
    using Att::creerAttribut;
};

template<class Att, class... Atts> class InfoBddBase<Att, Atts...> : public InfoBddBase<Att>, public InfoBddBase<Atts...>
{
public:
    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut();

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut();
};

template<class Att, class... Atts> QMap<int,QString> InfoBddBase<Att, Atts...>::attribut()
    {return Att::attribut().unite(InfoBddBase<Atts...>::attribut());}

template<class Att, class... Atts> QMap<int, QPair<bdd::createSql, bool> > InfoBddBase<Att, Atts...>::creerAttribut()
    {return Att::creerAttribut().unite(InfoBddBase<Atts...>::creerAttribut());}

SINGLE_INFOBDD(Alpha,Alpha,al,Integer,true)
SINGLE_INFOBDD(Card,Card,cd,Integer,true)
SINGLE_INFOBDD(CibleAtt,Cible,cb,Integer,true)
SINGLE_INFOBDD(Creation,Creation,cr,DateTime,true)
SINGLE_INFOBDD(DateValide,Date,dt,Date,true)
SINGLE_INFOBDD(DateTime,DateTime,dt,DateTime,true)
SINGLE_INFOBDD(Decimale,Decimale,dc,Integer,true)
SINGLE_INFOBDD(Exact,Exact,ex,Bool,true)
SINGLE_INFOBDD(Feuille,Feuille,fl,Bool,true)
SINGLE_INFOBDD(IdCible,IdCible,IDCb,Integer,true)
SINGLE_INFOBDD(IdOrigine,IdOrigine,IDO,Integer,true)
SINGLE_INFOBDD(IdProg,IdProg,ip,Integer,false)
SINGLE_INFOBDD(Id1,Id1,ID1,Integer,true)
SINGLE_INFOBDD(Id1Null,Id1,ID1,Integer,false)
SINGLE_INFOBDD(Id2,Id2,ID2,Integer,true)
SINGLE_INFOBDD(Id2Null,Id2,ID2,Integer,false)
SINGLE_INFOBDD(Id3,Id3,ID3,Integer,true)
SINGLE_INFOBDD(Max,Max,mx,Integer,true)
SINGLE_INFOBDD(Min,Min,mi,Integer,true)
SINGLE_INFOBDD(Modif,Modif,md,Bool,true)
SINGLE_INFOBDD(Modification,Modification,mf,DateTime,true)
SINGLE_INFOBDD(Nc,Nc,nc,Text,true)
SINGLE_INFOBDD(Nom,Nom,mn,Text,true)
SINGLE_INFOBDD(Num,Num,nm,Integer,true)
SINGLE_INFOBDD(Origine,Origine,org,Integer,true)
SINGLE_INFOBDD(Parent,Parent,pt,Integer,false)
SINGLE_INFOBDD(Saisie,Saisie,ss,Bool,true)
SINGLE_INFOBDD(Texte,Texte,te,Text,true)
SINGLE_INFOBDD(Total,Total,tt,Integer,true)
SINGLE_INFOBDD(TpVal,TpVal,tv,Integer,true)
SINGLE_INFOBDD(Type,Type,ty,Integer,true)
SINGLE_INFOBDD(ValeurInt,Valeur,vl,Integer,false)
SINGLE_INFOBDD(ValeurDouble,Valeur,vl,Double,false)
SINGLE_INFOBDD(ValeurVariant,Valeur,vl,Variant,false)

/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd sans condition d'unicité.
 */
template<class Ent> class NoUniqueInfoBdd
{public:
    typedef NoUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK};

template<class Ent> QVector<QMap<int,int>> NoUniqueInfoBdd<Ent>::attributUnique()
    {return QVector<QMap<int,int>>();}

/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd sans clé étrangère.
 */
class NoKeyInfoBdd
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();
};

// Arbre
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les Arbres.
 */
template<class Ent> class ArbreInfoBdd : public InfoBddBase<ParentInfoBdd<Ent>,FeuilleInfoBdd<Ent>,NumInfoBdd<Ent>>
{
public:
    typedef ArbreUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> ArbreInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(ArbreUniqueSql<Ent>::NumUnique,Ent::Num);
    att[0].insert(ArbreUniqueSql<Ent>::ParentUnique,Ent::Parent);
    return att;
}

/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type noeuds d'arbre.
 */
class NodeInfoBdd
{
public:
    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attributArbre()
        {return ArbreInfoBdd<Arbre>::attribut();}
};

// IdProgNomUnique
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type IdCibleEntity.
 */
template<class Ent> class IdProgNomUniqueInfoBdd : public InfoBddBase<IdProgInfoBdd<Ent>,NomInfoBdd<Ent>>
{
public:
    typedef IdProgNomUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> IdProgNomUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(2);
    att[0].insert(IdProgNomUniqueSql<Ent>::IdProgUnique,Ent::IdProg);
    att[1].insert(IdProgNomUniqueSql<Ent>::NomUnique,Ent::Nom);
    return att;
}

//IdCibleEntity
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type IdCibleEntity.
 */
template<class Ent> class IdCibleUniqueInfoBdd : public InfoBddBase<Id1InfoBdd<Ent>,CibleAttInfoBdd<Ent>>
{
public:
    typedef IdCibleUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> IdCibleUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(CibleUniqueSql<Ent>::Id1Unique,Ent::Id1);
    att[0].insert(CibleUniqueSql<Ent>::CibleUnique,Ent::Cible);
    return att;
}

//CibleSimpleEntity
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleSimpleEntity.
 */
template<class Ent> class CibleSimpleUniqueInfoBdd : public InfoBddBase<IdCibleInfoBdd<Ent>,CibleAttInfoBdd<Ent>>
{
public:
    typedef CibleSimpleUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleSimpleUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(CibleSimpleUniqueSql<Ent>::IdCibleUnique,Ent::IdCible);
    att[0].insert(CibleSimpleUniqueSql<Ent>::CibleUnique,Ent::Cible);
    return att;
}

//CibleSimpleNum
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleSimpleNumEntity.
 */
template<class Ent> class CibleSimpleNumUniqueInfoBdd : public InfoBddBase<CibleSimpleUniqueInfoBdd<Ent>,NumInfoBdd<Ent>>
{
public:
    typedef CibleSimpleNumUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleSimpleNumUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(CibleSimpleUniqueInfoBdd<Ent>::attributUnique());
    att[0].insert(CibleSimpleNumUniqueSql<Ent>::NumUnique,Ent::Num);
    return att;
}

//CibleSimpleNumType
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleSimpleNumTypeEntity.
 */
template<class Ent> class CibleSimpleNumTypeUniqueInfoBdd : public InfoBddBase<CibleSimpleNumUniqueInfoBdd<Ent>,TypeInfoBdd<Ent>>
{
public:
    typedef CibleSimpleNumTypeUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleSimpleNumTypeUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(CibleSimpleNumUniqueInfoBdd<Ent>::attributUnique());
    att[0].insert(CibleSimpleNumTypeUniqueSql<Ent>::TypeUnique,Ent::Type);
    return att;
}

//CibleEntity
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleEntity.
 */
template<class Ent> class CibleInfoBdd : public InfoBddBase<IdCibleUniqueInfoBdd<Ent>,IdCibleInfoBdd<Ent>>
{
public:
    typedef CibleUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(IdCibleUniqueInfoBdd<Ent>::attributUnique());
    att[0].insert(CibleUniqueSql<Ent>::IdCibleUnique,Ent::IdCible);
    return att;
}

//DateTimeCibleEntity
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleDateTimeEntity.
 */
template<class Ent> class CibleDateTimeInfoBdd : public InfoBddBase<CibleInfoBdd<Ent>,DateTimeInfoBdd<Ent>>
{
public:
    typedef DateTimeCibleUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleDateTimeInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(CibleInfoBdd<Ent>::attributUnique());
    att[0].insert(DateTimeCibleUniqueSql<Ent>::DateTimeUnique,Ent::DateTime);
    return att;
}

// CibleNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumDateTimeCibleEntity.
 */
template<class Ent> class CibleNumInfoBdd : public InfoBddBase<CibleInfoBdd<Ent>,NumInfoBdd<Ent>>
{
public:
    typedef NumCibleUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleNumInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(CibleInfoBdd<Ent>::attributUnique());
    att[0].insert(NumCibleUniqueSql<Ent>::NumUnique,Ent::Num);
    return att;
}

//CibleNullEntity
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleNullEntity.
 */
template<class Ent> class CibleNullInfoBdd : public InfoBddBase<Id1NullInfoBdd<Ent>,IdCibleInfoBdd<Ent>,CibleAttInfoBdd<Ent>>
{
public:
    typedef CibleNullUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleNullInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(CibleNullUniqueSql<Ent>::IdCibleUnique,Ent::IdCible);
    att[0].insert(CibleNullUniqueSql<Ent>::CibleUnique,Ent::Cible);
    return att;
}

//CibleNullNumEntity
/*! \ingroup groupeInfoBddBase
 * \brief Classe mère des InfoBdd pour les entités de type CibleNullEntity.
 */
template<class Ent> class CibleNullNumInfoBdd : public InfoBddBase<CibleNullInfoBdd<Ent>,NumInfoBdd<Ent>>
{
public:
    typedef NumCibleNullUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> CibleNullNumInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(CibleNullInfoBdd<Ent>::attributUnique());
    att[0].insert(NumCibleNullUniqueSql<Ent>::NumUnique,Ent::Num);
    return att;
}

// NumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumEntity.
 */
template<class Ent> class NumUniqueInfoBdd : public NumInfoBdd<Ent>
{
public:
    typedef NumUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> NumUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(NumUniqueSql<Ent>::NumUnique,Ent::Num);
    return att;
}

// IdNumEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type IdNumEntity.
 */
template<class Ent> class IdNumInfoBdd : public InfoBddBase<Id1InfoBdd<Ent>,NumInfoBdd<Ent>>
{
public:
    typedef IdNumUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> IdNumInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(NumUniqueInfoBdd<Ent>::attributUnique());
    att[0].insert(IdNumUniqueSql<Ent>::Id1Unique,Ent::Id1);
    return att;
}

// IdProgEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type IdProgEntity.
 */
template<class Ent> class IdProgUniqueInfoBdd : public IdProgInfoBdd<Ent>
{
public:
    typedef IdProgUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> IdProgUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(IdProgUniqueSql<Ent>::IdProgUnique,Ent::IdProg);
    return att;
}

// TexteEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TexteEntity.
 */
template<class Ent> class TexteUniqueInfoBdd : public InfoBddBase<CreationInfoBdd<Ent>,ModificationInfoBdd<Ent>,TexteInfoBdd<Ent>>
{
public:
    typedef TexteUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> TexteUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(TexteUniqueSql<Ent>::TexteUnique,Ent::Texte);
    return att;
}

// NomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NomEntity.
 */
template<class Ent> class NomUniqueInfoBdd : public NomInfoBdd<Ent>
{
public:
    typedef NomUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> NomUniqueInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(NomUniqueSql<Ent>::NomUnique,Ent::Nom);
    return att;
}

// NcNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NcNomEntity.
 */
template<class Ent> class NcNomInfoBdd : public InfoBddBase<NcInfoBdd<Ent>,NomUniqueInfoBdd<Ent>>
{
public:
    typedef NcNomUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> NcNomInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(NomUniqueInfoBdd<Ent>::attributUnique());
    att[0].insert(NcNomUniqueSql<Ent>::NcUnique,Ent::Nc);
    return att;
}

// TypeNomEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type TypeNomEntity.
 */
template<class Ent> class NomTypeInfoBdd : public InfoBddBase<NomUniqueInfoBdd<Ent>,TypeInfoBdd<Ent>>
{
public:
    typedef TypeNomUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> NomTypeInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(NomUniqueInfoBdd<Ent>::attributUnique());
    att[0].insert(TypeNomUniqueSql<Ent>::TypeUnique,Ent::Type);
    return att;
}

// RelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type RelationEntity.
 */
template<class Ent> class RelationInfoBdd : public InfoBddBase<Id1InfoBdd<Ent>,Id2InfoBdd<Ent>>
{
public:
    typedef RelationUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> RelationInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(RelationUniqueSql<Ent>::Id1Unique,Ent::Id1);
    att[0].insert(RelationUniqueSql<Ent>::Id2Unique,Ent::Id2);
    return att;
}

// RelationExactOneNotNullEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type RelationExactOneNotNullEntity.
 */
template<class Ent> class RelationExactOneNotNullInfoBdd : public InfoBddBase<Id1NullInfoBdd<Ent>,Id2NullInfoBdd<Ent>>
{
public:
    typedef RelationExactOneNotNullUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> RelationExactOneNotNullInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(2);
    att[0].insert(RelationExactOneNotNullUniqueSql<Ent>::Id1Unique,Ent::Id1);
    att[1].insert(RelationExactOneNotNullUniqueSql<Ent>::Id2Unique,Ent::Id2);
    return att;
}

// DateTimeRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type DateTimeRelationEntity.
 */
template<class Ent> class DateTimeRelationInfoBdd : public InfoBddBase<RelationInfoBdd<Ent>,DateTimeInfoBdd<Ent>>
{
public:
    typedef DateTimeRelationUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> DateTimeRelationInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(RelationInfoBdd<Ent>::attributUnique());
    att[0].insert(DateTimeRelationUniqueSql<Ent>::DateTimeUnique,Ent::DateTime);
    return att;
}

// NumRelationEntity
/*! \ingroup groupeInfoBdd
 * \brief Classe mère des InfoBdd pour les entités de type NumRelationEntity.
 */
template<class Ent> class RelationNumInfoBdd : public InfoBddBase<RelationInfoBdd<Ent>,NumInfoBdd<Ent>>
{
public:
    typedef NumRelationUniqueSql<Ent> EntUniqueSql;
    FONC_UNIQUE_LINK
};

template<class Ent> QVector<QMap<int,int>> RelationNumInfoBdd<Ent>::attributUnique()
{
    QVector<QMap<int,int>> att(RelationInfoBdd<Ent>::attributUnique());
    att[0].insert(NumRelationUniqueSql<Ent>::NumUnique,Ent::Num);
    return att;
}

#endif // INFOBDDBASE_H
