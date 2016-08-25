/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */
#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "AttributEntity.h"
#include "EntityNom.h"
#include "InfoEntity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Attribut.
 */
class Attribut : public NomEntity
{
    ATTRIBUT_ENTITY_BOOL(PrBareme,prBareme)
    ATTRIBUT_ENTITY_BOOL(PrCommentaire,prCommentaire)
    ATTRIBUT_ENTITY_BOOL(PrCorrection,prCorrection)
    ATTRIBUT_ENTITY_BOOL(PrCours,prCours)
    ATTRIBUT_ENTITY_BOOL(PrExercice,prExercice)
    ATTRIBUT_ENTITY_STR_NOT_EMPTY(Nc,nc)
public:
    using NomEntity::NomEntity;
    BASE_ENTITY(Attribut,InfoEntity::AttributId)

    //! Constructeur à partir des valeurs attributs.
    Attribut(const QString & nom, bool bareme, bool commentaire, bool correction, bool cours, bool exercice, int id = 0, const QString & nc = QString())
        : NomEntity(nom,id),
          m_prBareme(bareme),
          m_prCommentaire(commentaire),
          m_prCorrection(correction),
          m_prCours(cours),
          m_prExercice(exercice),
          m_nc(nc)
    {}

    MEMBRE_ATT_6(Attribut,NomEntity,PrBareme,prBareme,PrCommentaire,prCommentaire,PrCorrection,prCorrection,PrCours,prCours,PrExercice,prExercice,Nc,nc)
};

#endif // ATTRIBUT_H
