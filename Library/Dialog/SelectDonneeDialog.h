/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/10/2016
 */
#ifndef SELECTDONNEEDIALOG_H
#define SELECTDONNEEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../Entities/Donnee.h"
#include "../Widget/ReadTreeWidget.h"

/*! \ingroup groupeDialogue
 * \brief Fenêtre de dialogue de selection d'une donnée.
 */
class SelectDonneeDialog : public QDialog
{
    Q_OBJECT
protected:
    QLabel *m_label;                            //!< Texte d'entête.
    QPushButton *m_cancelBouton;                //!< Bouton d'annulation.
    QPushButton *m_okBouton;                    //!< Bouton de confirmation de selection.
    QHBoxLayout *m_hLayout;                     //!< Calque secondaire.
    QVBoxLayout *m_vLayout;                     //!< Calque principal.
    ReadTreeWidget<Donnee> * m_treeWidget;      //!< Arbre de données.

public:
    //! Constructeur.
    SelectDonneeDialog(const Tree<Donnee> & tree, QWidget * parent = 0);

public slots:
    //! Surdéfinition.
    void accept();

    //! Surdéfinition.
    void reject();
};

#endif // SELECTDONNEEDIALOG_H
