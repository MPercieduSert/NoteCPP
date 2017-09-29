/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/09/2017
 */
#ifndef NEWMOTCLEDIALOG_H
#define NEWMOTCLEDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de création d'un mot clé.
 */
class NewMotCleDialog : public QDialog
{
    Q_OBJECT
public:
    //! Structure de réponse de la fenêtre de dialogue.
    struct dialogResult
    {
        QString nc;
        QString nom;
    };

protected:
    // Donnée

    // Widget
    QLabel * m_ncLabel;             //!< Label du nom court
    QLabel * m_nomLabel;            //!< Label du nom
    QLineEdit * m_ncLine;           //!< Line Edit nom court
    QLineEdit * m_nomLine;          //!< Line Edit nom
    QPushButton * m_cancelBouton;   //!< Bouton d'annulation
    QPushButton * m_creerBouton;    //!< Bouton création
    QHBoxLayout *m_hLayout;         //!< Layout secondaire des boutons
    QVBoxLayout *m_vLayout;         //!< Layout principal


public:
    //! Contructeur
    NewMotCleDialog(const QString & nomparent, int position, QWidget * parent = nullptr);

    //! Retourne le résultat de la fenêtre de dialogue.
    dialogResult value() const;

public slots:
    //! Surdéfinition.
    void accept();
};

#endif // NEWMOTCLEDIALOG_H
