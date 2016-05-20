/*Auteur: PERCIE DU SERT Maxime
 *Date: 30/04/2016
 */
#ifndef UNIQUESQL
#define UNIQUESQL

#include "AbstractUniqueSql.h"

/*! \ingroup groupeUniqueSqlBase
 * \brief Traits des conditions d'unicité.
 */
template<class Ent> class UniqueSql
{

};

/*! \ingroup groupeUniqueSqlSpe
 * \brief Conditions d'unicité de l'entité Annee.
 */
template<> class UniqueSql<Annee> : public SimpleUniqueSql<Annee>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    UniqueSql<Annee>(QSqlQuery * requete)
        :SimpleUniqueSql(requete)
    {}

    //! Destructeur.
    ~UniqueSql<Annee>()
    {}
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Annee &entity)
        {bindValue(InfoSql<Annee>::AnUnique,entity.an());}
};

UNIQUE_SQL(AttributArbre,NumParent)
UNIQUE_SQL(CoursArbre,NumParent)
UNIQUE_SQL(DonneeArbre,NumParent)
UNIQUE_SQL(EnonceArbre,NumParent)
UNIQUE_SQL(ExerciceArbre,NumParent)

UNIQUE_SQL(Attribut,No)
UNIQUE_SQL(ClasseEleve,Relation)

/*! \ingroup groupeUniqueSqlSpe
 * \brief Conditions d'unicité de l'entité Classe.
 */
template<> class UniqueSql<Classe> : public RelationUniqueSql<Classe>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    UniqueSql<Classe>(QSqlQuery * requete)
        :RelationUniqueSql<Classe>(requete)
    {}

    //! Destructeur.
    ~UniqueSql<Classe>()
    {}
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Classe & entity)
    {
        RelationUniqueSql<Classe>::bindValuesUnique(entity);
        bindValue(InfoSql<Classe>::IdNivUnique,entity.idNiv());
        bindValue(InfoSql<Classe>::NumUnique,entity.num());
    }
};

UNIQUE_SQL(Commentaire,Texte)
UNIQUE_SQL(Donnee,No)

/*! \ingroup groupeUniqueSqlSpe
 * \brief Conditions d'unicité de l'entité Eleve.
 */
template<> class UniqueSql<Eleve> : public NomUniqueSql<Eleve>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    UniqueSql<Eleve>(QSqlQuery * requete)
        :NomUniqueSql<Eleve>(requete)
    {}

    //! Destructeur.
    ~UniqueSql<Eleve>()
    {}
protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Eleve & entity)
    {
        NomUniqueSql<Eleve>::bindValuesUnique(entity);
        bindValue(InfoSql<Eleve>::NaissanceUnique, entity.naissance());
        bindValue(InfoSql<Eleve>::PrenomUnique, entity.prenom());
    }
};


UNIQUE_SQL(Etablissement,NomType)

/*! \ingroup groupeUniqueSqlSpe
 * \brief Conditions d'unicité de l'entité Groupe.
 */
template<> class UniqueSql<Groupe> : public AttsRelationExactOneNotNullUniqueSql<Groupe>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    UniqueSql<Groupe>(QSqlQuery * requete)
        :AttsRelationExactOneNotNullUniqueSql<Groupe>(requete)
    {}

    //! Destructeur.
    ~UniqueSql<Groupe>()
    {}

protected:
    //! Transmet les valeurs des attributs uniques à la requète SQL préparée.
    void bindValuesUnique(const Groupe & entity)
    {
        bindValue(InfoSql<Groupe>::NomUnique,entity.nom());
    }
};

UNIQUE_SQL(Niveau,Nom)

UNIQUE_SQL(CommentaireClasse,DateRelation)
UNIQUE_SQL(CommentaireEleve,DateRelation)
UNIQUE_SQL(CommentaireGroupe,DateRelation)

UNIQUE_SQL(DonneeClasse,DateRelation)
UNIQUE_SQL(DonneeEleve,DateRelation)
UNIQUE_SQL(DonneeEtablissement,DateRelation)
UNIQUE_SQL(DonneeNiveau,DateRelation)
UNIQUE_SQL(DonneeSource,DateRelation)

UNIQUE_SQL(GroupeEleve,Relation)

UNIQUE_SQL(AttributCommentaire,Relation)
UNIQUE_SQL(NiveauPrecedent,Relation)
UNIQUE_SQL(EtablissementNiveau,Relation)

UNIQUE_SQL(Source,Nom)
UNIQUE_SQL(TypeNiveau,Nom)

#endif // UNIQUESQL
