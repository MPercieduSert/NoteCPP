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
#include "../Entities/Classe.h"
#include "../Entities/ClasseEleve.h"
#include "../Entities/Donnee.h"
#include "../Entities/Eleve.h"
#include "../Entities/Controle.h"
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
        att[0].insert(AnneeUniqueSql::AnUnique,Annee::An);
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
template<> class InfoBdd<Attribut> : public TypeNcNomInfoBdd, public NodeInfoBdd
{
public:
    typedef TypeNcNomOnlyLinkSql<Attribut> EntLinkSql;
    typedef NoUniqueSql EntUniqueSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("at");}

    //! Retourne le nom la table sql.
    static QString tableArbre()
        {return QString("arbat");}
};

// Cible Attribut
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CibleAttribut.
 */
template<> class InfoBdd<CibleAttribut> : public CibleInfoBdd
{
public:
    typedef CibleOnlyLinkSql<CibleAttribut> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cbat");}
};

// Cible Commentaire
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CibleCommentaire.
 */
template<> class InfoBdd<CibleCommentaire> : public DateTimeCibleInfoBdd
{
public:
    typedef DateTimeCurrentCibleOnlyLinkSql<CibleCommentaire> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cbcm");}
};

// Cible Donnee
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CibleDonnee.
 */
template<> class InfoBdd<CibleDonnee> : public ValeurNumDateTimeCibleInfoBdd
{
public:
    typedef ValeurNumDateTimeCurrentCibleOnlyLinkSql<CibleDonnee> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cbdn");}
};

// Classe
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Classe.
 */
template<> class InfoBdd<Classe> : public NomInfoBdd
{
public:
    typedef ClasseLinkSql EntLinkSql;
    typedef ClasseUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NomInfoBdd::attribut());
        att.insert(Classe::IdAn,"IDan");
        att.insert(Classe::IdEtab,"IDetab");
        att.insert(Classe::IdNiv,"IDniv");
        att.insert(Classe::Num,"num");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(2);
        att[0].insert(ClasseUniqueSql::IdAnUnique,Classe::IdAn);
        att[0].insert(ClasseUniqueSql::IdEtabUnique,Classe::IdEtab);
        att[0].insert(ClasseUniqueSql::IdNivUnique,Classe::IdNiv);
        att[0].insert(ClasseUniqueSql::NumUnique,Classe::Num);
        att[1].insert(ClasseUniqueSql::IdAnUnique,Classe::IdAn);
        att[1].insert(ClasseUniqueSql::IdEtabUnique,Classe::IdEtab);
        att[1].insert(ClasseUniqueSql::NomUnique,Classe::Nom);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NomInfoBdd::creerAttribut());
        att.insert(Classe::IdAn,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::IdEtab,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::IdNiv,QPair<createSql, bool>(createSql::integer,true));
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
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("clel");}
};

// Coefficient
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Coefficient.
 */
template<> class InfoBdd<Coefficient> : public ValeurDoubleIdNumInfoBdd
{
public:
    typedef ValeurDoubleIdNumOnlyLinkSql<Coefficient> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("coef");}
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

// Controle
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Controle.
 */
template<> class InfoBdd<Controle> : public NumRelationInfoBdd
{
public:
    typedef ControleLinkSql EntLinkSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NumRelationInfoBdd::attribut());
        att.insert(Controle::Bareme,"br");
        att.insert(Controle::Date,"dt");
        att.insert(Controle::Decimale,"dc");
        att.insert(Controle::Enonce,"en");
        att.insert(Controle::Minima,"min");
        att.insert(Controle::Nom,"nom");
        att.insert(Controle::Saisie,"ss");
        att.insert(Controle::Total,"tt");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(NumRelationInfoBdd::creerAttribut());
        att.insert(Controle::Bareme,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Controle::Date,QPair<createSql, bool>(createSql::text,true));
        att.insert(Controle::Decimale,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Controle::Enonce,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Controle::Minima,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Controle::Nom,QPair<createSql, bool>(createSql::text,true));
        att.insert(Controle::Saisie,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Controle::Total,QPair<createSql, bool>(createSql::integer,true));
        return att;}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("ctr");}
};

// Donnee
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Donnee.
 */
template<> class InfoBdd<Donnee> : public NodeInfoBdd
{
public:
    typedef DonneeLinkSql EntLinkSql;
    typedef DonneeUniqueSql EntUniqueSql;

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
        att[0].insert(DonneeUniqueSql::IdProgUnique,Donnee::IdProg);
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
        att.insert(DonneeCard::Exact,"ex");
        att.insert(DonneeCard::Cible,"cb");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(DonneeCardUniqueSql::IdDonneeUnique,DonneeCard::IdDonnee);
        att[0].insert(DonneeCardUniqueSql::CibleUnique,DonneeCard::Cible);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att;
        att.insert(DonneeCard::IdDonnee,QPair<createSql, bool>(createSql::integer,true));
        att.insert(DonneeCard::Card,QPair<createSql, bool>(createSql::integer,true));
        att.insert(DonneeCard::Exact,QPair<createSql,bool>(createSql::integer,false));
        att.insert(DonneeCard::Cible,QPair<createSql, bool>(createSql::integer,true));
        return att;}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dc");}
};

// Eleve
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Eleve.
 */
template<> class InfoBdd<Eleve> : public NomInfoBdd
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
        att[0].insert(EleveUniqueSql::NomUnique,Eleve::Nom);
        att[0].insert(EleveUniqueSql::NaissanceUnique,Eleve::Naissance);
        att[0].insert(EleveUniqueSql::PrenomUnique,Eleve::Prenom);
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
        att[0].insert(GroupeUniqueSql::NomUnique,Groupe::Nom);
        att[1].insert(GroupeUniqueSql::NomUnique,Groupe::Nom);
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
template<> class InfoBdd<GroupeEleve> : public NumRelationInfoBdd
{
public:
    typedef NumRelationOnlyLinkSql<GroupeEleve> EntLinkSql;
    typedef RelationUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {return RelationInfoBdd::attributUnique();}

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
template<> class InfoBdd<Niveau> : public NcNomInfoBdd
{
public:
    typedef NiveauLinkSql EntLinkSql;
    typedef NomUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NcNomInfoBdd::attribut());
        att.insert(Niveau::IdTp,"IDtp");
        att.insert(Niveau::IdTpEtab,"IDtpetab");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {return NomInfoBdd::attributUnique();}

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
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("nivpre");}
};

// Note
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Note.
 */
template<> class InfoBdd<Note> : public ValeurIntDateTimeNumRelationInfoBdd
{
public:
    typedef ValeurIntDateTimeCurrentNumRelationOnlyLinkSql<Note> EntLinkSql;
    typedef RelationUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {return RelationInfoBdd::attributUnique();}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("nt");}
};

// Source
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Source.
 */
template<> class InfoBdd<Source> : public TypeNcNomInfoBdd
{
public:
    typedef TypeNcNomOnlyLinkSql<Source> EntLinkSql;
    typedef NomUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {return NomInfoBdd::attributUnique();}

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("sr");}
};

// TypeControle
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeControle.
 */
template<> class InfoBdd<TypeControle> : public NcNomInfoBdd
{
public:
    typedef TypeControleLinkSql EntLinkSql;
    typedef NomUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NcNomInfoBdd::attribut());
        //att.insert(TypeControle::IdSousType,"IDst");
        att.insert(TypeControle::Appreciation,"app");
        att.insert(TypeControle::Decimale,"dc");
        att.insert(TypeControle::Modif,"md");
        att.insert(TypeControle::Total,"tt");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {return NomInfoBdd::attributUnique();}

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NcNomInfoBdd::creerAttribut());
        att.insert(TypeControle::Appreciation,QPair<createSql, bool>(createSql::integer,false));
        att.insert(TypeControle::Decimale,QPair<createSql, bool>(createSql::integer,true));
        att.insert(TypeControle::Modif,QPair<createSql, bool>(createSql::integer,false));
        att.insert(TypeControle::Total,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpctr");}
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
