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
        att.insert(Annee::anPos,"an");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(AnneeUniqueSql::anUnique,Annee::anPos);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<createSql, bool> > att;
        att.insert(Annee::anPos,QPair<createSql, bool>(createSql::integer,true));
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
template<> class InfoBdd<Attribut> : public NoUniqueInfoBdd
{
public:
    typedef AttributLinkSql EntLinkSql;
    typedef NoUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(NcNomInfoBdd::attribut());
        att.insert(Attribut::prBaremePos,"prbr");
        att.insert(Attribut::prCommentairePos,"prcm");
        att.insert(Attribut::prCorrectionPos,"prcrr");
        att.insert(Attribut::prCoursPos,"prcrs");
        att.insert(Attribut::prExercicePos,"prex");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<createSql, bool> > att(NomInfoBdd::creerAttribut());
        att.insert(Attribut::ncPos,QPair<createSql, bool>(createSql::text,false));
        att.insert(Attribut::prBaremePos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::prCommentairePos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::prCorrectionPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::prCoursPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Attribut::prExercicePos,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("at");}
};

// AttributArbre
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité AttributArbre.
 */
template<> class InfoBdd<AttributArbre> : public ArbreInfoBdd
{
public:
    typedef ArbreOnlyLinkSql<AttributArbre> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
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
        att.insert(Classe::idAnPos,"IDan");
        att.insert(Classe::idEtabPos,"IDetab");
        att.insert(Classe::idNivPos,"Idniv");
        att.insert(Classe::nomPos,"nom");
        att.insert(Classe::numPos,"num");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(2);
        att[0].insert(ClasseUniqueSql::idAnUnique,Classe::idAnPos);
        att[0].insert(ClasseUniqueSql::idEtabUnique,Classe::idEtabPos);
        att[0].insert(ClasseUniqueSql::idNivUnique,Classe::idNivPos);
        att[0].insert(ClasseUniqueSql::numUnique,Classe::numPos);
        att[1].insert(ClasseUniqueSql::idAnUnique,Classe::idAnPos);
        att[1].insert(ClasseUniqueSql::idEtabUnique,Classe::idEtabPos);
        att[1].insert(ClasseUniqueSql::nomUnique,Classe::nomPos);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att;
        att.insert(Classe::idAnPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::idEtabPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::idNivPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Classe::nomPos,QPair<createSql, bool>(createSql::text,true));
        att.insert(Classe::numPos,QPair<createSql, bool>(createSql::integer,true));
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
        att.insert(ClasseEleve::entreePos,"ent");
        att.insert(ClasseEleve::sortiePos,"sort");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(RelationInfoBdd::creerAttribut());
        att.insert(ClasseEleve::entreePos,QPair<createSql, bool>(createSql::text,false));
        att.insert(ClasseEleve::sortiePos,QPair<createSql, bool>(createSql::text,false));
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

// CoursArbre
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CoursArbre.
 */
template<> class InfoBdd<CoursArbre> : public ArbreInfoBdd
{
public:
    typedef ArbreOnlyLinkSql<CoursArbre> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("arbcrs");}
};

// Donnee
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Donnee.
 */
template<> class InfoBdd<Donnee>
{
public:
    typedef DonneeLinkSql EntLinkSql;
    typedef NoUniqueSql EntUniqueSql;

    //! Retourne la liste des nom sql des attributs.
    static QMap<int,QString> attribut()
    {
        QMap<int,QString> att(TypeNomInfoBdd::attribut());
        att.insert(Donnee::cardPos,"cd");
        att.insert(Donnee::surPos,"sur");
        att.insert(Donnee::tpValPos,"tpvl");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
        {return QVector<QMap<int,int>>();}

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(TypeNomInfoBdd::creerAttribut());
        att.insert(Donnee::cardPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Donnee::surPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Donnee::tpValPos,QPair<createSql, bool>(createSql::integer,true));
        return att;}

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dn");}
};

// DonneeArbre
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité DonneeArbre.
 */
template<> class InfoBdd<DonneeArbre> : public ArbreInfoBdd
{
public:
    typedef ArbreOnlyLinkSql<DonneeArbre> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("arbdn");}
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
        att.insert(Eleve::fillePos,"fl");
        att.insert(Eleve::naissancePos,"ne");
        att.insert(Eleve::prenomPos,"pnm");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(EleveUniqueSql::nomUnique,Eleve::nomPos);
        att[0].insert(EleveUniqueSql::naissanceUnique,Eleve::naissancePos);
        att[0].insert(EleveUniqueSql::prenomUnique,Eleve::prenomPos);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int, QPair<bdd::createSql, bool> > att(NomInfoBdd::creerAttribut());
        att.insert(Eleve::fillePos,QPair<bdd::createSql, bool>(createSql::integer,true));
        att.insert(Eleve::naissancePos,QPair<bdd::createSql, bool>(createSql::text,true));
        att.insert(Eleve::prenomPos,QPair<bdd::createSql, bool>(createSql::text,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("el");}
};

// EnonceArbre
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité EnonceArbre.
 */
template<> class InfoBdd<EnonceArbre> : public ArbreInfoBdd
{
public:
    typedef ArbreOnlyLinkSql<EnonceArbre> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("arben");}
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

// ExerciceArbre
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité ExerciceArbre.
 */
template<> class InfoBdd<ExerciceArbre> : public ArbreInfoBdd
{
public:
    typedef ArbreOnlyLinkSql<ExerciceArbre> EntLinkSql;

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("arbex");}
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
        att.insert(Groupe::alphaPos,"alp");
        att.insert(Groupe::nomPos,"nm");
        att.insert(Groupe::typePos,"tp");
        return att;
    }

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(RelationExactOneNotNullInfoBdd::attributUnique());
        att[0].insert(GroupeUniqueSql::nomUnique,Groupe::nomPos);
        att[1].insert(GroupeUniqueSql::nomUnique,Groupe::nomPos);
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(RelationExactOneNotNullInfoBdd::creerAttribut());
        att.insert(Groupe::alphaPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Groupe::nomPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Groupe::typePos,QPair<createSql, bool>(createSql::integer,true));
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
        att.insert(Niveau::idTpPos,"IDtp");
        att.insert(Niveau::idTpEtabPos,"IDtpetab");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NcNomInfoBdd::creerAttribut());
        att.insert(Niveau::idTpPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(Niveau::idTpEtabPos,QPair<createSql, bool>(createSql::integer,true));
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
        att.insert(NiveauPrecedent::idPrecPos,InfoBdd<Niveau>::table());
        att.insert(NiveauPrecedent::idSuivPos,InfoBdd<Niveau>::table());
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
        att.insert(TypeEtablissement::maxPos,"max");
        att.insert(TypeEtablissement::minPos,"min");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NomInfoBdd::creerAttribut());
        att.insert(TypeEtablissement::maxPos,QPair<createSql, bool>(createSql::integer,true));
        att.insert(TypeEtablissement::minPos,QPair<createSql, bool>(createSql::integer,true));
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
        att.insert(TypeNiveau::anBacPos,"an");
        return att;
    }

    //! Retourne la liste des caractéristiques sql des attributs.
    static QMap<int, QPair<bdd::createSql, bool> > creerAttribut()
    {
        QMap<int,QPair<bdd::createSql, bool>> att(NomInfoBdd::creerAttribut());
        att.insert(TypeNiveau::anBacPos,QPair<createSql, bool>(createSql::integer,true));
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpniv");}
};
#endif // INFOBDD_H
