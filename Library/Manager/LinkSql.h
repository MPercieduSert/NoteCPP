/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/04/2016
 */
#ifndef LINKSQL_H
#define LINKSQL_H

#include "AbstractLinkSql.h"
#include "LinkSqlBase.h"
#include "../Entities/Annee.h"
#include "../Entities/Attribut.h"
#include "../Entities/Classe.h"
#include "../Entities/ClasseEleve.h"
#include "../Entities/Donnee.h"
#include "../Entities/DonneeCard.h"
#include "../Entities/Eleve.h"
#include "../Entities/Groupe.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeEtablissement.h"
#include "../Entities/TypeNiveau.h"


/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Annee de programation et sa représentation en base de donnée.
 */
class AnneeLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(Annee,An,an,int)
public:
    MEMBRE_LINK_ATT_1(AbstractLinkSql,AnneeLinkSql,Annee,An,an)

    //! Crée dynamiquement une nouvelle entité de type Annee, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Annee * newFromRequete() const
    {
        return new Annee(an(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Attribut de programation et sa représentation en base de donnée.
 */
class AttributLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(Attribut,Nc,nc,QString)
    ATTRIBUT_LINK(Attribut,PrBareme,prBareme,bool)
    ATTRIBUT_LINK(Attribut,PrCommentaire,prCommentaire,bool)
    ATTRIBUT_LINK(Attribut,PrCorrection,prCorrection,bool)
    ATTRIBUT_LINK(Attribut,PrCours,prCours,bool)
    ATTRIBUT_LINK(Attribut,PrExercice,prExercice,bool)
public:
    MEMBRE_LINK_ATT_6(NomLinkSql,AttributLinkSql,Attribut,PrBareme,prBareme,PrCommentaire,prCommentaire,PrCorrection,prCorrection,PrCours,prCours,PrExercice,prExercice,Nc,nc)

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
 * \brief Lien entre l'entité Classe de programation et sa représentation en base de donnée.
 */
class ClasseLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(Classe,IdAn,idAn,int)
    ATTRIBUT_LINK(Classe,IdEtab,idEtab,int)
    ATTRIBUT_LINK(Classe,IdNiv,idNiv,int)
    ATTRIBUT_LINK(Classe,Num,num,int)
public:
    MEMBRE_LINK_ATT_4(NomLinkSql,ClasseLinkSql,Classe,IdAn,idAn,IdEtab,idEtab,IdNiv,idNiv,Num,num)
    //! Crée dynamiquement une nouvelle entité de type Classe, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Classe * newFromRequete() const
    {
        return new Classe(idAn(),idEtab(),idNiv(),nom(),num(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité ClasseEleve de programation et sa représentation en base de donnée.
 */
class ClasseEleveLinkSql : public RelationLinkSql
{
protected:
    ATTRIBUT_LINK(ClasseEleve,Entree,entree,QDate)
    ATTRIBUT_LINK(ClasseEleve,Sortie,sortie,QDate)
public:
    MEMBRE_LINK_ATT_2(RelationLinkSql,ClasseEleveLinkSql,ClasseEleve,Entree,entree,Sortie,sortie)
    //! Crée dynamiquement une nouvelle entité de type ClasseEleve, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    ClasseEleve * newFromRequete() const
    {
        return new ClasseEleve(id1(),id2(),entree(),sortie(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Donnee de programation et sa représentation en base de donnée.
 */
class DonneeLinkSql : public TypeNomLinkSql
{
protected:
    ATTRIBUT_LINK_NULL_TO_ZERO(Donnee,IdProg,idProg,int)
    ATTRIBUT_LINK(Donnee,Modif,modif,bool)
    ATTRIBUT_LINK(Donnee,TpVal,tpVal,int)
public:
    MEMBRE_LINK_ATT_1(TypeNomLinkSql,DonneeLinkSql,Donnee,TpVal,tpVal)
    //! Crée dynamiquement une nouvelle entité de type Donnee, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Donnee * newFromRequete() const
    {
        return new Donnee(modif(),nom(),type(),tpVal(),id(),idProg());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité DonneeCard de programation et sa représentation en base de donnée.
 */
class DonneeCardLinkSql : public AbstractLinkSql
{
protected:
    ATTRIBUT_LINK(DonneeCard,IdDonnee,idDonnee,int)
    ATTRIBUT_LINK(DonneeCard,Card,card,int)
    ATTRIBUT_LINK(DonneeCard,Sur,sur,int)

public:
    MEMBRE_LINK_ATT_3(AbstractLinkSql,DonneeCardLinkSql,DonneeCard,IdDonnee,idDonnee,Card,card,Sur,sur)
    //! Crée dynamiquement une nouvelle entité de type Donnee, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    DonneeCard * newFromRequete() const
    {
        return new DonneeCard(idDonnee(),card(),sur(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Eleve de programation et sa représentation en base de donnée.
 */
class EleveLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(Eleve,Fille,fille,bool)
    ATTRIBUT_LINK(Eleve,Naissance,naissance,QDate)
    ATTRIBUT_LINK(Eleve,Prenom,prenom,QString)
public:
    MEMBRE_LINK_ATT_3(NomLinkSql,EleveLinkSql,Eleve,Fille,fille,Naissance,naissance,Prenom,prenom)
    //! Crée dynamiquement une nouvelle entité de type Eleve, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Eleve * newFromRequete() const
    {
        return new Eleve(fille(),naissance(),nom(),prenom(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Groupe de programation et sa représentation en base de donnée.
 */
class GroupeLinkSql : public RelationExactOneNotNullLinkSql
{
protected:
    ATTRIBUT_LINK(Groupe,Alpha,alpha,int)
    ATTRIBUT_LINK(Groupe,Nom,nom,QString)
    ATTRIBUT_LINK(Groupe,Type,type,int)
public:
    MEMBRE_LINK_ATT_3(RelationExactOneNotNullLinkSql,GroupeLinkSql,Groupe,Alpha,alpha,Nom,nom,Type,type)
    //! Crée dynamiquement une nouvelle entité de type Groupe, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Groupe * newFromRequete() const
    {
        return new Groupe(id1(),id2(),alpha(),nom(),type());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Niveau de programation et sa représentation en base de donnée.
 */
class NiveauLinkSql : public NcNomLinkSql
{
protected:
    ATTRIBUT_LINK(Niveau,IdTp,idTp,int)
    ATTRIBUT_LINK(Niveau,IdTpEtab,idTpEtab,int)
public:
    MEMBRE_LINK_ATT_2(NcNomLinkSql,NiveauLinkSql,Niveau,IdTp,idTp,IdTpEtab,idTpEtab)
    //! Crée dynamiquement une nouvelle entité de type Niveau, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Niveau * newFromRequete() const
    {
        return new Niveau(idTp(),idTpEtab(),nc(),nom(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité Niveau de programation et sa représentation en base de donnée.
 */
class TypeEtablissementLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(TypeEtablissement,Max,max,int)
    ATTRIBUT_LINK(TypeEtablissement,Min,min,int)
public:
    MEMBRE_LINK_ATT_2(NomLinkSql,TypeEtablissementLinkSql,TypeEtablissement,Max,max,Min,min)
    //! Crée dynamiquement une nouvelle entité de type TypeEtablissement, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    TypeEtablissement * newFromRequete() const
    {
        return new TypeEtablissement(max(),min(),nom(),id());
    }
};

/*! \ingroup groupeLinkSqlSpe
 * \brief Lien entre l'entité TypeNiveau de programation et sa représentation en base de donnée.
 */
class TypeNiveauLinkSql : public NomLinkSql
{
protected:
    ATTRIBUT_LINK(TypeNiveau,AnBac,anBac,int)
public:
    MEMBRE_LINK_ATT_1(NomLinkSql,TypeNiveauLinkSql,TypeNiveau,AnBac,anBac)
    //! Crée dynamiquement une nouvelle entité de type TypeNiveau, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    TypeNiveau * newFromRequete() const
    {
        return new TypeNiveau(anBac(),nom(),id());
    }
};

#endif // LINKSQL_H
