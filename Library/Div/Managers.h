/*Auteur: PERCIE DU SERT Maxime
 *Date: 10/05/2016
 */
#ifndef MANAGERS_H
#define MANAGERS_H

#include "AbstractManagers.h"

/*! \ingroup groupeFile
 *  \brief Cette classe contient les managers des entités pour la base de donnée.
 */
class Managers : public AbstractManagers
{
protected:
    ManagerOf<Annee> m_AnneeManager;
    ManagerOf<Attribut> m_AttributManager;
    ManagerOf<AttributArbre> m_AttributArbreManager;
    ManagerOf<AttributCommentaire> m_AttributCommentaireManager;    
    ManagerOf<Classe> m_ClasseManager;
    ManagerOf<ClasseEleve> m_ClasseEleveManager;
    ManagerOf<Commentaire> m_CommentaireManager;
    ManagerOf<CommentaireClasse> m_CommentaireClasseManager;
    ManagerOf<CommentaireEleve> m_CommentaireEleveManager;
    ManagerOf<CommentaireGroupe> m_CommentaireGroupeManager;
    ManagerOf<CoursArbre> m_CoursArbreManager;
    ManagerOf<Donnee> m_DonneeManager;
    ManagerOf<DonneeArbre> m_DonneeArbreManager;
    ManagerOf<DonneeClasse> m_DonneeClasseManager;
    ManagerOf<DonneeEleve> m_DonneeEleveManager;
    ManagerOf<DonneeEtablissement> m_DonneeEtablissementManager;
    ManagerOf<DonneeNiveau> m_DonneeNiveauManager;
    ManagerOf<DonneeSource> m_DonneeSourceManager;
    ManagerOf<Eleve> m_EleveManager;
    ManagerOf<EnonceArbre> m_EnonceArbreManager;
    ManagerOf<Etablissement> m_EtablissementManager;
    ManagerOf<EtablissementType> m_EtablissementTypeManager;
    ManagerOf<EtablissementNiveau> m_EtablissementNiveauManager;
    ManagerOf<ExerciceArbre> m_ExerciceArbreManager;
    ManagerOf<Groupe> m_GroupeManager;
    ManagerOf<GroupeEleve> m_GroupeEleveManager;
    ManagerOf<Niveau> m_NiveauManager;
    ManagerOf<NiveauPrecedent> m_NiveauPrecedentManager;
    ManagerOf<Source> m_SourceManager;
    ManagerOf<TypeEtablissement> m_TypeEtablissementManager;
    ManagerOf<TypeNiveau> m_TypeNiveauManager;


public:
    using AbstractManagers::get;

    Managers(const QSqlQuery & req = QSqlQuery());

    template<class Ent> ManagerOf<Ent> & get();
};

DEF_GET_MANAGER(Annee)
DEF_GET_MANAGER(Attribut)
DEF_GET_MANAGER(AttributArbre)
DEF_GET_MANAGER(AttributCommentaire)
DEF_GET_MANAGER(Classe)
DEF_GET_MANAGER(ClasseEleve)
DEF_GET_MANAGER(Commentaire)
DEF_GET_MANAGER(CommentaireClasse)
DEF_GET_MANAGER(CommentaireEleve)
DEF_GET_MANAGER(CommentaireGroupe)
DEF_GET_MANAGER(CoursArbre)
DEF_GET_MANAGER(Donnee)
DEF_GET_MANAGER(DonneeArbre)
DEF_GET_MANAGER(DonneeClasse)
DEF_GET_MANAGER(DonneeEleve)
DEF_GET_MANAGER(DonneeEtablissement)
DEF_GET_MANAGER(DonneeNiveau)
DEF_GET_MANAGER(DonneeSource)
DEF_GET_MANAGER(Eleve)
DEF_GET_MANAGER(EnonceArbre)
DEF_GET_MANAGER(Etablissement)
DEF_GET_MANAGER(EtablissementNiveau)
DEF_GET_MANAGER(EtablissementType)
DEF_GET_MANAGER(ExerciceArbre)
DEF_GET_MANAGER(Groupe)
DEF_GET_MANAGER(GroupeEleve)
DEF_GET_MANAGER(Niveau)
DEF_GET_MANAGER(NiveauPrecedent)
DEF_GET_MANAGER(Source)
DEF_GET_MANAGER(TypeEtablissement)
DEF_GET_MANAGER(TypeNiveau)

#endif // MANAGERS_H
