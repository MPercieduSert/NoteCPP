#include "ListeNoteModel.h"

ListeNoteModel::ListeNoteModel(Bdd *bdd, const Classe &classe, QObject *parent)
    : ListeElevesModel(bdd,bdd->getMap<Eleve,ClasseEleve>(ClasseEleve::IdEl,ClasseEleve::IdCl,classe.id()),parent,QList<int>()<<Eleve::Nom<<Eleve::Prenom),
      m_classe(classe)
    {insertColumn(m_bdd->getList<Controle>(Controle::IdCl,classe.id(),Controle::Date));}

QVariant ListeNoteModel::dataPropre(const Indice &indice, int role) const
{
    if(indice.first < m_dataN.count())
    {
        switch (role) {
        case Qt::DisplayRole:
            return (double) m_dataN[indice.first][indice.second].valeur() / m_vectControle[indice.first].decimale();
        case Qt::EditRole:
            return m_dataN[indice.first][indice.second].valeur();
        case Qt::ForegroundRole:
            return m_dataN[indice.first][indice.second].valeur() >= m_vectControle[indice.first].minima() ?
                    QBrush(Qt::blue) : QBrush(Qt::red);
        case Qt::WhatsThisRole:
            return std::count_if(m_dataN[indice.first].cbegin(),m_dataN[indice.first].cend(),
                    [this,&indice](Note * const ptr) -> bool {return ptr->valeur() > m_dataN[indice.first][indice.second].valeur();}) + 1;
        default:
            break;
    }}
    return QVariant();
}

bool ListeNoteModel::insertColumn(const Controle &ctr)
{
    beginInsertColumns(QModelIndex(),columnCount(),columnCount());
    headerInsert(m_dataN.count(),ctr.nom());
    appendIdCol(m_dataN.count());
    m_vectControle.append(ctr);
    m_dataN.append(m_bdd->getMap<Note>(Note::IdCtr,ctr.id(),Note::IdEl));
    endInsertColumns();
    return true;
}

bool ListeNoteModel::insertColumn(const ListPtr<Controle> &ctrs)
{
    beginInsertColumns(QModelIndex(),columnCount(),columnCount());
    for(ListPtr<Controle>::iterator i = ctrs.begin(); i != ctrs.end(); ++i)
    {
        headerInsert(m_dataN.count(),(*i).nom());
        appendIdCol(m_dataN.count());
        m_vectControle.append(*i);
        m_dataN.append(m_bdd->getMap<Note>(Note::IdCtr,(*i).id(),Note::IdEl));
    }
    endInsertColumns();
    return true;
}

void ListeNoteModel::save()
{
    for(QVector<MapPtr<Note>>::const_iterator i = m_dataN.cbegin(); i != m_dataN.cend(); ++i)
        m_bdd->save(*i);
}

bool ListeNoteModel::setDataPropre(const Indice &indice, const QVariant &value, int /*role*/)
{
    if(indice.first < m_dataN.count())
    {
        m_dataN[indice.first][indice.second].setValeur(value.toInt());
        return true;
    }
    else
        return false;
}

void ListeNoteModel::sortPropre(int column, Qt::SortOrder order)
{
    if(column < m_dataN.count())
        std::sort(m_idRow.begin(),m_idRow.end(),[order,column,this] (int i, int j) -> bool
                                                {return order == Qt::SortOrder::AscendingOrder ?
                        m_dataN[column][i].valeur() < m_dataN[column][j].valeur()
                      : m_dataN[column][i].valeur() > m_dataN[column][j].valeur();});
}

QVector<double> ListeNoteModel::vectNotes(int section) const
{
    int pos = m_idCol[section] - Offset;
    if(0 <= pos && pos < m_vectControle.count())
    {
        QVector<double> vect(m_dataN[pos].count());
        QVector<double>::iterator j = vect.begin();
        for(MapPtr<Note>::iterator i = m_dataN[pos].begin(); i != m_dataN[pos].end(); ++i, ++j)
            *j = (double) (*i).valeur() / m_vectControle[pos].decimale();
        return vect;
    }
    else
        return QVector<double>();
}
