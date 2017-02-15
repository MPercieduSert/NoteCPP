/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/04/2016
 */
#ifndef LINKSQL_H
#define LINKSQL_H

#include "AbstractLinkSql.h"
#include "LinkSqlBase.h"
#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/ClasseEleve.h"
#include "../Entities/Controle.h"
#include "../Entities/Donnee.h"
#include "../Entities/DonneeCard.h"
#include "../Entities/Eleve.h"
#include "../Entities/Groupe.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeControle.h"
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
 * \brief Lien entre l'entité Controle de programation et sa représentation en base de donnée.
 */
class ControleLinkSql : public NumRelationLinkSql
{
protected:
    ATTRIBUT_LINK(Controle,Bareme,bareme,bool)
    ATTRIBUT_LINK(Controle,Date,date,QDate)
    ATTRIBUT_LINK(Controle,Decimale,decimale,int)
    ATTRIBUT_LINK(Controle,Enonce,enonce,bool)
    ATTRIBUT_LINK(Controle,Minima,minima,int)
    ATTRIBUT_LINK(Controle,Nom,nom,QString)
    ATTRIBUT_LINK(Controle,Saisie,saisie,bool)
    ATTRIBUT_LINK(Controle,Total,total,int)

public:
    MEMBRE_LINK_ATT_8(NumRelationLinkSql,ControleLinkSql,Controle,Bareme,bareme,Date,date,Decimale,decimale,Enonce,enonce,Minima,minima,Nom,nom,Saisie,saisie,Total,total)
    //! Crée dynamiquement une nouvelle entité de type Donnee, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    Controle * newFromRequete() const
    {
        return new Controle(id1(),id2(),bareme(),date(),decimale(),enonce(),minima(),nom(),num(),saisie(),total(),id());
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
    MEMBRE_LINK_ATT_3(TypeNomLinkSql,DonneeLinkSql,Donnee,IdProg,idProg,Modif,modif,TpVal,tpVal)
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
    ATTRIBUT_LINK(DonneeCard,Cible,cible,int)

public:
    MEMBRE_LINK_ATT_3(AbstractLinkSql,DonneeCardLinkSql,DonneeCard,IdDonnee,idDonnee,Card,card,Cible,cible)
    //! Crée dynamiquement une nouvelle entité de type Donnee, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    DonneeCard * newFromRequete() const
    {
        return new DonneeCard(idDonnee(),card(),cible(),id());
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
 * \brief Lien entre l'entité TypeControle de programation et sa représentation en base de donnée.
 */
class TypeControleLinkSql : public NcNomLinkSql
{
protected:
    ATTRIBUT_LINK(TypeControle,Appreciation,appreciation,bool)
    ATTRIBUT_LINK(TypeControle,Decimale,decimale,int)
    ATTRIBUT_LINK(TypeControle,Modif,modif,bool)
    ATTRIBUT_LINK(TypeControle,Total,total,int)

public:
    MEMBRE_LINK_ATT_4(NcNomLinkSql,TypeControleLinkSql,TypeControle,Appreciation,appreciation,Decimale,decimale,Modif,modif,Total,total)
    //! Crée dynamiquement une nouvelle entité de type TypeNiveau, l'hydrate à partir de la requète SQL.
    //! Puis retourne un  pointeur vers cette nouvelle entité.
    TypeControle * newFromRequete() const
    {
        return new TypeControle(appreciation(),decimale(),modif(),nc(),nom(),total(),id());
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
