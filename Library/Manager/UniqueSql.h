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
#include "../Entities/Utilisation.h"

CONSTR_DESTR_UNIQUE_SQL(Annee,SimpleUniqueSql)
    enum {AnUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Annee &entity)
        {bindValue(AnUnique,entity.an());}};

CONSTR_DESTR_UNIQUE_SQL(Classe,DoubleUniqueSql)
    enum {IdAnUnique,IdEtabUnique,IdNivUnique,NumUnique,NomUnique = IdNivUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_1(const Classe & entity)
    {
        bindValue(IdAnUnique,entity.idAn());
        bindValue(IdEtabUnique,entity.idEtab());
        bindValue(IdNivUnique,entity.idNiv());
        bindValue(NumUnique,entity.num());
    }

    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_2(const Classe & entity)
    {
        bindValue(IdAnUnique,entity.idAn());
        bindValue(IdEtabUnique,entity.idEtab());
        bindValue(NomUnique,entity.nom());
    }};

CONSTR_DESTR_UNIQUE_SQL(DonneeCard,SimpleUniqueSql)
    enum {IdDonneeUnique,CibleUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const DonneeCard &entity)
    {
        bindValue(IdDonneeUnique,entity.idDn());
        bindValue(CibleUnique,entity.cible());
    }};

CONSTR_DESTR_UNIQUE_SQL(Eleve,NomUniqueSql)
    enum{NaissanceUnique = NomUniqueSql::NbrUnique, PrenomUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Eleve & entity)
    {
        NomUniqueSql<Eleve>::bindValuesUnique(entity);
        bindValue(NaissanceUnique, entity.naissance());
        bindValue(PrenomUnique, entity.prenom());
    }};

CONSTR_DESTR_UNIQUE_SQL(Groupe,AttsRelationExactOneNotNullUniqueSql)
    enum {NomUnique = AttsRelationExactOneNotNullUniqueSql<Groupe>::NbrUnique1};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Groupe & entity)
    {
        bindValue(NomUnique,entity.nom());
    }};

CONSTR_DESTR_UNIQUE_SQL(Utilisation,DoubleUniqueSql)
    enum {IdCibleUnique,IdOrigineUnique,CibleUnique,OrigineUnique,NumUnique,DateTimeUnique = 0,NomUnique};
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique_1(const Utilisation & entity)
        {
            bindValue(IdCibleUnique,entity.idCible());
            bindValue(IdOrigineUnique,entity.idOrigine());
            bindValue(CibleUnique,entity.cible());
            bindValue(OrigineUnique,entity.origine());
            bindValue(NumUnique,entity.num());
        }

        //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
        void bindValuesUnique_2(const Utilisation & entity)
        {
            bindValue(DateTimeUnique,entity.dateTime());
            bindValue(NomUnique,entity.nom());
        }};
#endif // UNIQUESQL
