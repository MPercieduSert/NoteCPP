#ifndef MANAGER_H
#define MANAGER_H

#include <QMessageBox>
#include <QSqlError>

#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include "../Entities/Entity.h"
#include "../Entities/ListEntities.h"

class Manager
{
protected:
    const QVector<QString> m_colonne;
    const QVector<int> m_colonneUnique;
    QSqlQuery m_requete;
    QString m_sqlAdd;
    QString m_sqlExists;
    QString m_sqlExistsUnique;
    QString m_sqlGet;
    QString m_sqlGetList;
    QString m_sqlGetListWhere;
    QString m_sqlModify;
    QString m_tableName;

public:
    Manager(QSqlDatabase & bdd, const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique);
    Manager(const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique);
    virtual ~Manager()  {}
    virtual bool exists(const Entity & entity) = 0;
    virtual bool existsUnique(Entity & entity) = 0;
    virtual bool get(Entity & entity) = 0;
    //virtual ListEntities<Entity> getList() = 0;
    virtual ListEntities<Entity> getList(int ordre) = 0;
    //virtual ListEntities<Entity> getList(int cle, const QVariant & value) = 0;
    virtual ListEntities<Entity> getList(int cle, const QVariant & value, int order) = 0;
    virtual ListEntities<Entity> getList(int cle, const QVariant & value, int order1, int order2) = 0;
    //virtual ListEntities<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2) = 0;
    virtual ListEntities<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int order) = 0;
    bool getUnique(Entity & entity)
    {
        if(existsUnique(entity))
        {
            return get(entity);
        }
        else
        {
            return false;
        }
    }
    int nbrColonne() const {return m_colonne.size();}
    virtual bool sameInBdd(const Entity & entity) = 0;
    bool save(Entity & entity)
    {
        if(entity.isValid())
        {
            if(entity.isNew())
            {
                return add(entity);
            }
            else
            {
                if(sameInBdd(entity))
                {
                    return true;
                }
                else
                {
                    return modify(entity);
                }
            }
        }
        else
        {
            QMessageBox::critical(0,"",messageErreurs(entity));
            return false;
        }
    }
    bool save(const Entity & entity)
    {
        if(entity.isValid())
        {
            if(entity.isNew())
            {
                return add(entity);
            }
            else
            {
                if(sameInBdd(entity))
                {
                    return true;
                }
                else
                {
                    return modify(entity);
                }
            }
        }
        else
        {
            QMessageBox::critical(0,"",messageErreurs(entity));
            return false;
        }
    }
    void setBdd(QSqlDatabase & bdd)
    {
        m_requete = QSqlQuery(bdd);
    }
protected:
    virtual bool add(Entity & entity) = 0;
    virtual bool add(const Entity & entity) = 0;
    QString messageErreurs(const Entity & entity) const;
    virtual bool modify(const Entity & entity) = 0;
    void writeStringQuery();
};

#endif // MANAGER_H
