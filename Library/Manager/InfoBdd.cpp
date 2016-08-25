#include "InfoBdd.h"

QMap<int,QString> InfoBdd<Attribut>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Attribut::idPos,InfoBdd<AttributArbre>::table());
    return att;
}

QMap<int,QString> InfoBdd<AttributArbre>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Arbre::parentPos,table());
    return att;
}

QMap<int,QString> InfoBdd<AttributCommentaire>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(AttributCommentaire::idAtPos,InfoBdd<Attribut>::table());
    att.insert(AttributCommentaire::idCmPos,InfoBdd<Commentaire>::table());
    return att;
}

QMap<int,QString> InfoBdd<Classe>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Classe::idAnPos,InfoBdd<Annee>::table());
    att.insert(Classe::idEtabPos,InfoBdd<Etablissement>::table());
    att.insert(Classe::idNivPos,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<ClasseEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(ClasseEleve::idClPos,InfoBdd<Classe>::table());
    att.insert(ClasseEleve::idElPos,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<CommentaireClasse>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CommentaireClasse::idCmPos,InfoBdd<Commentaire>::table());
    att.insert(CommentaireClasse::idClPos,InfoBdd<Classe>::table());
    return att;
}

QMap<int,QString> InfoBdd<CommentaireEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CommentaireEleve::idCmPos,InfoBdd<Commentaire>::table());
    att.insert(CommentaireEleve::idElPos,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<CommentaireGroupe>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CommentaireGroupe::idCmPos,InfoBdd<Commentaire>::table());
    att.insert(CommentaireGroupe::idGrPos,InfoBdd<Groupe>::table());
    return att;
}

QMap<int,QString> InfoBdd<CoursArbre>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Arbre::parentPos,table());
    return att;
}

QMap<int,QString> InfoBdd<Donnee>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Donnee::idPos,InfoBdd<DonneeArbre>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeArbre>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Arbre::parentPos,table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeClasse>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeClasse::idDnPos,InfoBdd<Donnee>::table());
    att.insert(DonneeClasse::idClPos,InfoBdd<Classe>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeEleve::idDnPos,InfoBdd<Donnee>::table());
    att.insert(DonneeEleve::idElPos,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeEtablissement>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeEtablissement::idDnPos,InfoBdd<Donnee>::table());
    att.insert(DonneeEtablissement::idEtabPos,InfoBdd<Etablissement>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeNiveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeNiveau::idDnPos,InfoBdd<Donnee>::table());
    att.insert(DonneeNiveau::idNivPos,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeSource>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeSource::idDnPos,InfoBdd<Donnee>::table());
    att.insert(DonneeSource::idSrPos,InfoBdd<Source>::table());
    return att;
}

QMap<int,QString> InfoBdd<EnonceArbre>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Arbre::parentPos,table());
    return att;
}

QMap<int,QString> InfoBdd<EtablissementNiveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(EtablissementNiveau::idEtabPos,InfoBdd<Etablissement>::table());
    att.insert(EtablissementNiveau::idNivPos,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<EtablissementType>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(EtablissementType::idEtabPos,InfoBdd<Etablissement>::table());
    att.insert(EtablissementType::idTpPos,InfoBdd<TypeEtablissement>::table());
    return att;
}

QMap<int,QString> InfoBdd<ExerciceArbre>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Arbre::parentPos,table());
    return att;
}

QMap<int,QString> InfoBdd<Groupe>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Groupe::idAnPos,InfoBdd<Annee>::table());
    att.insert(Groupe::idClPos,InfoBdd<Classe>::table());
    return att;
}

QMap<int,QString> InfoBdd<GroupeEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(GroupeEleve::idGrPos,InfoBdd<Groupe>::table());
    att.insert(GroupeEleve::idElPos,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<Niveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Niveau::idTpPos,InfoBdd<TypeNiveau>::table());
    att.insert(Niveau::idTpEtabPos,InfoBdd<TypeEtablissement>::table());
    return att;
}
