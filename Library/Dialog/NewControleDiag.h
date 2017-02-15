/*Auteur: PERCIE DU SERT Maxime
 *Date: 13/02/2017
 */
#ifndef NEWCONTROLEDIAG_H
#define NEWCONTROLEDIAG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QStringListModel>
#include <QVBoxLayout>

#include "../Div/VectorPtr.h"
#include "../Entities/TypeControle.h"

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'un controle.
 */
class NewControleDiag: public QDialog
{
    Q_OBJECT
protected:
    // Widget

    QLabel * m_labelDate;       //!< Date du controle.
    QLabel * m_labelNom;        //!< Nom du controle.
    QLabel * m_labelTotal;      //!< Total du controle.
    QLabel * m_labelType;       //!< Titre du choix du type de controle.
    QLineEdit * m_lineDate;     //!< Demande de la date du controle.
    QLineEdit * m_lineNom;      //!< Demande du nom.
    QLineEdit * m_lineTotal;    //!< Demande du total.
    QPushButton * m_buttonCreerType;        //!< Bouton pour la création d'un type de controle.
    QPushButton * m_buttonAccepter;         //!< Bouton Ok.
    QPushButton * m_buttonAnnuler;          //!< Bouton Annuler.
    QStringListModel * m_stringModelType;   //!< Liste des types de controle.

    // Calque
    QHBoxLayout * m_layoutButton;   //!< Calque des bouton annuler et créer.
    QHBoxLayout * m_layoutChoix;    //! Calque de choix du type et des paramètres.
    QVBoxLayout * m_LayoutMain;     //!< Calque Principale.
    QVBoxLayout * m_layoutParametre;    //!< Calque du paramétrage du controle.
    QVBoxLayout * m_layoutType;     //!< Calque du choix du type de controle.
public:
    //! Constructeur
    NewControleDiag(const VectorPtr<TypeControle> & vectTpCtr, QWidget* parent = 0);
};

#endif // NEWCONTROLEDIAG_H
