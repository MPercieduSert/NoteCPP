#include "ListeEleveModel.h"

ListeEleveModel::ListeEleveModel(Bdd *bdd, const Classe &classe, QObject *parent)
    : ListeElevesModel(bdd,bdd->getMap<Eleve,ClasseEleve>(ClasseEleve::IdEl,ClasseEleve::IdCl,classe.id()),parent),
      m_classe(classe)
{}

QVariant ListeEleveModel::dataPropre(const Indice &indice, int /*role*/) const
{
    if(indice.first < m_dataD.count())
        return m_dataD[indice.first][indice.second].valeur();
    return QVariant();
}

bool ListeEleveModel::insertColumn(const Donnee &dn)
{
    beginInsertColumns(QModelIndex(),columnCount(),columnCount());
    appendIdCol(m_dataD.count());
    headerInsert(m_dataD.count(),dn.nom());
    MapPtr<CibleDonnee> MapCbDn;
    for(QVector<int>::const_iterator i = m_idRow.cbegin(); i != m_idRow.cend(); ++i)
    {
        MapCbDn.insert(*i,CibleDonnee(dn.id(),*i,bdd::cible::EleveCb));
        m_bdd->getUnique(MapCbDn[*i]);
    }
    m_dataD.append(std::move(MapCbDn));
    endInsertColumns();
    return true;
}

//bool ListeEleveModel::insertRows(int position, int rows, const QModelIndex & /*parent*/)
//{
//    beginInsertRows(QModelIndex(), position, position+rows-1);
//    for (int row = 0; row < rows; ++row)
//        m_dataE.insert(position, new Eleve());
//    endInsertRows();
//    return true;
//}
//bool ListeEleveModel::removeRows(int position, int rows, const QModelIndex & /*parent*/)
//{
//    beginRemoveRows(QModelIndex(), position, position+rows-1);
//    for (int row = 0; row < rows; ++row)
//    {
//        m_dataE.removeAt(position);
//        for(QVector<VectorPtr<CibleDonnee>>::iterator i = m_dataD.begin(); i != m_dataD.end(); ++i)
//            i->removeAt(position);
//    }
//    endRemoveRows();
//    return true;
//}

void ListeEleveModel::save()
{
    m_bdd->save(m_eleve);
    for(QVector<MapPtr<CibleDonnee>>::const_iterator i = m_dataD.cbegin(); i != m_dataD.cend(); ++i)
        m_bdd->save(*i);
}

bool ListeEleveModel::setDataPropre(const Indice &indice, const QVariant &value, int /*role*/)
{
    if(indice.first < m_dataD.count())
    {
        m_dataD[indice.first][indice.second].setValeur(value);
        return true;
    }
    else
        return false;
}

void ListeEleveModel::sortPropre(int column, Qt::SortOrder order)
{
    if(column < m_dataD.count())
        std::sort(m_idRow.begin(),m_idRow.end(),[order,column,this] (int i, int j) -> bool
                                                {return order == Qt::SortOrder::AscendingOrder ?
                        m_dataD[column][i].valeur() < m_dataD[column][j].valeur()
                      : m_dataD[column][i].valeur() > m_dataD[column][j].valeur();});
}
