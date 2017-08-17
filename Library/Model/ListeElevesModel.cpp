#include "ListeElevesModel.h"

ListeElevesModel::ListeElevesModel(Bdd * bdd, const MapPtr<Eleve> && mapEleve, QObject * parent, const QList<int> &colonnes)
    : MAbstractTableModel(parent),
      m_bdd(bdd),
      m_eleve(std::move(mapEleve)),
      m_idCol(QVector<int>::fromList(colonnes)),
      m_idRow(QVector<int>::fromList(m_eleve.keys()))
{
    if(m_idCol.isEmpty())
        m_idCol<<Eleve::Nom<<Eleve::Prenom<<Eleve::Naissance<<Eleve::Fille;
    for(QVector<int>::const_iterator i = m_idCol.cbegin(); i != m_idCol.cend(); ++i)
        m_header.insert(*i,Eleve::nomAttribut(*i));
    m_nbrColEleve = m_header.count();
//    QString str;
//    for(MapPtr<Eleve>::iterator i = m_eleve.begin(); i != m_eleve.end(); ++i)
//        str.append((*i).affiche());
//    QMessageBox::critical(0,"",str);
}

int ListeElevesModel::columnCount(const QModelIndex & /*parent*/) const
    {return m_idCol.count();}

QVariant ListeElevesModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return data(indice(index),role);
    return QVariant();
}

QVariant ListeElevesModel::data(const Indice &indice, int role) const
{
    if(indice.first < Offset)
    {
        if(role == Qt::DisplayRole || role == Qt::EditRole)
        {
            switch (indice.first){
            case Eleve::Nom:
                return QVariant(m_eleve[indice.second].nom());
                break;
            case Eleve::Prenom:
                return QVariant(m_eleve[indice.second].prenom());
                break;
            case Eleve::Fille:
                return QVariant(m_eleve[indice.second].afficheFille());
                break;
            case Eleve::Naissance:
                return QVariant(m_eleve[indice.second].naissance());
                break;
          }}
          return QVariant();
    }
    else
        return dataPropre(Indice(indice.first-Offset,indice.second),role);
}
Qt::ItemFlags ListeElevesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant ListeElevesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return m_header[m_idCol[section]];
    else
        return section+1;
}

//bool ListeElevesModel::insertRows(int position, int rows, const QModelIndex & /*parent*/)
//{
//    beginInsertRows(QModelIndex(), position, position+rows-1);
//    for (int row = 0; row < rows; ++row)
//        m_eleve.insert(position, new Eleve());
//    endInsertRows();
//    return true;
//}
//bool ListeElevesModel::removeRows(int position, int rows, const QModelIndex & /*parent*/)
//{
//    beginRemoveRows(QModelIndex(), position, position+rows-1);
//    for (int row = 0; row < rows; ++row)
//    {
//        m_eleve.removeAt(position);
//    }
//    endRemoveRows();
//    return true;
//}
int ListeElevesModel::rowCount(const QModelIndex & /*parent*/) const
    {return m_idRow.count();}

void ListeElevesModel::save()
    {m_bdd->save(m_eleve);}

bool ListeElevesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole && setData(indice(index),value,role))
        emit dataChanged(index,index);
    return false;
}

bool ListeElevesModel::setData(const Indice &indice, const QVariant &value, int role)
{
    if(indice.first < Offset)
    {
        switch (indice.first) {
        case Eleve::Nom:
            m_eleve[indice.second].setNom(value.toString());
            break;
        case Eleve::Prenom:
            m_eleve[indice.second].setPrenom(value.toString());
            break;
        case Eleve::Fille:
            m_eleve[indice.second].setFille(value.toBool());
            break;
        case Eleve::Naissance:
            if(value.toDate().isValid())
                m_eleve[indice.second].setNaissance(value.toDate());
            else
                m_eleve[indice.second].setNaissance(QDate::fromString(value.toString(),"dd/MM/yyyy"));
            break;
        }
        return true;
    }
    else if(setDataPropre(Indice(indice.first-Offset,indice.second),value,role))
        return true;
    return false;
}

void ListeElevesModel::sort(int column, Qt::SortOrder order)
{
    if(m_idCol[column] < Offset)
    {
        switch (m_idCol[column]) {
        case Eleve::Nom:
            std::sort(m_idRow.begin(),m_idRow.end(),sortEleve<NomPrenomNaissance>(this,order == Qt::SortOrder::AscendingOrder));
            break;
        case Eleve::Prenom:
            std::sort(m_idRow.begin(),m_idRow.end(),sortEleve<PrenomNomNaissance>(this,order == Qt::SortOrder::AscendingOrder));
            break;
        case Eleve::Naissance:
            std::sort(m_idRow.begin(),m_idRow.end(),sortEleve<NaissanceNomPrenom>(this,order == Qt::SortOrder::AscendingOrder));
            break;
        default:
            break;
    }}
    else
        sortPropre(m_idCol[column]-Offset,order);
    emit dataChanged(QModelIndex().child(0,0),QModelIndex().child(rowCount()-1,columnCount()-1));
}

template<> bool ListeElevesModel::sortEleve<ListeElevesModel::NomPrenomNaissance>::operator ()(int i, int j) const
{
    if(m_model->m_eleve[i].nom() != m_model->m_eleve[j].nom())
        return m_asc ? m_model->m_eleve[i].nom() < m_model->m_eleve[j].nom()
                     : m_model->m_eleve[i].nom() > m_model->m_eleve[j].nom();
    if(m_model->m_eleve[i].prenom() != m_model->m_eleve[j].prenom())
        return m_asc ? m_model->m_eleve[i].prenom() < m_model->m_eleve[j].prenom()
                     : m_model->m_eleve[i].prenom() > m_model->m_eleve[j].prenom();
    return m_asc ? m_model->m_eleve[i].naissance() < m_model->m_eleve[j].naissance()
                 : m_model->m_eleve[i].naissance() >= m_model->m_eleve[j].naissance();
}

template<> bool ListeElevesModel::sortEleve<ListeElevesModel::PrenomNomNaissance>::operator ()(int i, int j) const
{
    if(m_model->m_eleve[i].prenom() != m_model->m_eleve[j].prenom())
        return m_asc ? m_model->m_eleve[i].prenom() < m_model->m_eleve[j].prenom()
                     : m_model->m_eleve[i].prenom() > m_model->m_eleve[j].prenom();
    if(m_model->m_eleve[i].nom() != m_model->m_eleve[j].nom())
        return m_asc ? m_model->m_eleve[i].nom() < m_model->m_eleve[j].nom()
                     : m_model->m_eleve[i].nom() > m_model->m_eleve[j].nom();
    return m_asc ? m_model->m_eleve[i].naissance() < m_model->m_eleve[j].naissance()
                 : m_model->m_eleve[i].naissance() >= m_model->m_eleve[j].naissance();
}

template<> bool ListeElevesModel::sortEleve<ListeElevesModel::NaissanceNomPrenom>::operator ()(int i, int j) const
{
    if(m_model->m_eleve[i].naissance() != m_model->m_eleve[j].naissance())
        return m_asc ? m_model->m_eleve[i].naissance() < m_model->m_eleve[j].naissance()
                     : m_model->m_eleve[i].naissance() >= m_model->m_eleve[j].naissance();
    if(m_model->m_eleve[i].nom() != m_model->m_eleve[j].nom())
        return m_asc ? m_model->m_eleve[i].nom() < m_model->m_eleve[j].nom()
                     : m_model->m_eleve[i].nom() > m_model->m_eleve[j].nom();
    return m_asc ? m_model->m_eleve[i].prenom() < m_model->m_eleve[j].prenom()
                 : m_model->m_eleve[i].prenom() >= m_model->m_eleve[j].prenom();

}
