/*Auteur: PERCIE DU SERT Maxime
 *Date: 09/09/2016
 */
#ifndef LISTPTR_H
#define LISTPTR_H

#include <QList>
#include <QVector>

#include "Macro.h"


/*! \defgroup groupeDivers Divers
 * \brief Ensemble de classes diverses.
 */

/*! \ingroup groupeDivers
 * \brief Classe patron des listes de de pointeurs utilisées.
 */

template<class T> class ListPtr : public QList<T*>
{
public:
    class iterator : public QList<T*>::const_iterator
    {
    public:
        using QList<T*>::const_iterator::const_iterator;

        //! Constructeur.
        iterator(const typename QList<T*>::const_iterator & i) : QList<T*>::const_iterator(i)
            {}

        //! Opérateur *.
        T & operator *() const
            {return *(QList<T*>::const_iterator::operator *());}

        //! Opérateur [].
        T & operator [](int n) const
            {return *(QList<T*>::const_iterator::operator [](n));}
    };

public:
    using QList<T*>::append;
    using QList<T*>::operator <<;

    CONSTR_DEFAUT(ListPtr)

    //! Constructeur de recopie.
    ListPtr(const ListPtr<T> & liste)
    {
        for(typename QList<T*>::const_iterator i = liste->cbeginPtr(); i != liste->cendPtr(); ++i)
            append(new T(*i));
    }

    //! Constructeur de déplacement.
    ListPtr(ListPtr<T> && ) = default;

    //! Destructeur.
    ~ListPtr()
    {
        for(typename QList<T*>::const_iterator i = cbeginPtr(); i != cendPtr(); ++i)
            delete *i;
    }

    //! Ajoute un pointeur à la fin de la liste.
    void append(const T & entity)
        {append(new T(entity));}

    //! Retourne une référence constante sur la n-ième entité de la listes.
    const T & at(int n) const
        {return *(at(n));}

    //! Renvoie un itérateur sur le début de la liste.
    iterator begin() const
        {return QList<T*>::cbegin();}

    //! Renvoie un itérateur sur le début de la liste.
    typename QList<T*>::const_iterator cbeginPtr() const
        {return QList<T*>::cbegin();}

    //! Renvoie un itérateur sur la fin de la liste.
    typename QList<T*>::const_iterator cendPtr() const
        {return QList<T*>::cend();}

    //! Renvoie un itérateur sur la fin de la liste.
    iterator end() const
        {return QList<T*>::cend();}

    //! Supprime toutes les entités pointées par les pointeurs de la liste.
    void clear()
    {
        for(typename QList<T*>::const_iterator i = cbeginPtr(); i != cendPtr(); ++i)
            delete *i;
        QList<T*>::clear();
    }

    //! Supprime la liste des pointeurs, sans supprimer les entités pointés par les pointeurs composants cette liste.
    void clearList()
        {QList<T*>::clear();}

    //! Affectation par copie
    ListPtr<T> & operator = (const ListPtr<T> & liste)
    {
        clear();
        for(typename QList<T*>::const_iterator i = liste->cbeginPtr(); i != liste->cendPtr(); ++i)
            append(new T(*i));
        return *this;
    }

    //! Affectation par déplacement
    ListPtr<T> & operator = (ListPtr<T> && ) = default;

    //! Ajoute un pointeur sur une entité à la liste (ce pointeur doit être créer dynamiquement).
    ListPtr<T> & operator << (T * entity)
        {append(entity); return *this;}
};

#endif // LISTPTR_H
