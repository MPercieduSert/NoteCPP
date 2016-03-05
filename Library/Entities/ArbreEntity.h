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

    static const entityId IdEntity = ArbreId;   //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "Arbre";     //!< Nom de l'entitée.
    static const int NbrAtt = 5;                //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*, NbrAtt> Att {{"feuille", "niveau", "num", "parent", "ID"}}; //!< //!< Tableau des attributs de l'entitée.

protected:
    bool m_feuille;     //!< Attribut: Vrai si ce noeud de l'arbre n'a pas de descendant.
    int m_niveau;       //!< Attribut: Niveau de profondeur du noeud dans l'arbre. La profondeur d'une racine est 0.
    int m_num;          //!< Attribut: Numéro du noeud dans la liste des descendants de son ancêtre direct.
    int m_parent;       //!< Clé vers l'arbre: Identifiant du noeud parent.

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

    GET_SET_BOOL(feuille,Feuille)
    GET_SET_INT_SUP(niveau,Niveau,0)
    GET_SET_INT_SUP(num,Num,0)
    GET_SET_INT_SUP(parent,Parent,0)

    //! Teste si l'entitée est valide.
    bool isValid() const
    {
        return Entity::isValid() && (m_niveau >= 0) && (!m_num >= 0) && (!m_parent >= 0);
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const ArbreEntity & arbre) const
    {
        return Entity::egal(arbre)
                && (m_feuille == arbre.m_feuille)
                && (m_niveau == arbre.m_niveau)
                && (m_num == arbre.m_num)
                && (m_parent == arbre.m_parent);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const ArbreEntity & arbre)
    {
        setFeuille(arbre.feuille());
        setNiveau(arbre.niveau());
        setNum(arbre.num());
        setParent(arbre.parent());
    }
};

#endif // ARBREENTITY_H
