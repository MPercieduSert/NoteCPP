/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Attribut.
 */

class Attribut : public Entity
{
protected:
    QString m_nom;              //!< Attribut: Nom de l'attribut.
    bool m_prBareme;            //!< Attribut: Vraie si l'attribut peut être associé à un barème.
    bool m_prCommentaire;       //!< Attribut: Vraie si l'attribut peut être associé à un commentaire.
    bool m_prCorrection;        //!< Attribut: Vraie si l'attribut peut être associé à une correction.
    bool m_prCours;             //!< Attribut: Vraie si l'attribut peut être associé à un cours.
    bool m_prExercice;          //!< Attribut: Vraie si l'attribut peut être associé à un exercice.
    QString m_nc;               //!< Attribut: Nom cours de l'attribut.

public:
    NOM_POS_7_ATT(Nom,PrBareme,PrCommentaire,PrCorrection,PrCours,PrExercice,Nc)
    INCLUCE_METHODE(Attribut)

    //! Constructeur à partir des valeurs attributs.
    Attribut(const QString & nom, bool bareme, bool commentaire, bool correction, bool cours, bool exercice, int id = 0, const QString & nc = QString()): Entity(id)
    {
        setNom(nom);
        setPrBareme(bareme);
        setPrCommentaire(commentaire);
        setPrCorrection(correction);
        setPrCours(cours);
        setPrExercice(exercice);
        setNc(nc);
    }

    GET_SET_TEXTE_NULL(nc,Nc)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_BOOL(prBareme,PrBareme)
    GET_SET_BOOL(prCommentaire,PrCommentaire)
    GET_SET_BOOL(prCorrection,PrCorrection)
    GET_SET_BOOL(prCours,PrCours)
    GET_SET_BOOL(prExercice,PrExercice)

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (!m_nom.isEmpty());}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Attribut & entity) const
    {
        return Entity::egal(entity)
                &&(m_nom == entity.m_nom)
                &&(m_prBareme == entity.m_prBareme)
                &&(m_prCommentaire == entity.m_prCommentaire)
                &&(m_prCorrection == entity.m_prCorrection)
                &&(m_prCours == entity.m_prCours)
                &&(m_prExercice == entity.m_prExercice)
                &&(m_nc == entity.m_nc);
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Attribut & entity)
    {
        setNom(entity.nom());
        setPrBareme(entity.prBareme());
        setPrCommentaire(entity.prCommentaire());
        setPrCorrection(entity.prCorrection());
        setPrCours(entity.prCours());
        setPrExercice(entity.prExercice());
        setNc(entity.nc());
    }
};

#endif // ATTRIBUT_H
