/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/05/2016
 */
#ifndef NEWANNEEDIALOG_H
#define NEWANNEEDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "../Widget/SpinBoxAnnee.h"

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'une année.
 */
class NewAnneeDialog : public QDialog
{
    Q_OBJECT
protected:
    QLabel *m_label;                //! Texte
    QPushButton *m_creerBouton;     //! Bouton de confirmation de création
    QPushButton *m_cancelBouton;    //! Bouton d'annulation
    SpinBoxAnnee *m_box;            //! Sélecteur d'année
    QVBoxLayout *m_vLayout;         //! Layout principal
    QHBoxLayout *m_hLayout;         //! Layout secondaire

public:
    //! Constructeur.
    NewAnneeDialog(QWidget *parent = 0);

public slots:
    //! Surdéfinition.
    void accept();

    //! Surdéfinition.
    void reject();
};

#endif // NEWANNEEDIALOG_H
