/*Auteur: PERCIE DU SERT Maxime
 *Date: 28/02/2016
 */
#ifndef ELEVE_H
#define ELEVE_H

#include "AttributMultiple.h"
#include "Entity.h"
#include "InfoEntity.h"

SINGLE_ATTRIBUT(FilleAttribut,AttributBool,AttributBool,Fille,fille,bool)
SINGLE_ATTRIBUT(NaissanceAttribut,AttributDateValide,AttributDateValide,Naissance,naissance,QDate)
SINGLE_ATTRIBUT(PrenomAttribut,AttributStringNotEmpty,AttributStringNotEmpty,Prenom,prenom,QString)

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Eleve.
 */
class Eleve : public EntityAttributsID<Attributs<FilleAttribut,NaissanceAttribut,NomAttribut,PrenomAttribut>,InfoEntity::EleveId>
{
public:
    //! Positions des attributs.
    enum Position {Id = PositionEnum<IdAttribut,Eleve>::Position,
                   Fille = PositionEnum<FilleAttribut,Eleve>::Position,
                   Naissance = PositionEnum<NaissanceAttribut,Eleve>::Position,
                   Nom = PositionEnum<NomAttribut,Eleve>::Position,
                   Prenom = PositionEnum<PrenomAttribut,Eleve>::Position,
                   NbrAtt};

    using EAID = EntityAttributsID<Attributs<FilleAttribut,NaissanceAttribut,NomAttribut,PrenomAttribut>,InfoEntity::EleveId>;
    using EAID::EntityAttributsID;
    BASE_ENTITY(Eleve)

    //! Constructeur à partir des valeurs d'un ensemble d'attributs unique.
    Eleve(const QDate & naissance, const QString &nom, const QString &prenom, int id = 0)
        : EAID(id)
    {
        setNom(nom);
        setNaissance(naissance);
        setPrenom(prenom);
    }

    //! Constructeur à partir des valeurs attributs.
    Eleve(bool fille, const QDate & naissance, const QString &nom, const QString &prenom, int id = 0)
        : Eleve(naissance, nom, prenom, id)
        {setFille(fille);}

    //! Renvoie F si l'éléve est une fille et M sinon.
    QChar afficheFille() const                      {return fille() ? QChar('F'): QChar('M');}
};

#endif // ELEVE_H
