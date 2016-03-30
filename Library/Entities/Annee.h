/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */
#ifndef ANNEE_H
#define ANNEE_H

#include "AttributEntityAlias.h"
#include "Entity.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité Annee.
 */
struct AnneeInfo
{
    static const int ID = InfoEntity::AnneeId;
    static constexpr char Name[] {"Annee"};
    ATTRIBUT_1(An)
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Annee.
 */
class Annee : public EntityTemp<Annee,AnneeInfo>,
        public AnAttribut
{
public:
    //! Constructeur par defaut.
    Annee(int id = 0)
        : EntityTemp(id)
        {}

    //! Constructeur à partir des valeurs attributs.
    Annee(int an, int id)
        : EntityTemp(id),
          AnAttribut(an)
        {}

    //! Constructeur de recopie.
    Annee(const Annee & entity)
        : EntityTemp(entity), AnAttribut(entity.an())
        {}

    //! Destructeur.
    ~Annee()
        {}

    //! Renvoie la chaine de caractère "annee-annee+1".
    QString affiche() const
    {return QString::number(an())+"-"+QString::number(an()+1);}

    //! Teste si l'entité est valide.
    bool isValid() const
    {return EntityTemp::isValid() && AnAttribut::valide();}

    //! Oprérateur d'ordre strictement croissant sur an.
    bool operator < (const Annee & annee) const
    {
        return an() < annee.an();
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Annee & entity) const
    {
        return EntityTemp::egal(entity)
                && (an() == entity.an());
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Annee & entity)
    {
        EntityTemp::set(entity);
        setAn(entity.an());
    }
};

#endif // ANNEE_H
