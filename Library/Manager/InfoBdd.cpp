#include "InfoBdd.h"

QMap<int,QString> InfoBdd<Attribut>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Attribut::Id,tableArbre());
    return att;
}

QMap<int,QString> InfoBdd<AttributCommentaire>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(AttributCommentaire::IdAt,InfoBdd<Attribut>::table());
    att.insert(AttributCommentaire::IdCm,InfoBdd<Commentaire>::table());
    return att;
}

QMap<int,QString> InfoBdd<Classe>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Classe::IdAn,InfoBdd<Annee>::table());
    att.insert(Classe::IdEtab,InfoBdd<Etablissement>::table());
    att.insert(Classe::IdNiv,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<ClasseEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(ClasseEleve::IdCl,InfoBdd<Classe>::table());
    att.insert(ClasseEleve::IdEl,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<CommentaireClasse>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CommentaireClasse::IdCm,InfoBdd<Commentaire>::table());
    att.insert(CommentaireClasse::IdCl,InfoBdd<Classe>::table());
    return att;
}

QMap<int,QString> InfoBdd<CommentaireEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CommentaireEleve::IdCm,InfoBdd<Commentaire>::table());
    att.insert(CommentaireEleve::IdEl,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<CommentaireGroupe>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CommentaireGroupe::IdCm,InfoBdd<Commentaire>::table());
    att.insert(CommentaireGroupe::IdGr,InfoBdd<Groupe>::table());
    return att;
}

QMap<int,QString> InfoBdd<Donnee>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Donnee::Id,tableArbre());
    return att;
}

QMap<int,QString> InfoBdd<DonneeCard>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeCard::IdDonnee,InfoBdd<Donnee>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeClasse>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeClasse::IdDn,InfoBdd<Donnee>::table());
    att.insert(DonneeClasse::IdCl,InfoBdd<Classe>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeEleve::IdDn,InfoBdd<Donnee>::table());
    att.insert(DonneeEleve::IdEl,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeEtablissement>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeEtablissement::IdDn,InfoBdd<Donnee>::table());
    att.insert(DonneeEtablissement::IdEtab,InfoBdd<Etablissement>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeNiveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeNiveau::IdDn,InfoBdd<Donnee>::table());
    att.insert(DonneeNiveau::IdNiv,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<DonneeSource>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(DonneeSource::IdDn,InfoBdd<Donnee>::table());
    att.insert(DonneeSource::IdSr,InfoBdd<Source>::table());
    return att;
}

QMap<int,QString> InfoBdd<EtablissementNiveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(EtablissementNiveau::IdEtab,InfoBdd<Etablissement>::table());
    att.insert(EtablissementNiveau::IdNiv,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<EtablissementType>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(EtablissementType::IdEtab,InfoBdd<Etablissement>::table());
    att.insert(EtablissementType::IdTp,InfoBdd<TypeEtablissement>::table());
    return att;
}

QMap<int,QString> InfoBdd<Groupe>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Groupe::IdAn,InfoBdd<Annee>::table());
    att.insert(Groupe::IdCl,InfoBdd<Classe>::table());
    return att;
}

QMap<int,QString> InfoBdd<GroupeEleve>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(GroupeEleve::IdGr,InfoBdd<Groupe>::table());
    att.insert(GroupeEleve::IdEl,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<Niveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Niveau::IdTp,InfoBdd<TypeNiveau>::table());
    att.insert(Niveau::IdTpEtab,InfoBdd<TypeEtablissement>::table());
    return att;
}
