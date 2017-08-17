/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/05/2016
 */
#ifndef MANAGERS_H
#define MANAGERS_H

#include <type_traits>
#include "AbstractManagers.h"
#include "../Manager/GestionAutorisationCible.h"

/*! \ingroup groupeFile
 *  \brief Cette classe contient les managers des entités pour la base de donnée.
 */
class Managers : public AbstractManagers
{
protected:
    ManagerOf<Annee> m_AnneeManager;
    ManagerOf<CibleCommentaire> m_CibleCommentaireManager;
    ManagerOf<CibleDonnee> m_CibleDonneeManager;
    ManagerOf<CibleMotCle> m_CibleMotCleManager;
    ManagerOf<Classe> m_ClasseManager;
    ManagerOf<ClasseEleve> m_ClasseEleveManager;
    ManagerOf<Coefficient> m_CoefficientManager;
    ManagerOf<Commentaire> m_CommentaireManager;
    ManagerOf<Controle> m_ControleManager;
    ManagerOf<Donnee> m_DonneeManager;
    ManagerOf<DonneeCard> m_DonneeCardManager;
    ManagerOf<Eleve> m_EleveManager;
    ManagerOf<Etablissement> m_EtablissementManager;
    ManagerOf<EtablissementNiveau> m_EtablissementNiveauManager;
    ManagerOf<EtablissementType> m_EtablissementTypeManager;
    ManagerOf<Groupe> m_GroupeManager;
    ManagerOf<GroupeEleve> m_GroupeEleveManager;
    ManagerOf<MotCle> m_MotCleManager;
    ManagerOf<MotClePermission> m_MotClePermissionManager;
    ManagerOf<Niveau> m_NiveauManager;
    ManagerOf<NiveauPrecedent> m_NiveauPrecedentManager;
    ManagerOf<Note> m_NoteManager;
    ManagerOf<RestrictionModification> m_RestrictionModificationManager;
    ManagerOf<Source> m_SourceManager;
    ManagerOf<TypeControle> m_TypeControleManager;
    ManagerOf<TypeEtablissement> m_TypeEtablissementManager;
    ManagerOf<TypeNiveau> m_TypeNiveauManager;

    GestionAutorisationCible<Coefficient,RestrictionModification> m_CoefficientGestion;
    GestionAutorisationCible<Donnee,RestrictionModification> m_DonneeGestion;
    GestionAutorisationCible<DonneeCard,RestrictionModification> m_DonneeCardGestion;
    GestionAutorisationCible<MotCle,RestrictionModification> m_MotCleGestion;
    GestionAutorisationCible<MotClePermission,RestrictionModification> m_MotClePermissionGestion;
    GestionAutorisationCible<Niveau,RestrictionModification> m_NiveauGestion;
    GestionAutorisationCible<NiveauPrecedent,RestrictionModification> m_NiveauPrecedentGestion;
    GestionAutorisationCible<TypeControle,RestrictionModification> m_TypeControleGestion;
    GestionAutorisationCible<TypeEtablissement,RestrictionModification> m_TypeEtablissementGestion;
    GestionAutorisationCible<TypeNiveau,RestrictionModification> m_TypeNiveauGestion;

public:
    using AbstractManagers::get;

    //! Constructeur.
    Managers(const QSqlQuery & req = QSqlQuery());

    //! Méthode template permettant d'obtenir le manager correspondant à l'entité.
    template<class Ent> ManagerOf<Ent> & get();
};

DEF_GET_MANAGER(Annee)
DEF_GET_MANAGER(CibleCommentaire)
DEF_GET_MANAGER(CibleDonnee)
DEF_GET_MANAGER(CibleMotCle)
DEF_GET_MANAGER(Classe)
DEF_GET_MANAGER(ClasseEleve)
DEF_GET_MANAGER(Coefficient)
DEF_GET_MANAGER(Commentaire)
DEF_GET_MANAGER(Controle)
DEF_GET_MANAGER(Donnee)
DEF_GET_MANAGER(DonneeCard)
DEF_GET_MANAGER(Eleve)
DEF_GET_MANAGER(Etablissement)
DEF_GET_MANAGER(EtablissementNiveau)
DEF_GET_MANAGER(EtablissementType)
DEF_GET_MANAGER(Groupe)
DEF_GET_MANAGER(GroupeEleve)
DEF_GET_MANAGER(MotCle)
DEF_GET_MANAGER(MotClePermission)
DEF_GET_MANAGER(Niveau)
DEF_GET_MANAGER(NiveauPrecedent)
DEF_GET_MANAGER(Note)
DEF_GET_MANAGER(RestrictionModification)
DEF_GET_MANAGER(Source)
DEF_GET_MANAGER(TypeControle)
DEF_GET_MANAGER(TypeEtablissement)
DEF_GET_MANAGER(TypeNiveau)

#endif // MANAGERS_H
