/*Auteur: PERCIE DU SERT Maxime
 *Date: 30/04/2016
 */
#ifndef UNIQUESQL
#define UNIQUESQL

#include "UniqueSqlBase.h"
#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/Donnee.h"
#include "../Entities/DonneeCard.h"
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

CONSTR_DESTR_UNIQUE_SQL(Donnee,SimpleUniqueSql)
    enum {idProgUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Donnee &entity)
        {bindValue(idProgUnique,entity.idProg());}};

CONSTR_DESTR_UNIQUE_SQL(DonneeCard,SimpleUniqueSql)
    enum {idDonneeUnique,surUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const DonneeCard &entity)
    {
        bindValue(idDonneeUnique,entity.idDonnee());
        bindValue(surUnique,entity.sur());
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
#endif // UNIQUESQL
