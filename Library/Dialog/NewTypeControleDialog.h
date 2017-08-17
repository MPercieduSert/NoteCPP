/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/03/2017
 */
#ifndef NEWTYPECONTROLEDIALOG_H
#define NEWTYPECONTROLEDIALOG_H

#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

#include "../Entities/TypeControle.h"
#include "../Widget/ReadTreeWidget.h"
#include "../Widget/SpinBoxDecimale.h"


/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'un controle.
 */
class NewTypeControleDialog : public QDialog
{
    Q_OBJECT
protected:
    // Widget
    QLabel * m_labelDecimale;                               //!< Décimale par deafut des notes du type d'épreuve.
    QLabel * m_labelNc;                                     //!< Nom cours du type d'épreuve.
    QLabel * m_labelNom;                                    //!< Nom du type d'épreuve.
    QLabel * m_labelSurType;                                //!< Demande d'un sur type.
    QLabel * m_labelTotal;                                  //!< Total par deafaut du type d'épreuve.
    QLabel * m_labelType;                                   //!< Type particulier du type d'épreuve.
    QCheckBox * m_lineAppreciation;                         //!< Demande si l'épreuve est à appréciation par défaut ou non.
    SpinBoxDecimale * m_lineDecimale;                              //!< Demande des décimales par defaut des notes du typed'épreuve.
    QCheckBox * m_lineModif;                                //!< Demande si les paramètre des épreuves de ce type sont modifiable.
    QLineEdit * m_lineNc;                                   //!< Demande du nom cours du type d'épreuve.
    QLineEdit * m_lineNom;                                  //!< Demande du nom.
    QSpinBox * m_lineTotal;                                 //!< Demande du total par défaut.
    QComboBox * m_lineType;                                //!< Demande type particulier du type d'épreuve.
    QPushButton * m_buttonAccepter;                         //!< Bouton Ok.
    QPushButton * m_buttonAnnuler;                          //!< Bouton Annuler.
    ReadTreeWidget<TypeControle> * m_treeModelSurType;      //!< Liste des types de épreuve existant.

    // Calque
    QHBoxLayout * m_layoutButton;   //!< Calque des bouton annuler et créer.
    QHBoxLayout * m_layoutChoix;    //! Calque de choix du sur type et des paramètres.
    QVBoxLayout * m_LayoutMain;     //!< Calque Principale.
    QGridLayout * m_layoutParametre;    //!< Calque du paramétrage du type d'épreuve.
    QVBoxLayout * m_layoutSurType;      //!< Calque du choix du sur type de d'épreuve.

public:
    enum {Aucun = -1};
    //! Constructeur
    NewTypeControleDialog(Tree<TypeControle> &&treeTpCtr, QWidget* parent = 0);

    //! Retourne le resultat de la fenêtre de dialogue.
    TypeControle value() const;

public slots:
    //! Action lorsque la selection du sur-type d'épreuve change.
    void selectedSurTypeChange(const QModelIndex &/*current*/, const QModelIndex &/*previous*/);
};

#endif // NEWTYPECONTROLEDIALOG_H
