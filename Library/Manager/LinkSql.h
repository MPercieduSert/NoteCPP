/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/04/2016
 */
#ifndef LINKSQL_H
#define LINKSQL_H

#include "AbstractLinkSql.h"
#include "AttributsLinkSql.h"
#include "InfoSql.h"
#include "LinkSqlArbre.h"
#include "LinkSqlDivers.h"
#include "LinkSqlNom.h"
#include "LinkSqlRelation.h"

/*! \ingroup groupeLinkSqlBase
 * \brief Lien entre une entité de programation et sa représentation en base de donnée.
 */
template<class Ent> class LinkSql
{

};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Annee de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Annee> : public IdLinkSql<Annee>, public AnAttributSql<Annee>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Annee>(QSqlQuery * requete)
        : ReqSql(requete)
        {}

    //! Destructeur.
    ~LinkSql<Annee>()
    {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Annee & entity)
    {
        IdLinkSql<Annee>::bindValues(entity);
        setAn(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Annee & entity) const
    {
        IdLinkSql<Annee>::fromRequete(entity);
        entity.setAn(an());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Annee * newFromRequete() const
    {
        return new Annee(an(),id());
    }
};

LINK_SQL(AttributArbre,Arbre)
LINK_SQL(CoursArbre,Arbre)
LINK_SQL(DonneeArbre,Arbre)
LINK_SQL(EnonceArbre,Arbre)
LINK_SQL(ExerciceArbre,Arbre)

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Attribut de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Attribut> : public NcNomLinkSql<Attribut>,
        public PrBaremeAttributSql<Attribut>,
        public PrCommentaireAttributSql<Attribut>,
        public PrCorrectionAttributSql<Attribut>,
        public PrCoursAttributSql<Attribut>,
        public PrExerciceAttributSql<Attribut>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Attribut>(QSqlQuery * requete)
        : ReqSql(requete)
        {}

     //! Destructeur.
     ~LinkSql<Attribut>()
          {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Attribut & entity)
    {
        NcNomLinkSql<Attribut>::bindValues(entity);
        setPrBareme(entity);
        setPrCommentaire(entity);
        setPrCorrection(entity);
        setPrCours(entity);
        setPrExercice(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Attribut & entity) const
    {
        NcNomLinkSql<Attribut>::fromRequete(entity);
        entity.setPrBareme(prBareme());
        entity.setPrCommentaire(prCommentaire());
        entity.setPrCorrection(prCorrection());
        entity.setPrCours(prCours());
        entity.setPrExercice(prExercice());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Attribut * newFromRequete() const
    {
        return new Attribut(nom(),
                            prBareme(),
                            prCommentaire(),
                            prCorrection(),
                            prCours(),
                            prExercice(),
                            id(),
                            nc());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité ClasseEleve de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<ClasseEleve> : public RelationLinkSql<ClasseEleve>,
        public EntreeAttributSql<ClasseEleve>,
        public SortieAttributSql<ClasseEleve>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<ClasseEleve>(QSqlQuery * requete)
        : ReqSql(requete)
        {}

    //! Destructeur.
    ~LinkSql<ClasseEleve>()
         {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const ClasseEleve & entity)
    {
        RelationLinkSql<ClasseEleve>::bindValues(entity);
        setEntree(entity);
        setSortie(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(ClasseEleve & entity) const
    {
        RelationLinkSql<ClasseEleve>::fromRequete(entity);
        entity.setEntree(entree());
        entity.setSortie(sortie());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    ClasseEleve * newFromRequete() const
    {
        return new ClasseEleve(id1(),id2(),entree(),sortie(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Classe de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Classe> : public NumRelationLinkSql<Classe>, public IdNivAttributSql<Classe>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Classe>(QSqlQuery * requete)
        : ReqSql(requete)
    {}

    //! Destructeur.
    ~LinkSql<Classe>()
         {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Classe & entity)
    {
        NumRelationLinkSql<Classe>::bindValues(entity);
        setIdNiv(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Classe & entity) const
    {
        NumRelationLinkSql<Classe>::fromRequete(entity);
        entity.setIdNiv(idNiv());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Classe * newFromRequete() const
    {
        return new Classe(id1(),id2(),idNiv(),num(),id());
    }
};

LINK_SQL(Commentaire,Texte)

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Donnee de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Donnee> : public TypeNomLinkSql<Donnee>,
                                          public CardAttributSql<Donnee>,
                                          public SurAttributSql<Donnee>,
                                          public TpValAttributSql<Donnee>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Donnee>(QSqlQuery * requete)
        : ReqSql(requete)
        {}

    //! Destructeur.
    ~LinkSql<Donnee>()
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Donnee & entity)
    {
        TypeNomLinkSql<Donnee>::bindValues(entity);
        setCard(entity);
        setSur(entity);
        setTpVal(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Donnee & entity) const
    {
        TypeNomLinkSql<Donnee>::fromRequete(entity);
        entity.setCard(card());
        entity.setSur(sur());
        entity.setTpVal(tpVal());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Donnee * newFromRequete() const
    {
        return new Donnee(card(),nom(),sur(),type(),tpVal(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Eleve de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Eleve> : public NomLinkSql<Eleve>,
                                    public FilleAttributSql<Eleve>,
                                    public NaissanceAttributSql<Eleve>,
                                    public PrenomAttributSql<Eleve>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Eleve>(QSqlQuery * requete)
        : ReqSql(requete)
        {}

    //! Destructeur.
    ~LinkSql<Eleve>()
         {}


    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Eleve & entity)
    {
        NomLinkSql<Eleve>::bindValues(entity);
        setFille(entity);
        setNaissance(entity);
        setPrenom(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Eleve & entity) const
    {
        NomLinkSql<Eleve>::fromRequete(entity);
        entity.setFille(fille());
        entity.setNaissance(naissance());
        entity.setPrenom(prenom());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Eleve * newFromRequete() const
    {
        return new Eleve(fille(),naissance(),nom(),prenom(),id());
    }
};

LINK_SQL(Etablissement,NcNomType)

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Groupe de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Groupe> : public RelationLinkSql<Groupe>,
                                          public AlphaAttributSql<Groupe>,
                                          public NomAttributSql<Groupe>,
                                          public TypeAttributSql<Groupe>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Groupe>(QSqlQuery * requete)
        : ReqSql(requete)
        {}

    //! Destructeur.
    ~LinkSql<Groupe>()
        {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Groupe & entity)
    {
        RelationLinkSql<Groupe>::bindValues(entity);
        setAlpha(entity);
        setNom(entity);
        setType(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Groupe & entity) const
    {
        RelationLinkSql::fromRequete(entity);
        entity.setAlpha(alpha());
        entity.setNom(nom());
        entity.setType(type());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Groupe * newFromRequete() const
    {
        return new Groupe(id1(),id2(),alpha(),nom(),type());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Niveau de programation et sa représentation en base de donnée.
 */
template<> class LinkSql<Niveau> : public NcNomLinkSql<Niveau>, public IdTpAttributSql<Niveau>
{
public:
    //! Construteur, transmettre en argument l'objet de requète utilisée par le manageur.
    LinkSql<Niveau>(QSqlQuery * requete)
        : ReqSql(requete)
    {}

    //! Destructeur.
    ~LinkSql<Niveau>()
         {}

    //! Transmet les valeurs des attributs à la requète SQL préparée.
    void bindValues(const Niveau & entity)
    {
        NcNomLinkSql<Niveau>::bindValues(entity);
        setIdTp(entity);
    }

    //! Hydrate l'entité entity avec à partir de la requète.
    void fromRequete(Niveau & entity) const
    {
        NcNomLinkSql<Niveau>::fromRequete(entity);
        entity.setIdTp(idTp());
    }

    //! Crée dynamiquement une nouvelle entité de type T, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Niveau * newFromRequete() const
    {
        return new Niveau(idTp(),nc(),nom(),id());
    }
};

LINK_SQL(CommentaireClasse,DateRelation)
LINK_SQL(CommentaireEleve,DateRelation)
LINK_SQL(CommentaireGroupe,DateRelation)

LINK_SQL(DonneeClasse,ValeurDateRelation)
LINK_SQL(DonneeEleve,ValeurDateRelation)
LINK_SQL(DonneeEtablissement,ValeurDateRelation)
LINK_SQL(DonneeNiveau,ValeurDateRelation)
LINK_SQL(DonneeSource,ValeurDateRelation)

LINK_SQL(GroupeEleve,NumRelation)

LINK_SQL(AttributCommentaire,Relation)
LINK_SQL(NiveauPrecedent,Relation)
LINK_SQL(EtablissementNiveau,Relation)

LINK_SQL(Source,NomType)

LINK_SQL(TypeNiveau,NomType)

#endif // LINKSQL_H
