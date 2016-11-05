/*Auteur: PERCIE DU SERT Maxime
 *Date: 02/02/2016
 */

//! \defgroup groupeTree Les Arbres
//! \brief Cette partie regroupe l'implémentation des arbres.

#ifndef TREEITEM_H
#define TREEITEM_H

#include<QList>
#include <stdexcept>

/*! \ingroup groupeTree
 * \brief Cette classe est une représentation des noeuds d'un arbre.
 *
 * Cette classe représente les noeuds d'un arbre contenant les informations suivantes:
 *  - une donnée de type T attachée au noeud,
 *  - un pointeur sur le TreeItem parent dans l'arbre (l'élément racine posséde un pointeur parent nul),
 *  - Une liste de pointeurs sur les TreeItem descendants directs dans l'arbre (pour les feuilles de l'arbre cette liste est vide).
 *
 * L'itérateur TreeItem::iterator propose différente façon de parcourir les noeuds d'un arbre de TreeItem.
 *
 * \sa Tree
 */
template<class T> class TreeItem
{
public:

    /*! \ingroup groupeTree
     * \brief Itérateur sur un arbre de TreeItem proposant différente façon de parcourir les noeuds.
     *
     * Cet itérateur propose deux méthodes pour parcourir les noeuds de l'arbre.
     *  + La méthode incrémentation-décrémentation.
     *  + La méthode suivant-précédent.
     *
     * Exemple:
     */
     /* \latexonly
     * Un exemple d'arbre de racine a {
     *  node [shape=record, fontname=Helvetica, fontsize=10];
     *  a [ label="a"];
     *  b [ label="b"];
     *  c [ label="c"];
     *  d [ label="d"];
     *  e [ label="e"];
     *  f [ label="f"];
     *  a -> b [ arrowhead="open", style="dashed" ];
     *  b -> c [ arrowhead="open", style="dashed" ];
     *  b -> d [ arrowhead="open", style="dashed" ];
     *  a -> d [ arrowhead="open", style="dashed" ];
     *  d -> f [ arrowhead="open", style="dashed" ];
     * }
     * \endlatexonly
     *                 1
     *              |       |
     *              2       5
     *          |       |   |
     *          3       4   6
     */
    class iterator
    {
    protected:
        TreeItem<T> * m_ptr;    //!< Pointeur vers la position courante de l'itérateur.
        bool m_sens;            //!< Indicateur du sens de parcours: true -> descente; false -> remontée.

    public:
        //! Constructeur de conversion à partir d'un pointeur sur un noeud.
        iterator(TreeItem<T> * node = nullptr): m_ptr(node), m_sens(true)
            {}

        //! Constructeur de recopie.
        iterator(const iterator & i): m_ptr(i.m_ptr), m_sens(i.m_sens)
            {}

        //! Opérateur d'affectation.
        iterator & operator =(const iterator & i)
        {
            m_ptr = i.m_ptr;
            m_sens = i.m_sens;
            return *this;
        }

        //! Opérateur de conversion à partir d'un pointeur sur un noeud de l'arbre.
        iterator & operator =(TreeItem<T> * node)
        {
            m_ptr = node;
            m_sens = true;
            return *this;
        }

        //! Opératateur de pré-incrémentation. Positionne l'itérateur sur le noeud suivant, les noeuds sont parcourus uniquement à la descente.
        iterator & operator ++()
        {
            if(m_ptr != nullptr)
            {
                if(m_ptr->m_childs.isEmpty())
                    next();
                else
                    m_ptr = m_ptr->m_childs.first();
            }
            return *this;
        }

        //! Opérateur de post-incrémentation.
        iterator operator ++(int)
        {
            iterator i = *this;
            ++(*this);
            return i;
        }

        //! Opérateur de pré-décrémentation.
        iterator & operator --()
        {
            if(!isNull())
            {
                if(!m_ptr->isRoot())
                {
                    if(m_ptr == m_ptr->m_parent->m_childs.frist())
                        m_ptr = m_ptr->m_parent;
                    else
                    {
                        m_ptr = m_ptr->m_parent->m_childs.at(m_ptr->m_parent->m_childs.indexOf(m_ptr)-1);
                        m_ptr = m_ptr->lastestChild();
                    }
                }
                else
                    m_ptr = nullptr;
            }
            return *this;
        }

        //! Opérateur de post-décrémentation.
        iterator operator --(int)
        {
            iterator i(*this);
            --(*this);
            return i;
        }

        //! Test d'égalité entre deux itérateurs.
        bool operator ==(const iterator & i) const
            {return m_ptr == i.m_ptr;}

        //! Test de différence entre deux itérateurs.
        bool operator !=(const iterator & i) const
            {return m_ptr != i.m_ptr;}

        //! Test si la position courante de l'itérateur correspond à pointeur sur le noeuds.
        bool operator ==(TreeItem<T> * node) const
            {return m_ptr == node;}

        //! Test si la position courante de l'itérateur est différente du pointeur sur le noeuds.
        bool operator !=(TreeItem<T> * node) const
            {return m_ptr != node;}

        /*! \brief Incrémente n fois l'itérateur. Si n est négatif, -=-n est appliqué.
         * Pour un n grand cet opérateur est plus efficace que d'appliquer n fois l'opérateur d'incrémemtation.
         */
        iterator & operator +=(int n);

        /*! \brief Décrémente n fois l'itérateur. Si n est négatif, +=-n est appliqué.
         * Cet opérateur applique n fois l'opérateur de décrémemtation, sauf si
         * l'itérateur est décrémenté alors qu'il est positionné sur la racine,
         * a ce moment l'itérateur est positionné sur le noeud virtuel nul.
         */
        iterator & operator -=(int n);

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

        //! Renvoie un pointeur sur le noeud courant.
        TreeItem<T> * operator *() const
            {return m_ptr;}

        //! Positionne l'itérateur sur le noeud correspond au chemin transmis en argument.
        /*! La postion souhaitée de l'itérateur est transmise par la liste des noeuds qu'il faut parcourir. Ces noeuds sont référencés
         * par leurs indices dans la liste des descendants directs du noeuds précédemment atteint. Le chemin contenue dans la liste
         * débute à la racine de l'arbre.
         */
        iterator & operator [](const QList<int> & list)
        {
            root();
            for(QList<int>::const_iterator i = list.cbegin(); i != list.cend(); ++i)
                m_ptr = m_ptr->m_childs.at(*i);
            return *this;
        }

        //! Détermine la position du noeud courant par rapport à la racine.
        QList<int> index()
        {
            QList<int> list;
            recIndex(m_ptr, list);
            return list;
        }

        /*! \brief Test si le noeud courant de l'itérateur est le noeud virtuel nul.
         * Cette méthode est plus éfficace que le test "itérateur == tree.end()" pour tester la fin de parcours.
         *
         * L'itérateur est placé sur la position virtuelle 0,
         * si l'itérateur n'est pas initialisé ou si l'on parcourt l'arbre au delà du dernier noeuds ou avant la racine.
         */
        bool isNull()
            {return m_ptr == nullptr;}

        //! Positionne l'itérateur sur le noeud précédent dans le parcours de type suivant-précédent:
        //! les noeuds sont parcours deux fois, à la descente et à la remonté.
        iterator & precedent();

        //! Place l'itérateur à la racine de l'arbre. L'itérateur doit être préalablement positionné sur un noeud non nul de l'arbre.
        iterator & root()
        {
            if(!isNull())
            {
                recRoot();
                m_sens = true;
            }
            return *this;
        }

        /*! \brief Positionne l'itérateur sur le noeud de chemin d'indices list.
         *
         * Positionne l'itérateur sur le noeud de chemin des indices list des différents descendants empruntés.
         * Par défaut le chemin est relatif, mettre root = true si le chemin absolue (par rapport à la racine).
         * Par défaut une exception est lancé si l'un des indice de la liste n'est pas valide,
         * mettre verif = false pour ne pas effectuer les vérifications.
         */
        iterator & seek(const QList<int> & list, bool root = false, bool verif = true);

        /*! \brief Positionne l'itérateur sur le noeud de chemin de données list.
         *
         * Positionne l'itérateur sur le noeud de chemin des données list des différents descendants empruntés.
         * Si plusieurs noeuds frères possèdent les mêmes données c'est celui de plus faible indice qui sera empruntés.
         * Par défaut le chemin est relatif, mettre root = true si le chemin absolue (par rapport à la racine).
         * Par défaut une exception est lancé si l'une des donnée de la liste n'existe pas,
         * mettre verif = false pour ne pas lancer d'exception.
         */
        iterator & seek(const QList<T> & list, bool root = true, bool verif = true);

        //! Renvoie le sens de parcours (méthode suivant) de l'itérateur: true -> descente; false -> remontée.
        bool sens()
            {return m_sens;}

        //! Modifie le sens de parcours de la méthode suivant-précédent.
        void setSens(bool sens)
            {m_sens = sens;}

        //! Positionne l'itérateur sur le noeud suivant dans le parcours de type suivant-précédent: les noeuds sont parcourus deux fois, à la descente et à la remontée.
        iterator & suivant();

        /*! \brief Positionne l'itérateur sur le n ieme frère suivant.
         *
         * Positionne l'itérateur sur le n ieme frère suivant. L'argument n peut être négatif.
         * Si n est trop négatif, l'itérateur est positionné sur le premier des frères
         * et si n est trop grand, l'itérateur est positionné sur le dernier des frères.
         */
        iterator & toNextChild(int n = 1);

        /*! \brief Positionne l'itérateur sur le n ieme parent du noeud courant si n est positif.
         * Si n est négatif, l'itérateur est positionné sur le n ième premier descendant direct.
         *
         * Positionne l'itérateur sur le n ieme parent du noeud courant si n est positif.
         * Si n est plus grand que le nombre de parents l'itérateur est positionné sur le noeud virtuel nul.
         * Si n est négatif, l'itérateur est positionné sur le n ième premier descendant direct tant qu'il y a des descendants.
         */
        iterator & toParent(int n = 1);

    protected:
        //! Positionne l'itérateur sur le frère suivant du noeud courant. Si le noeud courant est le dernier des frères, on réapplique la méthode avec le parent. Si le noeud courant est le tout dernier des descendants de l'arbre, l'itérateur est placé sur le noeud virtuel nul.
        void next();

        //! Parcours de manière récursive les noeuds en décrémentant le compteur comp jusqu'a ce que celui-ci s'annule, puis positionne l'itérateur sur le noeud correspondant.
        void nextComp(int comp);

        /*! \brief Parcours de manière récursive l'ensemble des descendants du noeud pointé par ptr en décrémentant le compteur comp.
         * De plus, si ce compteur s'annule l'itérateur est placé sur le noeuds correspondant à l'annulation et le parcours s'arrète.
         */
        int nextCompChild(int comp, TreeItem<T> * ptr);

        //! Méthode récursive déterminant la position du noeud courant par rapport à la racine.
        static void recIndex(TreeItem<T> * node, QList<int> & list);

        //! Méthode récursive positionnant l'itérateur sur la racine de l'arbre. L'itérateur ne doit pas être nul.
        void recRoot();
    };
    friend class iterator;

protected:
    TreeItem<T> *m_parent;              //!< Pointeur vers le TreeItem parent dans l'arbre, nul si le TreeItem est la racine de l'arbre.
    T m_data;                           //!< Donné accroché au noeud de l'arbre.
    QList<TreeItem<T>*> m_childs;       //!< Liste de pointeur sur les descendants directs du noeud.

public:
    //! Constructeur sans donnée associée au noeud. Par défaut un noeud est la racine d'un arbre.
    TreeItem(TreeItem<T> * parent = nullptr) : m_parent(parent)
    {
        if(parent)
            parent->m_childs.append(this);
    }

    //! Constructeur de recopie. Recopie également récursivement l'ensemble des descendants.
    TreeItem(const TreeItem<T> & tree);

    //! Constructeur par déplacement.
    TreeItem(TreeItem<T> && tree)
        : m_parent(tree.m_parent),
          m_data(std::move(tree.m_data)),
          m_childs(std::move(tree.m_childs))
    {
        if(m_parent)
        {
            m_parent->m_childs[m_parent->m_childs.indexOf(&tree)] = this;
            tree.m_parent = nullptr;
        }
    }

    //! Constructeur avec une donnée associée au noeud. Par défaut un noeud est la racine d'un arbre.
    TreeItem(const T & data, TreeItem * parent = nullptr) : m_parent(parent), m_data(data)
    {
        if(parent)
            parent->m_childs.append(this);
    }

    //! Destructeur. Détruit également récursivement l'ensemble des descendants.
    ~TreeItem()
    {
        for(typename QList<TreeItem<T>* >::const_iterator i = m_childs.cbegin(); i != m_childs.cend(); ++i)
            delete *i;
    }

    //! Ajoute nbr descendants directs au noeud et renvoie un pointeur sur le dernier descendant créé.
    TreeItem<T> * addChild(int nbr = 1);

    //! Ajoute un descendant de donnée associée data, puis renvoie un pointeur sur ce nouveau noeud.
    TreeItem<T> * addChild(const T & data)
        {return new TreeItem(data,this);}

    /*!
     * \brief Ajoute le noeud pointé par child aux descendants du noeud.
     *
     * Le noeud pointé par child est ajouté en dernière position dans la liste des descendants directs.
     * Si le descendant ajouté avait déjà un parent,
     * ce descendant est alors supprimé de la liste des descendants directs
     * de ce parent avant que ne soit changé le pointeur sur le parent du noeud ajouté.
     */
    void appendChild(TreeItem<T> *child)
    {
        m_childs.append(child);
        changeHeredite(child);
    }

    //! Renvoie un pointeur sur le descendant direct d'indice position. Cette fonction ne vérifie pas si position excéde le nombre de descendants directs contrairement à child.
    TreeItem<T> * child(int position) const
        {return m_childs.at(position);}

    //! Crée un itérateur initialisé sur le noeud.
    iterator begin() const
        {return iterator(this);}

    //! Crée un itérateur initialisé sur la racine.
    iterator beginRoot() const
        {return iterator(root());}

    //! Renvoie la liste liste des pointerurs vers les descendants directs.
    const QList<TreeItem<T>*> & childs()
        {return m_childs;}

    //! Renvoie le nombre de descendant direct.
    int childCount() const
        {return m_childs.count();}

    //! Transmet une référence constante sur la donnée associée au noeud.
    const T & data() const
        {return m_data;}

    //! Crée un itérateur initialisé sur le noeud virtuel nul. Cette fonction permet la compatibilité avec les algorithmes standards. Utiliser de préférence la méthode isNull directement sur le pointeur.
    iterator end() const
        {return iterator(nullptr);}

    //! Test si le noeud posséde un descendant direct.
    bool hasChild() const
        {return !m_childs.isEmpty();}

    //! Insert le noeud pointé par child à l'indice position dans la liste des descendants directs.
    void insertChild(const TreeItem<T> *child, const int position = 0);

    //! Test si le noeud est la racine de l'arbre.
    bool isRoot() const
        {return m_parent == nullptr;}

    //! Renvoie un pointeur sur le dernier descendant direct.
    TreeItem<T> * lastChild() const
        {return m_childs.last();}

    //! Méthode récursive renvoyant un pointeur sur le dernier descendant du noeud.
    TreeItem<T> * lastestChild() const;

    //! Transmet une référence sur la donnée associée au noeud. La donnée pouvant être modifiée.
    T & modifData()
        {return m_data;}

    /*! \brief Déplace le descendant direct d'indice from à l'indice to.
     *
     * Déplace le descendant direct d'indice from à l'indice to.
     * Une exception est lancée si l'un des deux indices from ou to n'est pas valide.
     */
    void move(int from, int to);

    //! Renvoie un pointeur sur le parent du noeud ou 0 si le noeud est la racine.
    TreeItem<T> * parent() const
        {return m_parent;}

    //! Renvoie l'indice du noeud parmis les descendant direct de son parent et -1 si le noeud est la racine.
    int position() const
        {return isRoot() ? 0 : m_parent->m_childs.indexOf(const_cast<TreeItem<T>*>(this));}

    //! Détruit tous les descendants du noeud.
    void removeAllChild()
    {
        for(typename QList<TreeItem<T>*>::const_iterator i = m_childs.cbegin(); i != m_childs.cend(); ++i)
            delete *i;
        m_childs.clear();
    }
     /*! \brief Retire le descendant d'indice position de la liste des descendants directs.
      *
      * Retire le descendant d'indice position de la liste des descendants directs. Ce descendant est détruit ainsi que tous ses descedants.
      * Une exception est lancée si position n'est pas un indice valide.
      */
    void removeChild(int position);

    /*! \brief Retire les descendants d'indices position à position+nbr-1 de la liste des descendants directs.
     *
     * Retire les descendants d'indices position à position+nbr-1 de la liste des descendants directs.
     * Ces descendants sont détruient ainsi que tous leurs descedants.
     * Une exception est lancée si position et position+nbr ne sont pas des indices valides.
     */
    void removeChild(int position, int nbr);

    //! Méthode récursive renvoyant un pointeur sur la racine de l'arbre.
    TreeItem<T> * root() const;

    //! Modifie la donnée associée au noeud.
    void setData(const T & data)
        {m_data = data;}

    /*! \brief Renvoie le nombre de noeuds du sous-arbre ayant ce noeud pour racine.
     *
     * Méthode déterminant de manière récursive le nombre de noeuds du sous-arbre ayant ce noeud pour racine,
     * c'est-à-dire le nombre de descendants directs et indirects majoré de un pour prendre en compte ce noeud.
     */
    int size() const;

    /*!
     * \brief Opérateur d'affectation de recopie.
     *
     * L'opérateur d'affectation modifie la donnée du noeud par celle de tree, détruit tous les descendants du noeuds
     * pour les remplacer par une copie de ceux de tree.
     */
    TreeItem<T> & operator = (const TreeItem<T> & tree)
    {
        m_data = tree.m_data;
        removeAllChild();
        for(typename QList<TreeItem *>::const_iterator i = tree.m_childs.cbegin(); i != tree.m_childs.cend(); ++i)
        {
            TreeItem<T> * child = new TreeItem<T>(**i);
            appendChild(child);
        }
    }

    //! Opérateur d'affectation par déplacement.
    TreeItem<T> & operator = (TreeItem<T> && tree)
    {
        m_parent = tree.m_parent;
        m_data = std::move(tree.m_data);
        m_childs = std::move(tree.m_childs);
        if(tree.m_parent)
        {
            m_parent->m_childs[m_parent->m_childs.indexOf(&tree)] = this;
            tree.m_parent = nullptr;
        }
    }

    //! Ajoute une copie de tree et de ses descendants, aux descendants du noeud. Puis renvoie une référence de ce nouveau noeud.
    TreeItem<T> & operator << (const TreeItem<T> & tree)
    {
        TreeItem * child = new TreeItem<T>(tree);
        appendChild(child);
        return *child;
    }

    //! Ajoute tree aux descendants du noeud en rattachant tree et ses descendant au noeud. Puis renvoie une référence de *tree.
    TreeItem<T> & operator << (const TreeItem<T> * tree)
    {
        appendChild(tree);
        return *tree;
    }

    //! Ajoute au noeud un descendant de donnée associée data.
    TreeItem<T> & operator << (const T & data)
        {return *(addChild(data));}

protected:
    //! Change l'hérédité d'un noeud en le supprimant de la liste des descendants de son noeud parent avant de remplacer le pointeur sur ce dernier par this.
    void changeHeredite(TreeItem<T> *child)
    {
        if(!child->isRoot())
        {
            child->m_parent->m_childs.removeOne(child);
        }
        child->m_parent = this;
    }
};

template<class T> TreeItem<T>::TreeItem(const TreeItem<T> & tree): m_parent(nullptr), m_data(tree.m_data)
{
    for(typename QList<TreeItem *>::const_iterator i = tree.m_childs.cbegin(); i != tree.m_childs.cend(); ++i)
        appendChild(new TreeItem<T>(**i));
}

template<class T> TreeItem<T> * TreeItem<T>::addChild(const int nbr)
{
    for(int i = 0; i != nbr; ++i)
        appendChild(new TreeItem<T>);
    return lastChild();
}

/*template<class T> TreeItem<T> * TreeItem<T>::child(const int position) const
{
    if(0 <= position && position < m_childs.size())
    {
        return m_childs.at(position);
    }
    else
    {
        throw std::runtime_error(QString("La position donnée :")
                                 .append(QString::number(position))
                                 .append(", dépasse le nombre de descendant:")
                                 .append(QString::number(m_childs.size())).append(".").toStdString());
    }
}*/

template<class T> void TreeItem<T>::insertChild(const TreeItem<T> *child, const int position)
{
    if(position == 0)
    {
        m_childs.prepend(child);
        changeHeredite(child);
    }
    else if(0 < position && position < m_childs.size())
    {
        m_childs.insert(position,child);
        changeHeredite(child);
    }
    else
    {
        throw std::runtime_error(QString("La position donnée :")
                                 .append(QString::number(position))
                                 .append(", dépasse le nombre de descendant:")
                                 .append(QString::number(m_childs.size())).append(".").toStdString());
    }
}

template<class T> TreeItem<T> * TreeItem<T>::lastestChild() const
{
    if(m_childs.isEmpty())
    {
        return this;
    }
    else
    {
        return m_childs.last()->lastestChild();
    }
}

template<class T> void TreeItem<T>::move(const int from, const int to)
{
    if(0 <= from && 0 <= to && from < m_childs.size() && to < m_childs.size() )
    {
        if(from != to)
        {
            m_childs.move(from, to);
        }
    }
    else
    {
        throw std::runtime_error("from ou to dépassent le nombre de child");
    }
}

template<class T> void TreeItem<T>::removeChild(const int position)
{
    if(0 <= position && position < m_childs.size())
    {
        delete m_childs.at(position);
        m_childs.removeAt(position);
    }
    else
    {
        throw std::runtime_error(QString("La position donnée :")
                                 .append(QString::number(position))
                                 .append(", dépasse le nombre de descendant:")
                                 .append(QString::number(m_childs.size())).append(".").toStdString());
    }
}

template<class T> void TreeItem<T>::removeChild(const int position, const int nbr)
{
    if(0 <= position && 0 < nbr && position < m_childs.size()  && position + nbr < m_childs.size())
    {
        for(int i = position; i != position + nbr; ++i)
        {
            delete m_childs.at(i);
            m_childs.removeAt(i);
        }
    }
    else
    {
        throw std::runtime_error(QString("La position donnée :")
                                 .append(QString::number(position))
                                 .append(", ou position+nbr:")
                                 .append(QString::number(position+nbr))
                                 .append(", dépasse le nombre de descendant:")
                                 .append(QString::number(m_childs.size())).append(".").toStdString());
    }
}

template<class T> TreeItem<T> * TreeItem<T>::root() const
{
    if(!isRoot())
        return m_parent->root();
    else
        return this;
}

template<class T> int TreeItem<T>::size() const
{
    int c=1;
    for(typename QList<T>::const_iterator i = m_childs.cbegin(); i != m_childs.cend(); ++i)
        c += (*i)->size();
    return c;
}

// %%%%%%%%%%%%%% iterator %%%%%%%%%%%%%

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::operator += (int n)
{
    if(!isNull() && n != 0)
    {
        if (n < 0)
            return *this -= -n;
        else
            nextComp(n);
    }
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::operator -=(int n)
{
    if(!isNull() && n != 0)
    {
        if (n < 0)
            return *this += -n;
        else
        {
            while(n && !isNull())
            {
                --(*this);
                --n;
            }
        }
    }
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::precedent()
{
    if(!isNull())
    {
        if(m_sens)
        {
            if(!m_ptr->isRoot())
            {
                if(m_ptr == m_ptr->m_parent->m_childs.first())
                    m_ptr = m_ptr->m_parent;
                else
                {
                    m_ptr = m_ptr->m_parent->m_childs.at(m_ptr->m_parent->m_childs.indexOf(m_ptr)-1);
                    m_sens = false;
                }
            }
            else
                m_ptr = nullptr;
        }
        else
        {
            if(m_ptr->hasChild())
                m_ptr = m_ptr->m_childs.last();
            else
                m_sens = true;
        }
    }
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::seek(const QList<int> & list, bool root, bool verif)
{
    m_sens = true;
    if(root)
        recRoot();
    for(QList<int>::const_iterator i = list.cbegin(); i != list.cend(); ++i)
    {
        if(verif && !(0<= *i && *i < m_ptr->m_childs.size()))
            throw std::runtime_error(QString("La position donnée :")
                                     .append(QString::number(*i))
                                     .append(", dépasse le nombre de descendant:")
                                     .append(QString::number(m_ptr->m_childs.size())).append(".").toStdString());
        m_ptr = m_ptr->m_childs.at(*i);
    }
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::seek(const QList<T> & list, bool root, bool verif)
{
    m_sens = true;
    if(root)
        recRoot();
    bool controle = true;
    typename QList< TreeItem<T> *>::const_iterator j;
    for(typename QList<T>::const_iterator i = list.cbegin(); controle && i != list.cend(); ++i)
    {
        j = m_ptr->m_childs.cbegin();
        while(j != m_ptr->m_childs.cend() && (*j)->m_data != *i)
            ++j;

        if(j != m_ptr->m_childs.cend())
            controle = false;
        if(verif && !controle)
            throw std::runtime_error("Noeud inexistant");
    }
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::suivant()
{
    if(!isNull())
    {
        if(m_sens)
        {
            if(m_ptr->hasChild())
                m_ptr = m_ptr->m_childs.first();
            else
                m_sens = false;
        }
        else
        {
            if(!m_ptr->isRoot())
            {
                if(m_ptr == m_ptr->m_parent->m_childs.last())
                    m_ptr = m_ptr->m_parent;
                else
                {
                    m_ptr = m_ptr->m_parent->m_childs.at(m_ptr->m_parent->m_childs.indexOf(m_ptr)+1);
                    m_sens = true;
                }
            }
            else
                m_ptr = nullptr;
        }
    }
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::toNextChild(int n)
{
    int l = m_ptr->m_parent->m_childs.indexOf(m_ptr);
    if (l+n <= 0)
        m_ptr = m_ptr->m_parent->m_childs.first();
    else if (l+n >= m_ptr->m_parent->m_childs.size())
        m_ptr = m_ptr->m_parent->m_childs.last();
    else
        m_ptr = m_ptr->m_parent->m_childs.at(l+n);
    return *this;
}

template<class T> typename TreeItem<T>::iterator & TreeItem<T>::iterator::toParent(int n)
{
    if(n>0)
        for(int i = 0; i < n && !isNull(); ++i) m_ptr = m_ptr->m_parent;
    else if(n<0)
        for(int i = 0; i < n && !m_ptr->m_childs.isEmpty(); ++i) m_ptr = m_ptr->m_childs.first();
    return *this;
}

// %%%%%%%%%%%%%%% protected %%%%%%%%%%%%%%

template<class T> void TreeItem<T>::iterator::next()
{
    if(!m_ptr->isRoot())
    {
        if(m_ptr == m_ptr->m_parent->m_childs.last())
        {
            m_ptr = m_ptr->m_parent;
            next();
        }
        else
            m_ptr = m_ptr->m_parent->m_childs.at(m_ptr->m_parent->m_childs.indexOf(m_ptr)+1);
    }
    else
        m_ptr = nullptr;
}

template<class T> void TreeItem<T>::iterator::nextComp(int comp)
{
       comp = nextCompChild(comp,m_ptr);
       if(comp)
       {
           next();
           if(!isNull())
           {
               --comp;
               nextComp(comp);
           }
       }
}

template<class T> int TreeItem<T>::iterator::nextCompChild(int comp,TreeItem<T> * ptr)
{
    if(comp)
    {
        if(!ptr->m_childs.isEmpty())
        {
            for(typename QList<T>::iterator i = ptr->m_childs.cbegin(); comp && i != ptr->m_childs.cend(); ++i)
            {
                --comp;
                comp = nextCompChild(comp,*i);
            }
        }
    }
    else
        m_ptr = ptr;
    return comp;
}

template<class T> void TreeItem<T>::iterator::recIndex(TreeItem<T> * node, QList<int> & list)
{
    if(!node->isRoot())
    {
        list.prepend(node->m_parent->m_childs.indexOf(node));
        node = node->parent();
        recIndex(node, list);
    }
}

template<class T> void TreeItem<T>::iterator::recRoot()
{
    if(!m_ptr->isRoot())
    {
        m_ptr = m_ptr->m_parent;
        recRoot();
    }
}

#endif // TREEITEM_H
