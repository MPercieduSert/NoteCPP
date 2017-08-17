#include "ListeElevesDelegate.h"

QWidget * ListeElevesDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    Indice ind = indice(index);
    if(ind.first < ListeElevesModel::Offset)
    {
        switch (ind.first) {
        case Eleve::Fille:
        {
            QCheckBox * editor = new QCheckBox("F",parent);
            editor->setAutoFillBackground(true);
            return editor;
        }
        case Eleve::Naissance:
        {
            QDateEdit * editor = new QDateEdit(parent);
            editor->setMinimumDate(QDate(1900,1,1));
            editor->setMaximumDate(QDate::currentDate());
            editor->setCalendarPopup(true);
            return editor;
        }}
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void ListeElevesDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    Indice ind = ((ListeElevesModel *) index.model())->indice(index);
    if(ind.first == Eleve::Fille)
    {
        bool bb = ((ListeElevesModel *)index.model())->data(ind,Qt::EditRole).toBool();
        QCheckBox * checkBox = static_cast<QCheckBox *>(editor);
        checkBox->setChecked(bb);
    }
    else
        QStyledItemDelegate::setEditorData(editor, index);
}
