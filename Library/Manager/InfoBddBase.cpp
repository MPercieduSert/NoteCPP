#include "InfoBddBase.h"

QVector<QMap<int,int>> NoUniqueInfoBdd::attributUnique()
    {return QVector<QMap<int,int>>();}

QMap<int,QString> NoKeyInfoBdd::foreignKey()
    {return QMap<int,QString>();}

// Arbre
QMap<int,QString> ArbreInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(Arbre::numPos,"nm");
    att.insert(Arbre::feuillePos,"fl");
    att.insert(Arbre::niveauPos,"nv");
    att.insert(Arbre::parentPos,"pt");
    return att;
}

QVector<QMap<int,int>> ArbreInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(ArbreUniqueSql::numUnique,Arbre::numPos);
    att[0].insert(ArbreUniqueSql::parentUnique,Arbre::parentPos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ArbreInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(Arbre::numPos,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(Arbre::feuillePos,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(Arbre::niveauPos,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(Arbre::parentPos,QPair<bdd::createSql,bool>(createSql::integer,false));
    return att;
}

// DateTimeNum
QMap<int,QString> DateTimeNumInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(DateTimeNumEntity::numPos,"nm");
    att.insert(DateTimeNumEntity::datePos,"dt");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeNumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(DateTimeNumEntity::numPos,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(DateTimeNumEntity::datePos,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// DateTimeRelation
QMap<int,QString> DateTimeRelationInfoBdd::attribut()
{
    QMap<int,QString> att(RelationInfoBdd::attribut());
    att.insert(DateTimeRelationEntity::datePos,"dt");
    return att;
}

QVector<QMap<int,int>> DateTimeRelationInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(RelationInfoBdd::attributUnique());
    att[0].insert(DateTimeRelationUniqueSql::dateUnique,DateTimeRelationEntity::datePos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> DateTimeRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(RelationInfoBdd::creerAttribut());
    att.insert(DateTimeRelationEntity::datePos,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// NcNom
QMap<int,QString> NcNomInfoBdd::attribut()
{
    QMap<int,QString> att(NomInfoBdd::attribut());
    att.insert(NcNomEntity::ncPos,"nc");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NcNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NomInfoBdd::creerAttribut());
    att.insert(NcNomEntity::ncPos,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

QVector<QMap<int,int>> NcNomInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(NomInfoBdd::attributUnique());
    att[0].insert(NcNomUniqueSql::ncUnique,NcNomEntity::ncPos);
    return att;
}

// Nom
QMap<int,QString> NomInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(NomEntity::nomPos,"nm");
    return att;
}

QVector<QMap<int,int>> NomInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(NomUniqueSql::nomUnique,NomEntity::nomPos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(NomEntity::nomPos,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// Num
QMap<int,QString> NumInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(NumEntity::numPos,"nm");
    return att;
}

QVector<QMap<int,int>> NumInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(NumUniqueSql::numUnique,NumEntity::numPos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NumInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(NumEntity::numPos,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// NumRelation
QMap<int,QString> NumRelationInfoBdd::attribut()
{
    QMap<int,QString> att(RelationInfoBdd::attribut());
    att.insert(NumRelationEntity::numPos,"nm");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> NumRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(RelationInfoBdd::creerAttribut());
    att.insert(NumRelationEntity::numPos,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// RelationEntity
QMap<int,QString> RelationInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(RelationEntity::id1Pos,"id1");
    att.insert(RelationEntity::id2Pos,"id2");
    return att;
}

QVector<QMap<int,int>> RelationInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(RelationUniqueSql::id1Unique,RelationEntity::id1Pos);
    att[0].insert(RelationUniqueSql::id2Unique,RelationEntity::id2Pos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> RelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(RelationEntity::id1Pos,QPair<bdd::createSql,bool>(createSql::integer,true));
    att.insert(RelationEntity::id2Pos,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

// RelationExactOneNotNull
QMap<int,QString> RelationExactOneNotNullInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(RelationExactOneNotNullEntity::id1Pos,"id1");
    att.insert(RelationExactOneNotNullEntity::id2Pos,"id2");
    return att;
}

QVector<QMap<int,int>> RelationExactOneNotNullInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(2);
    att[0].insert(RelationExactOneNotNullUniqueSql::id1Unique,RelationExactOneNotNullEntity::id1Pos);
    att[1].insert(RelationExactOneNotNullUniqueSql::id2Unique,RelationExactOneNotNullEntity::id2Pos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> RelationExactOneNotNullInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(RelationExactOneNotNullEntity::id1Pos,QPair<bdd::createSql,bool>(createSql::integer,false));
    att.insert(RelationExactOneNotNullEntity::id2Pos,QPair<bdd::createSql,bool>(createSql::integer,false));
    return att;
}

// Texte
QMap<int,QString> TexteInfoBdd::attribut()
{
    QMap<int,QString> att;
    att.insert(TexteEntity::textePos,"txt");
    return att;
}

QVector<QMap<int,int>> TexteInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(1);
    att[0].insert(TexteUniqueSql::texteUnique,TexteEntity::textePos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TexteInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att;
    att.insert(TexteEntity::textePos,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// TypeNcNom
QMap<int,QString> TypeNcNomInfoBdd::attribut()
{
    QMap<int,QString> att(TypeNomInfoBdd::attribut());
    att.insert(TypeNcNomEntity::ncPos,"nc");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TypeNcNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(TypeNomInfoBdd::creerAttribut());
    att.insert(TypeNcNomEntity::ncPos,QPair<bdd::createSql,bool>(createSql::text,true));
    return att;
}

// TypeNom
QMap<int,QString> TypeNomInfoBdd::attribut()
{
    QMap<int,QString> att(NomInfoBdd::attribut());
    att.insert(TypeNomEntity::typePos,"tp");
    return att;
}

QVector<QMap<int,int>> TypeNomInfoBdd::attributUnique()
{
    QVector<QMap<int,int>> att(NomInfoBdd::attributUnique());
    att[0].insert(TypeNomUniqueSql::typeUnique,TypeNomEntity::typePos);
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> TypeNomInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(NomInfoBdd::creerAttribut());
    att.insert(TypeNomEntity::typePos,QPair<bdd::createSql,bool>(createSql::integer,true));
    return att;
}

//ValeurDateTimeRelation
QMap<int,QString> ValeurDateTimeRelationInfoBdd::attribut()
{
    QMap<int,QString> att(DateTimeRelationInfoBdd::attribut());
    att.insert(ValeurDateTimeRelationEntity::valeurPos,"vl");
    return att;
}

QMap<int, QPair<bdd::createSql,bool>> ValeurDateTimeRelationInfoBdd::creerAttribut()
{
    QMap<int,QPair<bdd::createSql,bool>> att(DateTimeRelationInfoBdd::creerAttribut());
    att.insert(ValeurDateTimeRelationEntity::valeurPos,QPair<bdd::createSql,bool>(createSql::blob,false));
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
        att.insert(Arbre::numPos,"nm");
        att.insert(Arbre::feuillePos,"fl");
        att.insert(Arbre::niveauPos,"nv");
        att.insert(Arbre::parentPos,"pt");
        break;

    case InfoEntity::entityBaseId::DateTimeRelationEntityId:
        att.insert(DateTimeRelationEntity::id1Pos,"id1");
        att.insert(DateTimeRelationEntity::id2Pos,"id2");
        att.insert(DateTimeRelationEntity::datePos,"dt");
        break;

    case InfoEntity::entityBaseId::DateTimeNumEntityId:
        att.insert(DateTimeNumEntity::numPos,"nm");
        att.insert(DateTimeNumEntity::dateTimePos,"dtt");
        break;

    case InfoEntity::entityBaseId::NcNomEntityId:
        att.insert(NcNomEntity::nomPos,"nm");
        att.insert(NcNomEntity::ncPos,"nc");
        break;

    case InfoEntity::entityBaseId::NomEntityId:
        att.insert(NomEntity::nomPos,"nm");
        break;

    case InfoEntity::entityBaseId::NumEntityId:
        att.insert(NumEntity::numPos,"nm");
        break;

    case InfoEntity::entityBaseId::NumRelationEntityId:
        att.insert(NumRelationEntity::id1Pos,"id1");
        att.insert(NumRelationEntity::id2Pos,"id2");
        att.insert(NumRelationEntity::numPos,"nm");
        break;

    case InfoEntity::entityBaseId::RelationEntityId:
        att.insert(RelationEntity::id1Pos,"id1");
        att.insert(RelationEntity::id2Pos,"id2");
        break;

    case InfoEntity::entityBaseId::RelationExactOneNotNullEntityId:
        att.insert(RelationExactOneNotNullEntity::id1Pos,"id1");
        att.insert(RelationExactOneNotNullEntity::id2Pos,"id2");
        break;

    case InfoEntity::entityBaseId::TexteEntityId:
        att.insert(TexteEntity::textePos,"txt");
        break;

    case InfoEntity::entityBaseId::TypeNcNomEntityId:
        att.insert(TypeNcNomEntity::nomPos,"nm");
        att.insert(TypeNcNomEntity::ncPos,"nc");
        att.insert(TypeNcNomEntity::typePos,"tp");
        break;

    case InfoEntity::entityBaseId::TypeNomEntityId:
        att.insert(TypeNomEntity::nomPos,"nm");
        att.insert(TypeNomEntity::typePos,"tp");
        break;

    case InfoEntity::entityBaseId::ValeurDateTimeRelationEntityId:
        att.insert(ValeurDateTimeRelationEntity::id1Pos,"id1");
        att.insert(ValeurDateTimeRelationEntity::id2Pos,"id2");
        att.insert(ValeurDateTimeRelationEntity::datePos,"dt");
        att.insert(ValeurDateTimeRelationEntity::valeurPos,"vl");
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
        att.insert(ArbreUniqueSql::numUnique,Arbre::numPos);
        att.insert(ArbreUniqueSql::parentUnique,Arbre::parentPos);
        break;

    case InfoEntity::entityBaseId::DateTimeRelationEntityId:
        att.insert(DateRelationUniqueSql::id1Unique,DateTimeRelationEntity::id1Pos);
        att.insert(DateRelationUniqueSql::id2Unique,DateTimeRelationEntity::id2Pos);
        att.insert(DateRelationUniqueSql::dateUnique,DateTimeRelationEntity::datePos);
        break;

    case InfoEntity::entityBaseId::NomEntityId:
        att.insert(NomUniqueSql::nomUnique,NomEntity::nomPos);
        break;

    case InfoEntity::entityBaseId::NumEntityId:
        att.insert(NumUniqueSql::numUnique,NumEntity::numPos);
        break;

    case InfoEntity::entityBaseId::RelationEntityId:
        att.insert(RelationUniqueSql::id1Unique,RelationEntity::id1Pos);
        att.insert(RelationUniqueSql::id2Unique,RelationEntity::id2Pos);
        break;

    case InfoEntity::entityBaseId::RelationExactOneNotNullEntityId:
        att.insert(RelationExactOneNotNullUniqueSql::id1Unique,RelationExactOneNotNullEntity::id1Pos);
        att.insert(RelationExactOneNotNullUniqueSql::id2Unique,RelationExactOneNotNullEntity::id2Pos);
        break;

    case InfoEntity::entityBaseId::TexteEntityId:
        att.insert(TexteUniqueSql::texteUnique,TexteEntity::textePos);
        break;

    case InfoEntity::entityBaseId::TypeNomEntityId:
        att.insert(TypeNomUniqueSql::nomUnique,TypeNomEntity::nomPos);
        att.insert(TypeNomUniqueSql::typeUnique,TypeNomEntity::typePos);
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
        att.insert(Arbre::numPos,QPair<int,bool>(createSql::integer,true));
        att.insert(Arbre::feuillePos,QPair<int,bool>(createSql::integer,true));
        att.insert(Arbre::niveauPos,QPair<int,bool>(createSql::integer,true));
        att.insert(Arbre::parentPos,QPair<int,bool>(createSql::integer,false));
        break;

    case InfoEntity::entityBaseId::DateTimeRelationEntityId:
        att.insert(DateTimeRelationEntity::id1Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(DateTimeRelationEntity::id2Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(DateTimeRelationEntity::datePos,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::DateTimeNumEntityId:
        att.insert(DateTimeNumEntity::numPos,QPair<int,bool>(createSql::integer,true));
        att.insert(DateTimeNumEntity::dateTimePos,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::NcNomEntityId:
        att.insert(NcNomEntity::nomPos,QPair<int,bool>(createSql::text,true));
        att.insert(NcNomEntity::ncPos,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::NomEntityId:
        att.insert(NomEntity::nomPos,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::NumEntityId:
        att.insert(NumEntity::numPos,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::NumRelationEntityId:
        att.insert(NumRelationEntity::id1Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(NumRelationEntity::id2Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(NumRelationEntity::numPos,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::RelationEntityId:
        att.insert(RelationEntity::id1Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(RelationEntity::id2Pos,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::RelationExactOneNotNullEntityId:
        att.insert(RelationExactOneNotNullEntity::id1Pos,QPair<int,bool>(createSql::integer,false));
        att.insert(RelationExactOneNotNullEntity::id2Pos,QPair<int,bool>(createSql::integer,false));
        break;

    case InfoEntity::entityBaseId::TexteEntityId:
        att.insert(TexteEntity::textePos,QPair<int,bool>(createSql::text,true));
        break;

    case InfoEntity::entityBaseId::TypeNcNomEntityId:
        att.insert(TypeNcNomEntity::nomPos,QPair<int,bool>(createSql::text,true));
        att.insert(TypeNcNomEntity::ncPos,QPair<int,bool>(createSql::text,true));
        att.insert(TypeNcNomEntity::typePos,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::TypeNomEntityId:
        att.insert(TypeNomEntity::nomPos,QPair<int,bool>(createSql::text,true));
        att.insert(TypeNomEntity::typePos,QPair<int,bool>(createSql::integer,true));
        break;

    case InfoEntity::entityBaseId::ValeurDateTimeRelationEntityId:
        att.insert(ValeurDateTimeRelationEntity::id1Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(ValeurDateTimeRelationEntity::id2Pos,QPair<int,bool>(createSql::integer,true));
        att.insert(ValeurDateTimeRelationEntity::datePos,QPair<int,bool>(createSql::text,true));
        att.insert(ValeurDateTimeRelationEntity::valeurPos,QPair<int,bool>(createSql::blob,false));
        break;

    default:
        throw std::invalid_argument(QString("Caractéristiques sql des attributs defaut non définies pour l'entité d'identifiant :")
                                    .append(QString::number(n)).toStdString());
    }
    return att;
}
*/
