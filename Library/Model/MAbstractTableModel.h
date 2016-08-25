/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/07/2016
 */
#ifndef MABSTRACTTABLEMODEL_H
#define MABSTRACTTABLEMODEL_H

#include <QAbstractTableModel>

/*! \defgroup groupeModel Entités
 * \brief Ensemble de classes représentant les models.
 */

/*! \ingroup groupeModel
 * \brief Classe mère des model de type tabelau.
 */
class MAbstractTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    //! Constructeur.
    explicit MAbstractTableModel(QObject *parent = 0);
    //! Destructeur.
    ~MAbstractTableModel() {}

    //! Enregistre les données du model dans la base de donnée.
    virtual void save() = 0;

signals:

public slots:
};

#endif // MABSTRACTTABLEMODEL_H
