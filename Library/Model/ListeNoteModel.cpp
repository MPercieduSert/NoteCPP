#include "ListeNoteModel.h"

ListeNoteModel::ListeNoteModel(Bdd *bdd, const Classe &classe, QObject *parent)
    : MAbstractTableModel(parent),
      m_bdd(bdd),
      m_classe(classe)
{
    QMap<int,QVariant> where;
    where.insert(ClasseEleve::IdCl,classe.id());
    QMap<int,bool> order;
    order.insert(Eleve::Nom,true);
    order.insert(Eleve::Prenom,true);
    order.insert(Eleve::Naissance,true);
    m_vectEleve = m_bdd->getVector<Eleve,ClasseEleve>(Eleve::Id,
                                               ClasseEleve::IdEl,
                                               QMap<int,QVariant>(),
                                               where,
                                               order);

    m_vectControle = m_bdd->getVector<Controle>(Controle::IdCl,classe.id(),Controle::Date);
    m_dataN.resize(m_vectControle.size());
    int j = 0;
    for(VectorPtr<Controle>::iterator i = m_vectControle.begin(); i != m_vectControle.end(); ++i, ++j)
        m_dataN[j] = m_bdd->getMap<Note>(Note::IdCtr,(*i).id(),Note::IdEl);
}

int ListeNoteModel::columnCount(const QModelIndex & /*parent*/) const
{
    return NbrDonneeEleve + m_vectControle.count();
}

QVariant ListeNoteModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && (role == Qt::DisplayRole || role == Qt::EditRole))
    {
        if(index.column() < NbrDonneeEleve)
        {
            switch (index.column())
            {
            case NomIndex:
                return QVariant(m_vectEleve[index.row()].nom());
                break;
            case PrenomIndex:
                return QVariant(m_vectEleve[index.row()].prenom());
                break;
            }
        }
        else
            return m_dataN.at(index.column()-NbrDonneeEleve)[m_vectEleve[index.row()].id()]->valeur();
    }
    return QVariant();
}

Qt::ItemFlags ListeNoteModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    if (index.column() < NbrDonneeEleve)
        return QAbstractItemModel::flags(index);

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant ListeNoteModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        if(section == NomIndex)
            return tr("Nom");
        else if(section == PrenomIndex)
            return tr("Prenom");
        else
            return m_vectControle[section-NbrDonneeEleve].nom();
    }
    else
        return section+1;
}

bool ListeNoteModel::insertColumn(const Controle &ctr)
{
    beginInsertColumns(QModelIndex(),columnCount(),columnCount());
    m_vectControle.append(ctr);
    m_dataN.append(m_bdd->getMap<Note>(Note::IdCtr,ctr.id(),Note::IdEl));
    endInsertColumns();
    return true;
}

int ListeNoteModel::rowCount(const QModelIndex & /*parent*/) const
    {return m_vectEleve.size();}

void ListeNoteModel::save()
{
    for(QVector<MapPtr<Note>>::const_iterator i = m_dataN.cbegin(); i != m_dataN.cend(); ++i)
        m_bdd->save(*i);
}

bool ListeNoteModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole && index.column() >= NbrDonneeEleve)
    {
        m_dataN.at(index.column()-NbrDonneeEleve)[m_vectEleve[index.row()].id()]->setValeur(value.toInt());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}
