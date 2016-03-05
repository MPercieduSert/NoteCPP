/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ANNEE_H
#define ANNEE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Annee.
 */

class Annee : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {AnneePos = 0,
                   IdPos = 1};

    static const entityId IdEntity = AnneeId;   //!< Identifiant du type de l'entitée.
    static constexpr char Name[] = "Annee";     //!< Nom de l'entitée.
    static const int NbrAtt = 2;                //!< Nombre d'attributs de l'entitée.
    static constexpr std::array<const char*,NbrAtt> Att {{"annee", "ID"}};  //!< Tableau des attributs de l'entitée.

protected:
    int m_annee;//!< Attribut: annee de rentrée.

public:
    INCLUCE_METHODE(Annee)

    //! Constructeur à partir des valeurs attributs.
    Annee(int annee, int id)
        : Entity(id)
        {setAnnee(annee);}

    GET_SET_INT_SUP(annee,Annee,1)

    //! Renvoie la chaine de caractère "annee-annee+1".
    QString affiche() const
        {return QString::number(m_annee)+"-"+QString::number(m_annee+1);}

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (m_annee > 0);}

    bool operator < (const Annee & annee) const
    {
        return m_annee < annee.annee();
    }

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Annee & entity) const
    {
        return Entity::egal(entity)
                && (m_annee == entity.m_annee);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Annee & entity)
    {
        setAnnee(entity.annee());
    }
};

#endif // ANNEE_H
