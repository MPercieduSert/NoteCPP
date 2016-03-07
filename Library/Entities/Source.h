/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef SOURCE_H
#define SOURCE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Source.
 */

class Source : public Entity
{
protected:
    QString m_nom;      //!< Attribut: nom de la source.
    int m_type;         //!< Attribut: type de la source.

public:
    NOM_POS_2_ATT(Nom,Type)
    INCLUCE_METHODE(Source)

    //! Constructeur à partir des valeurs attributs.
    Source(const QString & nom, int type, int id) : Entity(id)
    {
        setNom(nom);
        setType(type);
    }

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Source(const QString & nom)
        {setNom(nom);}

    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_INT_SUP(type,Type,0)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (!m_nom.isEmpty()) && (m_type >= 0);}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Source & entity) const
    {
        return Entity::egal(entity)
                &&(m_nom == entity.m_nom)
                &&(m_type == entity.m_type);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Source & entity)
    {
        setNom(entity.nom());
        setType(entity.type());
    }
};

#endif // SOURCE_H
