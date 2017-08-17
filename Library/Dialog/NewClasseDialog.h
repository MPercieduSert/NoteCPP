/*Auteur: PERCIE DU SERT Maxime
 *Date: 09/09/2016
 */
#ifndef NEWCLASSEDIALOG_H
#define NEWCLASSEDIALOG_H

#include <QCalendarWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QDialog>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <stdexcept>

#include "../Entities/Annee.h"
#include "../Entities/Classe.h"
#include "../Entities/InfoEntity.h"
#include "../Entities/Niveau.h"
#include "../Entities/EntityOfDefaultType.h"
#include "../Div/VectorPtr.h"
#include "../Widget/SpinBoxAnnee.h"
#include "../Widget/SpinBoxNumExclu.h"


/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'une classe.
 */
class NewClasseDialog : public QDialog
{
    Q_OBJECT
public:
    //! Structure de réponse de la fenêtre de dialogue.
    struct dialogResult
    {
        //!< Type du résultat autre que accepter et annuler (transmis par l'identifiant de la classe)
        enum {CreerEtab = -1};
        Classe classe;  //!< Classe à créer.
        QDate entree;   //!< Date d'entree des éléves dans la classe.
        int nbrEleve;   //!< Nombre d'éléves de la classe.
    };

protected:
    // Donnée
    Annee m_annee;                                      //!< Année de la classe à créer.
    VectorPtr<Classe> m_classes;                        //!< Ensemble des classes existante pour cette année.
    bool m_creerEtab;                                   //!< Permet d'indiquer dans la réponse s'il faut créer un établissement.
    VectorPtr<Etablissement> m_etabs;                   //!< Liste des établissements.
    VectorPtr<EtablissementNiveau> m_etabNiveaux;       //!< Correspondance entre les établissements et les niveaux présent dans ces derniers.
    VectorPtr<Niveau> m_niveaux;                        //!< Liste des niveaux.

    // Label
    QLabel *m_anneeLabel;       //!< Affichage de l'année.
    QLabel *m_entreeLabel;      //!< Label de la date d'entrée des éléves dans la classe.
    QLabel *m_nameLabel;        //!< Label du nom de la classe.
    QLabel *m_nbrEleveLabel;    //!< Label du choix du nombre d'éléves.
    //QLabel *m_nbrPhaseLabel;  //!< Label du choix du nombre de phase dans l'année.
    QLabel *m_niveauLabel;      //!< Label du chhoix du niveau de la classe.
    QLabel *m_numLabel;         //!< Label du choix du numéro de la classe.
    //QLabel *m_colleLabel;     //!< Label du choix de la présence de colle.

    QDateEdit *m_entreeDate;  //!< Selectionne une date d'entrée des élèves.
    QLineEdit *m_nameLine;      //!< Champ du nom de la classe.
    //QCheckBox *m_colleCheckBox;   //!< Choix de la présence de colle.
    QSpinBox *m_nbrEleveSpinBox;    //!< Choix du nombre d'éléves.
    //QSpinBox * m_nbrPhaseSpinBox; //!< Choix du nombre de phases.
    QComboBox *m_etabComboBox;      //!< Choix d'établissement de la classe.
    QComboBox *m_niveauComboBox;    //!< Choix du niveau de la classe.
    SpinBoxNumExclu *m_numSpinBox; //!< Choix du numéro de la classe.

    // Bouton
    QPushButton *m_cancelBouton;    //!< Bouton d'annulation.
    QPushButton *m_creerBouton;     //!< Bouton de création de la classe.
    QPushButton *m_creerEtabBouton; //!< Bouton de création d'un établissement

    // Layout
    QGroupBox *m_groupePara;        //!< Groupe des paramètre de la classe.
    QGroupBox *m_groupeEtab;        //!< Groupe du choix de l'établissement.
    QHBoxLayout *m_hLayoutButton;   //!< Calque des boutons de création et d'annulation.
    QHBoxLayout *m_hLayoutEtab;     //!< Calque du choix de l'établissement.
    QGridLayout *m_gridLayout;      //!< Calque des paramètres de la classe.
    QVBoxLayout *m_vLayout;         //!< Calque Principal.

public:
    //! Constructeur.
    explicit NewClasseDialog(const Annee &annee, VectorPtr<Etablissement> etabs,
                             VectorPtr<EtablissementNiveau> etabNiveaux, VectorPtr<Niveau> niveaux,
                             VectorPtr<Classe> classes, QWidget *parent = 0);
    //! Destructeur.
    ~NewClasseDialog()  {}

    //! Retourne le résultat de la fenêtre de dialogue.
    dialogResult value() const;
signals:

public slots:
    //! Action lorsque l'on clique sur m_creerBouton.
    void creerEtab();
    //! Actualise les niveaux disponible lorsqu'un établissement est séléctionné.
    void etabChange(int n);
    //! Actualise le nom de la classe lorsqu'un numéro est séléctionné.
    void nameUpdate(int num);
    //! Actualise les numéros disponible pour la classe lorsqu'un niveau est séléctionné.
    void niveauChange(int n);
};

#endif // NEWCLASSEDIALOG_H
