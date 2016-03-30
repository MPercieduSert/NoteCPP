/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */

/*! \ingroup groupeFile
 * \brief Gestionnaire de la base de donnée.
 *
 * Gestionnaire de la base donnée sous SQLite3. Cette classe fait le lien entre la base de donnée et les Entity grâce aux Manager.
 */

#ifndef BDD_H
#define BDD_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <stdexcept>
#include "FileInterface.h"
#include "../Entities/Annee.h"
#include "../Entities/Entity.h"
#include "../Manager/AnneeManager.h"
#include "../Manager/ArbresManager.h"
#include "../Manager/AttributManager.h"
#include "../Manager/ClasseEleveManager.h"
#include "../Manager/ClasseManager.h"
#include "../Manager/CommentaireManager.h"
#include "../Manager/DonneeManager.h"
#include "../Manager/EleveManager.h"
#include "../Manager/EtablissementManager.h"
#include "../Manager/GroupeManager.h"
#include "../Manager/NiveauManager.h"
#include "../Manager/RelationsManager.h"
#include "../Manager/SourceManager.h"
#include "../Manager/TypeNiveauManager.h"

class Bdd : public FileInterface
{
public:
    static const int NbrEntity = InfoEntity::NbrEntity;//! Nombre de type d'entity à gérer

protected:
    QSqlDatabase m_bdd;                 //! Connexion à la base de donnée.
    QSqlQuery m_requete;                //! Requéte commune aux manageurs.
    Manager * m_managers[NbrEntity];    //! Tableau des manageurs.

    AttributArbreManager m_attributArbreManager;
    CoursArbreManager m_coursArbreManager;
    DonneeArbreManager m_donneeArbreManager;
    EnonceArbreManager m_enonceArbreManager;
    ExerciceArbreManager m_exerciceArbreManager;
    AnneeManager m_anneeManager;
    AttributManager m_attributManager;
    AttributCommentaireManager m_attributCommentaireManager;
    ClasseManager m_classeManager;
    ClasseEleveManager m_classeEleveManager;
    CommentaireManager m_commentaireManager;
    CommentaireClasseManager m_commentaireClasseManager;
    CommentaireEleveManager m_commentaireEleveManager;
    CommentaireGroupeManager m_commentaireGroupeManager;
    DonneeManager m_donneeManager;
    DonneeClasseManager m_donneeClasseManager;
    DonneeEleveManager m_donneeEleveManager;
    DonneeEtablissementManager m_donneeEtablissementManager;
    DonneeNiveauManager m_donneeNiveauManager;
    DonneeSourceManager m_donneeSourceManager;
    EleveManager m_eleveManager;
    EtablissementManager m_etablissementManager;
    EtablissementNiveauManager m_etablissementNiveauManager;
    GroupeManager m_groupeManager;
    GroupeEleveManager m_groupeEleveManager;
    NiveauManager m_niveauManager;
    NiveauPrecedentManager m_niveauPrecedentManager;
    SourceManager m_sourceManager;
    TypeNiveauManager m_typeNiveauManager;

public:
    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    Bdd(const QString & dbtype ="",const QString & fileName = "");

    //! Destructeur. Referme la base de donnée.
    ~Bdd();

    //! Affiche un QMessageBox signalant si la dernière requète contient une erreur.
    void affError(const QSqlQuery & query) const;

    //! Retourne le nom de la classe.
    QString afficheClasse(const Classe & classe, Classe::affichage alpha = Classe::Numeric);

    /*//! Retourne le nom de la classe d'identifiant idClasse.
    QString afficheClasse(int idClasse);//, Niveau::affiche_alpha alpha = Niveau::Numeric);*/

    //! Vérifie si le fichier de chemin name existe et est un fichier de base de donnée valide, si c'est le cas,
    //! le fichier de la base de donnée est remplacé par une copie du fichier de chemin name.
    bool copy(const QString & name);

    //! Créer la base de donnée avec les tables et les entrées par défault.
    bool creer();

    //! Renvoie une réfrence sur la base de donnée.
    QSqlDatabase &db()
        {return m_bdd;}

    //! Teste si le fichier de base de donnée existe.
    bool exists() const
        {return QFile::exists(m_fileName);}

    //! Teste s'il existe une entité de même identifiant que entity en base de donnée.
    bool exists(const Entity & entity)
    {
        if(entity.isNew())
        {
            return false;
        }
        else
        {
            return getManager(entity.idEntity())->exists(entity);
        }
    }

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    bool existsUnique(Entity & entity)
        {return getManager(entity.idEntity())->existsUnique(entity);}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrées en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Entity & entity)
        {return getManager(entity.idEntity())->get(entity);}

    //! Renvoie la liste des entités de la table d'identifiant idEntity ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(int idEntity, int ordre)
        {return getManager(idEntity)->getList(ordre);}

    //! Renvoie la liste des entités de la table d'identifiant idEntity vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(int idEntity, int cle, const QVariant & value, int order)
        {return getManager(idEntity)->getList(cle, value, order);}

    //! Renvoie la liste des entités de la table d'identifiant idEntity vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    ListEntities<Entity> getList(int idEntity, int cle, const QVariant & value, int order1, int order2)
        {return getManager(idEntity)->getList(cle, value, order1, order2);}

    //! Renvoie la liste des entités de la table d'identifiant idEntity vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(int idEntity, int cle1, int cle2, const QVariant & value1, const QVariant & value2, int order)
        {return getManager(idEntity)->getList(cle1, cle2, value1, value2, order);}

    //! Renvoie un pointeur sur le manager d'identifiant idEntity.
    Manager * getManager(int idEntity)
        {return m_managers[idEntity];}

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrées en base de donnée
    //! ayant les mêmes valeurs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool getUnique(Entity & entity)
        {return getManager(entity.idEntity())->getUnique(entity);}

    //! Teste si la base de donnée est valide.
    bool isValid()
        {return true;}

    //Manager * newManager(Entity::entityId idEntity);

    //! Ouvre la base de donnée.
    bool open()
    {
        bool bb = m_bdd.open();
        setBdd();
        return bb;
    }

    //! Enregistre l'entity dans la base de donnée.
    void save(Entity & entity)
        {return getManager(entity.idEntity())->save(entity);}

    //! Enregistre l'entity dans la base de donnée.
    void save(const Entity & entity)
        {return getManager(entity.idEntity())->save(entity);}

    //! Transmet la connexion à la base de donnée aux managers.
    void setBdd();

    //! Modifie le chemin de la base de donnée.
    void setFileName(const QString & fileName);
};

#endif // BDD_H
