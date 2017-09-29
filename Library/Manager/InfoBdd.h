/*Auteur: PERCIE DU SERT Maxime
 *Date: 27/05/2016
 */
#ifndef INFOBDD_H
#define INFOBDD_H

#include <type_traits>
#include "InfoBddBase.h"
#include "UniqueSql.h"
#include "../Entities/EntityOfDefaultType.h"
#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/ClasseEleve.h"
#include "../Entities/Controle.h"
#include "../Entities/Donnee.h"
#include "../Entities/Eleve.h"
#include "../Entities/Forme.h"
#include "../Entities/Groupe.h"
#include "../Entities/MotCle.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeControle.h"
#include "../Entities/TypeCours.h"
#include "../Entities/TypeEtablissement.h"
#include "../Entities/TypeNiveau.h"
#include "../Entities/Utilisation.h"

/*! \defgroup groupeInfoBdd Information sur la structure de la base de données.
 * \ingroup groupeManager
 * \brief Ensemble d'informations sur la structure des entités dans la base de données.
 */

namespace bdd {
    //! Enumération des numéros de cible
    //! Enumération des cibles.
    enum cible {AnneeCb,
                BaremeCb,
                CibleCommentaireCb,
                CibleDonneeCb,
                CibleMotCleCb,
                CibleTexteCb,
                ClasseCb,
                ClasseEleveCb,
                CoefficientCb,
                CommentaireCb,
                ControleCb,
                CoursCb,
                DonneeCb,
                DonneeCardCb,
                EleveCb,
                EnonceCb,
                EtablissementCb,
                EtablissementNiveauCb,
                EtablissementTypeCb,
                ExerciceCb,
                FormeCb,
                GroupeCb,
                GroupeEleveCb,
                MotCleCb,
                MotClePermissionCb,
                NiveauCb,
                NiveauPrecedentCb,
                NoteCb,
                PointCb,
                RestrictionModificationCb,
                SourceCb,
                TexteCb,
                TexteSourceCb,
                TypeControleCb,
                TypeCoursCb,
                TypeEtablissementCb,
                TypeExerciceCb,
                TypeNiveauCb,
                TypeUtilisationCb,
                UtilisationCb
               };
}
using namespace bdd;

class Bareme;
class Enonce;
class Point;

template<class Ent> struct Cible : std::integral_constant<int,-1> {};
template<> struct Cible<Annee> : std::integral_constant<int,bdd::cible::AnneeCb> {};
template<> struct Cible<Bareme> : std::integral_constant<int,bdd::cible::BaremeCb> {};
template<> struct Cible<CibleCommentaire> : std::integral_constant<int,bdd::cible::CibleCommentaireCb> {};
template<> struct Cible<CibleDonnee> : std::integral_constant<int,bdd::cible::CibleDonneeCb> {};
template<> struct Cible<CibleMotCle> : std::integral_constant<int,bdd::cible::CibleMotCleCb> {};
template<> struct Cible<CibleTexte> : std::integral_constant<int,bdd::cible::CibleTexteCb> {};
template<> struct Cible<Classe> : std::integral_constant<int,bdd::cible::ClasseCb> {};
template<> struct Cible<ClasseEleve> : std::integral_constant<int,bdd::cible::ClasseEleveCb> {};
template<> struct Cible<Coefficient> : std::integral_constant<int,bdd::cible::CoefficientCb> {};
template<> struct Cible<Commentaire> : std::integral_constant<int,bdd::cible::CommentaireCb> {};
template<> struct Cible<Controle> : std::integral_constant<int,bdd::cible::ControleCb> {};
template<> struct Cible<Cours> : std::integral_constant<int,bdd::cible::CoursCb> {};
template<> struct Cible<Donnee> : std::integral_constant<int,bdd::cible::DonneeCb> {};
template<> struct Cible<DonneeCard> : std::integral_constant<int,bdd::cible::DonneeCardCb> {};
template<> struct Cible<Eleve> : std::integral_constant<int,bdd::cible::EleveCb> {};
template<> struct Cible<Enonce> : std::integral_constant<int,bdd::cible::EnonceCb> {};
template<> struct Cible<Etablissement> : std::integral_constant<int,bdd::cible::EtablissementCb> {};
template<> struct Cible<EtablissementNiveau> : std::integral_constant<int,bdd::cible::EtablissementNiveauCb> {};
template<> struct Cible<EtablissementType> : std::integral_constant<int,bdd::cible::EtablissementTypeCb> {};
template<> struct Cible<Exercice> : std::integral_constant<int,bdd::cible::ExerciceCb> {};
template<> struct Cible<Forme> : std::integral_constant<int,bdd::cible::FormeCb> {};
template<> struct Cible<Groupe> : std::integral_constant<int,bdd::cible::GroupeCb> {};
template<> struct Cible<GroupeEleve> : std::integral_constant<int,bdd::cible::GroupeEleveCb> {};
template<> struct Cible<MotCle> : std::integral_constant<int,bdd::cible::MotCleCb> {};
template<> struct Cible<MotClePermission> : std::integral_constant<int,bdd::cible::MotClePermissionCb> {};
template<> struct Cible<Niveau> : std::integral_constant<int,bdd::cible::NiveauCb> {};
template<> struct Cible<NiveauPrecedent> : std::integral_constant<int,bdd::cible::NiveauPrecedentCb> {};
template<> struct Cible<Note> : std::integral_constant<int,bdd::cible::NoteCb> {};
template<> struct Cible<Point> : std::integral_constant<int,bdd::cible::PointCb> {};
template<> struct Cible<RestrictionModification> : std::integral_constant<int,bdd::cible::RestrictionModificationCb> {};
template<> struct Cible<Source> : std::integral_constant<int,bdd::cible::SourceCb> {};
template<> struct Cible<Texte> : std::integral_constant<int,bdd::cible::TexteCb> {};
template<> struct Cible<TexteSource> : std::integral_constant<int,bdd::cible::TexteSourceCb> {};
template<> struct Cible<TypeControle> : std::integral_constant<int,bdd::cible::TypeControleCb> {};
template<> struct Cible<TypeCours> : std::integral_constant<int,bdd::cible::TypeCoursCb> {};
template<> struct Cible<TypeEtablissement> : std::integral_constant<int,bdd::cible::TypeEtablissementCb> {};
template<> struct Cible<TypeExercice> : std::integral_constant<int,bdd::cible::TypeExerciceCb> {};
template<> struct Cible<TypeNiveau> : std::integral_constant<int,bdd::cible::TypeNiveauCb> {};
template<> struct Cible<TypeUtilisation> : std::integral_constant<int,bdd::cible::TypeUtilisationCb> {};
template<> struct Cible<Utilisation> : std::integral_constant<int,bdd::cible::UtilisationCb> {};



/*! \ingroup groupeInfoBdd
 * \brief Traits donnant le type de manager associé à l'entité.
 */
template<class Ent> struct TypeManager : std::integral_constant<int,bddInfo::typeManager::Simple> {};
template<> struct TypeManager<Coefficient> : std::integral_constant<int,bddInfo::typeManager::ModifControle> {};
template<> struct TypeManager<Cours> : std::integral_constant<int,bddInfo::typeManager::Arbre> {};
template<> struct TypeManager<Donnee> : std::integral_constant<int,bddInfo::typeManager::ArbreModifControle> {};
template<> struct TypeManager<DonneeCard> : std::integral_constant<int,bddInfo::typeManager::ModifControle> {};
template<> struct TypeManager<Exercice> : std::integral_constant<int,bddInfo::typeManager::Arbre> {};
template<> struct TypeManager<MotCle> : std::integral_constant<int,bddInfo::typeManager::ArbreModifControle> {};
template<> struct TypeManager<MotClePermission> : std::integral_constant<int,bddInfo::typeManager::ModifControlePermission> {};
template<> struct TypeManager<Niveau> : std::integral_constant<int,bddInfo::typeManager::ModifControle> {};
template<> struct TypeManager<NiveauPrecedent> : std::integral_constant<int,bddInfo::typeManager::ModifControle> {};
template<> struct TypeManager<TypeControle> : std::integral_constant<int,bddInfo::typeManager::ArbreSimpleModifControle> {};
template<> struct TypeManager<TypeCours> : std::integral_constant<int,bddInfo::typeManager::ArbreSimpleModifControle> {};
template<> struct TypeManager<TypeEtablissement> : std::integral_constant<int,bddInfo::typeManager::ModifControle> {};
template<> struct TypeManager<TypeExercice> : std::integral_constant<int,bddInfo::typeManager::ArbreSimpleModifControle> {};
template<> struct TypeManager<TypeNiveau> : std::integral_constant<int,bddInfo::typeManager::ModifControle> {};
template<> struct TypeManager<TypeUtilisation> : std::integral_constant<int,bddInfo::typeManager::ArbreSimpleModifControle> {};

/*! \ingroup groupeInfoBdd
 * \brief Traits testant si une entité est une cible valide d'une entitéCible.
 */
template<class Ent, class Cible> struct IsCible : std::integral_constant<bool,false> {};
//Commentaire
template<> struct IsCible<Commentaire,Annee> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Classe> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Controle> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Eleve> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Enonce> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Groupe> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Note> : std::integral_constant<bool,true> {};
template<> struct IsCible<Commentaire,Point> : std::integral_constant<bool,true> {};
//Donnee
template<> struct IsCible<Donnee,Etablissement> : std::integral_constant<bool,true> {};
template<> struct IsCible<Donnee,Niveau> : std::integral_constant<bool,true> {};
template<> struct IsCible<Donnee,TypeEtablissement> : std::integral_constant<bool,true> {};
template<> struct IsCible<Donnee,TypeNiveau> : std::integral_constant<bool,true> {};
//MotCle
template<> struct IsCible<MotCle,Bareme> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Commentaire> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Controle> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Cours> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Enonce> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Exercice> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,MotCle> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Texte> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,TypeControle> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,TypeUtilisation> : std::integral_constant<bool,true> {};
template<> struct IsCible<MotCle,Utilisation> : std::integral_constant<bool,true> {};
//Utilisation
template<> struct IsCible<Utilisation,Classe> : std::integral_constant<bool,true> {};
template<> struct IsCible<Utilisation,Eleve> : std::integral_constant<bool,true> {};
template<> struct IsCible<Utilisation,Groupe> : std::integral_constant<bool,true> {};

/*! \ingroup groupeInfoBdd
 * \brief Traits testant si une entité est une cible valide d'une entitéCible.
 */
template<class Ent, class Origine> struct IsOrigine : std::integral_constant<bool,false> {};

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant des informations sql sur les entités.
 */
template<class Ent> class InfoBdd
{
public:
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
SINGLE_INFOBDD(An,An,an,Integer,true)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Annee.
 */
template<> class InfoBdd<Annee> : public AnInfoBdd<Annee>, public NoKeyInfoBdd
{
public:
    typedef AnneeUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(AnneeUniqueSql::AnUnique,Annee::An);
        return att;
    }

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("an");}
};

// Cible Commentaire
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CibleCommentaire.
 */
template<> class InfoBdd<CibleCommentaire> : public InfoBddBase<CibleNullNumInfoBdd<CibleCommentaire>,DateTimeInfoBdd<CibleCommentaire>>
{
public:
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
template<> class InfoBdd<CibleDonnee> : public InfoBddBase<CibleNumInfoBdd<CibleDonnee>,
                                                            DateTimeInfoBdd<CibleDonnee>,
                                                            ValeurVariantInfoBdd<CibleDonnee>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cbdn");}
};

// Cible MotCle
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CibleMotCle.
 */
template<> class InfoBdd<CibleMotCle> : public CibleInfoBdd<CibleMotCle>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cbmc");}
};

// Cible Texte
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité CibleTexte.
 */
template<> class InfoBdd<CibleTexte> : public CibleInfoBdd<CibleTexte>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cbtt");}
};

// Classe
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Classe.
 */
template<> class InfoBdd<Classe> : public InfoBddBase<Id1InfoBdd<Classe>,
                                                      Id2InfoBdd<Classe>,
                                                      Id3InfoBdd<Classe>,
                                                      NomInfoBdd<Classe>,
                                                      NumInfoBdd<Classe>>
{
public:
    typedef ClasseUniqueSql EntUniqueSql;

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

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cl");}
};

// ClasseEleve
SINGLE_INFOBDD(Entree,Entree,et,Date,true)
SINGLE_INFOBDD(Sortie,Sortie,st,Date,false)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité ClasseEleve.
 */
template<> class InfoBdd<ClasseEleve> : public InfoBddBase<RelationInfoBdd<ClasseEleve>,
                                                           EntreeInfoBdd<ClasseEleve>,
                                                           SortieInfoBdd<ClasseEleve>>
{
public:
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
template<> class InfoBdd<Coefficient> : public InfoBddBase<IdNumInfoBdd<Coefficient>,ValeurDoubleInfoBdd<Coefficient>>
{
public:
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
template<> class InfoBdd<Commentaire> : public TexteUniqueInfoBdd<Commentaire>, public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("cm");}
};

// Controle
SINGLE_INFOBDD(Bareme,Bareme,br,Bool,true)
SINGLE_INFOBDD(Enonce,Enonce,en,Bool,true)
SINGLE_INFOBDD(Minima,Minima,min,Integer,true)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Controle.
 */
template<> class InfoBdd<Controle> : public InfoBddBase<RelationNumInfoBdd<Controle>,
                                                        BaremeInfoBdd<Controle>,
                                                        DateValideInfoBdd<Controle>,
                                                        DecimaleInfoBdd<Controle>,
                                                        EnonceInfoBdd<Controle>,
                                                        MinimaInfoBdd<Controle>,
                                                        NomInfoBdd<Controle>,
                                                        SaisieInfoBdd<Controle>,
                                                        TotalInfoBdd<Controle>>

{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("ctr");}
};

// Cours
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Cours.
 */
template<> class InfoBdd<Cours> : public InfoBddBase<Id1InfoBdd<Cours>,CreationInfoBdd<Cours>,ModificationInfoBdd<Cours>,NumInfoBdd<Cours>>,
            public NodeInfoBdd,
            public NoUniqueInfoBdd<Cours>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("crs");}

    //! Retourne le nom la table sql.
    static QString tableArbre()
        {return QString("arbcrs");}
};

// Donnee
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Donnee.
 */
template<> class InfoBdd<Donnee> : public InfoBddBase<IdProgUniqueInfoBdd<Donnee>,
                                                      NomInfoBdd<Donnee>,
                                                      TypeInfoBdd<Donnee>,
                                                      TpValInfoBdd<Donnee>>,
                                                      public NodeInfoBdd
{
public:
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
template<> class InfoBdd<DonneeCard> : public InfoBddBase<IdCibleUniqueInfoBdd<DonneeCard>,CardInfoBdd<DonneeCard>,ExactInfoBdd<DonneeCard>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("dc");}
};

// Eleve
SINGLE_INFOBDD(Fille,Fille,fl,Bool,true)
SINGLE_INFOBDD(Naissance,Naissance,na,Date,true)
SINGLE_INFOBDD(Prenom,Prenom,pn,Text,true)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Eleve.
 */
template<> class InfoBdd<Eleve> : public InfoBddBase<FilleInfoBdd<Eleve>,NaissanceInfoBdd<Eleve>,NomInfoBdd<Eleve>,PrenomInfoBdd<Eleve>>,
                                  public NoKeyInfoBdd
{
public:
    typedef EleveUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(1);
        att[0].insert(EleveUniqueSql::NomUnique,Eleve::Nom);
        att[0].insert(EleveUniqueSql::NaissanceUnique,Eleve::Naissance);
        att[0].insert(EleveUniqueSql::PrenomUnique,Eleve::Prenom);
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
template<> class InfoBdd<Etablissement> : public InfoBddBase<NomUniqueInfoBdd<Etablissement>,NcInfoBdd<Etablissement>>,
                                          public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("etab");}
};

// EtablissementNiveau
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité EtablissementNiveau.
 */
template<> class InfoBdd<EtablissementNiveau> : public RelationInfoBdd<EtablissementNiveau>
{
public:
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
template<> class InfoBdd<EtablissementType> : public RelationInfoBdd<EtablissementType>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("etabtp");}
};

// Exercice
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Exercice.
 */
template<> class InfoBdd<Exercice> : public InfoBddBase<Id1InfoBdd<Exercice>,CreationInfoBdd<Exercice>,ModificationInfoBdd<Exercice>,NumInfoBdd<Exercice>>,
            public NodeInfoBdd,
            public NoUniqueInfoBdd<Exercice>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("ex");}

    //! Retourne le nom la table sql.
    static QString tableArbre()
        {return QString("arbex");}
};

// Forme
SINGLE_INFOBDD(AlignH,AlignH,alh,Integer,true)
SINGLE_INFOBDD(AlignV,AlignV,alv,Integer,true)
SINGLE_INFOBDD(Capital,Capital,cap,Integer,true)
SINGLE_INFOBDD(Format,Format,fmt,Integer,true)
SINGLE_INFOBDD(Gras,Gras,grs,Integer,true)
SINGLE_INFOBDD(Italic,Italic,itc,Integer,true)
SINGLE_INFOBDD(Indent,Indent,idt,Integer,true)
SINGLE_INFOBDD(Ligne,Ligne,lgn,Integer,true)
SINGLE_INFOBDD(Marge,Marge,mrg,Integer,true)
SINGLE_INFOBDD(Police,Police,plc,Text,true)
SINGLE_INFOBDD(Taille,Taille,tll,Integer,true)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Exercice.
 */
template<> class InfoBdd<Forme> : public InfoBddBase<AlignHInfoBdd<Forme>,
                                                    AlignVInfoBdd<Forme>,
                                                    CapitalInfoBdd<Forme>,
                                                    FormatInfoBdd<Forme>,
                                                    GrasInfoBdd<Forme>,
                                                    ItalicInfoBdd<Forme>,
                                                    IndentInfoBdd<Forme>,
                                                    LigneInfoBdd<Forme>,
                                                    MargeInfoBdd<Forme>,
                                                    NomUniqueInfoBdd<Forme>,
                                                    PoliceInfoBdd<Forme>,
                                                    TailleInfoBdd<Forme>>,
                                   public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("frm");}
};



// Groupe
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Groupe.
 */
template<> class InfoBdd<Groupe> : public InfoBddBase<RelationExactOneNotNullInfoBdd<Groupe>,
                                                      AlphaInfoBdd<Groupe>,
                                                      NomInfoBdd<Groupe>,
                                                      TypeInfoBdd<Groupe>>
{
public:
    typedef GroupeUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(RelationExactOneNotNullInfoBdd<Groupe>::attributUnique());
        att[0].insert(GroupeUniqueSql::NomUnique,Groupe::Nom);
        att[1].insert(GroupeUniqueSql::NomUnique,Groupe::Nom);
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
template<> class InfoBdd<GroupeEleve> : public InfoBddBase<RelationInfoBdd<GroupeEleve>,NumInfoBdd<GroupeEleve>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("grel");}
};

// MotCle
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité MotCle.
 */
template<> class InfoBdd<MotCle> : public InfoBddBase<NcInfoBdd<MotCle>,NomInfoBdd<MotCle>,IdProgUniqueInfoBdd<MotCle>>,
                                   public NodeInfoBdd
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("mc");}

    //! Retourne le nom la table sql.
    static QString tableArbre()
        {return QString("arbmc");}
};

// MotClePermission
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité MotClePermission.
 */
template<> class InfoBdd<MotClePermission> : public InfoBddBase<IdCibleUniqueInfoBdd<MotClePermission>,NumInfoBdd<MotClePermission>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("mcp");}
    };

// Niveau
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Niveau.
 */
template<> class InfoBdd<Niveau> : public InfoBddBase<NomUniqueInfoBdd<Niveau>,Id1InfoBdd<Niveau>,Id2InfoBdd<Niveau>,NcInfoBdd<Niveau>>
{
public:
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
template<> class InfoBdd<NiveauPrecedent> : public RelationInfoBdd<NiveauPrecedent>
{
public:
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
template<> class InfoBdd<Note> : public InfoBddBase<RelationInfoBdd<Note>,DateTimeInfoBdd<Note>,NumInfoBdd<Note>,ValeurIntInfoBdd<Note>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("nt");}
};

// RestrictiontionModification
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Annee.
 */
template<> class InfoBdd<RestrictionModification> : public CibleSimpleNumUniqueInfoBdd<RestrictionModification>,
                                                    public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("am");}

    /*//! Retourne la table IdToCible.
    static QVector<int> idToCibleTable()
    {
            QVector<int> table(InfoEntity::NbrEntity);
            table[InfoEntity::AnneeId]=Cible<Annee>::value;
            table[InfoEntity::CibleCommentaireId]=Cible<CibleCommentaire>::value;
            table[InfoEntity::CibleDonneeId]=Cible<CibleDonnee>::value;
            table[InfoEntity::CibleMotCleId]=Cible<CibleMotCle>::value;
            table[InfoEntity::ClasseId]=Cible<Classe>::value;
            table[InfoEntity::ClasseEleveId]=Cible<ClasseEleve>::value;
            table[InfoEntity::CoefficientId]=Cible<Coefficient>::value;
            table[InfoEntity::CommentaireId]=Cible<Commentaire>::value;
            table[InfoEntity::ControleId]=Cible<Controle>::value;
            table[InfoEntity::DonneeId]=Cible<Donnee>::value;
            table[InfoEntity::DonneeCardId]=Cible<DonneeCard>::value;
            table[InfoEntity::EleveId]=Cible<Eleve>::value;
            table[InfoEntity::EtablissementId]=Cible<Etablissement>::value;
            table[InfoEntity::EtablissementNiveauId]=Cible<EtablissementNiveau>::value;
            table[InfoEntity::EtablissementTypeId]=Cible<EtablissementType>::value;
            table[InfoEntity::GroupeId]=Cible<Groupe>::value;
            table[InfoEntity::GroupeEleveId]=Cible<GroupeEleve>::value;
            table[InfoEntity::MotCleId]=Cible<MotCle>::value;
            table[InfoEntity::MotClePermissionId]=Cible<MotClePermission>::value;
            table[InfoEntity::NiveauId]=Cible<Niveau>::value;
            table[InfoEntity::NiveauPrecedentId]=Cible<NiveauPrecedent>::value;
            table[InfoEntity::NoteId]=Cible<Note>::value;
            table[InfoEntity::RestrictionModificationId]=Cible<RestrictionModification>::value;
            table[InfoEntity::SourceId]=Cible<Source>::value;
            table[InfoEntity::TypeControleId]=Cible<TypeControle>::value;
            table[InfoEntity::TypeEtablissementId]=Cible<TypeEtablissement>::value;
            table[InfoEntity::TypeNiveauId]=Cible<TypeNiveau>::value;
            return table;
    }*/
};

// Source
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Source.
 */
template<> class InfoBdd<Source> : public InfoBddBase<NomUniqueInfoBdd<Source>,NcInfoBdd<Source>,TypeInfoBdd<Source>>,
                                   public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("sr");}
};

//Texte
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité texte.
 */
template<> class InfoBdd<Texte> : public TexteUniqueInfoBdd<Texte>, public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tt");}
};

// TexteSource
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité NiveauPrecedent.
 */
template<> class InfoBdd<TexteSource> : public RelationInfoBdd<TexteSource>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("ts");}
};

// TypeControle
SINGLE_INFOBDD(Appreciation,Appreciation,app,Bool,true)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeControle.
 */
template<> class InfoBdd<TypeControle> : public InfoBddBase<NomUniqueInfoBdd<TypeControle>,
                                                            AppreciationInfoBdd<TypeControle>,
                                                            DecimaleInfoBdd<TypeControle>,
                                                            ModifInfoBdd<TypeControle>,
                                                            NcInfoBdd<TypeControle>,
                                                            ParentInfoBdd<TypeControle>,
                                                            TotalInfoBdd<TypeControle>,
                                                            TypeInfoBdd<TypeControle>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpctr");}
};

SINGLE_INFOBDD(Entete,Entete,ent,Text,false)
SINGLE_INFOBDD(Pied,Pied,pd,Text,false)

// TypeCours
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeCours.
 */
template<> class InfoBdd<TypeCours> : public InfoBddBase<Id1InfoBdd<TypeCours>,
                                                        Id2InfoBdd<TypeCours>,
                                                        Id3InfoBdd<TypeCours>,
                                                        ParentInfoBdd<TypeCours>,
                                                        IdProgNomUniqueInfoBdd<TypeCours>,
                                                        EnteteInfoBdd<TypeCours>,
                                                        PiedInfoBdd<TypeCours>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpcrs");}
};

// TypeEtablissement
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeEtablissement.
 */
template<> class InfoBdd<TypeEtablissement> : public InfoBddBase<NomUniqueInfoBdd<TypeEtablissement>,
                                                                 MaxInfoBdd<TypeEtablissement>,
                                                                 MinInfoBdd<TypeEtablissement>>,
                                              public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpetab");}
};

// TypeExercice
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeExercie.
 */
template<> class InfoBdd<TypeExercice> : public InfoBddBase<ParentInfoBdd<TypeExercice>,IdProgNomUniqueInfoBdd<TypeExercice>,NcInfoBdd<TypeExercice>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpex");}
};

// TypeNiveau
SINGLE_INFOBDD(AnBac,AnBac,an,Integer,true)

/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeNiveau.
 */
template<> class InfoBdd<TypeNiveau> : public InfoBddBase<NomUniqueInfoBdd<TypeNiveau>,AnBacInfoBdd<TypeNiveau>>,
                                       public NoKeyInfoBdd
{
public:
    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tpniv");}
};

// TypeUtilisation
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité TypeUtilisation.
 */
template<> class InfoBdd<TypeUtilisation> : public InfoBddBase<ParentInfoBdd<TypeUtilisation>,IdProgNomUniqueInfoBdd<TypeUtilisation>,NcInfoBdd<TypeUtilisation>>
{
public:
    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("tput");}
};

// Utilisation
/*! \ingroup groupeInfoBdd
 * \brief Classe contenant les informations sql sur l'entité Utilisation.
 */
template<> class InfoBdd<Utilisation> : public InfoBddBase<CibleDateTimeInfoBdd<Utilisation>,
                                                        NumInfoBdd<Utilisation>,
                                                        IdOrigineInfoBdd<Utilisation>,
                                                        OrigineInfoBdd<Utilisation>,
                                                        NomInfoBdd<Utilisation>>
{
public:
    typedef UtilisationUniqueSql EntUniqueSql;

    //! Retourne la liste des attributs uniques.
    static QVector<QMap<int,int>> attributUnique()
    {
        QVector<QMap<int,int>> att(2);
        att[0].insert(UtilisationUniqueSql::IdCibleUnique,Utilisation::IdCible);
        att[0].insert(UtilisationUniqueSql::IdOrigineUnique,Utilisation::IdOrigine);
        att[0].insert(UtilisationUniqueSql::CibleUnique,Utilisation::Cible);
        att[0].insert(UtilisationUniqueSql::OrigineUnique,Utilisation::Origine);
        att[0].insert(UtilisationUniqueSql::NumUnique,Utilisation::Num);
        att[1].insert(UtilisationUniqueSql::DateTimeUnique,Utilisation::DateTime);
        att[1].insert(UtilisationUniqueSql::NomUnique,Utilisation::Nom);
        return att;
    }

    //! Retourne les clés étrangère de la table sql.
    static QMap<int,QString> foreignKey();

    //! Retourne le nom la table sql.
    static QString table()
        {return QString("ut");}
};
#endif // INFOBDD_H
