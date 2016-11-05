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
    att[0].insert(ArbreUniqueSql::numUnique,Arbre::Num);
    att[0].insert(ArbreUniqueSql::parentUnique,Arbre::Parent);
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

// DateTimeNum
QMap<int,QString> DateTimeNumInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(DateTimeNumEntity::Num,"nm");
    att.insert(DateTimeNumEntity::DateTime,"dt");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(DateTimeNumEntity::Num,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(DateTimeNumEntity::DateTime,QPair<bdd::createSql,bool>(createSql::text,true));
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
    att[0].insert(DateTimeRelationUniqueSql::dateUnique,DateTimeRelationEntity::DateTime);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(RelationInfoBdd::creerAttribut());
    att.insert(DateTimeRelationEntity::DateTime,QPair<bdd::createSql,bool>(createSql::text,true));
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
    att[0].insert(NcNomUniqueSql::ncUnique,NcNomEntity::Nc);
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
    att[0].insert(NomUniqueSql::nomUnique,NomEntity::Nom);
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
    att[0].insert(NumUniqueSql::numUnique,NumEntity::Num);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(NumEntity::Num,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// NumRelation
QMap<int,QString> NumRelationInfoBdd::attribut()
{
    QMap<int,QString> att(RelationInfoBdd::attribut());
    att.insert(NumRelationEntity::Num,"nm");
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
    att.insert(RelationEntity::Id1,"id1");
    att.insert(RelationEntity::Id2,"id2");
    return att;
}

QVector<QMap<int,int>> RelationInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(RelationUniqueSql::id1Unique,RelationEntity::Id1);
    att[0].insert(RelationUniqueSql::id2Unique,RelationEntity::Id2);
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
    att.insert(RelationExactOneNotNullEntity::Id1,"id1");
    att.insert(RelationExactOneNotNullEntity::Id2,"id2");
    return att;
}

QVector<QMap<int,int>> RelationExactOneNotNullInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(2);
    att[0].insert(RelationExactOneNotNullUniqueSql::id1Unique,RelationExactOneNotNullEntity::Id1);
    att[1].insert(RelationExactOneNotNullUniqueSql::id2Unique,RelationExactOneNotNullEntity::Id2);
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
    att[0].insert(TexteUniqueSql::texteUnique,TexteEntity::Texte);
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
    att[0].insert(TypeNomUniqueSql::typeUnique,TypeNomEntity::Type);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TypeNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NomInfoBdd::creerAttribut());
    att.insert(TypeNomEntity::Type,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

//ValeurDateTimeRelation
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
/*
QMap<int,QString> InfoBddBase::attribut(InfoEntity::entityBaseId n)
{
    QMap<int,QString> att;
    switch (n)
    {
    case InfoEntity::entityBaseId::entityId:
        break;

    case InfoEntity::entityBaseId::ArbreId:
        att.insert(Arbre::Num,"nm");
        att.insert(Arbre::Feuille,"fl");
        att.insert(Arbre::niveauPos,"nv");
        att.insert(Arbre::Parent,"pt");
        break;

    case InfoEntity::entityBaseId::DateTimeRelationEntityId:
        att.insert(DateTimeRelationEntity::Id1,"id1");
        att.insert(DateTimeRelationEntity::Id2,"id2");
        att.insert(DateTimeRelationEntity::DateTime,"dt");
        break;

    case InfoEntity::entityBaseId::DateTimeNumEntityId:
        att.insert(DateTimeNumEntity::Num,"nm");
        att.insert(DateTimeNumEntity::dateTimePos,"dtt");
        break;

    case InfoEntity::entityBaseId::NcNomEntityId:
        att.insert(NcNomEntity::Nom,"nm");
        att.insert(NcNomEntity::Nc,"nc");
        break;

    case InfoEntity::entityBaseId::NomEntityId:
        att.insert(NomEntity::Nom,"nm");
        break;

    case InfoEntity::entityBaseId::NumEntityId:
        att.insert(NumEntity::Num,"nm");
        break;

    case InfoEntity::entityBaseId::NumRelationEntityId:
        att.insert(NumRelationEntity::Id1,"id1");
        att.insert(NumRelationEntity::Id2,"id2");
        att.insert(NumRelationEntity::Num,"nm");
        break;

    case InfoEntity::entityBaseId::RelationEntityId:
        att.insert(RelationEntity::Id1,"id1");
        att.insert(RelationEntity::Id2,"id2");
        break;

    case InfoEntity::entityBaseId::RelationExactOneNotNullEntityId:
        att.insert(RelationExactOneNotNullEntity::Id1,"id1");
        att.insert(RelationExactOneNotNullEntity::Id2,"id2");
        break;

    case InfoEntity::entityBaseId::TexteEntityId:
        att.insert(TexteEntity::Texte,"txt");
        break;

    case InfoEntity::entityBaseId::TypeNcNomEntityId:
        att.insert(TypeNcNomEntity::Nom,"nm");
        att.insert(TypeNcNomEntity::Nc,"nc");
        att.insert(TypeNcNomEntity::Type,"tp");
        break;

    case InfoEntity::entityBaseId::TypeNomEntityId:
        att.insert(TypeNomEntity::Nom,"nm");
        att.insert(TypeNomEntity::Type,"tp");
        break;

    case InfoEntity::entityBaseId::ValeurDateTimeRelationEntityId:
        att.insert(ValeurDateTimeRelationEntity::Id1,"id1");
        att.insert(ValeurDateTimeRelationEntity::Id2,"id2");
        att.insert(ValeurDateTimeRelationEntity::DateTime,"dt");
        att.insert(ValeurDateTimeRelationEntity::Valeur,"vl");
        break;

    default:
        throw std::invalid_argument(QString("Attribut sql par defaut non définit pour l'entité d'identifiant :")
                                    .append(QString::number(n)).toStdString());
    }
    return att;
}

QMap<int,int> InfoBddBase::attributUnique(InfoEntity::entityBaseId n)
{
    QMap<int,int> att;
    switch (n) {
    case InfoEntity::entityBaseId::entityId:
        break;

    case InfoEntity::entityBaseId::ArbreId:
        att.insert(ArbreUniqueSql::numUnique,Arbre::Num);
        att.insert(ArbreUniqueSql::parentUnique,Arbre::Parent);
        break;

    case InfoEntity::entityBaseId::DateTimeRelationEntityId:
        att.insert(DateRelationUniqueSql::id1Unique,DateTimeRelationEntity::Id1);
        att.insert(DateRelationUniqueSql::id2Unique,DateTimeRelationEntity::Id2);
        att.insert(DateRelationUniqueSql::dateUnique,DateTimeRelationEntity::DateTime);
        break;

    case InfoEntity::entityBaseId::NomEntityId:
        att.insert(NomUniqueSql::nomUnique,NomEntity::Nom);
        break;

    case InfoEntity::entityBaseId::NumEntityId:
        att.insert(NumUniqueSql::numUnique,NumEntity::Num);
        break;

    case InfoEntity::entityBaseId::RelationEntityId:
        att.insert(RelationUniqueSql::id1Unique,RelationEntity::Id1);
        att.insert(RelationUniqueSql::id2Unique,RelationEntity::Id2);
        break;

    case InfoEntity::entityBaseId::RelationExactOneNotNullEntityId:
        att.insert(RelationExactOneNotNullUniqueSql::id1Unique,RelationExactOneNotNullEntity::Id1);
        att.insert(RelationExactOneNotNullUniqueSql::id2Unique,RelationExactOneNotNullEntity::Id2);
        break;

    case InfoEntity::entityBaseId::TexteEntityId:
        att.insert(TexteUniqueSql::texteUnique,TexteEntity::Texte);
        break;

    case InfoEntity::entityBaseId::TypeNomEntityId:
        att.insert(TypeNomUniqueSql::nomUnique,TypeNomEntity::Nom);
        att.insert(TypeNomUniqueSql::typeUnique,TypeNomEntity::Type);
        break;  

    default:
        throw std::invalid_argument(QString("Attribut unique sql par defaut non définit pour l'entité d'identifiant :")
                                    .append(QString::number(n)).toStdString());
    }
    return att;
}

QMap<int,QPair<bdd::createSql,bool>> InfoBddBase::creerAttribut(InfoEntity::entityBaseId n)
{
    using namespace bdd;
    QMap<int,QPair<int,bool>> att;
    switch (n)
    {
    case InfoEntity::entityBaseId::entityId:
        break;

    case InfoEntity::entityBaseId::ArbreId:
        att.insert(Arbre::Num,QPair<int,bool>(createSql::integer,true));
        att.insert(Arbre::Feuille,QPair<int,bool>(createSql::integer,true));
        att.insert(Arbre::niveauPos,QPair<int,bool>(createSql::integer,true));
        att.insert(Arbre::Parent,QPair<int,bool>(createSql::integer,false));
        break;

    case InfoEntity::entityBaseId::DateTimeRelationEntityId:
        att.insert(DateTimeRelationEntity::Id1,QPair<int,bool>(createSql::integer,true));
        att.insert(DateTimeRelationEntity::Id2,QPair<int,bool>(createSql::integer,true));
        att.insert(DateTimeRelationEntity::DateTime,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::DateTimeNumEntityId:
        att.insert(DateTimeNumEntity::Num,QPair<int,bool>(createSql::integer,true));
        att.insert(DateTimeNumEntity::dateTimePos,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::NcNomEntityId:
        att.insert(NcNomEntity::Nom,QPair<int,bool>(createSql::text,true));
        att.insert(NcNomEntity::Nc,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::NomEntityId:
        att.insert(NomEntity::Nom,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::NumEntityId:
        att.insert(NumEntity::Num,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::NumRelationEntityId:
        att.insert(NumRelationEntity::Id1,QPair<int,bool>(createSql::integer,true));
        att.insert(NumRelationEntity::Id2,QPair<int,bool>(createSql::integer,true));
        att.insert(NumRelationEntity::Num,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::RelationEntityId:
        att.insert(RelationEntity::Id1,QPair<int,bool>(createSql::integer,true));
        att.insert(RelationEntity::Id2,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::RelationExactOneNotNullEntityId:
        att.insert(RelationExactOneNotNullEntity::Id1,QPair<int,bool>(createSql::integer,false));
        att.insert(RelationExactOneNotNullEntity::Id2,QPair<int,bool>(createSql::integer,false));
        break;

    case InfoEntity::entityBaseId::TexteEntityId:
        att.insert(TexteEntity::Texte,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::TypeNcNomEntityId:
        att.insert(TypeNcNomEntity::Nom,QPair<int,bool>(createSql::text,true));
        att.insert(TypeNcNomEntity::Nc,QPair<int,bool>(createSql::text,true));
        att.insert(TypeNcNomEntity::Type,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::TypeNomEntityId:
        att.insert(TypeNomEntity::Nom,QPair<int,bool>(createSql::text,true));
        att.insert(TypeNomEntity::Type,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::ValeurDateTimeRelationEntityId:
        att.insert(ValeurDateTimeRelationEntity::Id1,QPair<int,bool>(createSql::integer,true));
        att.insert(ValeurDateTimeRelationEntity::Id2,QPair<int,bool>(createSql::integer,true));
        att.insert(ValeurDateTimeRelationEntity::DateTime,QPair<int,bool>(createSql::text,true));
        att.insert(ValeurDateTimeRelationEntity::Valeur,QPair<int,bool>(createSql::blob,false));
        break;

    default:
        throw std::invalid_argument(QString("Caractéristiques sql des attributs defaut non définies pour l'entité d'identifiant :")
                                    .append(QString::number(n)).toStdString());
    }
    return att;
}
*/
