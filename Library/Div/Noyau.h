/*Auteur: PERCIE DU SERT Maxime
 *Date: 01/02/2016
 */
#ifndef NOYAU_H
#define NOYAU_H

#include "Bdd.h"
#include "Config.h"
#include "../Dialog/NewAnneeDialog.h"
#include "../Dialog/NewClasseDialog.h"
#include "../Dialog/NewEtablissementDialog.h"
#include "../Dialog/SelectAnneeDialog.h"
#include "../Div/VectorPtr.h"
#include "../Fen/FenFoundFile.h"

/*! \defgroup groupeNoyau Fenêtre
 * \brief Ensemble de classes regroupant les différentes fenêtres de l'application.
 */

/*! \ingroup groupeNoyau
 * \brief Chemin XML du dossier par de l'application par default.
 */
#define DEFAULT_DIRECTORY "conf/directories/default"

/*! \ingroup groupeNoyau
 * \brief Chemin XML de la base de donnée.
 */
#define DATA_BASE "conf/files/databases/database"

/*! \ingroup groupeNoyau
 * \brief Chemin XML de l'année par default.
 */
#define DEFAULT_ANNEE "conf/parametre/initialisation/anneeDefaut"

class TabModule;
class TabAbstractModule;

/*! \ingroup groupeNoyau
 * \brief Noyau de l'application.
 *
 * Noyau de l'application:
 *  + Initialise l'application avec la fenêtre principale.
 *  + Affiche les classes de l'année en cours.
 */
class Noyau : public QObject
{
    Q_OBJECT
protected:
     Annee m_anneeDefaut;       //!< année de travail.
     Bdd m_bdd;                 //!< Gestionnaire de la Base de donnée.
     Config m_config;           //!< Gestionnaire de la configuration.
     QWidget * m_parent;        //!< Parent.
     TabModule *m_tabModule;    //!< Zone centrale.

public:
     //! Constructeur.
    Noyau(const QString &path, QWidget * parent);

    //! Renvoie un pointeur sur l'onglet actif.
    TabAbstractModule * activeTab() const;

    //! Renvoie l'année par defaut
    const Annee & annee()
        {return m_anneeDefaut;}

    //! Renvoie un pointeur sur le gestionnaire de configuration.
    Config * config()
        {return &m_config;}

    //! Renvoie un pointeur sur le gestionnaire de Base de donnée.
    Bdd * bdd()
        {return &m_bdd;}

    //! Renvoie un pointeur sur la zone centrale.
    QWidget * centralZone();

protected:
    /*! \brief Ouvre une fenêtre de dialogue demandant de selectionner une année.
     *
     * Ouvre une fenêtre de dialogue demandant de selectionner une année.
     * \param preSelect annee préselectionner dans la liste si présente.
     * \param annule creer un bouton permettant d'annuler.
     * \param creer creer un bouton creer pour creer une nouvelle année.
     * \param vide autorise à selectionner l'annee vide.
     */
    Annee selectAnnee(QWidget * parent, Annee preSelect = Annee(0,0) ,bool annule = true, bool creer = true, bool vide = true);

    //! Modifie l'année par défaut
    void setAnnee(const Annee & an);

public slots:
    //! Demande à l'onglet actif de coller.
    void coller();

    //! Demande à l'onglet actif de couper.
    void couper();

    //! Demande à l'onglet actif de copier.
    void copier();

    //! Ouvre une fenêtre de création d'année.
    void creerAnnee(QWidget *parent);

    //! Ouvre une fenêtre de création d'une classe.
    void creerClasse(QWidget * parent);

    //! Ouvre une fenêtre de création d'un établissement.
    void creerEtablissement(QWidget * parent, const QString &nc = QString(), const QString &nom = QString());

    //! Demande à l'onglet actif d'effacer.
    void effacer();

    //! Demande à l'onglet actif de sauvegarder.
    void save();

    //! Ouvre une fenêtre permettant de modifier l'année de travail.
    void selectDefaultAnnee(QWidget *parent);

signals:
    //! Signal d'activation/désactivation de l'action effacer.
    void effacerPermis(bool bb);

    //! Signal d'activation/désactivation de l'action coller.
    void collerPermis(bool bb);

    //! Signal d'activation/désactivation de l'action copier.
    void copierPermis(bool bb);

    //! Signal d'activation/désactivation de l'action couper.
    void couperPermis(bool bb);

    //! Signal d'activation/désactivation de l'action créer une classe.
    void creerClassePermis(bool bb);

    //! Signal d'activation/désactivation de l'action saugarder.
    void savePermis(bool bb);
};

#endif // NOYAU_H
