#ifndef LISTEELEVEDELEGATE_H
#define LISTEELEVEDELEGATE_H

#include <QCheckBox>
#include <QDateEdit>
#include <QStyledItemDelegate>

#include "../Entities/Annee.h"
#include "../Model/ListeEleveModel.h"

class ListeEleveDelegate : public QStyledItemDelegate
{
    Q_OBJECT
protected:
    Annee m_annee;

public:
    ListeEleveDelegate(const Annee & annee, QObject * parent = 0);
    QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // LISTEELEVEDELEGATE_H
