#include "ListeNoteDelegate.h"

ListeNoteDelegate::ListeNoteDelegate(QObject *parent): QStyledItemDelegate(parent)
{

}

QWidget * ListeNoteDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    int pos = indice(index).first;
    if(pos >= ListeElevesModel::Offset)
        return new SpinBoxNote(4/*((ListeNoteModel *) index.model())->controle(pos).decimale()*/, 0, parent);
    else
        return QStyledItemDelegate::createEditor(parent, option, index);
}

/*void ListeNoteDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int pos = indice(index).first;
    if(pos >= ListeElevesModel::Offset)
        return new SpinBoxNote(((ListeNoteModel *) index.model())->controle(pos).decimale(), 0, parent);
    else
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void ListeNoteDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch (index.column()) {

    default:
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}*/
