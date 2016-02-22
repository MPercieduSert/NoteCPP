#ifndef MANAGERTEMP_H
#define MANAGERTEMP_H

#include "Manager.h"

template<class T> class ManagerTemp : public Manager
{
public:
    ManagerTemp(QSqlDatabase & bdd, const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique);
    ManagerTemp(const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique);
    virtual ~ManagerTemp()  {}
    bool exists(const Entity & entity)
    {
        T::convert(entity);
        m_requete.prepare(m_sqlExists);
        m_requete.bindValue(0,entity.id());
        m_requete.exec();
        affError();
        bool bb = m_requete.next();
        m_requete.finish();
        return bb;
    }
    bool existsUnique(Entity & entity)
    {
        m_requete.prepare(m_sqlExistsUnique);
        bindValuesUnique(T::convert(entity));
        m_requete.exec();
        affError();
        if(m_requete.next())
        {
            entity.setId(m_requete.value(0).toInt());
            m_requete.finish();
            return true;
        }
        else
        {
            m_requete.finish();
            return false;
        }
    }
    bool sameInBdd(const Entity &entity)
    {
        T entityT(entity.id());
        if(get(entityT))
        {
            return entityT == entity;
        }
        else
        {
            return false;
        }
    }
    bool get(Entity & entity)
    {
        m_requete.prepare(m_sqlGet);
        m_requete.bindValue(0,entity.id());
        m_requete.exec();
        affError();
        if(m_requete.next())
        {
            fromRequete(T::convert(entity));
            m_requete.finish();
            return true;
        }
        else
        {
            m_requete.finish();
            return false;
        }
    }
    /*ListEntities<Entity> getList()
    {
        m_requete.prepare(m_sqlGetList+"id");
        return listFormRequete();
    }*/

    ListEntities<Entity> getList(int ordre)
    {
        m_requete.prepare(m_sqlGetList+m_colonne.at(ordre));
        return listFormRequete();
    }
    /*ListEntities<Entity> getList(int cle, const QVariant & value)
    {
        m_requete.prepare(m_sqlGetListWhere.arg(m_colonne.at(cle))+" ORDER BY id");
        m_requete.bindValue(0,value);
        return listFormRequete();
    }*/
    ListEntities<Entity> getList(int cle, const QVariant & value, int order)
    {
        m_requete.prepare(m_sqlGetListWhere.arg(m_colonne.at(cle))+QString(" ORDER BY ").append(m_colonne.at(order)));
        m_requete.bindValue(0,value);
        return listFormRequete();
    }
    ListEntities<Entity> getList(int cle, const QVariant & value, int order1, int order2)
    {
        m_requete.prepare(m_sqlGetListWhere.arg(m_colonne.at(cle))+QString(" ORDER BY ").append(m_colonne.at(order1)).append(",").append(m_colonne.at(order2)));
        m_requete.bindValue(0,value);
        return listFormRequete();
    }
    /*ListEntities<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2)
    {
        m_requete.prepare(m_sqlGetListWhere.arg(m_colonne.at(cle1))+QString("AND ").append(m_colonne.at(cle2)).append("=? ORDER BY id"));
        m_requete.bindValue(0,value1);
        m_requete.bindValue(1,value2);
        return listFormRequete();
    }*/
    ListEntities<Entity> getList(int cle1, int cle2, const QVariant & value1, const QVariant & value2, int order)
    {
        m_requete.prepare(m_sqlGetListWhere.arg(m_colonne.at(cle1))+
                          QString("AND ").append(m_colonne.at(cle2)).append("=? ORDER BY ").append(m_colonne.at(order)));
        m_requete.bindValue(0,value1);
        m_requete.bindValue(1,value2);
        return listFormRequete();
    }

protected:
    bool add(Entity & entity)
    {
        m_requete.prepare(m_sqlAdd);
        bindValues(T::convert(entity));
        if(m_requete.exec())
        {
            m_requete.exec("SELECT last_insert_rowid() FROM annee");
            m_requete.next();
            affError();
            entity.setId(m_requete.value(0).toInt());
            m_requete.finish();
            return true;
        }
        else
        {
            affError();
            return false;
        }
    }
    bool add(const Entity & entity)
    {
        m_requete.prepare(m_sqlAdd);
        bindValues(T::convert(entity));
        if(m_requete.exec())
        {
            m_requete.finish();
            return true;
        }
        else
        {
            affError();
            return false;
        }
    }
    void affError() const
    {
        QSqlError err = m_requete.lastError();
        if(err.type() != QSqlError::NoError)
        {
            QMessageBox::critical(0,err.text(),err.text()+"\n"+err.nativeErrorCode()+"\n"+m_requete.lastQuery());
        }
    }
    virtual void bindValues(const T & entity) = 0;
    virtual void bindValuesUnique(const T & entity) = 0;
    virtual void fromRequete(T & entity)= 0;
    ListEntities<Entity> listFormRequete()
    {
        m_requete.exec();
        affError();
        ListEntities<Entity> liste;
        while(m_requete.next())
        {
            liste.append(newFromRequete());
        }
        return liste;
    }
    virtual T * newFromRequete() = 0;
    bool modify(const Entity & entity)
    {
        m_requete.prepare(m_sqlModify);
        bindValues(T::convert(entity));
        m_requete.bindValue(nbrColonne(),entity.id());
        bool bb = m_requete.exec();
        affError();
        m_requete.finish();
        return bb;
    }
    /*bool verifEntity(const Entity & entity) const {return T::IdEntity == entity.idEntity();}
    T & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((T *) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

template<class T> ManagerTemp<T>::ManagerTemp(QSqlDatabase &bdd, const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique)
    :Manager(bdd,tableName,colonne,colonneUnique) {}
template<class T> ManagerTemp<T>::ManagerTemp(const QString &tableName, const QVector<QString> & colonne, const QVector<int> &colonneUnique)
    :Manager(tableName,colonne,colonneUnique) {}

#endif // MANAGERTEMP_H
