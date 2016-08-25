/*Auteur: PERCIE DU SERT Maxime
 *Date: 18/08/2016
 */
#ifndef LINKSQLBASE_H
#define LINKSQLBASE_H

#include "AbstractLinkSql.h"
#include "InfoBddBase.h"
#include "../Entities/Arbre.h"
#include "../Entities/Entity.h"
#include "../Entities/EntityDivers.h"
#include "../Entities/EntityNom.h"
#include "../Entities/EntityRelation.h"

// Link Nom

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités nommées.
 */
class NomLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(NomEntity,Nom,nom,QString)
public:
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
    MEMBRE_LINK_ATT_2(AbstractLinkSql,RelationExactOneNotNullLinkSql,RelationExactOneNotNullEntity,Id1,id1,Id2,id2)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés et un attribut date.
 */
class DateTimeRelationLinkSql : public RelationLinkSql
{
protected:
    ATTRIBUT_LINK(DateTimeRelationEntity,Date,date,QDateTime)
public:
    MEMBRE_LINK_ATT_1(RelationLinkSql,DateTimeRelationLinkSql,DateTimeRelationEntity,Date,date)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens pour les entités possédant deux clés, un attribut date et un attribut valeur.
 */
class ValeurDateTimeRelationLinkSql : public DateTimeRelationLinkSql
{
protected:
    ATTRIBUT_QVARIANT_LINK(ValeurDateTimeRelationEntity,Valeur,valeur)
public:
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
    MEMBRE_LINK_ATT_1(RelationLinkSql,NumRelationLinkSql,NumRelationEntity,Num,num)
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
    MEMBRE_LINK_ATT_1(AbstractLinkSql,NumLinkSql,NumEntity,Num,num)
};

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des liens entre les entités numérotées et datées.
 */
class DateTimeNumLinkSql : public NumLinkSql
{
protected:
    ATTRIBUT_LINK(DateTimeNumEntity,Date,date,QDateTime)
public:
    MEMBRE_LINK_ATT_1(NumLinkSql,DateTimeNumLinkSql,DateTimeNumEntity,Date,date)
};

//     Link Arbre

/*! \ingroup groupeLinkSqlBase
 * \brief Classe mère des lien entre les entités de type arbre et leurs représentations en base de donnée.
 */
class ArbreLinkSql : public NumLinkSql
{
protected:
    ATTRIBUT_LINK(Arbre,Feuille,feuille,bool)
    ATTRIBUT_LINK(Arbre,Niveau,niveau,int)
    ATTRIBUT_LINK_NULL_TO_ZERO(Arbre,Parent,parent,int)
public:
    MEMBRE_LINK_ATT_3(NumLinkSql,ArbreLinkSql,Arbre,Feuille,feuille,Niveau,niveau,Parent,parent)
};

/*! \ingroup groupeLinkSqlBase
* \brief Classe mère des liens entre les entités ayant un attribut texte.
*/
class TexteLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(TexteEntity,Texte,texte,QString)
public:
    MEMBRE_LINK_ATT_1(AbstractLinkSql,TexteLinkSql,TexteEntity,Texte,texte)
};

//      OnlyLinkSql

ONLY_LINK(ArbreLinkSql,ArbreOnlyLinkSql) {return new Ent(feuille(),niveau(),num(),parent(),id());}};

ONLY_LINK(NomLinkSql,NomOnlyLinkSql) {return new Ent(nom(),id());}};
ONLY_LINK(NcNomLinkSql,NcNomOnlyLinkSql) {return new Ent(nc(),nom(),id());}};
ONLY_LINK(TypeNomLinkSql,TypeNomOnlyLinkSql) {return new Ent(nom(),type(),id());}};
ONLY_LINK(TypeNcNomLinkSql,TypeNcNomOnlyLinkSql) {return new Ent(nc(),nom(),type(),id());}};

ONLY_LINK(RelationLinkSql,RelationOnlyLinkSql) {return new Ent(id1(),id2(),id());}};
ONLY_LINK(RelationExactOneNotNullLinkSql,RelationExactOneNotNullOnlyLinkSql) {return new Ent(id1(),id2(),id());}};
ONLY_LINK(DateTimeRelationLinkSql,DateTimeRelationOnlyLinkSql) {return new Ent(id1(),id2(),date(),id());}};
ONLY_LINK(ValeurDateTimeRelationLinkSql,ValeurDateTimeRelationOnlyLinkSql) {return new Ent(id1(),id2(),date(),valeur(),id());}};
ONLY_LINK(NumRelationLinkSql,NumRelationOnlyLinkSql) {return new Ent(id1(),id2(),num(),id());}};

ONLY_LINK(NumLinkSql,NumOnlyLinkSql) {return new Ent(num(),id());}};
ONLY_LINK(DateTimeNumLinkSql,DateTimeNumOnlyLinkSql) {return new Ent(date(),num(),id());}};
ONLY_LINK(TexteLinkSql,TexteOnlyLinkSql) {return new Ent(texte(),id());}};


#endif // LINKSQLBASE_H
