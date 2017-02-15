/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/05/2016
 */
#ifndef SELECTANNEEDIALOG_H
#define SELECTANNEEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../Entities/Annee.h"
#include "../Div/VectorPtr.h"

/*! \defgroup groupeDialog Dialogues
 * \brief Ensemble de fenètre de dialogues.
 */

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de selection d'une année.
 */
class SelectAnneeDialog : public QDialog
{
    Q_OBJECT
public:
    //! Constante de réponse (autre que l'identifiant de l'année).
    enum DialogCode {Creer = -1,
                     Annuler = -2};

protected:
    QLabel *m_label;                //!< Texte de l'entête.
    QPushButton *m_cancelBouton;    //!< Bouton d'annulation.
    QPushButton *m_creerBouton;     //!< Bouton de création.
    QPushButton *m_okBouton;        //!< Bouton de confirmation de selection.
    QComboBox *m_listBox;           //!< Liste déroulante des différants choix.
    QVBoxLayout *m_vLayout;         //!< Calque principal.
    QHBoxLayout *m_hLayout;         //!< Calque secondaire.

public:
    //! Constructeur.
    SelectAnneeDialog(const VectorPtr<Annee> & listeAnnee, QWidget *parent=0, int idDefault = -1, bool AnnuleButton = true, bool creerAnnee = false);

public slots:
    //! Ferme la fenêtre et donne la valeur de l'identifiant de l'éléement courant de m_listBox à result.
    void accept();

    //! Ferme la fenêtre et donne la valeur Creer à result.
    void creerClick();

    //! Ferme la fenêtre et donne la valeur Annuler à result.
    void reject();
};

#endif // SELECTANNEEDIALOG_H
