/*Auteur: PERCIE DU SERT Maxime
 *Date: 23/05/2016
 */
#ifndef VECTORENTITIES_H
#define VECTORENTITIES_H

#include <QList>
#include <QVector>
#include <QMessageBox>

#include "ListEntities.h"

/*! \ingroup groupeEntity
 * \brief Classe patron des vector d'entités.
 *
 */
template<class T> class VectorEntities : public QVector<T*>
{
public:
    class iterator
    {
    protected:
        typedef T * const * iter;
        iter m_ptr;

    public:
        //! Constructeur.
        iterator(iter ptr = 0)
            : m_ptr(ptr)
        {}

        //! Constructeur.
        iterator(const iterator & i)
            : m_ptr(i.m_ptr)
        {}

        //! Opérator d'affectation
        iterator & operator =(const iterator & i)
            {m_ptr = i.m_ptr; return *this;}

        //! Opérator d'affectation
        iterator & operator =(iter ptr)
            {m_ptr = ptr; return *this;}

        //! Opérator *
        T & operator *() const
            {return *(*m_ptr);}

        //! Opérateur de pré-incrémentation
        iterator &  operator ++()
            {++m_ptr; return *this;}

        //! Opérateur de post-incrémentation
        iterator operator ++(int /*n*/)
            {iterator i = *this; ++m_ptr; return i;}

        //! Opérateur de pré-décrémentation
        iterator &  operator --()
            {--m_ptr; return *this;}

        //! Opérateur de post-incrémentation
        iterator operator --(int /*n*/)
            {iterator i = *this; --m_ptr; return i;}

        //! Test d'égalité entre deux itérateurs.
        bool operator ==(const iterator & i) const
            {return m_ptr == i.m_ptr;}

        //! Test de différence entre deux itérateurs.
        bool operator !=(const iterator & i) const
            {return m_ptr != i.m_ptr;}

        //! Incrémente n fois l'itérateur.
        iterator & operator +=(int n)
            {m_ptr += n; return *this;}

        //! Décrémente n fois l'itérateur.
        iterator & operator -=(int n)
            {m_ptr -= n; return *this;}

        //! L'addition d'un itérateur i et d'un entier n produit une copie de l'itérateur i incrémenté n fois.
        iterator operator +(int n) const
        {
            iterator i(*this);
            return i += n;
        }

        //! La soustraction d'un itérateur i et d'un entier n produit une copie de l'itérateur i décrémenté n fois.
        iterator operator -(int n) const
        {
            iterator i(*this);
            return i -= n;
        }
    };

    using QVector<T*>::append;
    using QVector<T*>::begin;
    using QVector<T*>::cbegin;
    using QVector<T*>::cend;
    using QVector<T*>::end;
    using QVector<T*>::resize;
    using QVector<T*>::size;


    //! Constructeur par defaut.
    VectorEntities() = default;

    //! Constructeur de recopie.
    VectorEntities(const VectorEntities<T> & vect)
        : QVector<T*>(vect.size())
    {
        typename QVector<T*>::iterator j = begin();
        for(typename QVector<T*>::const_iterator i = vect.cbegin(); i != vect.cend(); ++i, ++j)
            *j = new T(**i);
    }

    //! Constructeur de déplacement
    VectorEntities(VectorEntities<T> && vect) = default;

    //! Constructeur à partir d'une liste d'entités.
    VectorEntities(const ListEntities<T> & liste);

    //! Constructeur à partir d'une liste d'entités temporaire.
    VectorEntities(ListEntities<T> && liste);

    //! Destructeur.
    ~VectorEntities()
    {
        for(typename QVector<T*>::const_iterator i = cbegin(); i != cend(); ++i)
            delete *i;
    }

    //! Ajoute un élément à la liste.
    void append(const T & value)
        {append(new T(value));}

    //! Renvoie une référence sur l'entité d'identifiant id si elle existe.
    iterator findId(int id);

    //! Affectation par copie d'une liste de type ListeEntities.
    VectorEntities<T> &operator =(const ListEntities<T> & liste);

    //! Affectation par déplacement du liste (temporaire) de type ListeEntities.
    VectorEntities<T> &operator =(ListEntities<T> && liste);

    //! Affectation par recopie.
    VectorEntities<T> &operator =(const VectorEntities<T> & vector);

    //! Affectation par déplacement.
    VectorEntities<T> &operator =(VectorEntities<T> && vector);

    //! Ajoute les éléments de liste à la suite de la liste.
    VectorEntities<T> &operator <<(const ListEntities<T> & liste);

    //! Ajoute les éléments de liste (temporaire) à la suite de la liste.
    VectorEntities<T> &operator <<(ListEntities<T> && liste);

    T & operator[](int n)
        {return *(QVector<T*>::operator[](n));}

    const T & operator[](int n) const
        {return *(QVector<T*>::operator[](n));}
};

template<class T> typename VectorEntities<T>::iterator VectorEntities<T>::findId(int id)
{
    iterator i = begin();
    while(i != end() && (*i).id() != id)
    {
        ++i;
    }
    return i;
}

template<class T> VectorEntities<T>::VectorEntities(const ListEntities<T> & liste)
    : QVector<T*>(liste.size())
{
    if(!liste.isEmpty())
    {
        typename QVector<T*>::iterator i = begin();
        for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
            *i = new T(*liste.currentPtr());
    }
}

template<class T> VectorEntities<T>::VectorEntities(ListEntities<T> && liste)
    : QVector<T*>(liste.size())
{
    if(!liste.isEmpty())
    {
        typename QVector<T*>::iterator i = begin();
        for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
            *i = liste.currentPtr();
    }
    liste.clearList();
}

template<class T> VectorEntities<T> & VectorEntities<T>::operator =(const ListEntities<T> & liste)
{
    for(typename QVector<T*>::const_iterator i = cbegin(); i != cend(); ++i)
        delete *i;
    QVector<T*>::clear();
    if(!liste.isEmpty())
    {
        resize(liste.size());
        typename QVector<T*>::iterator i = begin();
        for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
            *i = new T(*liste.currentPtr());
    }
    return *this;
}

template<class T> VectorEntities<T> & VectorEntities<T>::operator =(ListEntities<T> && liste)
{
    for(typename QVector<T*>::const_iterator i = cbegin(); i != cend(); ++i)
        delete *i;
    QVector<T*>::clear();
    if(!liste.isEmpty())
    {
        resize(liste.size());
        typename QVector<T*>::iterator i = begin();
        for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
            *i = liste.currentPtr();
    }
    liste.clearList();
    return *this;
}

template<class T> VectorEntities<T> & VectorEntities<T>::operator =(const VectorEntities<T> & vector)
{
    for(typename QVector<T*>::const_iterator i = cbegin(); i != cend(); ++i)
        delete *i;
    QVector<T*>::clear();
    if(!vector.isEmpty())
    {
        resize(vector.size());
        typename QVector<T*>::iterator i = begin();
        for(typename QVector<T*>::iterator j = vector.begin(); j != vector.end(); ++j, ++i)
            *i = new T(*j);
    }
    return *this;
}

template<class T> VectorEntities<T> & VectorEntities<T>::operator =(VectorEntities<T> && vector)
{
    for(typename QVector<T*>::const_iterator i = cbegin(); i != cend(); ++i)
        delete *i;
    QVector<T*>::clear();
    if(!vector.isEmpty())
    {
        resize(vector.size());
        typename QVector<T*>::iterator i = begin();
        for(typename QVector<T*>::const_iterator j = vector.begin(); j != vector.end(); ++j, ++i)
        {
            *i = new T(*j);
        }
        vector.clear();
    }
    return *this;
}

template<class T> VectorEntities<T> & VectorEntities<T>::operator << (const ListEntities<T> & liste)
{
    if(!liste.isEmpty())
    {
        int n = size();
        resize(n + liste.size());
        typename QVector<T*>::iterator i = begin() + n;
        for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
            *i = new T(*liste.currentPtr());
    }
    return *this;
}

template<class T> VectorEntities<T> &VectorEntities<T>::operator <<(ListEntities<T> && liste)
{
    if(!liste.isEmpty())
    {
        int n = size();
        resize(n + liste.size());
        typename QVector<T*>::iterator i = begin() + n;
        for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
            *i = liste.currentPtr();
    }
    liste.clearList();
    return *this;
}

#endif // VECTORENTITIES_H
