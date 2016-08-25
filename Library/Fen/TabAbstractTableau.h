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
    virtual void coller()   {}
    //! Slot coorepondant à l'action copier.
    virtual void copier()   {}
    //! Slot coorepondant à l'action effacer.
    virtual void effacer()   {}
    //! Slot coorepondant à l'action sauver.
    virtual void sauvegarder()   {m_model->save();}
};

#endif // TABABSTRACTTABLEAU_H
