/*Auteur: PERCIE DU SERT Maxime
 *Date: 11/07/2016
 */
#ifndef TABABSTRACTTABLEAU_H
#define TABABSTRACTTABLEAU_H

#include <QStyledItemDelegate>
#include <QTableView>

#include "TabAbstractModule.h"
#include "../Model/MAbstractTableModel.h"

/*! \ingroup groupeFen
 * \brief Classe mère des onglets contenant des tableaux
 */
class TabAbstractTableau : public TabAbstractModule
{
    Q_OBJECT
protected:
    QPushButton * m_addColumnButton;        //!< Bouton pour ajouter une colonne
    QStyledItemDelegate * m_delegate;       //!< Déleguer
    MAbstractTableModel * m_model;          //!< Model
    QTableView * m_view;                    //!< Vue
    QPushButton * m_saveButton;             //!< Bouton save
public:
    //! Constructeur.
    explicit TabAbstractTableau(int index, TabModule *parent = 0);

    //! Destructeur.
    ~TabAbstractTableau() {}

signals:

public slots:
    //! Slot coorepondant à l'action coller.
    void coller();
    //! Slot coorepondant à l'action copier.
    void copier();
    //! Slot coorepondant à l'action copier.
    void couper();
    //! Slot coorepondant à l'action effacer.
    void effacer();
    //! Slot coorepondant à l'action sauver.
    void save()   {m_model->save();}
};

#endif // TABABSTRACTTABLEAU_H
