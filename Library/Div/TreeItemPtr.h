/*Auteur: PERCIE DU SERT Maxime
 *Date: 09/09/2016
 */
#ifndef TREEITEMPTR_H
#define TREEITEMPTR_H

#include "Tree.h"

/*! \ingroup groupeTree
 * \brief Cette classe est une représentation des noeuds d'un arbre de pointeur.
 */
template<class T> class TreeItemPtr : public TreeItem<T*>
{
public:
    //! Iterateur.
    class iterator : public TreeItem<T*>::iterator
    {
    public:
        using TreeItem<T*>::iterator::iterator;

        //! Constructeur.
        iterator(const iterator &i) : TreeItem<T*>::iterator(i)
            {}

        //! opérateur *.
        TreeItemPtr<T> * operator *() const
            {return static_cast<TreeItemPtr<T>*>(TreeItem<T*>::iterator::operator *());}
    };

    using TreeItem<T*>::TreeItem;

    //! Constructeur.
    TreeItemPtr(TreeItemPtr<T> * parent = nullptr) : TreeItem<T*>(parent)
        {}

    //! Constructeur avec une donnée associée au noeud. Par défaut un noeud est la racine d'un arbre.
    TreeItemPtr(const T & data, TreeItemPtr<T> * parent = nullptr) : TreeItem<T*>(new T(data),parent)
        {}

    //! Constructeur par recopie par defaut.
    TreeItemPtr(const TreeItemPtr<T> & ) = default;

    //! Constructeur de déplacement par defaut.
    TreeItemPtr(TreeItemPtr<T> && ) = default;

    //! Destructeur par defaut.
    ~TreeItemPtr() = default;

    //! Ajoute nbr descendants directs au noeud et renvoie un pointeur sur le dernier descendant créé.
    TreeItemPtr<T> * addChild(int nbr = 1)
        {return static_cast<TreeItemPtr<T>*>(TreeItem<T*>::addChild(nbr));}

    //! Ajoute un descendant de donnée associée data, puis renvoie un pointeur sur ce nouveau noeud.
    TreeItemPtr<T> * addChild(const T & data)
        {return new TreeItemPtr<T>(data,this);}

    //! Renvoie une référence sur la donne du descendant direct d'indice position. Cette fonction ne vérifie pas si position excéde le nombre de descendants directs contrairement à child.
    T & child(int position) const
        {return *(TreeItem<T*>::child(position)->data());}

    //! Crée un itérateur initialisé sur le noeud.
    iterator begin() const
        {return iterator(TreeItem<T*>::begin());}

    //! Crée un itérateur initialisé sur la racine.
    iterator beginRoot() const
        {return iterator(TreeItem<T*>::beginRoot());}

    /*//! Renvoie une référence la donnée du descendant direct d'indice position. Cette fonction lance une exception si position excéde le nombre de descendants directs contrairement à child.
    T & child( int position) const
        {return *(TreeItem<T*>::child(position)->data());}*/

    //! Transmet une référence sur la donnée associée au noeud.
    T & data() const
        {return *TreeItem<T*>::data();}

    //! Crée un itérateur initialisé sur le noeud virtuel nul. Cette fonction permet la compatibilité avec les algorithmes standards. Utiliser de préférence la méthode isNull directement sur le pointeur.
    iterator end() const
        {return iterator(nullptr);}

    //! Renvoie un pointeur sur le dernier descendant direct.
    TreeItemPtr<T> * lastChild() const
        {return static_cast<TreeItemPtr<T>*>(TreeItem<T*>::lastChild());}

    //! Méthode récursive renvoyant un pointeur sur le dernier descendant du noeud.
    TreeItemPtr<T> * lastestChild() const
        {return static_cast<TreeItemPtr<T>*>(TreeItem<T*>::lastestChild());}

    //! Renvoie un pointeur sur le parent du noeud ou 0 si le noeud est la racine.
    TreeItemPtr<T> * parent() const
        {return static_cast<TreeItemPtr<T>*>(TreeItem<T*>::parent());}

    //! Méthode récursive renvoyant un pointeur sur la racine de l'arbre.
    TreeItemPtr<T> * root() const
        {return static_cast<TreeItemPtr<T>*>(TreeItem<T*>::root());}

    //! Opérateur d'affectation de recopie par defaut.
    TreeItemPtr<T> & operator = (const TreeItemPtr<T> & ) = default;

    //! Opérateur d'affectation par déplacement par defaut.
    TreeItemPtr<T> & operator = (TreeItemPtr<T> && ) = default;

    //! Ajoute une copie de tree et de ses descendants, aux descendants du noeud. Puis renvoie une référence de ce nouveau noeud.
    TreeItemPtr<T> & operator << (const TreeItemPtr<T> & tree)
        {return static_cast<TreeItemPtr<T> & >(TreeItem<T*>::operator <<(tree));}

    //! Ajoute tree aux descendants du noeud en rattachant tree et ses descendant au noeud. Puis renvoie une référence de *tree.
    TreeItemPtr<T> & operator << (const TreeItemPtr<T> * tree)
        {return static_cast<TreeItemPtr<T> & >(TreeItem<T*>::operator <<(tree));}

    //! Ajoute au noeud un descendant de donnée associée data.
    TreeItemPtr<T> & operator << (const T & data)
        {return *(addChild(data));}
};

#endif // TREEITEMPTR_H
