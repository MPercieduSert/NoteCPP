/*Auteur: PERCIE DU SERT Maxime
 *Date: 06/03/2016
 */

#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Etablissement.
 */

class Etablissement : public Entity
{
protected:
    QString m_nc;   //!< Attribut: nom court de l'établissement.
    QString m_nom;  //!< Attribut: nom de l'établissement.
    int m_type;     //!< Attribut: type d'établissement.

public:
    NOM_POS_3_ATT(Nc,Nom,Type)
    INCLUCE_METHODE(Etablissement)

    //! Constructeur à partir des valeurs attributs.
    Etablissement(const QString & nc, const QString & nom, int type, int id=0)
        : Entity(id)
    {
        setNc(nc);
        setNom(nom);
        setType(type);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Etablissement(const QString & nom)
        {setNom(nom);}

    GET_SET_TEXTE_NOT_NULL(nc,Nc)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_INT_SUP(type,Type,0)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (!m_nc.isEmpty()) && (!m_nom.isEmpty()) && (m_type >= 0);}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Etablissement & entity) const
    {
        return Entity::egal(entity)
                &&(m_nc == entity.m_nc)
                &&(m_nom == entity.m_nom)
                && (m_type == entity.m_type);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Etablissement & entity)
    {
        setNc(entity.nc());
        setNom(entity.nom());
        setType(entity.type());
    }
};

#endif // ETABLISSEMENT_H
