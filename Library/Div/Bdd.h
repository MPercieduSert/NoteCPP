/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */
#ifndef BDD_H
#define BDD_H

#include "AbstractBdd.h"

namespace bdd {
    //! Enumération des mise-à-jour de la base de donnée.
    enum miseAJourBdd{
        creationInitial = creationBdd::initiale,
        Donnees20170816,
        endMiseAJour
    };

    //! Enumération des types d'établissement.
    enum typeEtablissement { Primaire = 1,
                             College,
                             LyceeGeneral,
                             LyceePro,
                             Prepa,
                             Universite,
                             Iut,
                             EcoleInge
    };

    enum commentaireNum {AppreciationNum = 0};

    enum motClePermissionNum {InterditMCNum = 0,
                              PermisMCNum = 1};
}

/*! \ingroup groupeFile
 * \brief Gestionnaire de la base de donnée.
 */
class Bdd : public AbstractBdd
{
public:
    //static const int version_bdd = 100;
    //static const int version_bdd_creer = 100;

    //! Constructeur. Donner en argument le type ainsi que le chemin de la base de donnée.
    Bdd(const QString & dbtype = "", const QString & fileName = "")
        : AbstractBdd(dbtype,fileName,bdd::miseAJourBdd::endMiseAJour-1)
    {}

    //! Destructeur. Referme la base de donnée.
    ~Bdd()
        {}

    //! Supprime l'entité entity de la base de donnée et met l'identifiant de l'entité à zéro.
    template<class Ent> bool del(Ent & entity);

    //! Supprime l'entité entity de la base de donnée.
    template<class Ent> bool del(const Ent & entity);

    //! Renvoie l'identifiant de la donnée d'idProg fourni
    int idDonnee(typename Donnee::prog idP);

protected:
    //! Mise à jour de la base de donnée.
    void listeMiseAJourBdd(int version);

    DECL_DEL_METHODE

    /*//! Méthode de suppression pour les motClé.
    template<> bool del(MotCle & entity);

    //! Méthode de suppression pour les motClé.
    template<> bool del(const MotCle & entity);*/
};

DEF_DEL_METHODE

template<class Ent> bool Bdd::del(Ent & entity)
    {return AbstractBdd::del(entity);}

template<class Ent> bool Bdd::del(const Ent & entity)
    {return AbstractBdd::del(entity);}
#endif // BDD_H

