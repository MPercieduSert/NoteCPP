#ifndef MANAGERANNEE_H
#define MANAGERANNEE_H

#include <QRegExp>
#include "ManagerSql.h"
#include "../Entities/Annee.h"

template<class T> class ManagerAnnee : public ManagerSql<T>
{
protected:
    Annee m_annee;
public:
    ManagerAnnee(QSqlDatabase & bdd, const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique, const Annee & annee);
    ManagerAnnee(const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique, const Annee & annee);
    virtual ~ManagerAnnee() {}
    void setAnnee(const Annee & annee)
    {
        m_annee = annee;
        Manager::m_tableName.remove(QRegExp("[0-9]"));
        Manager::m_tableName.append(annee.id());
        Manager::writeStringQuery();
    }
};

template<class T> ManagerAnnee<T>::ManagerAnnee(QSqlDatabase & bdd, const QString &tableName, const QVector<QString> &colonne, const QVector<int> &colonneUnique, const Annee &annee):
    ManagerSql<T>(bdd, tableName+"_"+QString::number(annee.id()),colonne,colonneUnique), m_annee(annee) {}

template<class T> ManagerAnnee<T>::ManagerAnnee(const QString &tableName, const QVector<QString> &colonne, const QVector<int> &colonneUnique, const Annee &annee):
    ManagerSql<T>(tableName+"_"+QString::number(annee.id()),colonne,colonneUnique), m_annee(annee) {}

/*template<class T> void ManagerAnnee<T>::setAnnee(const Annee & annee)
{
    m_annee = annee;
    m_tableName.remove(QRegExp("[0-9]"));
    m_tableName.append(annee.id());
    writeStringQuery();
}*/

#endif // MANAGERANNEE_H
