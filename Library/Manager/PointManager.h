#ifndef POINTMANAGER_H
#define POINTMANAGER_H

#include "ManagerAnnee.h"
#include "../Entities/Point.h"

class PointManager : public ManagerAnnee<Point>
{
public:
    PointManager(const Annee & annee);
    PointManager(QSqlDatabase & bdd, const Annee & annee);
     ~PointManager() {}

protected:
     void bindValues(const Point & point)
    {
        m_requete.bindValue(0,point.bareme());
        m_requete.bindValue(1,point.commentaire());
        m_requete.bindValue(2,point.date());
        m_requete.bindValue(3,point.note());
        m_requete.bindValue(4,point.saisie());
        m_requete.bindValue(5,point.valeur());
    }
     void bindValuesUnique(const Point &point)
    {
        m_requete.bindValue(0,point.bareme());
        m_requete.bindValue(1,point.note());
    }
     void fromRequete(Point & point)
    {
        point.setBareme(m_requete.value(0).toInt());
        point.setCommentaire(m_requete.value(1).toInt());
        point.setDate(m_requete.value(2).toDateTime());
        point.setNote(m_requete.value(3).toInt());
        point.setSaisie(m_requete.value(4).toBool());
        point.setValeur(m_requete.value(5).toInt());
    }
     Point * newFromRequete()
    {
        return new Point(m_requete.value(1).toInt(),
                         m_requete.value(2).toInt(),
                         m_requete.value(3).toDateTime(),
                         m_requete.value(4).toInt(),
                         m_requete.value(5).toBool(),
                         m_requete.value(6).toInt(),
                         m_requete.value(0).toInt());
    }
};

#endif // POINTMANAGER_H
