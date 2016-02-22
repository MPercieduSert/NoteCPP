#include "ListeEleveModel.h"

ListeEleveModel::ListeEleveModel(Bdd & bdd, const Classe &classe, QObject *parent): MAbstractTableModel(parent), m_bdd(bdd), m_classe(classe)
{
    ListEntities<Eleve>::vector(m_data,m_bdd.getList(Entity::EleveId,Eleve::ClassePos,QVariant(m_classe.id())));
    m_header<<tr("Nom")<<tr("Prenom")<<tr("Fille/Garçon")<<tr("Date de naissance")<<tr("Départ")<<tr("Date de départ");
}
ListeEleveModel::~ListeEleveModel()
{
    QString string;
    foreach (Eleve eleve, m_data) {
        string.append(eleve.nom()+" "+eleve.prenom()+" "+eleve.afficheFille()+" "+eleve.naissance().toString()+" "+eleve.abandon().toString()+"\n");
    }
    QMessageBox::critical(0,"",string);
}
bool ListeEleveModel::canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    Q_UNUSED(action);
    Q_UNUSED(row);
    Q_UNUSED(parent);

    if (!data->hasFormat("application/vnd.text.list"))
        return false;

    if (column > 2)
        return false;

    return true;
}
int ListeEleveModel::columnCount(const QModelIndex &parent) const
{
    return Eleve::NbrValue;
}
QVariant ListeEleveModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && (role == Qt::DisplayRole || role == Qt::EditRole))
    {
        switch (index.column()) {
        case nomIndex:
            return QVariant(m_data[index.row()].nom());
            break;
        case prenomIndex:
            return QVariant(m_data[index.row()].prenom());
            break;
        case sexeIndex:
            return QVariant(m_data[index.row()].afficheFille());
            break;
        case naissanceIndex:
            return QVariant(m_data[index.row()].naissance());
            break;
        case abandonIndex:
            return m_data[index.row()].abandon().isValid() ? QVariant("Plus là") : QVariant("Présent");
            break;
        case abandonIndex + 1:
            return QVariant(m_data[index.row()].abandon());
            break;
        }
    }
    return QVariant();
}
bool ListeEleveModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if (!canDropMimeData(data, action, row, column, parent))
        return false;
    if (action == Qt::IgnoreAction)
        return true;
    QByteArray encodedData = data->data("application/vnd.text.list");
    QDataStream stream(&encodedData, QIODevice::ReadOnly);
    QStringList newItems;

    while (!stream.atEnd()) {
        QString text;
        stream >> text;
        newItems << text;
    }
    foreach (const QString &text, newItems) {
        QModelIndex idx = index(row, column, QModelIndex());
        setData(idx, text);
        ++row;
    }
    return true;
}
Qt::ItemFlags ListeEleveModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsDropEnabled;
}
QVariant ListeEleveModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return m_header.at(section);
    else
        return section+1;
}
bool ListeEleveModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        m_data.insert(position, Eleve());
    }

    endInsertRows();
    return true;
}
bool ListeEleveModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        m_data.removeAt(position);
    }

    endRemoveRows();
    return true;
}
int ListeEleveModel::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

bool ListeEleveModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        switch (index.column()) {
        case nomIndex:
            m_data[index.row()].setNom(value.toString());
            break;
        case prenomIndex:
            m_data[index.row()].setPrenom(value.toString());
            break;
        case sexeIndex:
            m_data[index.row()].setFille(value.toBool());
            break;
        case naissanceIndex:
            m_data[index.row()].setNaissance(value.toDate());
            break;
        case abandonIndex:
            if(!value.toBool())
            {
                QDate date;
                if(9 <= QDate::currentDate().month() && QDate::currentDate().month() <= 12)
                {
                    date.setDate(m_bdd.annee().rentree(),QDate::currentDate().month(),QDate::currentDate().day());
                }
                else
                {
                    date.setDate(m_bdd.annee().rentree()+1,QDate::currentDate().month(),QDate::currentDate().day());
                }
                m_data[index.row()].setAbandon(date);
            }
            else
            {
                m_data[index.row()].setAbandon(QDate());
            }
            break;
        case abandonIndex + 1:
            m_data[index.row()].setAbandon(value.toDate());
            break;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::DropActions ListeEleveModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}
