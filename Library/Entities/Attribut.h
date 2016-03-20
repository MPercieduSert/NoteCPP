/*Auteur: PERCIE DU SERT Maxime
 *Date: 04/03/2016
 */

#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Attribut.
 */
class Attribut : public NomEntity, public EntityTemp<IdentifiantEntity::AttributId,7,Attribut>, public PrBaremeAttribut, public PrCommentaireAttribut, public PrCorrectionAttribut, public PrCoursAttribut, public PrExerciceAttribut, public NcNullAttribut
{
public:
    POS_7_ATT(Nom,PrBareme,PrCommentaire,PrCorrection,PrCours,PrExercice,Nc)

    //! Constructeur par defaut.
    Attribut(int id = 0)
        : NomEntity(id)
    {}

    //! Constructeur à partir des valeurs attributs.
    Attribut(const QString & nom, bool bareme, bool commentaire, bool correction, bool cours, bool exercice, int id = 0, const QString & nc = QString())
        : NomEntity(nom,id),
          PrBaremeAttribut(bareme),
          PrCommentaireAttribut(commentaire),
          PrCorrectionAttribut(correction),
          PrCoursAttribut(cours),
          PrExerciceAttribut(exercice),
          NcNullAttribut(nc)
    {}

    //! Constructeur de recopie.
    Attribut(const Attribut & entity)
        : NomEntity(entity),
          PrBaremeAttribut(entity.prBareme()),
          PrCommentaireAttribut(entity.prCommentaire()),
          PrCorrectionAttribut(entity.prCorrection()),
          PrCoursAttribut(entity.prCours()),
          PrExerciceAttribut(entity.prExercice()),
          NcNullAttribut(entity.nc())
    {}

    //! Destructeur.
    ~Attribut()
    {}

    //! Teste si l'entitée est valide.
    bool isValid() const
    {return NomEntity::isValid()
                && PrBaremeAttribut::valide()
                && PrCommentaireAttribut::valide()
                && PrCorrectionAttribut::valide()
                && PrCoursAttribut::valide()
                && PrExerciceAttribut::valide()
                && NcNullAttribut::valide();}

protected:
    //! Test d'égalité entre cette entitée et celle transmise en argument.
    bool egal(const Attribut & entity) const
    {
        return NomEntity::egal(entity)
                &&(prBareme() == entity.prBareme())
                &&(prCommentaire() == entity.prCommentaire())
                &&(prCorrection() == entity.prCorrection())
                &&(prCours() == entity.prCours())
                &&(prExercice() == entity.prExercice())
                &&(nc() == entity.nc());
    }

    //! Remplace les attributs de l'entitée par celle de l'entitée transmise, sauf l'identifiant.
    void set(const Attribut & entity)
    {
        NomEntity::set(entity);
        setPrBareme(entity.prBareme());
        setPrCommentaire(entity.prCommentaire());
        setPrCorrection(entity.prCorrection());
        setPrCours(entity.prCours());
        setPrExercice(entity.prExercice());
        setNc(entity.nc());
    }
};

#endif // ATTRIBUT_H
