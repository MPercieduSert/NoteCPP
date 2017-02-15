/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/06/2016
 */
#ifndef NEWETABLISSEMENTDIALOG_H
#define NEWETABLISSEMENTDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSignalMapper>
#include <QVBoxLayout>

#include "../Entities/EntityOfDefaultType.h"
#include "../Entities/Niveau.h"
#include "../Entities/TypeEtablissement.h"
#include "../Div/VectorPtr.h"
#include "../Widget/SelectInListBox.h"

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'un établissement.
 */
class NewEtablissementDialog : public QDialog
{
    Q_OBJECT
public:
    //! Structure de réponse de la fenêtre de dialogue.
    struct dialogResult {
        Etablissement etab;         //!< Etablissement à créer.
        QVector<QVariant> donnee;   //!< Vecteur des données sur l'établissement.
        QVector<int> niveaux;       //!< Liste des identifiant des niveaux présent dans l'établissement.
        QVector<int> types;         //!< Liste des identifiant des types de classes de l'établissement.
    };

    //! Indices des données sur l'établissement.
    enum adresse {CodePostalInd,
                 NumRueInd,
                 PaysInd,
                 RueInd,
                 VilleInd,
                 Nbr
              };

protected:
    const int NbrChoixLine = 4;             //!< Nombre de choix du type d'établissement par ligne (+1).

    // Donnée
    VectorPtr<TypeEtablissement> m_vectTpEtab;     //!< Liste des types d'établissements.
    VectorPtr<Niveau> m_vectNiveau;                //!< Liste des Niveaux.

    // Widget
    QLabel *m_labelCP;              //!< Code postal de l'établissment.
    QLabel *m_labelNc;              //!< Nom Abrégé de l'établissement.
    QLabel *m_labelNom;             //!< Nom de l'établissement.
    QLabel *m_labelNuRue;           //!< Numéro de rue de l'établissement.
    QLabel *m_labelPays;            //!< Pays de l'établissement.
    QLabel *m_labelRue;             //!< Nom de Rue de l'adresse de l'établissement.
    QLabel *m_labelVille;           //!< Ville de l'établissement.
    QLineEdit *m_lineCp;            //!< Demande du code postal de l'établissement.
    QLineEdit *m_lineNc;            //!< Demande du nom abrégé de l'établissement.
    QLineEdit *m_lineNom;           //!< Demande du nom de l'établissement.
    QLineEdit *m_lineNuRue;         //!< Demande du numéro de rue de l'établissement.
    QLineEdit *m_linePays;          //!< Demande du pays de l'établissement.
    QLineEdit *m_lineRue;           //!< Demande la Rue de l'établissement.
    QLineEdit *m_lineVille;         //!< Demande la ville de l'établissement.
    QPushButton *m_buttonCancel;    //!< Bouton pour Annuler.
    QPushButton *m_buttonCreer;     //!< Bouton pour créer l'établissement.
    SelectInListBox *m_selectListeClasse;  //!< Selection des classe présente dans l'établisement.

    QSignalMapper *m_signalChoixType;   //!< Carte des choix du type d'établissement.

    //Layout
    QGroupBox *m_groupAdr;              //!< Regroupe les labels de l'adresse.
    QGroupBox *m_groupChoixType;        //!< Regroupe les choix des types de classe.
    QGridLayout *m_layoutAdr;           //!< Calque des line de l'adresse.
    QVBoxLayout *m_layoutBouton;        //!< Calque des bouton créer et annuler.
    QGridLayout *m_layoutChoixType;     //!< Calque des choix de type d'établissement.
    QHBoxLayout *m_layoutHaut;          //!< Calque de la partie haute.
    QVBoxLayout *m_layoutMain;          //!< Calque principal.
    QVBoxLayout *m_layoutNom;           //!< Calque du choix du nom de l'établissement.

public:
    //! Constructeur.
    explicit NewEtablissementDialog(const VectorPtr<TypeEtablissement> & vectTpEtab, const VectorPtr<Niveau> & vectNiveau, const QString & nc = QString(), const QString & nom = QString(), QWidget *parent = 0);

    //! Reourne le resultat de la fenêtre de dialogue.
    dialogResult value() const;

public slots:
    //! Ajoute à la liste de gauche les niveaux vérifiant idTpEtab == n.
    void boxCheckChange(int n);

};

#endif // NEWETABLISSEMENTDIALOG_H
