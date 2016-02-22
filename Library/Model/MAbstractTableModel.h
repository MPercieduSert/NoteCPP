#ifndef MABSTRACTTABLEMODEL_H
#define MABSTRACTTABLEMODEL_H

#include <QAbstractTableModel>

class MAbstractTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MAbstractTableModel(QObject *parent = 0);
    ~MAbstractTableModel() {}

signals:

public slots:
};

#endif // MABSTRACTTABLEMODEL_H
