#include "ListeEleveDelegate.h"

ListeEleveDelegate::ListeEleveDelegate(const Annee &annee, QObject *parent): QStyledItemDelegate(parent), m_annee(annee)
{

}

QWidget * ListeEleveDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    switch (index.column()) {
    case ListeEleveModel::sexeIndex:
    {
        QCheckBox * editor = new QCheckBox("F",parent);
        editor->setAutoFillBackground(true);
        return editor;
    }
    case ListeEleveModel::naissanceIndex:
    {
        QDateEdit * editor = new QDateEdit(parent);
        editor->setMinimumDate(QDate(1900,1,1));
        editor->setMaximumDate(QDate(m_annee.rentree(),9,1));
        editor->setCalendarPopup(true);
        return editor;
    }
    case ListeEleveModel::abandonIndex:
    {
        QCheckBox * editor = new QCheckBox(tr("Présent"),parent);
        editor->setAutoFillBackground(true);
        return editor;
    }
    case ListeEleveModel::abandonIndex + 1:
    {
        QDateEdit * editor = new QDateEdit(parent);
        editor->setMinimumDate(QDate(m_annee.rentree(),9,1));
        editor->setMaximumDate(QDate(m_annee.rentree()+1,8,31));
        editor->setCalendarPopup(true);
        return editor;
    }
    default:
        return QStyledItemDelegate::createEditor(parent, option, index);
    }

}

void ListeEleveDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    switch (index.column()) {
    case ListeEleveModel::sexeIndex:
    {
        bool bb = index.model()->data(index,Qt::EditRole).toBool();
        QCheckBox * checkBox = static_cast<QCheckBox *>(editor);
        checkBox->setChecked(bb);
        break;
    }
    case ListeEleveModel::abandonIndex:
    {
        bool bb = !index.model()->data(index,Qt::EditRole).toDate().isValid();
        QCheckBox * checkBox = static_cast<QCheckBox *>(editor);
        checkBox->setChecked(bb);
        break;
    }
    case ListeEleveModel::naissanceIndex:
    case ListeEleveModel::abandonIndex + 1:
    {
        QDate date = index.model()->data(index,Qt::EditRole).toDate();
        QDateEdit * dateEdit = static_cast<QDateEdit *>(editor);
        dateEdit->setDate(date);
        break;
    }
    default:
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void ListeEleveDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch (index.column()) {
    case ListeEleveModel::sexeIndex:
    case ListeEleveModel::abandonIndex:
    {
        QCheckBox * checkBox = static_cast<QCheckBox *>(editor);
        model->setData(index, checkBox->isChecked(), Qt::EditRole);
        break;
    }
    case ListeEleveModel::naissanceIndex:
    case ListeEleveModel::abandonIndex + 1:
    {
        QDateEdit * dateEdit = static_cast<QDateEdit *>(editor);
        model->setData(index, dateEdit->date(), Qt::EditRole);
        break;
    }
    default:
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}
