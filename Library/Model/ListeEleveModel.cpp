#include "ListeEleveModel.h"

ListeEleveModel::ListeEleveModel(Bdd *bdd, const Classe &classe, QObject *parent)
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
    m_dataE = m_bdd->getVector<Eleve,ClasseEleve>(Eleve::Id,
                                               ClasseEleve::IdEl,
                                               QMap<int,QVariant>(),
                                               where,
                                               order);

    m_header<<tr("Nom")<<tr("Prenom")<<tr("Fille/Garçon")<<tr("Date de naissance");//<<tr("Départ")<<tr("Date de départ");
}

int ListeEleveModel::columnCount(const QModelIndex & /*parent*/) const
{
    return NbrDonneeEleve + m_dataD.count();
}

QVariant ListeEleveModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && (role == Qt::DisplayRole || role == Qt::EditRole))
    {
        if(index.column() < NbrDonneeEleve)
        {
            switch (index.column())
            {
            case NomIndex:
                return QVariant(m_dataE[index.row()].nom());
                break;
            case PrenomIndex:
                return QVariant(m_dataE[index.row()].prenom());
                break;
            case SexeIndex:
                return QVariant(m_dataE[index.row()].afficheFille());
                break;
            case NaissanceIndex:
                return QVariant(m_dataE[index.row()].naissance());
                break;
            }
        }
        else
            return m_dataD.at(index.column()-NbrDonneeEleve)[index.row()].valeur();
    }
    return QVariant();
}

Qt::ItemFlags ListeEleveModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
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

bool ListeEleveModel::insertColumn(const Donnee &dn)
{
    beginInsertColumns(QModelIndex(),columnCount(),columnCount());
    m_header.append(dn.nom());
    VectorPtr<CibleDonnee> vectDn(rowCount(),CibleDonnee(dn.id(),0,bdd::cible::EleveCb,0));
    for(int i = 0; i != rowCount(); ++i)
    {
        vectDn[i].setIdCible(m_dataE.at(i)->id());
        m_bdd->getUnique(vectDn[i]);
    }
    m_dataD.append(vectDn);
    endInsertColumns();
    return true;
}

bool ListeEleveModel::insertRows(int position, int rows, const QModelIndex & /*parent*/)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row)
        m_dataE.insert(position, new Eleve());
    endInsertRows();
    return true;
}
bool ListeEleveModel::removeRows(int position, int rows, const QModelIndex & /*parent*/)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row)
    {
        m_dataE.removeAt(position);
        for(QVector<VectorPtr<CibleDonnee>>::iterator i = m_dataD.begin(); i != m_dataD.end(); ++i)
            i->removeAt(position);
    }
    endRemoveRows();
    return true;
}
int ListeEleveModel::rowCount(const QModelIndex & /*parent*/) const
    {return m_dataE.size();}

void ListeEleveModel::save()
{
    m_bdd->save(m_dataE);
    for(QVector<VectorPtr<CibleDonnee>>::const_iterator i = m_dataD.cbegin(); i != m_dataD.cend(); ++i)
        m_bdd->save(*i);
}

bool ListeEleveModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        if(index.column() < NbrDonneeEleve)
        {
            switch (index.column()) {
            case NomIndex:
                m_dataE[index.row()].setNom(value.toString());
                break;
            case PrenomIndex:
                m_dataE[index.row()].setPrenom(value.toString());
                break;
            case SexeIndex:
                m_dataE[index.row()].setFille(value.toBool());
                break;
            case NaissanceIndex:
                m_dataE[index.row()].setNaissance(value.toDate());
                break;
            /*case abandonIndex:
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
                break;*/
            }
        }
        else
            m_dataD[index.column()-NbrDonneeEleve][index.row()].setValeur(value);

        emit dataChanged(index, index);
        return true;
    }
    return false;
}
