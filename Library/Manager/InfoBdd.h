/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/05/2016
 */
#ifndef INFOBDD_H
#define INFOBDD_H

#include "InfoBddBase.h"
#include "LinkSql.h"
#include "UniqueSql.h"
#include "../Entities/EntityOfDefaultType.h"
#include "../Entities/Annee.h"
#include "../Entities/Attribut.h"
#include "../Entities/Classe.h"
#include "../Entities/ClasseEleve.h"
#include "../Entities/Donnee.h"
#include "../Entities/Eleve.h"
#include "../Entities/Groupe.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeEtablissement.h"
#include "../Entities/TypeNiveau.h"

using namespace bdd;
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant des informations sql sur les entités.
 */
template<class Ent> class InfoBdd
{
public:
    typedef AbstractLinkSql EntLinkSql;
    typedef AbstractUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
        {throw std::invalid_argument("Attributs sql non définies pour cette entité.");}

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
        {throw std::invalid_argument("Attributs unique sql non définies pour cette entité.");}

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<createSql, bool> > creerAttribut()
        {throw std::invalid_argument("Caractéristique attributs sql non définies pour cette entité.");}

    //! Retourne le nom la table sql.
    static QString table()
        {throw std::invalid_argument("Nom de table sql non définies pour cette entité.");}
};

// Annee
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Annee.
 */
template<> class InfoBdd<Annee> : public NoKeyInfoBdd
{
public:
    typedef AnneeLinkSql EntLinkSql;
    typedef AnneeUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att;
        att.insert(Annee::An,"an");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(AnneeUniqueSql::anUnique,Annee::An);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<createSql, bool> > att;
        att.insert(Annee::An,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("an");}
};

// Attribut
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Attribut.
 */
template<> class InfoBdd<Attribut> : public NoUniqueInfoBdd, public NodeInfoBdd
{
public:
    typedef AttributLinkSql EntLinkSql;
    typedef NoUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NcNomInfoBdd::attribut());
        att.insert(Attribut::PrBareme,"prbr");
        att.insert(Attribut::PrCommentaire,"prcm");
        att.insert(Attribut::PrCorrection,"prcrr");
        att.insert(Attribut::PrCours,"prcrs");
        att.insert(Attribut::PrExercice,"prex");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<createSql, bool> > att(NomInfoBdd::creerAttribut());
        att.insert(Attribut::Nc,QPair<createSql, bool>(createSql::text,false));
        att.insert(Attribut::PrBareme,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::PrCommentaire,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::PrCorrection,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::PrCours,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::PrExercice,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("at");}

    //! Retourne le nom la table sql.
    static QString tableArbre()
        {return QString("arbat");}
};

// AttributCommentaire
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité AttributCommentaire.
 */
template<> class InfoBdd<AttributCommentaire> : public RelationInfoBdd
{
public:
    typedef RelationOnlyLinkSql<AttributCommentaire> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("atcm");}
};

// Classe
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Classe.
 */
template<> class InfoBdd<Classe>
{
public:
    typedef ClasseLinkSql EntLinkSql;
    typedef ClasseUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att;
        att.insert(Classe::IdAn,"IDan");
        att.insert(Classe::IdEtab,"IDetab");
        att.insert(Classe::IdNiv,"Idniv");
        att.insert(Classe::Nom,"nom");
        att.insert(Classe::Num,"num");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(2);
        att[0].insert(ClasseUniqueSql::idAnUnique,Classe::IdAn);
        att[0].insert(ClasseUniqueSql::idEtabUnique,Classe::IdEtab);
        att[0].insert(ClasseUniqueSql::idNivUnique,Classe::IdNiv);
        att[0].insert(ClasseUniqueSql::numUnique,Classe::Num);
        att[1].insert(ClasseUniqueSql::idAnUnique,Classe::IdAn);
        att[1].insert(ClasseUniqueSql::idEtabUnique,Classe::IdEtab);
        att[1].insert(ClasseUniqueSql::nomUnique,Classe::Nom);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att;
        att.insert(Classe::IdAn,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::IdEtab,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::IdNiv,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::Nom,QPair<createSql, bool>(createSql::text,true));
        att.insert(Classe::Num,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cl");}
};

// ClasseEleve
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité ClasseEleve.
 */
template<> class InfoBdd<ClasseEleve> : public RelationInfoBdd
{
public:
    typedef ClasseEleveLinkSql EntLinkSql;
    typedef RelationUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(RelationInfoBdd::attribut());
        att.insert(ClasseEleve::Entree,"ent");
        att.insert(ClasseEleve::Sortie,"sort");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(RelationInfoBdd::creerAttribut());
        att.insert(ClasseEleve::Entree,QPair<createSql, bool>(createSql::text,false));
        att.insert(ClasseEleve::Sortie,QPair<createSql, bool>(createSql::text,false));
        return att;}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("clel");}
};

// Commentaire
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Commentaire.
 */
template<> class InfoBdd<Commentaire> : public TexteInfoBdd
{
public:
    typedef TexteOnlyLinkSql<Commentaire> EntLinkSql;

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cm");}
};

// CommentaireClasse
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CommentaireClasse.
 */
template<> class InfoBdd<CommentaireClasse> : public DateTimeRelationInfoBdd
{
public:
    typedef DateTimeRelationOnlyLinkSql<CommentaireClasse> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cmcl");}
};

// CommentaireEleve
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CommentaireEleve.
 */
template<> class InfoBdd<CommentaireEleve> : public DateTimeRelationInfoBdd
{
public:
    typedef DateTimeRelationOnlyLinkSql<CommentaireEleve> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cmel");}
};

// CommentaireGroupe
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CommentaireGroupe.
 */
template<> class InfoBdd<CommentaireGroupe> : public DateTimeRelationInfoBdd
{
public:
    typedef DateTimeRelationOnlyLinkSql<CommentaireGroupe> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cmgr");}
};

// Donnee
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Donnee.
 */
template<> class InfoBdd<Donnee> : public NodeInfoBdd
{
public:
    typedef DonneeLinkSql EntLinkSql;
    typedef NoUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(TypeNomInfoBdd::attribut());
        att.insert(Donnee::IdProg,"idp");
        att.insert(Donnee::Modif,"md");
        att.insert(Donnee::TpVal,"tpvl");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(DonneeUniqueSql::idProgUnique,Donnee::IdProg);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(TypeNomInfoBdd::creerAttribut());
        att.insert(Donnee::IdProg,QPair<createSql, bool>(createSql::integer,false));
        att.insert(Donnee::Modif,QPair<createSql, bool>(createSql::integer,false));
        att.insert(Donnee::TpVal,QPair<createSql, bool>(createSql::integer,true));
        return att;}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dn");}

    //! Retourne le nom la table sql.
    static QString tableArbre()
        {return QString("arbdn");}
};

// DonneeCard
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeCard.
 */
template<> class InfoBdd<DonneeCard>
{
public:
    typedef DonneeCardLinkSql EntLinkSql;
    typedef DonneeCardUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att;
        att.insert(DonneeCard::IdDonnee,"IDdn");
        att.insert(DonneeCard::Card,"cd");
        att.insert(DonneeCard::Sur,"sur");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(DonneeCardUniqueSql::idDonneeUnique,DonneeCard::IdDonnee);
        att[0].insert(DonneeCardUniqueSql::surUnique,DonneeCard::Sur);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att;
        att.insert(DonneeCard::IdDonnee,QPair<createSql, bool>(createSql::integer,true));
        att.insert(DonneeCard::Card,QPair<createSql, bool>(createSql::integer,true));
        att.insert(DonneeCard::Sur,QPair<createSql, bool>(createSql::integer,true));
        return att;}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dc");}
};

// DonneeClasse
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeClasse.
 */
template<> class InfoBdd<DonneeClasse> : public ValeurDateTimeRelationInfoBdd
{
public:
    typedef ValeurDateTimeRelationOnlyLinkSql<DonneeClasse> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dncl");}
};

// DonneeEleve
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeEleve.
 */
template<> class InfoBdd<DonneeEleve> : public ValeurDateTimeRelationInfoBdd
{
public:
    typedef ValeurDateTimeRelationOnlyLinkSql<DonneeEleve> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dnel");}
};

// DonneeEtablissement
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeEtablissement.
 */
template<> class InfoBdd<DonneeEtablissement> : public ValeurDateTimeRelationInfoBdd
{
public:
    typedef ValeurDateTimeRelationOnlyLinkSql<DonneeEtablissement> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dnetab");}
};

// DonneeNiveau
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeNiveau.
 */
template<> class InfoBdd<DonneeNiveau> : public ValeurDateTimeRelationInfoBdd
{
public:
    typedef ValeurDateTimeRelationOnlyLinkSql<DonneeNiveau> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dnniv");}
};

// DonneeSource
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeSource.
 */
template<> class InfoBdd<DonneeSource> : public ValeurDateTimeRelationInfoBdd
{
public:
    typedef ValeurDateTimeRelationOnlyLinkSql<DonneeSource> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dnsr");}
};

// Eleve
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Eleve.
 */
template<> class InfoBdd<Eleve> : public NoKeyInfoBdd
{
public:
    typedef EleveLinkSql EntLinkSql;
    typedef EleveUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NomInfoBdd::attribut());
        att.insert(Eleve::Fille,"fl");
        att.insert(Eleve::Naissance,"ne");
        att.insert(Eleve::Prenom,"pnm");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(EleveUniqueSql::nomUnique,Eleve::Nom);
        att[0].insert(EleveUniqueSql::naissanceUnique,Eleve::Naissance);
        att[0].insert(EleveUniqueSql::prenomUnique,Eleve::Prenom);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(NomInfoBdd::creerAttribut());
        att.insert(Eleve::Fille,QPair<bdd::createSql, bool>(createSql::integer,true));
        att.insert(Eleve::Naissance,QPair<bdd::createSql, bool>(createSql::text,true));
        att.insert(Eleve::Prenom,QPair<bdd::createSql, bool>(createSql::text,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("el");}
};

// Etablissement
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Etablissement.
 */
template<> class InfoBdd<Etablissement> : public NcNomInfoBdd
{
public:
    typedef NcNomOnlyLinkSql<Etablissement> EntLinkSql;

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("etab");}
};

// EtablissementNiveau
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité EtablissementNiveau.
 */
template<> class InfoBdd<EtablissementNiveau> : public RelationInfoBdd
{
public:
    typedef RelationOnlyLinkSql<EtablissementNiveau> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("etabniv");}
};

// EtablissementType
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité EtablissementType.
 */
template<> class InfoBdd<EtablissementType> : public RelationInfoBdd
{
public:
    typedef RelationOnlyLinkSql<EtablissementType> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("etabtp");}
};

// Groupe
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Groupe.
 */
template<> class InfoBdd<Groupe>
{
public:
    typedef GroupeLinkSql EntLinkSql;
    typedef GroupeUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(RelationExactOneNotNullInfoBdd::attribut());
        att.insert(Groupe::Alpha,"alp");
        att.insert(Groupe::Nom,"nm");
        att.insert(Groupe::Type,"tp");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(RelationExactOneNotNullInfoBdd::attributUnique());
        att[0].insert(GroupeUniqueSql::nomUnique,Groupe::Nom);
        att[1].insert(GroupeUniqueSql::nomUnique,Groupe::Nom);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(RelationExactOneNotNullInfoBdd::creerAttribut());
        att.insert(Groupe::Alpha,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Groupe::Nom,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Groupe::Type,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("gr");}
};

// GroupeEleve
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité GroupeEleve.
 */
template<> class InfoBdd<GroupeEleve> : public RelationInfoBdd
{
public:
    typedef RelationOnlyLinkSql<GroupeEleve> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("grel");}
};

// Niveau
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Niveau.
 */
template<> class InfoBdd<Niveau> : public NomInfoBdd
{
public:
    typedef NiveauLinkSql EntLinkSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NcNomInfoBdd::attribut());
        att.insert(Niveau::IdTp,"IDtp");
        att.insert(Niveau::IdTpEtab,"IDtpetab");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NcNomInfoBdd::creerAttribut());
        att.insert(Niveau::IdTp,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Niveau::IdTpEtab,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("niv");}
};

// NiveauPrecedent
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité NiveauPrecedent.
 */
template<> class InfoBdd<NiveauPrecedent> : public RelationInfoBdd
{
public:
    typedef RelationOnlyLinkSql<NiveauPrecedent> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey()
    {
        QMap<int,QString> att;
        att.insert(NiveauPrecedent::IdPrec,InfoBdd<Niveau>::table());
        att.insert(NiveauPrecedent::IdSuiv,InfoBdd<Niveau>::table());
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("nivpre");}
};

// Source
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Source.
 */
template<> class InfoBdd<Source> : public TypeNomInfoBdd
{
public:
    typedef TypeNcNomOnlyLinkSql<Source> EntLinkSql;

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("sr");}
};

// TypeEtablissement
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeEtablissement.
 */
template<> class InfoBdd<TypeEtablissement> : public NomInfoBdd
{
public:
    typedef TypeEtablissementLinkSql EntLinkSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NomInfoBdd::attribut());
        att.insert(TypeEtablissement::Max,"max");
        att.insert(TypeEtablissement::Min,"min");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NomInfoBdd::creerAttribut());
        att.insert(TypeEtablissement::Max,QPair<createSql, bool>(createSql::integer,true));
        att.insert(TypeEtablissement::Min,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpetab");}
};

// TypeNiveau
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeNiveau.
 */
template<> class InfoBdd<TypeNiveau> : public NomInfoBdd
{
public:
    typedef TypeNiveauLinkSql EntLinkSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NomInfoBdd::attribut());
        att.insert(TypeNiveau::AnBac,"an");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NomInfoBdd::creerAttribut());
        att.insert(TypeNiveau::AnBac,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpniv");}
};
#endif // INFOBDD_H
