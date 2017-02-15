/*Auteur: PERCIE DU SERT Maxime
 *Date: 18/08/2016
 */
#ifndef LINKSQLBASE_H
#define LINKSQLBASE_H

#include "AbstractLinkSql.h"
#include "../Entities/Arbre.h"
#include "../Entities/Entity.h"
#include "../Entities/EntityCible.h"
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityNom.h"
#include "../Entities/EntityRelation.h"

//! \ingroup groupeLinkSqlBase
//! Macro définisant les classes de liens pour les entités de type ValIdNum.
#define VAL_ID_NUM_LINK(NOM,TYPE) \
/*! \ingroup groupeLinkSqlBase \brief Classe mère des liens entre les entités numérotées, identifié et valué.*/ \
    class Valeur##NOM##IdNumLinkSql : public IdNumLinkSql \
    {protected: \
        ATTRIBUT_LINK(Valeur##NOM##IdNumEntity,Valeur,valeur,TYPE) \
    public: \
        MEMBRE_LINK_ATT_1(IdNumLinkSql,Valeur##NOM##IdNumLinkSql,Valeur##NOM##IdNumEntity,Id1,id1)};

// Link Cible

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités cible.
 */
class CibleLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(CibleEntity,Id1,id1,int)
    ATTRIBUT_LINK(CibleEntity,IdCible,idCible,int)
    ATTRIBUT_LINK(CibleEntity,Cible,cible,int)
public:
    using AbstractLinkSql::AbstractLinkSql;
    MEMBRE_LINK_ATT_3(AbstractLinkSql,CibleLinkSql,CibleEntity,Id1,id1,IdCible,idCible,Cible,cible)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités cible daté.
 */
class DateTimeCibleLinkSql : public CibleLinkSql
{
protected:
    ATTRIBUT_LINK(DateTimeCibleEntity,DateTime,dateTime,QDateTime)
public:
    using CibleLinkSql::CibleLinkSql;
    MEMBRE_LINK_ATT_1(CibleLinkSql,DateTimeCibleLinkSql,DateTimeCibleEntity,DateTime,dateTime)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités cible daté et numéroté.
 */
class NumDateTimeCibleLinkSql : public DateTimeCibleLinkSql
{
protected:
    ATTRIBUT_LINK(NumDateTimeCibleEntity,Num,num,int)
public:
    using DateTimeCibleLinkSql::DateTimeCibleLinkSql;
    MEMBRE_LINK_ATT_1(DateTimeCibleLinkSql,NumDateTimeCibleLinkSql,NumDateTimeCibleEntity,Num,num)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités cible daté et numéroté.
 */
class ValeurNumDateTimeCibleLinkSql : public NumDateTimeCibleLinkSql
{
protected:
    ATTRIBUT_LINK(ValeurNumDateTimeCibleEntity,Valeur,valeur,QVariant)
public:
    using NumDateTimeCibleLinkSql::NumDateTimeCibleLinkSql;
    MEMBRE_LINK_ATT_1(NumDateTimeCibleLinkSql,ValeurNumDateTimeCibleLinkSql,ValeurNumDateTimeCibleEntity,Valeur,valeur)
};

// Link Nom

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités nommées.
 */
class NomLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(NomEntity,Nom,nom,QString)
public:
    using AbstractLinkSql::AbstractLinkSql;
    MEMBRE_LINK_ATT_1(AbstractLinkSql,NomLinkSql,NomEntity,Nom,nom)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités ayant un attribut nc et nom.
 */
class NcNomLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(NcNomEntity,Nc,nc,QString)
public:
    using NomLinkSql::NomLinkSql;
    MEMBRE_LINK_ATT_1(NomLinkSql,NcNomLinkSql,NcNomEntity,Nc,nc)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités ayant un attribut nom et type.
 */
class TypeNomLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(TypeNomEntity,Type,type,int)
public:
    using NomLinkSql::NomLinkSql;
    MEMBRE_LINK_ATT_1(NomLinkSql,TypeNomLinkSql,TypeNomEntity,Type,type)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités ayant un attribut nom et type.
 */
class TypeNcNomLinkSql : public TypeNomLinkSql
{
protected:
    ATTRIBUT_LINK(TypeNcNomEntity,Nc,nc,QString)
public:
    using TypeNomLinkSql::TypeNomLinkSql;
    MEMBRE_LINK_ATT_1(TypeNomLinkSql,TypeNcNomLinkSql,TypeNcNomEntity,Nc,nc)
};

//      Link Relation

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés.
 */
class RelationLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(RelationEntity,Id1,id1,int)
    ATTRIBUT_LINK(RelationEntity,Id2,id2,int)
public:
    using AbstractLinkSql::AbstractLinkSql;
    MEMBRE_LINK_ATT_2(AbstractLinkSql,RelationLinkSql,RelationEntity,Id1,id1,Id2,id2)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés pouvant être nulle.
 */
class RelationExactOneNotNullLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK_NULL_TO_ZERO(RelationExactOneNotNullEntity,Id1,id1,int)
    ATTRIBUT_LINK_NULL_TO_ZERO(RelationExactOneNotNullEntity,Id2,id2,int)
public:
    using AbstractLinkSql::AbstractLinkSql;
    MEMBRE_LINK_ATT_2(AbstractLinkSql,RelationExactOneNotNullLinkSql,RelationExactOneNotNullEntity,Id1,id1,Id2,id2)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut date.
 */
class DateTimeRelationLinkSql : public RelationLinkSql
{
protected:
    ATTRIBUT_LINK(DateTimeRelationEntity,DateTime,dateTime,QDateTime)
public:
    using RelationLinkSql::RelationLinkSql;
    MEMBRE_LINK_ATT_1(RelationLinkSql,DateTimeRelationLinkSql,DateTimeRelationEntity,DateTime,dateTime)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés, un attribut date et un attribut valeur.
 */
class ValeurDateTimeRelationLinkSql : public DateTimeRelationLinkSql
{
protected:
    ATTRIBUT_QVARIANT_LINK(ValeurDateTimeRelationEntity,Valeur,valeur)
public:
    using DateTimeRelationLinkSql::DateTimeRelationLinkSql;
    MEMBRE_LINK_ATT_1(DateTimeRelationLinkSql,ValeurDateTimeRelationLinkSql,ValeurDateTimeRelationEntity,Valeur,valeur)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut num.
 */
class NumRelationLinkSql : public RelationLinkSql
{
protected:
    ATTRIBUT_LINK(NumRelationEntity,Num,num,int)
public:
    using RelationLinkSql::RelationLinkSql;
    MEMBRE_LINK_ATT_1(RelationLinkSql,NumRelationLinkSql,NumRelationEntity,Num,num)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et les attributs num et datetime.
 */
class DateTimeNumRelationLinkSql : public NumRelationLinkSql
{
protected:
    ATTRIBUT_LINK(DateTimeNumRelationEntity,DateTime,dateTime,QDateTime)
public:
    using NumRelationLinkSql::NumRelationLinkSql;
    MEMBRE_LINK_ATT_1(NumRelationLinkSql,DateTimeNumRelationLinkSql,DateTimeNumRelationEntity,DateTime,dateTime)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et les attributs num, datetime et valeur entière.
 */
class ValeurIntDateTimeNumRelationLinkSql : public DateTimeNumRelationLinkSql
    {
    protected:
        ATTRIBUT_LINK(ValeurIntDateTimeNumRelationEntity,Valeur,valeur,int)
    public:
        using DateTimeNumRelationLinkSql::DateTimeNumRelationLinkSql;
        MEMBRE_LINK_ATT_1(DateTimeNumRelationLinkSql,ValeurIntDateTimeNumRelationLinkSql,ValeurIntDateTimeNumRelationEntity,Valeur,valeur)
    };

//      Link Divers

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités numérotées.
 */
class NumLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(NumEntity,Num,num,int)
public:
    using AbstractLinkSql::AbstractLinkSql;
    MEMBRE_LINK_ATT_1(AbstractLinkSql,NumLinkSql,NumEntity,Num,num)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités numérotées et datées.
 */
class DateTimeNumLinkSql : public NumLinkSql
{
protected:
    ATTRIBUT_LINK(DateTimeNumEntity,DateTime,dateTime,QDateTime)
public:
    using NumLinkSql::NumLinkSql;
    MEMBRE_LINK_ATT_1(NumLinkSql,DateTimeNumLinkSql,DateTimeNumEntity,DateTime,dateTime)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités numérotées et identifié.
 */
class IdNumLinkSql : public NumLinkSql
{
protected:
    ATTRIBUT_LINK(IdNumEntity,Id1,id1,int)
public:
    using NumLinkSql::NumLinkSql;
    MEMBRE_LINK_ATT_1(NumLinkSql,IdNumLinkSql,IdNumEntity,Id1,id1)
};

VAL_ID_NUM_LINK(Int,int)
VAL_ID_NUM_LINK(Double,double)
VAL_ID_NUM_LINK(,QVariant)

//     Link Arbre

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des lien entre les entités de type arbre et leurs représentations en base de donnée.
 */
class ArbreLinkSql : public NumLinkSql
{
protected:
    ATTRIBUT_LINK(Arbre,Feuille,feuille,bool)
    ATTRIBUT_LINK_NULL_TO_ZERO(Arbre,Parent,parent,int)
public:
    using NumLinkSql::NumLinkSql;
    MEMBRE_LINK_ATT_2(NumLinkSql,ArbreLinkSql,Arbre,Feuille,feuille,Parent,parent)
};

/*! \ingroup groupeLinkSqlBase
* \brief Classe mère des liens entre les entités ayant un attribut texte.
*/
class TexteLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(TexteEntity,Texte,texte,QString)
public:
    using AbstractLinkSql::AbstractLinkSql;
    MEMBRE_LINK_ATT_1(AbstractLinkSql,TexteLinkSql,TexteEntity,Texte,texte)
};

//      OnlyLinkSql

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens de type arbre.
 */
class ArbreOnlyLinkSql : public ArbreLinkSql
{
public:
    //! \brief Construteur.
    ArbreOnlyLinkSql(const QString & table, const QMap<int,QString> & att)
        : ArbreLinkSql (table,att)
        {}

    //! \brief Destructeur.
    ~ArbreOnlyLinkSql()
        {}

    //! \brief Crée dynamiquement une nouvelle entité de type Ent, l'hydrate à partir de la requète SQL. Puis retourne un  pointeur vers cette nouvelle entité.
    Arbre * newFromRequete() const
        {return new Arbre(feuille(),num(),parent(),id());}
};

ONLY_LINK(CibleLinkSql,CibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),id());}};
ONLY_LINK(DateTimeCibleLinkSql,DateTimeCibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),dateTime(),id());}};
ONLY_LINK(NumDateTimeCibleLinkSql,NumDateTimeCibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),dateTime(),num(),id());}};
ONLY_LINK(ValeurNumDateTimeCibleLinkSql,ValeurNumDateTimeCibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),dateTime(),num(),valeur(),id());}};

ONLY_LINK_DATE_CURRENT(DateTimeCibleLinkSql,DateTimeCurrentCibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),dateTime(),id());}};
ONLY_LINK_DATE_CURRENT(NumDateTimeCibleLinkSql,NumDateTimeCurrentCibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),dateTime(),num(),id());}};
ONLY_LINK_DATE_CURRENT(ValeurNumDateTimeCibleLinkSql,ValeurNumDateTimeCurrentCibleOnlyLinkSql) {return new Ent(id1(),idCible(),cible(),dateTime(),num(),valeur(),id());}};

ONLY_LINK(NomLinkSql,NomOnlyLinkSql) {return new Ent(nom(),id());}};
ONLY_LINK(NcNomLinkSql,NcNomOnlyLinkSql) {return new Ent(nc(),nom(),id());}};
ONLY_LINK(TypeNomLinkSql,TypeNomOnlyLinkSql) {return new Ent(nom(),type(),id());}};
ONLY_LINK(TypeNcNomLinkSql,TypeNcNomOnlyLinkSql) {return new Ent(nc(),nom(),type(),id());}};

ONLY_LINK(RelationLinkSql,RelationOnlyLinkSql) {return new Ent(id1(),id2(),id());}};
ONLY_LINK(RelationExactOneNotNullLinkSql,RelationExactOneNotNullOnlyLinkSql) {return new Ent(id1(),id2(),id());}};
ONLY_LINK(DateTimeRelationLinkSql,DateTimeRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),id());}};
ONLY_LINK(ValeurDateTimeRelationLinkSql,ValeurDateTimeRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),valeur(),id());}};

ONLY_LINK_DATE_CURRENT(DateTimeRelationLinkSql,DateTimeCurrentRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),id());}};
ONLY_LINK_DATE_CURRENT(ValeurDateTimeRelationLinkSql,ValeurDateTimeCurrentRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),valeur(),id());}};

ONLY_LINK(NumRelationLinkSql,NumRelationOnlyLinkSql) {return new Ent(id1(),id2(),num(),id());}};
ONLY_LINK(DateTimeNumRelationLinkSql,DateTimeNumRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),num(),id());}};
ONLY_LINK(ValeurIntDateTimeNumRelationLinkSql,ValeurIntDateTimeNumRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),num(),valeur(),id());}};

ONLY_LINK_DATE_CURRENT(DateTimeNumRelationLinkSql,DateTimeCurrentNumRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),num(),id());}};
ONLY_LINK_DATE_CURRENT(ValeurIntDateTimeNumRelationLinkSql,ValeurIntDateTimeCurrentNumRelationOnlyLinkSql) {return new Ent(id1(),id2(),dateTime(),num(),valeur(),id());}};

ONLY_LINK(NumLinkSql,NumOnlyLinkSql) {return new Ent(num(),id());}};
ONLY_LINK(IdNumLinkSql,IdNumOnlyLinkSql) {return new Ent(id1(),num(),id());}};
ONLY_LINK(ValeurIntIdNumLinkSql,ValeurIntIdNumOnlyLinkSql) {return new Ent(id1(),num(),valeur(),id());}};
ONLY_LINK(ValeurDoubleIdNumLinkSql,ValeurDoubleIdNumOnlyLinkSql) {return new Ent(id1(),num(),valeur(),id());}};
ONLY_LINK(ValeurIdNumLinkSql,ValeurIdNumOnlyLinkSql) {return new Ent(id1(),num(),valeur(),id());}};
ONLY_LINK(DateTimeNumLinkSql,DateTimeNumOnlyLinkSql) {return new Ent(dateTime(),num(),id());}};
ONLY_LINK(TexteLinkSql,TexteOnlyLinkSql) {return new Ent(texte(),id());}};

ONLY_LINK_DATE_CURRENT(DateTimeNumLinkSql,DateTimeCurrentNumOnlyLinkSql) {return new Ent(dateTime(),num(),id());}};
#endif // LINKSQLBASE_H
