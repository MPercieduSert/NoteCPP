#include "InfoBdd.h"

QMap<int,QString> InfoBdd<MotCle>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(MotCle::Id,tableArbre());
    return att;
}

QMap<int,QString> InfoBdd<CibleCommentaire>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CibleCommentaire::IdCm,InfoBdd<Commentaire>::table());
    return att;
}

QMap<int,QString> InfoBdd<Cours>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Cours::Id,tableArbre());
    att.insert(Cours::IdTpCrs,InfoBdd<TypeCours>::table());
    return att;
}

QMap<int,QString> InfoBdd<CibleDonnee>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CibleDonnee::IdDn,InfoBdd<Donnee>::table());
    return att;
}

QMap<int,QString> InfoBdd<CibleMotCle>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CibleMotCle::IdMC,InfoBdd<MotCle>::table());
    return att;
}

QMap<int,QString> InfoBdd<CibleTexte>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(CibleTexte::IdTxt,InfoBdd<Texte>::table());
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

QMap<int,QString> InfoBdd<Coefficient>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Coefficient::IdCtr,InfoBdd<Controle>::table());
    return att;
}

QMap<int,QString> InfoBdd<Controle>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Controle::IdCl,InfoBdd<Classe>::table());
    att.insert(Controle::IdTp,InfoBdd<TypeControle>::table());
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
    att.insert(DonneeCard::IdDn,InfoBdd<Donnee>::table());
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

QMap<int,QString> InfoBdd<Exercice>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Exercice::Id,tableArbre());
    att.insert(Exercice::IdTpEx,InfoBdd<Exercice>::table());
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

QMap<int,QString> InfoBdd<MotClePermission>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(MotClePermission::IdMC,InfoBdd<MotCle>::table());
    return att;
}

QMap<int,QString> InfoBdd<Niveau>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Niveau::IdTp,InfoBdd<TypeNiveau>::table());
    att.insert(Niveau::IdTpEtab,InfoBdd<TypeEtablissement>::table());
    return att;
}

QMap<int,QString> InfoBdd<NiveauPrecedent>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(NiveauPrecedent::IdPrec,InfoBdd<Niveau>::table());
    att.insert(NiveauPrecedent::IdSuiv,InfoBdd<Niveau>::table());
    return att;
}

QMap<int,QString> InfoBdd<Note>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Note::IdCtr,InfoBdd<Controle>::table());
    att.insert(Note::IdEl,InfoBdd<Eleve>::table());
    return att;
}

QMap<int,QString> InfoBdd<TexteSource>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(TexteSource::IdSr,InfoBdd<Source>::table());
    att.insert(TexteSource::IdTxt,InfoBdd<Texte>::table());
    return att;
}

QMap<int,QString> InfoBdd<TypeControle>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(TypeControle::Parent,table());
    return att;
}

QMap<int,QString> InfoBdd<TypeCours>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(TypeCours::IdFE,InfoBdd<Forme>::table());
    att.insert(TypeCours::IdFC,InfoBdd<Forme>::table());
    att.insert(TypeCours::IdFP,InfoBdd<Forme>::table());
    att.insert(TypeCours::Parent,table());
    return att;
}

QMap<int,QString> InfoBdd<TypeExercice>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(TypeExercice::Parent,table());
    return att;
}

QMap<int,QString> InfoBdd<TypeUtilisation>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(TypeUtilisation::Parent,table());
    return att;
}

QMap<int,QString> InfoBdd<Utilisation>::foreignKey()
{
    QMap<int,QString> att;
    att.insert(Utilisation::IdTpUt,InfoBdd<TypeUtilisation>::table());
    return att;
}
