#include "TreeModelMotCle.h"

TreeModelMotCle::TreeModelMotCle(Bdd * bdd, QObject *parent)
    : TreeModelEditTemp<MotCle>(QList<typename MotCle::Position>(), parent), m_bdd(bdd)
{
    m_cibleList[BaremeIndex] = Cible<Bareme>::value;
    m_cibleList[CommentaireIndex] = Cible<Commentaire>::value;
    m_cibleList[ControleIndex] = Cible<Controle>::value;
    m_cibleList[CoursIndex] = Cible<Cours>::value;
    m_cibleList[EnonceIndex] = Cible<Enonce>::value;
    m_cibleList[ExerciceIndex] = Cible<Exercice>::value;
    m_cibleList[MotCleIndex] = Cible<MotCle>::value;
    m_cibleList[TexteIndex] = Cible<Texte>::value;
    m_cibleList[TypeControleIndex] = Cible<TypeControle>::value;
    m_cibleList[TypeUtilisationIndex] = Cible<TypeUtilisation>::value;
    m_cibleList[UtilisationIndex] = Cible<Utilisation>::value;

    m_header.append(tr("Nom"));
    m_header.append(tr("Nom court"));
    m_headerPerm[BaremeIndex] = QString("Bareme");//Bareme::Name();
    m_headerPerm[CommentaireIndex] = QString("Commentaire");//Commentaire::Name();
    m_headerPerm[ControleIndex] = Controle::Name();
    m_headerPerm[CoursIndex] = Cours::Name();
    m_headerPerm[EnonceIndex] = QString("Enoncé");//Enonce::Name();
    m_headerPerm[ExerciceIndex] = Exercice::Name();
    m_headerPerm[MotCleIndex] = MotCle::Name();
    m_headerPerm[TexteIndex] = QString("Texte");//Texte::Name();
    m_headerPerm[TypeControleIndex] = TypeControle::Name();
    m_headerPerm[TypeUtilisationIndex] = QString("TypeUtilisation");//TypeUtilisation::Name();
    m_headerPerm[UtilisationIndex] = Utilisation::Name();

    QMap<int,int> cibleToIndex;
    cibleToIndex[Cible<Bareme>::value] = BaremeIndex;
    cibleToIndex[Cible<Commentaire>::value] = CommentaireIndex;
    cibleToIndex[Cible<Controle>::value] = ControleIndex;
    cibleToIndex[Cible<Cours>::value] = CoursIndex;
    cibleToIndex[Cible<Enonce>::value] = EnonceIndex;
    cibleToIndex[Cible<Exercice>::value] = ExerciceIndex;
    cibleToIndex[Cible<MotCle>::value] = MotCleIndex;
    cibleToIndex[Cible<Texte>::value] = TexteIndex;
    cibleToIndex[Cible<TypeControle>::value] = TypeControleIndex;
    cibleToIndex[Cible<TypeUtilisation>::value] = TypeUtilisationIndex;
    cibleToIndex[Cible<Utilisation>::value] = UtilisationIndex;

    setDataTree(m_bdd->getArbre<MotCle>());
    int id;
    for(TreeItem<MotCle>::iterator i = m_tree.begin(); i != m_tree.end(); ++i)
    {
        id = (*i)->data().id();
        std::fill(m_permission[id].begin(),m_permission[id].end(),bdd::motClePermissionNum::InterditMCNum);
        ListPtr<MotClePermission> listPerm = m_bdd->getList<MotClePermission>(MotClePermission::IdMC, (*i)->data().id());
        for(ListPtr<MotClePermission>::iterator j = listPerm.begin(); j != listPerm.end(); ++j)
            m_permission[id][cibleToIndex.value((*j).cible())] = (*j).num();
    }
}

bool TreeModelMotCle::autorisation(const QModelIndex & index, bdd::Autorisation autoris) const
{
    if(autoris == bdd::Autorisation::Suppr)
        return m_bdd->getAutorisation(getItem(index)->data(),autoris);
    if(autoris == bdd::Autorisation::Modif)
    {
        if(index.column() < NbrColumnMotCle)
            return m_bdd->getAutorisation(getItem(index)->data(),autoris);
        else
        {
            MotClePermission perm(getItem(index)->data().id(),cible(index));
            return !m_bdd->getUnique(perm) || m_bdd->getAutorisation(perm,bdd::Modif);
        }
    }
    return TreeModelMotCle::autorisation(index,autoris);
}


QVariant TreeModelMotCle::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole && role != Qt::FontRole && role != Qt::ForegroundRole)
        return QVariant();

    TreeItem<MotCle> *item = getItem(index);
    if(index.column() ==  NomMotCleIndex)
    {
        if(role == Qt::DisplayRole || role == Qt::EditRole)
            return item->data().nom();
    }
    else if(index.column() ==  NcMotCleIndex)
    {
        if(role == Qt::DisplayRole || role == Qt::EditRole)
            return item->data().nc();
    }
    else if(index.column() < NbrColumnMotCle + NbrIndex)
    {
        switch (role) {
        case Qt::DisplayRole:
            return m_permission.value(item->data().id()).at(index.column() - NbrColumnMotCle) == bdd::motClePermissionNum::InterditMCNum ? QString("\uF051") : QString("\uF052");
        case Qt::EditRole:
            return m_permission.value(item->data().id()).at(index.column() - NbrColumnMotCle);
        case Qt::FontRole:
            return QFont("Wingdings 2");
        case Qt::ForegroundRole:
            return m_permission.value(item->data().id()).at(index.column() - NbrColumnMotCle) == bdd::motClePermissionNum::InterditMCNum ? QColor(Qt::red) : QColor(Qt::green);
        }
    }
    return QVariant();
}

Qt::ItemFlags TreeModelMotCle::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    if(!autorisation(index,bdd::Autorisation::Modif))
        return QAbstractItemModel::flags(index);
    return TreeModelEditTemp::flags(index);
}

QVariant TreeModelMotCle::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if(section < NbrColumnMotCle)
            return m_header.at(section);
        else if(section < NbrColumnMotCle + NbrIndex)
            return m_headerPerm.at(section - NbrColumnMotCle);
    }
    return QVariant();
}

bool TreeModelMotCle::hydrateNewEntity(MotCle & entity, int row, const QModelIndex &parent)
{
    NewMotCleDialog diag(getItem(parent)->data().nom(),row+1);
    if(diag.exec())
    {
        NewMotCleDialog::dialogResult result = diag.value();
        entity.setNom(result.nom);
        entity.setNc(result.nc);
        m_bdd->save(entity,getItem(parent)->data(),row);
        std::fill(m_permission[entity.id()].begin(),m_permission[entity.id()].end(),bdd::motClePermissionNum::InterditMCNum);
        return true;
    }
    else
        return false;
}

int TreeModelMotCle::id(const QModelIndex & index) const
{
    if(!index.isValid())
        return 0;
    return getItem(index)->data().id();
}

bool TreeModelMotCle::removeEntity(const MotCle & entity)
{
    if(QMessageBox::question(0,tr("Suppression d'un mot clé"),QString(tr("Êtes-vous certain de vouloir supprimer le mot clé : ").append(entity.nom()).append(".")),QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
        return m_bdd->del(entity);
    return false;
}

bool TreeModelMotCle::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid() || role != Qt::EditRole)
        return false;
    if(index.column() == NomMotCleIndex)
    {
        getItem(index)->modifData().setNom(value.toString());
        m_bdd->save(getItem(index)->data());
        return true;
    }
    else if(index.column() == NcMotCleIndex)
    {
        getItem(index)->modifData().setNc(value.toString());
        m_bdd->save(getItem(index)->data());
        return true;
    }
    else if(NbrColumnMotCle <= index.column() && index.column() < NbrColumn)
    {
        m_permission[getItem(index)->data().id()][index.column() - NbrColumnMotCle] = value.toInt();
        MotClePermission perm(getItem(index)->data().id(), cible(index) , value.toInt());
        m_bdd->saveUnique(perm);
        return true;
    }
    return false;
}
