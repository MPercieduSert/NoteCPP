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
#include "../Entities/ListEntities.h"

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
    Bdd & m_bdd;
    Classe m_classe;
    QVector<Eleve> m_data;
    QStringList m_header;

public:
    ListeEleveModel(Bdd & bdd, const Classe &classe, QObject * parent = 0);
    ~ListeEleveModel();
    bool canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::DropActions supportedDropActions() const;

protected:
    void dataFromBdd();
};

#endif // LISTEELEVEMODEL_H
