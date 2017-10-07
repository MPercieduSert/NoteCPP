#include "MotCleModel.h"

MotCleModel::MotCleModel(Bdd *bd, int cible, QObject *parent)
    : TreeModelReadTemp<MotCle>(QList<MotCle::Position>()<<MotCle::Nom,parent),
      m_bdd(bd),
      m_cible(cible)
{
    setTreeMotCle();
}

QString MotCleModel::dataListeNomMotCle() const
{
    QString str;
    for(QMap<int,bool>::const_iterator i = m_idMotCle.cbegin(); i != m_idMotCle.cend(); ++i)
    {
        MotCle mot(i.key());
        m_bdd->get(mot);
        str.append(mot.nom());
        if(i.value())
            str.append("*");
        str.append(",");
    }
    str.chop(1);
    return str;
}

void MotCleModel::setIdSet(const QSet<int> & idSet)
{
    m_idSet = idSet;
    m_idMotCle.clear();
    int newValue = Tous;
    for(QSet<int>::const_iterator i = m_idSet.cbegin(); i != m_idSet.cend(); ++i)
    {
        ListPtr<CibleMotCle> cibleMotcleList(m_bdd->getList<CibleMotCle>(CibleMotCle::Cible,m_cible,CibleMotCle::IdCible,*i));
        for(ListPtr<CibleMotCle>::iterator j = cibleMotcleList.begin(); j != cibleMotcleList.end(); ++j)
        {
            QMap<int,bool>::iterator k = m_idMotCle.find((*j).idMC());
            if(k == m_idMotCle.end())
                m_idMotCle[(*j).idMC()] = newValue;
            else if(*k == TousJusquaPresent)
                *k = Tous;
        }
        for(QMap<int,bool>::iterator k = m_idMotCle.begin(); k != m_idMotCle.end(); ++k)
        {
            if(*k == TousJusquaPresent)
                *k = PasTous;
        }
        newValue = PasTous;
    }
    emit changedIdSet(m_idSet);
}

void MotCleModel::setTreeMotCle()
{
    setDataTree((m_bdd->getArbre<MotCle>()).elagageFeuilleData(
                                 [this](const MotCle & motCle)->bool
                                 {
                                    MotClePermission perm(motCle.id(),m_cible);
                                    m_bdd->getUnique(perm);
                                    return perm.num() != bdd::motClePermissionNum::InterditMCNum;
                                 }));
}
