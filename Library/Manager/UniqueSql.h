/*Auteur: PERCIE DU SERT Maxime
 *Date: 30/04/2016
 */
#ifndef UNIQUESQL
#define UNIQUESQL

#include "UniqueSqlBase.h"
#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Entities/Groupe.h"

CONSTR_DESTR_UNIQUE_SQL(Annee,SimpleUniqueSql)
    enum {anUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Annee &entity)
        {bindValue(anUnique,entity.an());}};

CONSTR_DESTR_UNIQUE_SQL(Classe,DoubleUniqueSql)
    enum {idAnUnique,idEtabUnique,idNivUnique,numUnique,nomUnique = idNivUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_1(const Classe & entity)
    {
        bindValue(idAnUnique,entity.idAn());
        bindValue(idEtabUnique,entity.idEtab());
        bindValue(idNivUnique,entity.idNiv());
        bindValue(numUnique,entity.num());
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_2(const Classe & entity)
    {
        bindValue(idAnUnique,entity.idAn());
        bindValue(idEtabUnique,entity.idEtab());
        bindValue(nomUnique,entity.nom());
    }};

CONSTR_DESTR_UNIQUE_SQL(Eleve,NomUniqueSqlTemp)
    enum{naissanceUnique = NomUniqueSql::NbrUnique, prenomUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Eleve & entity)
    {
        NomUniqueSqlTemp<Eleve>::bindValuesUnique(entity);
        bindValue(naissanceUnique, entity.naissance());
        bindValue(prenomUnique, entity.prenom());
    }};

CONSTR_DESTR_UNIQUE_SQL(Groupe,AttsRelationExactOneNotNullUniqueSql)
    enum {nomUnique = AttsRelationExactOneNotNullUniqueSql<Groupe>::NbrUnique1};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Groupe & entity)
    {
        bindValue(nomUnique,entity.nom());
    }};

    /*
    UNIQUE_SQL(ClasseEleve,Relation)
    UNIQUE_SQL(Commentaire,Texte)
    UNIQUE_SQL(CommentaireClasse,DateRelation)
    UNIQUE_SQL(CommentaireEleve,DateRelation)
    UNIQUE_SQL(CommentaireGroupe,DateRelation)
    UNIQUE_SQL(CoursArbre,NumParent)
    UNIQUE_SQL(Donnee,No)
    UNIQUE_SQL(DonneeArbre,NumParent)
    UNIQUE_SQL(DonneeClasse,DateRelation)
    UNIQUE_SQL(DonneeEleve,DateRelation)
    UNIQUE_SQL(DonneeEtablissement,DateRelation)
    UNIQUE_SQL(DonneeNiveau,DateRelation)
    UNIQUE_SQL(DonneeSource,DateRelation)
    UNIQUE_SQL(EnonceArbre,NumParent)
    UNIQUE_SQL(Etablissement,Nom)
    UNIQUE_SQL(EtablissementNiveau,Relation)
    UNIQUE_SQL(EtablissementType,Relation)
    UNIQUE_SQL(ExerciceArbre,NumParent)
    UNIQUE_SQL(GroupeEleve,Relation)
    UNIQUE_SQL(Niveau,Nom)
    UNIQUE_SQL(NiveauPrecedent,Relation)
    UNIQUE_SQL(Source,Nom)
    UNIQUE_SQL(TypeNiveau,Nom)
    UNIQUE_SQL(TypeEtablissement,Nom)
    UNIQUE_SQL(VersionBdd,Num)
    */
#endif // UNIQUESQL
