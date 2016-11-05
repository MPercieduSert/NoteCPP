/*Auteur: PERCIE DU SERT Maxime
 *Date: 15/07/2016
 */
#ifndef LISTEELEVEMODEL_H
#define LISTEELEVEMODEL_H

#include <QList>
#include <QMessageBox>
#include <QMimeData>
#include <QStringList>

#include "MAbstractTableModel.h"
#include "../Div/Bdd.h"
#include "../Entities/Classe.h"
#include "../Entities/Eleve.h"
#include "../Div/VectorPtr.h"

/*! \ingroup groupeModel
 * \brief Model de la liste des éléves.
 */
class ListeEleveModel : public MAbstractTableModel
{
    Q_OBJECT
public:
    enum indexColum {nomIndex = 0,
                    prenomIndex = 1,
                    sexeIndex = 2,
                    naissanceIndex = 3,
                    abandonIndex = 4};

protected:
    Bdd * m_bdd;                //!< Lien avec la base de donnée.
    Classe m_classe;            //!< Classe associé à la liste.
    VectorPtr<Eleve> m_data;      //!< Vecteur des éléves présent dans la classe.
    QStringList m_header;       //!< Entêtes des colonnes.

public:
    //! Constructeur.
    ListeEleveModel(Bdd * bdd, const Classe &classe, QObject * parent = 0);
    //! Destructeur.
    ~ListeEleveModel();

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    void save();
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

protected:
    void dataFromBdd();    
};

#endif // LISTEELEVEMODEL_H
