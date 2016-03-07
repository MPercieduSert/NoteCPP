/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef NIVEAU_H
#define NIVEAU_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Niveau.
 */

class Niveau : public Entity
{
protected:
    int m_idTp;      //!< Clé: clé vers le type de niveau.
    QString m_nc;       //!< Attribut: abréviation du niveau.
    QString m_nom;      //!< Attribut: nom du niveau

public:
    NOM_POS_3_ATT(IdTp,Nc,Nom)
    INCLUCE_METHODE(Niveau)

    //! Constructeur à partir des valeurs attributs.
    Niveau(int idTp, const QString & nc, const QString & nom, int id = 0)
        : Entity(id)
    {
        setIdTp(idTp);
        setNc(nc);
        setNom(nom);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Niveau(const QString & nom)
        {setNom(nom);}

    GET_SET_ID(Tp)
    GET_SET_TEXTE_NOT_NULL(nc,Nc)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (m_idTp > 0) && (!m_nc.isEmpty()) && (!m_nom.isEmpty());}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Niveau & entity) const
    {
        return Entity::egal(entity)
                && (m_idTp == entity.m_idTp)
                &&(m_nc == entity.m_nc)
                &&(m_nom == entity.m_nom);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Niveau & entity)
    {
        setIdTp(entity.idTp());
        setNc(entity.nc());
        setNom(entity.nom());
    }
};

#endif // NIVEAU_H
