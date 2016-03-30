/*Auteur: PERCIE DU SERT Maxime
 *Date: 24/03/2016
 */
#ifndef ARBRES
#define ARBRES

#include "Arbre.h"
#include "InfoEntity.h"

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité AttributArbre.
 */
struct AttributArbreInfo : ArbreInfo
{
    static const int ID = InfoEntity::AttributArbreId;
    static constexpr char Name[] {"Arbre Attribut"};
};

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité CoursArbre.
 */
struct CoursArbreInfo : ArbreInfo
{
    static const int ID = InfoEntity::CoursArbreId;
    static constexpr char Name[] {"Arbre Cours"};
};

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité DonneeArbre.
 */
struct DonneeArbreInfo : ArbreInfo
{
    static const int ID = InfoEntity::DonneeArbreId;
    static constexpr char Name[] {"Arbre Donnee"};
};

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité EnonceArbre.
 */
struct EnonceArbreInfo : ArbreInfo
{
    static const int ID = InfoEntity::EnonceArbreId;
    static constexpr char Name[] {"Arbre Enonce"};
};

/*! \ingroup groupeInfoEntity
 * \brief Information sur l'entité ExerciceArbre.
 */
struct ExerciceArbreInfo : ArbreInfo
{
    static const int ID = InfoEntity::ExerciceArbreId;
    static constexpr char Name[] {"Arbre Exercice"};
};

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité AttributArbre.
 */
typedef Arbre<AttributArbreInfo> AttributArbre;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité CoursArbre.
 */
typedef Arbre<CoursArbreInfo> CoursArbre;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité DonneeArbre.
 */
typedef Arbre<DonneeArbreInfo> DonneeArbre;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité EnonceArbre.
 */
typedef Arbre<EnonceArbreInfo> EnonceArbre;

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité ExerciceArbre.
 */
typedef Arbre<ExerciceArbreInfo> ExerciceArbre;

#endif // ARBRES

