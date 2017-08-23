#include "Managers.h"

Managers::Managers(const QSqlQuery & req)
    : AbstractManagers(req),
      m_CoefficientGestion(Cible<Coefficient>::value),
      m_DonneeGestion(Cible<Donnee>::value),
      m_DonneeCardGestion(Cible<DonneeCard>::value),
      m_MotCleGestion(Cible<MotCle>::value),
      m_MotClePermissionGestion(Cible<MotClePermission>::value),
      m_NiveauGestion(Cible<Niveau>::value),
      m_NiveauPrecedentGestion(Cible<NiveauPrecedent>::value),
      m_TypeControleGestion(Cible<TypeControle>::value),
      m_TypeCoursGestion(Cible<TypeCours>::value),
      m_TypeEtablissementGestion(Cible<TypeEtablissement>::value),
      m_TypeExerciceGestion(Cible<TypeExercice>::value),
      m_TypeNiveauGestion(Cible<TypeNiveau>::value),
      m_TypeUtilisationGestion(Cible<TypeUtilisation>::value)
{
    MANAGER_TAB(Annee)
    MANAGER_TAB(CibleCommentaire)
    MANAGER_TAB(CibleDonnee)
    MANAGER_TAB(CibleMotCle)
    MANAGER_TAB(CibleTexte)
    MANAGER_TAB(Classe)
    MANAGER_TAB(ClasseEleve)
    MANAGER_TAB(Coefficient)
    MANAGER_TAB(Commentaire)
    MANAGER_TAB(Controle)
    MANAGER_TAB(Cours)
    MANAGER_TAB(Donnee)
    MANAGER_TAB(DonneeCard)
    MANAGER_TAB(Eleve)
    MANAGER_TAB(Etablissement)
    MANAGER_TAB(EtablissementNiveau)
    MANAGER_TAB(EtablissementType)
    MANAGER_TAB(Exercice)
    MANAGER_TAB(Forme)
    MANAGER_TAB(Groupe)
    MANAGER_TAB(GroupeEleve)
    MANAGER_TAB(MotCle)
    MANAGER_TAB(MotClePermission)
    MANAGER_TAB(Niveau)
    MANAGER_TAB(NiveauPrecedent)
    MANAGER_TAB(Note)
    MANAGER_TAB(RestrictionModification)
    MANAGER_TAB(Source)
    MANAGER_TAB(Texte)
    MANAGER_TAB(TexteSource)
    MANAGER_TAB(TypeControle)
    MANAGER_TAB(TypeCours)
    MANAGER_TAB(TypeEtablissement)
    MANAGER_TAB(TypeExercice)
    MANAGER_TAB(TypeNiveau)
    MANAGER_TAB(TypeUtilisation)
    MANAGER_TAB(Utilisation)

    m_CoefficientGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_DonneeGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_DonneeCardGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_MotCleGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_MotClePermissionGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_NiveauGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_NiveauPrecedentGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_TypeControleGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_TypeCoursGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_TypeEtablissementGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_TypeExerciceGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_TypeNiveauGestion.setManagerRestriction(&m_RestrictionModificationManager);
    m_TypeUtilisationGestion.setManagerRestriction(&m_RestrictionModificationManager);

    m_CoefficientManager.setGestionAutorisation(&m_CoefficientGestion);
    m_DonneeManager.setGestionAutorisation(&m_DonneeGestion);
    m_DonneeCardManager.setGestionAutorisation(&m_DonneeCardGestion);
    m_MotCleManager.setGestionAutorisation(&m_MotCleGestion);
    m_MotClePermissionManager.setGestionAutorisation(&m_MotClePermissionGestion);
    m_NiveauManager.setGestionAutorisation(&m_NiveauGestion);
    m_NiveauPrecedentManager.setGestionAutorisation(&m_NiveauPrecedentGestion);
    m_TypeControleManager.setGestionAutorisation(&m_TypeControleGestion);
    m_TypeCoursManager.setGestionAutorisation(&m_TypeCoursGestion);
    m_TypeEtablissementManager.setGestionAutorisation(&m_TypeEtablissementGestion);
    m_TypeExerciceManager.setGestionAutorisation(&m_TypeExerciceGestion);
    m_TypeNiveauManager.setGestionAutorisation(&m_TypeNiveauGestion);
    m_TypeUtilisationManager.setGestionAutorisation(&m_TypeUtilisationGestion);

    setRequete(m_requete, true);
}
