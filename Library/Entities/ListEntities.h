#ifndef LISTENTITIES_H
#define LISTENTITIES_H

#include <QList>
#include <QVector>
#include "Entity.h"

template<class T> class ListEntities
{
protected:
    QList<T*> * m_ptr_list;
    mutable typename QList<T*>::const_iterator m_iterator;
    mutable bool m_begin = false;

public:
    ListEntities() : m_ptr_list(new QList<T*>)      {}
    ListEntities(const ListEntities<T> & liste) : m_ptr_list(liste.m_ptr_list)  {}
    void append(T* entity)                          {m_ptr_list->append(entity);}
    const T & at(int n) const                       {return *((*m_ptr_list).at(n));}
    void begin() const                              {m_iterator = m_ptr_list->cbegin(); m_begin = true;}
    void clearAll()
    {
        for(typename QList<T*>::const_iterator i = m_ptr_list->cbegin(); i != m_ptr_list->cend(); ++i) delete *i;
        delete m_ptr_list;
    }
    void clearList()                                {delete m_ptr_list;}
    const T & current() const                       {return **m_iterator;}
    T * currentPtr() const                          {return *m_iterator;}
    bool isEmpty() const                            {return m_ptr_list->empty();}
    bool next() const
    {
        if(m_begin)
        {
            m_begin = false;
        }
        else
        {
            ++m_iterator;
        }
        return m_iterator != m_ptr_list->cend();
    }
    int size() const                                {return m_ptr_list->size();}
    ListEntities & operator << (T * entity)         {append(entity); return *this;}
    ListEntities & operator << (ListEntities<Entity> liste)
    {
        if(!liste.isEmpty())
        {
            //m_ptr_list->reserve(size()+liste.size());
            liste.begin();
            do m_ptr_list->append(T::convert(liste.currentPtr()));while(liste.sstNext());
        }
        liste.clearList();
        return *this;
    }
    ListEntities & operator >> (T & entity)         {entity<<**m_iterator; ++m_iterator;return *this;}
    bool sstNext() const
    {
        ++m_iterator;
        return m_iterator != m_ptr_list->cend();
    }
    static QVector<T> vector(ListEntities<Entity> liste)
    {
        QVector<T> vector(liste.size());
        if(!liste.isEmpty())
        {
            typename QVector<T>::iterator i = vector.begin();
            liste.begin();
            do
            {
                *i = *(T::convert(liste.currentPtr()));
                ++i;
            }
            while(liste.sstNext());
        }
        liste.clearAll();
        return vector;
    }
    static void vector(QVector<T> & vector, ListEntities<Entity> liste)
    {
        vector.resize(liste.size());
        if(!liste.isEmpty())
        {
            typename QVector<T>::iterator i = vector.begin();
            liste.begin();
            do
            {
                 *i = *(T::convert(liste.currentPtr()));
                ++i;
            }
            while(liste.sstNext());
        }
        liste.clearAll();
    }
};

#endif // LISTENTITIES_H
