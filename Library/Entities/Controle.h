/*Auteur: PERCIE DU SERT Maxime
 *Date: 05/03/2016
 */

#ifndef CONTROLE_H
#define CONTROLE_H

#include "Entity.h"

/*! \ingroup groupeEntity
 * \brief Représentation de l'entité Controle.
 */

class Controle : public Entity
{
protected:
    int m_idCl;         //!< Clé: Classe subissant le controle.
    int m_idTp;         //!< Clé: Type du controle.
    QDate m_date;       //!< Attribut: Date du controle.
    int m_decimale;     //!< Attribut: Nombre de fractions de 1 autorisées.
    int m_minima;       //!< Attribut: Barre de classement.
    QString m_nom;      //!< Attribut: Nom du controle.
    bool m_saisie;      //!< Attribut: Saissie des notes autorisées?
    int m_total;        //!< Attribut: Note maximal du controle.

public:
    NOM_POS_8_ATT(IdCl,IdTp,Date,Decimale,Minima,Nom,Saisie,Total)
    INCLUCE_METHODE(Controle)

    //! Constructeur à partir des valeurs attributs.
    Controle(int idCl, int idTp, const QDate &date, int decimale, int minima, const QString &nom, bool saisie, int total, int id = 0)
        : Entity(id)
    {
        setIdCl(idCl);
        setIdTp(idTp);
        setDate(date);
        setDecimale(decimale);
        setMinima(minima);
        setNom(nom);
        setSaisie(saisie);
        setTotal(total);
    }

    GET_SET_ID(Cl)
    GET_SET_ID(Tp)
    GET_SET_DATE_VALIDE(date,Date)
    GET_SET_INT_SUP(decimale,Decimale,1)
    GET_SET_INT_SUP(minima,Minima,0)
    GET_SET_TEXTE_NOT_NULL(nom,Nom)
    GET_SET_BOOL(saisie,Saisie)
    GET_SET_INT_SUP(total,Total,1)

    //! Teste si l'entité est valide.
    bool isValid() const
    {
        return Entity::isValid() && (m_idCl > 0) && (m_idTp > 0) && (m_date.isValid()) && (m_decimale > 0)
                && (m_minima >= 0) && (!m_nom.isEmpty()) && (m_total > 0);
    }

protected:
    //! Test d'égalité entre cette entité et celle transmise en argument.
    bool egal(const Controle & entity) const
    {
        return Entity::egal(entity)
                &&(m_idCl == entity.m_idCl)
                &&(m_idTp == entity.m_idTp)
                &&(m_date == entity.m_date)
                &&(m_decimale == entity.m_decimale)
                &&(m_minima == entity.m_minima)
                &&(m_nom == entity.m_nom)
                &&(m_saisie == entity.m_saisie)
                &&(m_total == entity.m_total);
    }

    //! Remplace les attributs de l'entité par celle de l'entité transmise, sauf l'identifiant.
    void set(const Controle & entity)
    {
        setIdCl(entity.idCl());
        setIdTp(entity.idTp());
        setDate(entity.date());
        setDecimale(entity.decimale());
        setMinima(entity.minima());
        setNom(entity.nom());
        setSaisie(entity.saisie());
        setTotal(entity.total());
    }
};

#endif // CONTROLE_H
