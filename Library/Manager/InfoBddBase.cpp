#include "InfoBddBase.h"

QVector<QMap<int,int>> NoUniqueInfoBdd::attributUnique()
    {return QVector<QMap<int,int>>();}

QMap<int,QString> NoKeyInfoBdd::foreignKey()
    {return QMap<int,QString>();}

// Arbre
QMap<int,QString> ArbreInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(Arbre::Num,"nm");
    att.insert(Arbre::Feuille,"fl");
    att.insert(Arbre::Parent,"pt");
    return att;
}

QVector<QMap<int,int>> ArbreInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(ArbreUniqueSql::NumUnique,Arbre::Num);
    att[0].insert(ArbreUniqueSql::ParentUnique,Arbre::Parent);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ArbreInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(Arbre::Num,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(Arbre::Feuille,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(Arbre::Parent,QPair<bdd::createSql,bool>(createSql::integer,false));
    return att;
}

//CibleEntity
QMap<int,QString> CibleInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(CibleEntity::Id1,"ID1");
    att.insert(CibleEntity::IdCible,"IDcb");
    att.insert(CibleEntity::Cible,"cb");
    return att;
}

QVector<QMap<int,int>> CibleInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(CibleUniqueSql::Id1Unique,CibleEntity::Id1);
    att[0].insert(CibleUniqueSql::IdCibleUnique,CibleEntity::IdCible);
    att[0].insert(CibleUniqueSql::CibleUnique,CibleEntity::Cible);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> CibleInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(CibleEntity::Id1,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(CibleEntity::IdCible,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(CibleEntity::Cible,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

//DateTimeCible
QMap<int,QString> DateTimeCibleInfoBdd::attribut()
{
    QMap<int,QString> att(CibleInfoBdd::attribut());
    att.insert(DateTimeCibleEntity::DateTime,"dt");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeCibleInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(CibleInfoBdd::creerAttribut());
    att.insert(DateTimeCibleEntity::DateTime,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// DateTimeNum
QMap<int,QString> DateTimeNumInfoBdd::attribut()
{
    QMap<int,QString> att(NumInfoBdd::attribut());
    att.insert(DateTimeNumEntity::DateTime,"dt");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NumInfoBdd::creerAttribut());
    att.insert(DateTimeNumEntity::DateTime,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// DateTimeNumRelation
QMap<int,QString> DateTimeNumRelationInfoBdd::attribut()
{
    QMap<int,QString> att(NumRelationInfoBdd::attribut());
    att.insert(DateTimeNumRelationEntity::DateTime,"dt");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeNumRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NumRelationInfoBdd::creerAttribut());
    att.insert(DateTimeNumRelationEntity::DateTime,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// DateTimeRelation
QMap<int,QString> DateTimeRelationInfoBdd::attribut()
{
    QMap<int,QString> att(RelationInfoBdd::attribut());
    att.insert(DateTimeRelationEntity::DateTime,"dt");
    return att;
}

QVector<QMap<int,int>> DateTimeRelationInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(RelationInfoBdd::attributUnique());
    att[0].insert(DateTimeRelationUniqueSql::DateTimeUnique,DateTimeRelationEntity::DateTime);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(RelationInfoBdd::creerAttribut());
    att.insert(DateTimeRelationEntity::DateTime,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// IdNum
QMap<int,QString> IdNumInfoBdd::attribut()
{
    QMap<int,QString> att(NumInfoBdd::attribut());
    att.insert(IdNumEntity::Id1,"Id1");
    return att;
}

QVector<QMap<int,int>> IdNumInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(NumInfoBdd::attributUnique());
    att[0].insert(IdNumUniqueSql::Id1Unique,IdNumEntity::Id1);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> IdNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NumInfoBdd::creerAttribut());
    att.insert(IdNumEntity::Id1,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// NcNom
QMap<int,QString> NcNomInfoBdd::attribut()
{
    QMap<int,QString> att(NomInfoBdd::attribut());
    att.insert(NcNomEntity::Nc,"nc");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NcNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NomInfoBdd::creerAttribut());
    att.insert(NcNomEntity::Nc,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

QVector<QMap<int,int>> NcNomInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(NomInfoBdd::attributUnique());
    att[0].insert(NcNomUniqueSql::NcUnique,NcNomEntity::Nc);
    return att;
}

// Nom
QMap<int,QString> NomInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(NomEntity::Nom,"nm");
    return att;
}

QVector<QMap<int,int>> NomInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(NomUniqueSql::NomUnique,NomEntity::Nom);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(NomEntity::Nom,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// Num
QMap<int,QString> NumInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(NumEntity::Num,"nm");
    return att;
}

QVector<QMap<int,int>> NumInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(NumUniqueSql::NumUnique,NumEntity::Num);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(NumEntity::Num,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// NumDateTimeCible
QMap<int,QString> NumDateTimeCibleInfoBdd::attribut()
{
    QMap<int,QString> att(DateTimeCibleInfoBdd::attribut());
    att.insert(NumDateTimeCibleEntity::Num,"nm");
    return att;
}

QVector<QMap<int,int>> NumDateTimeCibleInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(CibleInfoBdd::attributUnique());
    att[0].insert(NumDateTimeCibleUniqueSql::NumUnique,NumDateTimeCibleEntity::Num);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NumDateTimeCibleInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(DateTimeCibleInfoBdd::creerAttribut());
    att.insert(NumDateTimeCibleEntity::Num,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// NumRelation
QMap<int,QString> NumRelationInfoBdd::attribut()
{
    QMap<int,QString> att(RelationInfoBdd::attribut());
    att.insert(NumRelationEntity::Num,"nm");
    return att;
}

QVector<QMap<int,int>> NumRelationInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(RelationInfoBdd::attributUnique());
    att[0].insert(NumRelationUniqueSql::NumUnique,NumRelationEntity::Num);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NumRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(RelationInfoBdd::creerAttribut());
    att.insert(NumRelationEntity::Num,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// RelationEntity
QMap<int,QString> RelationInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(RelationEntity::Id1,"ID1");
    att.insert(RelationEntity::Id2,"ID2");
    return att;
}

QVector<QMap<int,int>> RelationInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(RelationUniqueSql::Id1Unique,RelationEntity::Id1);
    att[0].insert(RelationUniqueSql::Id2Unique,RelationEntity::Id2);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> RelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(RelationEntity::Id1,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(RelationEntity::Id2,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// RelationExactOneNotNull
QMap<int,QString> RelationExactOneNotNullInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(RelationExactOneNotNullEntity::Id1,"ID1");
    att.insert(RelationExactOneNotNullEntity::Id2,"ID2");
    return att;
}

QVector<QMap<int,int>> RelationExactOneNotNullInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(2);
    att[0].insert(RelationExactOneNotNullUniqueSql::Id1Unique,RelationExactOneNotNullEntity::Id1);
    att[1].insert(RelationExactOneNotNullUniqueSql::Id2Unique,RelationExactOneNotNullEntity::Id2);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> RelationExactOneNotNullInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(RelationExactOneNotNullEntity::Id1,QPair<bdd::createSql,bool>(createSql::integer,false));
    att.insert(RelationExactOneNotNullEntity::Id2,QPair<bdd::createSql,bool>(createSql::integer,false));
    return att;
}

// Texte
QMap<int,QString> TexteInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(TexteEntity::Texte,"txt");
    return att;
}

QVector<QMap<int,int>> TexteInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(TexteUniqueSql::TexteUnique,TexteEntity::Texte);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TexteInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(TexteEntity::Texte,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// TypeNcNom
QMap<int,QString> TypeNcNomInfoBdd::attribut()
{
    QMap<int,QString> att(TypeNomInfoBdd::attribut());
    att.insert(TypeNcNomEntity::Nc,"nc");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TypeNcNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(TypeNomInfoBdd::creerAttribut());
    att.insert(TypeNcNomEntity::Nc,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// TypeNom
QMap<int,QString> TypeNomInfoBdd::attribut()
{
    QMap<int,QString> att(NomInfoBdd::attribut());
    att.insert(TypeNomEntity::Type,"tp");
    return att;
}

QVector<QMap<int,int>> TypeNomInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(NomInfoBdd::attributUnique());
    att[0].insert(TypeNomUniqueSql::TypeUnique,TypeNomEntity::Type);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TypeNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NomInfoBdd::creerAttribut());
    att.insert(TypeNomEntity::Type,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// ValeurDateTimeRelation
QMap<int,QString> ValeurDateTimeRelationInfoBdd::attribut()
{
    QMap<int,QString> att(DateTimeRelationInfoBdd::attribut());
    att.insert(ValeurDateTimeRelationEntity::Valeur,"vl");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ValeurDateTimeRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(DateTimeRelationInfoBdd::creerAttribut());
    att.insert(ValeurDateTimeRelationEntity::Valeur,QPair<bdd::createSql,bool>(createSql::blob,false));
    return att;
}

// ValeurIdNumEntity
QMap<int,QString> ValeurIdNumInfoBdd::attribut()
{
    QMap<int,QString> att(IdNumInfoBdd::attribut());
    att.insert(ValeurIdNumEntity::Valeur,"vl");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ValeurIdNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(IdNumInfoBdd::creerAttribut());
    att.insert(ValeurIdNumEntity::Valeur,QPair<bdd::createSql,bool>(createSql::blob,false));
    return att;
}

//ValeurIdNumEntity
QMap<int, QPair<bdd::createSql,bool>> ValeurDoubleIdNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(IdNumInfoBdd::creerAttribut());
    att.insert(ValeurIdNumEntity::Valeur,QPair<bdd::createSql,bool>(createSql::real,false));
    return att;
}

//ValeurIntIdNumEntity
QMap<int, QPair<bdd::createSql,bool>> ValeurIntIdNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(IdNumInfoBdd::creerAttribut());
    att.insert(ValeurIdNumEntity::Valeur,QPair<bdd::createSql,bool>(createSql::integer,false));
    return att;
}

// ValeurIntDateTimeNumRelation
QMap<int,QString> ValeurIntDateTimeNumRelationInfoBdd::attribut()
{
    QMap<int,QString> att(DateTimeNumRelationInfoBdd::attribut());
    att.insert(ValeurIntDateTimeNumRelationEntity::Valeur,"vl");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ValeurIntDateTimeNumRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(DateTimeNumRelationInfoBdd::creerAttribut());
    att.insert(ValeurIntDateTimeNumRelationEntity::Valeur,QPair<bdd::createSql,bool>(createSql::integer,false));
    return att;
}

// ValeurNumDateTimeCibleEntity
QMap<int,QString> ValeurNumDateTimeCibleInfoBdd::attribut()
{
    QMap<int,QString> att(NumDateTimeCibleInfoBdd::attribut());
    att.insert(ValeurNumDateTimeCibleEntity::Valeur,"vl");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ValeurNumDateTimeCibleInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NumDateTimeCibleInfoBdd::creerAttribut());
    att.insert(ValeurNumDateTimeCibleEntity::Valeur,QPair<bdd::createSql,bool>(createSql::blob,false));
    return att;
}
