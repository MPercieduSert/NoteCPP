/*Auteur: PERCIE DU SERT Maxime
 *Date: 03/03/2016
 */

#ifndef LISTENTITIES_H
#define LISTENTITIES_H

#include <QList>
#include <QVector>
#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Classe patron des listes d'entitées utilisées par les méthodes de type GetList des manageurs.
 *
 * Classe patron des listes d'entitées utilisées par les méthodes de type GetList des manageurs.
 * Ces listes contiennent les pointeurs vers des entitées créée dynamiquement par les méthodes GetList des manageurs
 * qu'il faut penser à supprimer après utilisation grâce à la méthode clear().
 */

template<class T> class ListEntities
{
protected:
    QList<T*> * m_ptr_list;     //! Pointeur sur la liste des pointeurs d'entitées.
    mutable typename QList<T*>::const_iterator m_iterator; //! Itérateur permettant de parcourir les éléments.

public:
    //! Constructeur par défaut.
    ListEntities()
        : m_ptr_list(new QList<T*>)
        {}

    //! Constructeur de recopie.
    ListEntities(const ListEntities<T> & liste)
        : m_ptr_list(liste.m_ptr_list)
        {}

    //! Ajoute un pointeur à la fin de la liste.
    void append(T* entity)
        {m_ptr_list->append(entity);}

    //! Retourne une référence constante sur la n-ième entitée de la listes.
    const T & at(int n) const
        {return *((*m_ptr_list).at(n));}

    //! Place l'itérateur au début de la liste.
    void begin() const
        {m_iterator = m_ptr_list->cbegin();}

    //! Supprime toutes les entitées pointées par les pointeurs de la liste.
    void clear()
    {
        for(typename QList<T*>::const_iterator i = m_ptr_list->cbegin(); i != m_ptr_list->cend(); ++i) delete *i;
        delete m_ptr_list;
    }

    //! Supprime la liste des pointeurs.
    void clearList()
        {delete m_ptr_list;}

    //! Renvoie le pointeur sur l'élément courant de la liste.
    T * currentPtr() const
        {return *m_iterator;}

    //! Teste si la liste est vide.
    bool isEmpty() const
        {return m_ptr_list->empty();}

    //! Teste si l'élément courant n'est pas placé après la fin de la liste.
    bool isNotEnd() const
        {return m_iterator != m_ptr_list->cend();}

    //! Renvoie le nombre d'entitées de la liste.
    int size() const
        {return m_ptr_list->size();}

    //! Renvoie une référence constante sur l'élément courant de la liste.
    const T & operator *() const
        {return **m_iterator;}

    //! Pré-incrémentation: Déplacement l'élément courant sur l'élément suivant.
    ListEntities & operator ++()
        {++m_iterator; return *this;}

    //! Ajoute un pointeur sur une entitée à la liste (ce pointeur doit être créer dynamiquement).
    ListEntities & operator << (T * entity)
        {append(entity); return *this;}

    //! Ajoute les éléments de liste à la suite de la liste.
    ListEntities & operator << (ListEntities<Entity> liste)
    {
        if(!liste.isEmpty())
        {
            //m_ptr_list->reserve(size()+liste.size());
            for(liste.begin(); liste.isNotEnd(); ++liste)
                m_ptr_list->append(T::convert(liste.currentPtr()));
        }
        liste.clearList();
        return *this;
    }

    //! Hydrate l'entitée entity avec les valeur de l'élément courant, puis place l'élément courant sur l'élément suivant de la liste.
    ListEntities & operator >> (T & entity)         {entity<<**m_iterator; ++m_iterator;return *this;}

    //! Renvoie un vecteur contenant une copie des entitées de la liste puis supprime les éléments de la liste et la liste.
    static QVector<T> vector(ListEntities<Entity> liste)
    {
        QVector<T> vector(liste.size());
        if(!liste.isEmpty())
        {
            typename QVector<T>::iterator i = vector.begin();
            for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
                *i = *(T::convert(liste.currentPtr()));
        }
        liste.clear();
        return vector;
    }

    //! Remplit le vecteur vecto avec une copie des entitées de la liste puis supprime les éléments de la liste et la liste.
    static void vector(QVector<T> & vector, ListEntities<Entity> liste)
    {
        vector.resize(liste.size());
        if(!liste.isEmpty())
        {
            typename QVector<T>::iterator i = vector.begin();
            for(liste.begin(); liste.isNotEnd(); ++liste, ++i)
                *i = *(T::convert(liste.currentPtr()));
        }
        liste.clear();
    }
};

/*
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
*/
/*
    bool sstNext() const
    {
        ++m_iterator;
        return m_iterator != m_ptr_list->cend();
    }
*/
#endif // LISTENTITIES_H
