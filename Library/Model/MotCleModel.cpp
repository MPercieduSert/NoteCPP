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
    for(QMap<int,int>::const_iterator i = m_idMotCleComp.cbegin(); i != m_idMotCleComp.cend(); ++i)
    {
        MotCle mot(i.key());
        m_bdd->get(mot);
        str.append(mot.nom());
        if(i.value() != m_idEntityList.count())
            str.append("*");
        str.append(",");
    }
    str.chop(1);
    return str;
}

void MotCleModel::setIdEntityList(const QList<int> & idEntityList)
{
    m_idEntityList = idEntityList;
    m_idMotCleComp.clear();
    for(QList<int>::const_iterator i = m_idEntityList.cbegin(); i != m_idEntityList.cend(); ++i)
    {
        ListPtr<CibleMotCle> cibleMotcleList(m_bdd->getList<CibleMotCle>(CibleMotCle::Cible,m_cible,CibleMotCle::IdCible,*i));
        for(ListPtr<CibleMotCle>::iterator j = cibleMotcleList.begin(); j != cibleMotcleList.end(); ++j)
        {
            if(!m_idMotCleComp.contains((*j).idMC()))
                m_idMotCleComp[(*j).idMC()] = 0;
            ++m_idMotCleComp[(*j).idMC()];
        }
    }

    emit changedIdEntityList(m_idEntityList);
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
