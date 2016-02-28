/*Auteur: PERCIE DU SERT Maxime
 *Date: 22/02/2016
 */

#ifndef ARBREENTITY_H
#define ARBREENTITY_H

#include <Entity.h>

/*! \ingroup groupeEntity
 * \brief Classe mère des entitées de type arbre.
 */

class ArbreEntity : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {FeuillePos = 0,
                  NiveauPos = 1,
                  NumPos = 2,
                  ParentPos = 3,
                  IdPos = 4
                  };

    static const entityId IdEntity = ArbreId;  //!< Identifiant du type des entitées Annee.
    static constexpr char Name[] = "Arbre";
    static const int NbrAtt = 5;                //!< Nombre d'attributs des entitées Annee.
    static constexpr std::array<const char*, NbrAtt> Att {{"feuille", "niveau", "num", "parent", "ID"}}; //!< Tableau des attributs des entitées Annee.
    //static const int NbrEnsUni = 1;             //!< Nombre d'ensemble d'attributs uniques de l'entitée autre que l'identifiant.
    //static constexpr std::array<const char*, NbrEnsUni> EnsUni {{"num, parent"}}; //!< Tableau des chaines des ensembles d'attributs uniques de l'entitée.

protected:
    bool m_feuille; //!< Attribut: Vrai si ce noeud de l'arbre n'a pas de descendant.
    int m_niveau;   //!< Attribut: Niveau de profondeur du noeud dans l'arbre. La profondeur d'une racine est 0.
    int m_num;      //!< Attribut: Numéro du noeud dans la liste des descendants de son ancêtre direct.
    int m_parent;     //!< Clé vers l'arbre: Identifiant du noeud parent.

public:
    INCLUCE_METHODE(ArbreEntity)

    //! Constructeur à partir des valeurs attributs.
    ArbreEntity(bool feuille, int niveau, int num, int parent, int id = 0)
        : Entity(id)
    {
        setFeuille(feuille);
        setNiveau(niveau);
        setNum(num);
        setParent(parent);
    }

    //! Retourne la valeur de l'attribut feuille.
    bool feuille() const
        {return m_feuille;}

    //! Retourne la valeur de l'attribut niveau.
    int niveau() const
        {return m_niveau;}

    //! Retourne la valeur de l'attribut num.
    int num() const
        {return m_num;}

    //! Retourne la valeur de l'attribut parent.
    int parent() const
        {return m_parent;}

    //! Modifie l'attribut feuille.
    void setFeuille(bool feuille)
        {m_feuille = feuille;}

    //! Modifie l'attribut niveau.
    void setNiveau(int niveau)
    {
        if(niveau >= 0)
        {
            m_niveau = niveau;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NiveauPos));
        }
    }

    //! Modifie l'attribut num.
    void setNum(int num)
    {
        if(num >= 0)
        {
            m_num = num;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NumPos));
        }
    }

    //! Modifie l'attribut parent.
    void setParent(int parent)
    {
        if(parent >= 0)
        {
            m_parent = parent;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ParentPos));
        }
    }

    //! Opérateur testant l'égalité de deux entitées, c'est-à-dire l'égalité de tous les attributs.
    bool operator == (const Entity & entity) const
    {
        const ArbreEntity & entityT = convert(entity);
        return (m_id == entityT.id())
                &&(m_feuille == entityT.feuille())
                &&(m_niveau == entityT.niveau())
                &&(m_num == entityT.num())
                &&(m_parent == entityT.parent());
    }

protected:
    //! Remplace les attributs de l'entitée par celle de l'entitée entity, sauf l'identifiant.
    void set(const ArbreEntity & arbre)
    {
        setFeuille(arbre.feuille());
        setNiveau(arbre.niveau());
        setNum(arbre.num());
        setParent(arbre.parent());
    }
};

#endif // ARBREENTITY_H
