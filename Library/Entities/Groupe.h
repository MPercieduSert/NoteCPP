/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef GROUPE_H
#define GROUPE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Groupe.
 */

class Groupe : public Entity
{
public:
    enum grPour {GrAnnee = 0,
                 GrClasse =1};

protected:
    int m_idAn;         //!< Clé: Clé vers l'année.
    int m_idCl;         //!< Clé: Clé vers la classe.
    int m_alpha;        //!< Attribut: type d'affichage.
    QString m_nom;      //!< Attribut: Nom du groupe.
    int m_type;         //!< Attribut: type du groupe.

public:
    NOM_POS_5_ATT(IdAn,IdCl,Alpha,Nom,Type)
    INCLUCE_METHODE(Groupe)

    //! Constructeur à partir des valeurs attributs.
    Groupe(int idAn, int idCl, int alpha, const QString & nom, int type, int id = 0)
        : Entity(id)
    {
        setIdAn(idAn);
        setIdCl(idCl);
        setAlpha(alpha);
        setNom(nom);
        setType(type);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Groupe(int cle, const QString & nom, grPour pr)
    {
        if(pr == GrClasse)
            {setIdCl(cle);}
        else
            {setIdAn(cle);}
        setNom(nom);
    }

    GET_SET_INT_SUP(idAn,IdAn,0)
    GET_SET_INT_SUP(idCl,IdCl,0)
    GET_SET_INT_SUP(alpha,Alpha,0)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_INT_SUP(type,Type,0)

    //! Teste si l'entitée est valide.
    bool isValid() const
    {return Entity::isValid()
                    && ((m_idAn > 0 && m_idCl == 0) || (m_idAn == 0 && m_idCl > 0))
                    && (m_alpha >= 0) && (!m_nom.isEmpty()) && (m_type >= 0);}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Groupe & entity) const
    {
        return Entity::egal(entity)
                && (m_idAn == entity.m_idAn)
                && (m_idCl == entity.m_idCl)
                && (m_alpha == entity.m_alpha)
                &&(m_nom == entity.m_nom)
                &&(m_type == entity.m_type);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Groupe & entity)
    {
        setIdAn(entity.idAn());
        setIdCl(entity.idCl());
        setAlpha(entity.alpha());
        setNom(entity.nom());
        setType(entity.type());
    }
};

#endif // GROUPE_H
