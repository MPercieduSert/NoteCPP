/*Auteur: PERCIE DU SERT Maxime
 *Date: 18/05/2016
 */
#ifndef ABSTRACTBDD_H
#define ABSTRACTBDD_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <stdexcept>

#include "FileInterface.h"
#include "Managers.h"

/*! \ingroup groupeFile
 *  \brief Classe mère du gestionnaire de base de donnée.
 *
 * Gestionnaire de la base donnée sous SQLite3. Cette classe fait le lien entre la base de donnée et les Entity grâce aux Manager.
 */
class AbstractBdd : public FileInterface
{
protected:
    QSqlDatabase m_bdd;                 //! Connexion à la base de donnée.
    Managers m_manager;                 //! Manager des entités.

public:
    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    AbstractBdd(const QString & dbtype = "", const QString & fileName = "");

    //! Destructeur. Referme la base de donnée.
    ~AbstractBdd();

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
    template<class Ent> bool exists(const Ent & entity);

    //! Teste s'il existe une entité ayant les mêmes valeurs d'attributs uniques que entity en base de donnée.
    template<class Ent> bool existsUnique(Ent & entity);

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrées en base de donnée
    //! ayant le même identifiant que entity.
    //! Retourne True si l'opération s'est correctement déroulée.
    template<class Ent> bool get(Ent & entity);

    //! Renvoie la liste des entités de la table d'identifiant idEntity ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListEntities<Ent> getList(int ordre = Info<Ent>::IdPos);

    //! Renvoie la liste des entités de la table d'identifiant idEntity vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListEntities<Ent> getList(int cle, const QVariant & value, int order = Info<Ent>::IdPos);

    //! Renvoie la liste des entités de la table d'identifiant idEntity vérifiant la condition,
    //! valeur de la colonne d'identifiant cle = value, ordonnée suivant les colonnes d'identifiant ordre1 puis ordre2.
    template<class Ent> ListEntities<Ent> getList(int cle, const QVariant & value, int order1, int order2);

    //! Renvoie la liste des entités de la table d'identifiant idEntity vérifiant les deux conditions,
    //! valeur de la colonne d'identifiant cle1 = value1 et valeur de la colonne d'identifiant cle2 = value2,
    //! ordonnée suivant la colonne d'identifiant ordre.
    template<class Ent> ListEntities<Ent> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int order = Info<Ent>::IdPos);

    //! Hydrate l'entité entity avec les valeurs des attributs de l'entité enregistrées en base de donnée
    //! ayant les mêmes valeurs uniques.
    //! Retourne True si l'opération s'est correctement déroulée.
    template<class Ent> bool getUnique(Ent & entity);

    //! Teste si la base de donnée est valide.
    bool isValid()
        {return true;}

    //! Ouvre la base de donnée.
    bool open()
    {
        bool bb = m_bdd.open();
        if(bb)
            setBdd();
        return bb;
    }

    //! Enregistre l'entity dans la base de donnée.
    template<class Ent> void save(Ent & entity);

    //! Transmet la connexion à la base de donnée aux managers.
    void setBdd();

    //! Modifie le chemin de la base de donnée.
    void setFileName(const QString & fileName);
};

template<class Ent> bool AbstractBdd::exists(const Ent & entity)
{
    if(entity.isNew())
    {
        return false;
    }
    else
    {
        return m_manager.get<Ent>().exists(entity);
    }
}

template<class Ent> bool AbstractBdd::existsUnique(Ent & entity)
    { return m_manager.get<Ent>().existsUnique(entity);}

template<class Ent> bool AbstractBdd::get(Ent & entity)
    { return m_manager.get<Ent>().get(entity);}

template<class Ent> ListEntities<Ent> AbstractBdd::getList(int ordre)
    { return m_manager.get<Ent>().getList(ordre);}

template<class Ent> ListEntities<Ent> AbstractBdd::getList(int cle, const QVariant & value, int order)
    { return m_manager.get<Ent>().getList(cle, value, order);}

template<class Ent> ListEntities<Ent> AbstractBdd::getList(int cle, const QVariant & value, int order1, int order2)
    { return m_manager.get<Ent>().getList(cle, value, order1, order2);}

template<class Ent> ListEntities<Ent> AbstractBdd::getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int order)
    { return m_manager.get<Ent>().getList(cle1, cle2, value1, value2, order);}

template<class Ent> bool AbstractBdd::getUnique(Ent & entity)
    { return m_manager.get<Ent>().getUnique(entity);}

template<class Ent> void AbstractBdd::save(Ent & entity)
    { return m_manager.get<Ent>().save(entity);}
#endif // ABSTRACTBDD_H
