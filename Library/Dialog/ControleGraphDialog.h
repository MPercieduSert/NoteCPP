/*Auteur: PERCIE DU SERT Maxime
 *Date: 21/03/2017
 */
#ifndef CONTROLEGRAPHDIALOG_H
#define CONTROLEGRAPHDIALOG_H

#include <QBrush>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include "../Entities/Controle.h"
#include "../Entities/EntityOfDefaultType.h"
#include "../Widget/Histogramme.h"

/*! \ingroup groupeDialogue
 * \brief Fenêtre de visualisation des notes d'une épreuve.
 */
class ControleGraphDialog : public QDialog
{
    Q_OBJECT
protected:
    Controle m_controle;                    //!< Controle associé à la fenêtre de dialogue.

    // Widget
    Histogramme * m_plotter;                //!< Graphique.
    //Plotter *m_plotter;
    QPushButton * m_buttonAccepter;         //!< Bouton Ok.
    QPushButton * m_buttonAnnuler;          //!< Bouton Annuler.

    // Calque
    QHBoxLayout * m_layoutButton;   //!< Calque des bouton annuler et créer.
    QVBoxLayout * m_LayoutMain;     //!< Calque Principale.
public:
    //! Constructeur.
    ControleGraphDialog(const Controle & controle, const QVector<double> &notes, QWidget * parent = 0);

    //! Renvoie la largeur des intervalles.
    double largeurBar() const
        {return 1;}
};

#endif // CONTROLEGRAPHDIALOG_H
