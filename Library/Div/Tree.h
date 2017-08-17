/*Auteur: PERCIE DU SERT Maxime
 *Date: 07/02/2016
 */
#ifndef Tree_H
#define Tree_H

#include "TreeItem.h"

/*! \ingroup groupeTree
 *  \brief Cette classe represente un arbre dont les noeuds sont constitués par des TreeItem<T> et d'un noeud courant (curseur).
 *
 * Cette classe represente un arbre. Elle est constituée de la racine d'un arbre dont les noeuds sont constitués par des TreeItem<T>
 * et d'un itérateur sur cet arbre jouant le role d'un curseur, ce qui munit l'arbre d'un noeud courant.
 */

template<class T> class Tree
{
protected:
    TreeItem<T> * m_root;//!< Pointeur sur la racine de l'arbre.
    mutable typename TreeItem<T>::iterator m_i;//!< Itérateur sur l'arbre de racine pointée par m_root.

public:
    //! Constructeur, prend le neud transmis pour racine (doit être dynamiquement et ne dois pas avoir de parent) et initialise l'itérateur sur cette racine.
    Tree(TreeItem<T> * root = new TreeItem<T>())
        : m_root(root),
          m_i(m_root)
        {}

    //! Constructeur de recopie.
    Tree(const Tree<T> & tree)
        : Tree(new TreeItem<T>(*(tree.m_root)))
        {}

    //! Constructeur de déplacement.
    Tree(Tree<T> && tree)
        : Tree(tree.m_root)
    {
        tree.m_root = nullptr;
        tree.m_i = nullptr;
    }

    //! Constructeur de recopie.
    template<class U> Tree(const Tree<U> & tree)
        : Tree(new TreeItem<T>(*(tree.root())))
        {}

    //! Constructeur, crée une racine de donnée associée data et initialise l'itérateur sur cette racine.
    Tree(const T & data)
        : Tree(new TreeItem<T>(data))
        {}

    //! Constructeur, créer un arbre possédant la même structure et les même valeur que tree, T doit posséder un constructeur à partir de U.
    //template<class U> Tree(const Tree<U> & tree);

    //! Destructeur. Détruit tous les noeuds de l'arbre.
    ~Tree()
        {delete m_root;}

    //! Crée un nouveau descendant direct au noeud courant, ce nouveau noeud à pour donnée associée data (voir l'opérateur <<).
    void addChild(const T & data)
        {m_i = (*m_i)->addChild(data);}

    //! Réinitialise l'itérateur sur la racine.
    typename TreeItem<T>::iterator begin() const
        {return m_i = m_root;}

    //! Renvoie la liste des descendants directs du noeud courant.
    const QList<TreeItem<T>*> & childs()
        {return (*m_i)->childs();}

    //! Réinitialise l'itérateur sur la racine et détruit l'ensemble des descendants de la racine.
    void clear()
    {
        m_i = m_root;
        m_root->removeAllChild();
    }

    //! Renvoie la donnée associée au noeuds courant.
    const T & data() const
        {return (*m_i)->data();}

    //! Crée un itérateur initialisé sur le noeud virtuel nul. Cette fonction permet la compatibilité avec les algorithmes standards. Utiliser de préférence la méthode isNull directement sur le pointeur.
    typename TreeItem<T>::iterator end() const
        {return nullptr;}

    //! Créer une nouveau de valeur T est l'insert à l'indice position dans la liste des descendants directs du noeud courant.
    void insertChild(const T & data, const int position = 0)
        {(*m_i)->insertChild(data, position);}

    //! Insert une copie de tree à l'indice position dans la liste des descendants directs du noeud courant.
    void insertChild(const Tree<T> & tree, const int position = 0)
        {(*m_i)->insertChild(new TreeItem<T>(tree.root()), position);}

    //! Insert tree à l'indice position dans la liste des descendants directs du noeud courant.
    void insertChild(Tree<T> && tree, const int position = 0)
    {
        (*m_i)->insertChild(tree.root(), position);
        tree.rootNull();
    }

    //! Replace l'itérateur sur le noeud suivant (méthode de parcours incrémentation-décrémentation) puis test si le nouveau noeud n'est pas la racine.
    bool next() const
    {
        ++m_i;
        return !m_i.isNull();
    }

    //! Replace l'itérateur sur le noeud précédent (méthode de parcours suivant-précédent) puis test si le nouveau noeud n'est pas la racine.
    bool precedent() const
    {
        m_i.precedent();
        return m_i != m_root;
    }

    //! Replace l'itérateur sur le noeud précédent (méthode de parcours incrémentation-décrémentation) puis test si le nouveau noeud n'est pas la racine.
    bool previous() const
    {
        --m_i;
        return !m_i.isNull();
    }

    //! Renvoie un pointeur constant sur la racine de l'arbre.
    TreeItem<T> * root() const
        {return m_root;}

    /*! \brief Replace le noeud courant sur le noeud de chemin d'indices list.
     *
     * Replace le noeud courant sur le noeud de chemin d'indices list. Par défaut ce chemin est absolu,
     * mettre root=false si le chemin est relatif. Par defaut une exception est lancée si les indices du chemin ne sont pas valides,
     * mettre verif=false pour éviter ceci.
     */
    Tree<T> & seek(const QList<int> & list, bool root = true, bool verif = true);

    /*! \brief Replace le noeud courant sur le noeud de chemin de données list.
     *
     * Replace le noeud courant sur le noeud de chemin de données list. Par défaut ce chemin est absolu,
     * mettre root=false si le chemin est relatif. Par defaut une exception est lancée si les indices du chemin ne sont pas valides,
     * mettre verif=false pour éviter ceci.
     */
    Tree<T> & seek(const QList<T> & list, bool root = true, bool verif = true);

    //! Modifie la donnée associée au noeuds courant.
    void setData(const T & data)
        {(*m_i)->setData(data);}

    //! Renvoie le sens de parcours (méthode suivant) du noeud courant: true -> descente; false -> remontée.
    bool sens() const
        {return m_i.sens();}

    //! Modifie le sens de parcours de la méthode suivant-précédent.
    void setSens(bool sens)
        {m_i.setSens(sens);}

    //! Replace l'itérateur sur le noeud suivant (méthode de parcours suivant-précédent) puis test si le nouveau noeud n'est pas la racine.
    bool suivant() const
    {
        m_i.suivant();
        return m_i != m_root;
    }

    //! Replace le noeud courant au niveau du parent du précédent noeud courant.
    void toParent() const
        {m_i.toParent();}

    /*! \brief Renvoie la valeur de la donnée contenue par le noeud de chemin d'indices list.
     *
     * Renvoie la valeur de la donnée contenue par le noeud de chemin d'indices list. Par défaut ce chemin est absolu,
     * mettre root=false si le chemin est relatif. Cette méthode ne déplace pas le noeud courant.
     * Par defaut si les indices du chemin ne sont pas valides,
     * de nouveaux noeuds sont créés, mettre newvalue=false pour qu'un execption soit lancée.
     */
    const T & value(const QList<int> & list, bool root = true, bool newvalue = true);

    //! Affectation par recopie.
    Tree<T> & operator = (const Tree<T> & tree)
    {
        delete m_root;
        m_root = new TreeItem<T>(*tree.m_root);
        m_i = tree.m_i;
        return *this;
    }

    //! Affectation par deplacement.
    Tree<T> & operator = (Tree<T> && tree)
    {
        delete m_root;
        m_root = tree.m_root;
        tree.m_root = nullptr;
        m_i = tree.m_i;
        return *this;
    }

    //! Transmet une réfrence sur la donnée associé au neud courant.
    T & operator * ()
        {return (*m_i)->modifData();}

    //! Ajoute une copie de Tree et de ses descendant aux descendants directs du noeud courant sans modifier ce dernier.
    Tree<T> & operator << (const Tree<T> & tree)
    {
        (**m_i) << &tree.root();
        return *this;
    }

    //! Ajoute Tree et de ses descendant aux descendants directs du noeud courant sans modifier ce dernier.
    Tree<T> & operator << (Tree<T> && tree)
    {
        (**m_i) << tree.root();
        tree.rootNull();
        return *this;
    }

    //! Crée un nouveau descendant direct au noeud courant, ce nouveau noeud à pour donnée associée data (voir la méthode addchild). Puis replace le noeud courant sur ce nouveau noeud avant de renvoyer un réfrence de l'arbre.
    Tree<T> & operator << (const T & data)
        {m_i = &((**m_i)<<data); return *this;}

    //! Affecte à data la donnée associée au noeud courant puis replace ce dernier sur le noeud suivant (pour l'incrémentation).
    const Tree<T> & operator >> ( T & data)
        {data = (*m_i)->data(); ++m_i; return *this;}

    //! Transmet une référence sur la donnée du noeud de chemin absolue d'indices list. Cette méthode ne déplace pas le noeud courant. (Le chemin d'indice doit être valide.)
    T & operator [](const QList<int> & list);

protected:
    //! Met la racine à zero.
    void rootNull()
        {m_root = nullptr;}
};

//template<class T> template<class U> Tree<T>::Tree(const Tree<U> & tree)
//{
//    m_root = new TreeItem<U>(&tree.root());
//    m_i = m_root;
//}

template<class T> Tree<T> & Tree<T>::seek(const QList<int> & list, bool root, bool verif)
{
    if(root)
    {
        m_i = m_root;
    }
    m_i.seek(list, false, verif);
    return *this;
}

template<class T> Tree<T> & Tree<T>::seek(const QList<T> & list, bool root, bool verif)
{
    if(root)
    {
        m_i = m_root;
    }
    m_i.seek(list, false, verif);
    return *this;
}

template<class T> const T & Tree<T>::value(const QList<int> & list, bool root, bool newvalue)
{
    typename TreeItem<T>::iterator sav_m_i(m_i);
    if(root)
    {
        m_i = m_root;
    }
    for(QList<int>::const_iterator i = list.cbegin(); i != list.cend(); ++i)
    {
        if(0<= *i && *i < (*m_i)->m_childs.size())
        {
            m_i = (*m_i)->m_childs.at(*i);
        }
        else if(newvalue)
        {
            m_i = (*m_i)->addChild();
        }
        else
        {
            throw std::runtime_error("position dépasse le nombre de child");
        }
    }
    const T & data = (*m_i)->m_data;
    m_i = sav_m_i;
    return data;
}

template<class T> T & Tree<T>::operator [](const QList<int> & list)
{
    typename TreeItem<T>::iterator sav_m_i(m_i);
    m_i = m_root;
    for(QList<int>::const_iterator i = list.cbegin(); i != list.cend(); ++i) m_i = (*m_i)->m_childs.at(*i);
    T & data = (*m_i)->m_data;
    m_i = sav_m_i;
    return data;
}

#endif // Tree_H
