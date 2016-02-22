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
#include "../Manager/AppreciationManager.h"
#include "../Manager/AttributManager.h"
#include "../Manager/Attribut_baremeManager.h"
#include "../Manager/Attribut_exerciceManager.h"
#include "../Manager/BaremeManager.h"
#include "../Manager/ClasseManager.h"
#include "../Manager/CommentaireManager.h"
#include "../Manager/CoefficientManager.h"
#include "../Manager/ControleManager.h"
#include "../Manager/Controle_exerciceManager.h"
#include "../Manager/EleveManager.h"
#include "../Manager/Eleve_groupeManager.h"
#include "../Manager/ExerciceManager.h"
#include "../Manager/GroupeManager.h"
#include "../Manager/NoteManager.h"
#include "../Manager/NumControleManager.h"
#include "../Manager/NiveauManager.h"
#include "../Manager/Manager.h"
#include "../Manager/PointManager.h"
#include "../Manager/SourceManager.h"
#include "../Manager/TypeControleManager.h"
#include "../Manager/TypeGroupeManager.h"
#include "../Manager/TypeNiveauManager.h"

class Bdd : public FileInterface
{
protected:
    static const int m_nbrEntity = 23;//! Nombre de type d'entity à gérer
    QSqlDatabase m_bdd;//! Connexion à la base de donnée.
    Manager * m_managers[m_nbrEntity];//! Tableau des managers.

    AnneeManager m_anneeManager;
    AppreciationManager m_appreciationManager;
    AttributManager m_attributManager;
    Attribut_baremeManager m_attribut_baremeManager;
    Attribut_exerciceManager m_attribut_exerciceManager;
    BaremeManager m_baremeManager;
    ClasseManager m_classeManager;
    CoefficientManager m_coefficientManager;
    CommentaireManager m_commentaireManager;
    ControleManager m_controleManager;
    Controle_exerciceManager m_controle_exerciceManager;
    EleveManager m_eleveManager;
    Eleve_groupeManager m_eleve_groupeManager;
    ExerciceManager m_exerciceManager;
    GroupeManager m_groupeManager;
    NoteManager m_noteManager;
    NumControleManager m_numControleManager;
    NiveauManager m_niveauManager;
    PointManager m_pointManager;
    SourceManager m_sourceManager;
    TypeControleManager m_typeControleManager;
    TypeGroupeManager m_typeGroupeManager;
    TypeNiveauManager m_typeNiveauManager;

public:
    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    Bdd(const QString & dbtype ="",const QString & fileName = "");

    //! Destructeur. Referme la base de donnée.
    ~Bdd();

    //! Affiche un QMessageBox signalant si la dernière requète contient une erreur.
    void affError(const QSqlQuery & query) const;

    //! Retourne le nom de la classe.
    QString afficheClasse(const Classe & classe);//, Niveau::affiche_alpha alpha = Niveau::Numeric);

    //! Retourne le nom de la classe d'identifiant idClasse.
    QString afficheClasse(int idClasse);//, Niveau::affiche_alpha alpha = Niveau::Numeric);

    //! Vérifie si le fichier de chemin name existe et est un fichier de base de donnée valide, si c'est le cas,
    //! le fichier de la base de donnée est remplacé par une copie du fichier de chemin name.
    bool copy(const QString & name);

    //! Créer la base de donnée avec les tables et les entrées par défault.
    bool creer();

    //bool creerAnnee(Annee & annee);

    //! Renvoie une réfrence sur la base de donnée.
    QSqlDatabase &db() const
        {return m_bdd;}

    //! Teste si le fichier de base de donnée existe.
    bool exists() const
        {return QFile::exists(m_fileName);}

    //! Teste si entity existe en base de donnée.
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

    //! Teste s'il existe déjà une entity avec les valeurs uniques en base de donnée.
    bool existsUnique(Entity & entity)
        {return getManager(entity.idEntity())->existsUnique(entity);}

    //! Remplit entity avec les valeurs enregistrées en base de donnée dans l'entity de même identifiant.
    //! Retourne True si l'opération s'est correctement déroulée.
    bool get(Entity & entity)
        {return getManager(entity.idEntity())->get(entity);}

    //! Renvoie la liste des entity de la table d'identtifiant idEntity ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(Entity::entityId idEntity, int ordre = Entity::position::IdPos)
        {return getManager(idEntity)->getList(ordre);}

    //! Renvoie la liste des entity de la table d'identtifiant idEntity vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(Entity::entityId idEntity, int cle, const QVariant & value, int order = Entity::position::IdPos)
        {return getManager(idEntity)->getList(cle, value, order);}

    //! Renvoie la liste des entity de la table d'identtifiant idEntity vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    ListEntities<Entity> getList(Entity::entityId idEntity, int cle, const QVariant & value, int order1, int order2)
        {return getManager(idEntity)->getList(cle, value, order1, order2);}

    //! Renvoie la liste des entity de la table d'identtifiant idEntity vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    ListEntities<Entity> getList(Entity::entityId idEntity, int cle1, int cle2, const QVariant & value1, const QVariant & value2, int order = Entity::position::IdPos)
        {return getManager(idEntity)->getList(cle1, cle2, value1, value2, order);}

    //! Renvoie un pointeur sur le manager d'identifiant idEntity.
    Manager * getManager(Entity::entityId idEntity)
        {return m_managers[idEntity];}

    //! Remplit entity avec les valeurs enregistrées en base de donnée dans l'entity de même valeur unique.
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
        return m_bdd.open();
    }

    //! Enregistre l'entity dans la base de donnée.
    bool save(Entity & entity)
    {
        return getManager(entity.idEntity())->save(entity);
    }

    //! Enregistre l'entity dans la base de donnée.
    bool save(const Entity & entity)
    {
        return getManager(entity.idEntity())->save(entity);
    }

    //void setAnnee(const Annee & annee);

    //! Transmet la connexion à la base de donnée aux managers.
    void setBdd();

    //! Modifie le chemin de la base de donnée.
    void setFileName(const QString & fileName);
};

#endif // BDD_H
