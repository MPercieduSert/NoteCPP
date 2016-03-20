/*Auteur: PERCIE DU SERT Maxime
 *Date: 29/02/2016
 */

#ifndef TYPE_NIVEAU_H
#define TYPE_NIVEAU_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée TypeNiveau.
 */

class TypeNiveau : public NomEntity, public EntityTemp<IdentifiantEntity::TypeNiveauId,2,TypeNiveau>
{
public:
    //! Numéro des types de niveaux.
    enum num {Primaire = 1,
              College = 2,
              Lycee = 3,
              Prepa = 4,
              Licence = 5};

    POS_1_ATT(Nom)

    //! Constructeur par defaut.
    TypeNiveau(int id = 0)
        : NomEntity(id)
    {}

    //! Constructeur à partir des valeurs TypeNiveaus.
    TypeNiveau(const QString & nom, int id = 0)
        : NomEntity(nom,id)
    {}

    //! Constructeur de recopie.
    TypeNiveau(const TypeNiveau & entity)
        : NomEntity(entity)
    {}

    //! Destructeur.
    ~TypeNiveau()
    {}
};

#endif // TYPE_NIVEAU_H
