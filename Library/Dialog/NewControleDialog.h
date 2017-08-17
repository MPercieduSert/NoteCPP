/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/02/2017
 */
#ifndef NEWCONTROLEDIALOG_H
#define NEWCONTROLEDIALOG_H

#include <QCheckBox>
#include <QDateEdit>
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

#include "../Entities/Controle.h"
#include "../Entities/EntityComplexe.h"
#include "../Widget/ReadTreeWidget.h"
#include "../Widget/SpinBoxDecimale.h"

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'un controle.
 */
class NewControleDialog: public QDialog
{
    Q_OBJECT
public:
    //! Structure de réponse de la fenêtre de dialogue.
    struct dialogResult
    {
        bool appreciation;  //!< Appréciation à créer par défaut ou non.
        Controle controle;  //!< Controle à créer.
        bool creerType;     //!< Permet de savoir s'il faut créer un type de controle.
    };

protected:
    bool m_creerType;           //!< //!< Permet d'indiquer dans la réponse s'il faut créer un établissement.

    // Widget
    QLabel * m_labelDate;       //!< Date du épreuve.
    QLabel * m_labelDecimale;   //!< Décimale des notes de l'épreuve.
    QLabel * m_labelMinima;     //!< Note minima acceptable de l'épreuve.
    QLabel * m_labelNom;        //!< Nom du épreuve.
    QLabel * m_labelTotal;      //!< Total du épreuve.
    QLabel * m_labelType;       //!< Titre du choix du type de épreuve.
    QCheckBox * m_lineAppreciation; //!< Demande si l'épreuve possède une appréciation pour tous les candidats.
    QCheckBox * m_lineBareme;   //!< Demande si un barème est associé à l'épreuve.
    QDateEdit * m_lineDate;     //!< Demande de la date du épreuve.
    SpinBoxDecimale * m_lineDecimale;  //!< Demande des décimales des notes de l'épreuve.
    QCheckBox * m_lineEnonce;   //!< Demande si un énoncé est associé à l'épreuve.
    QSpinBox * m_lineMinima;    //!< Demande de la note minima.
    QLineEdit * m_lineNom;      //!< Demande du nom.
    QSpinBox * m_lineTotal;     //!< Demande du total.
    QPushButton * m_buttonCreerType;        //!< Bouton pour la création d'un type de épreuve.
    QPushButton * m_buttonAccepter;         //!< Bouton Ok.
    QPushButton * m_buttonAnnuler;          //!< Bouton Annuler.
    ReadTreeWidget<TypeControleNum> * m_treeModelType;   //!< Liste des types de épreuve.

    // Calque
    QHBoxLayout * m_layoutButton;   //!< Calque des bouton annuler et créer.
    QHBoxLayout * m_layoutChoix;    //! Calque de choix du type et des paramètres.
    QVBoxLayout * m_LayoutMain;     //!< Calque Principale.
    QGridLayout * m_layoutParametre;    //!< Calque du paramétrage du épreuve.
    QVBoxLayout * m_layoutType;     //!< Calque du choix du type de épreuve.
public:
    //! Constructeur
    NewControleDialog(const Tree<TypeControleNum> & treeTpCtr, QWidget* parent = 0);

    //! Retourne le resultat de la fenêtre de dialogue.
    dialogResult value() const;

public slots:
    //! Action lorsque l'on clique sur m_buttonCreerType.
    void creerType();

    //! Action lorsque la selection du type d'épreuve change.
    void selectedTypeChange(const QModelIndex &/*current*/, const QModelIndex &/*previous*/);
};

#endif // NEWCONTROLEDIALOG_H
