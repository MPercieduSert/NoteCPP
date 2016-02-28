/*Auteur: PERCIE DU SERT Maxime
 *Date: 26/02/2016
 */

#ifndef ANNEE_H
#define ANNEE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entitée Année.
 */

class Annee : public Entity
{
public:
    //! Position des attributs dans l'entitée, suit notamment l'ordre des colonnes dans la base de donnée.
    enum position {AnneePos = 0,
                  IdPos = 1};

    static const entityId IdEntity = AnneeId;   //!< Identifiant du type des entitées Annee.
    static constexpr char Name[] = "Annee";     //!< Nom de l'entitée.
    static const int NbrAtt = 2;                //!< Nombre d'attributs des entitées Annee.
    static constexpr std::array<const char*,NbrAtt> Att {{"annee", "ID"}};  //!< Tableau des attributs des entitées Annee.
    //static const int NbrEnsUni = 1;             //!< Nombre d'ensemble d'attributs uniques de l'entitée autre que l'identifiant.
    //static constexpr std::array<const char*, NbrEnsUni> EnsUni {{"annee"}}; //!< Tableau des chaines des ensembles d'attributs uniques de l'entitée.

protected:
    int m_annee;//!< Attribut: annee de rentrée.

public:
    INCLUCE_METHODE(Annee)

    //! Constructeur à partir des valeurs attributs.
    Annee(int annee, int id = 0) : Entity(id)
    {
        setAnnee(annee);
    }

    // Renvoie la chaine de caractère "annee-annee+1".
    QString affiche() const
        {return QString::number(m_annee)+"-"+QString::number(m_annee+1);}

    //! Retourne la valeur de l'attribut annee.
    bool annee() const
        {return m_annee;}

    //! Teste si l'entitée est valide.
    bool isValid() const
        {return Entity::isValid() && (m_annee > 0);}

    //! Modifie l'attribut annee.
    void setAnnee(int annee)
    {
        if(annee > 0)
        {
            m_annee = annee;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,AnneePos));
        }
    }

    //! Opérateur testant l'égalité de deux entitées, c'est-à-dire l'égalité de tous les attributs.
    bool operator == (const Entity & entity) const
    {
        const Annee & entityT = convert(entity);
        return (m_id == entityT.id())
                &&(m_annee == entityT.annee());
    }

    bool operator < (const Annee & annee) const
    {
        return m_annee < annee.annee();
    }

protected:
    void set(const Annee & annee)
    {
        setAnnee(annee.annee());
    }
};
/*static Annee & convert(const Entity & entity)
{
    if(verifEntity(entity))
    {
        return *((Annee*) &entity);
    }
    else
    {
        throw std::runtime_error("Mauvaise correspondance des Entity");
    }
}
static Annee * convert(Entity *entity)
{
    if(verifEntity(*entity))
    {
        return (Annee*) entity;
    }
    else
    {
        throw std::runtime_error("Mauvaise correspondance des Entity");
    }
}
static bool verifEntity(const Entity & entity)              {return IdEntity == entity.idEntity();}
protected:*/
/*void setBool1(bool encours)                         {setEncours(encours);}
void setInt1(int rentree)                           {setRentree(rentree);}
bool valueBool1() const                             {return m_encours;}
int valueInt1() const                               {return m_rentree;}*/
/*
    void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case EncoursPos:
            setEncours(val.toBool());
            break;

        case RentreePos:
            setRentree(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case EncoursPos:
            return QVariant(encours());
            break;

        case RentreePos:
            return QVariant(rentree());
            break;

        default:
            return QVariant();
        }
    }
*/

#endif // ANNEE_H
