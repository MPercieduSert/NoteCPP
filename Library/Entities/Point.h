#ifndef POINT_H
#define POINT_H

#include "Entity.h"

class Point : public Entity
{
public:
    static const entityId IdEntity = PointId;
    static const int NbrValue = 6;
protected:
    int m_bareme;
    int m_commentaire;
    QDateTime m_date;
    int m_note;
    bool m_saisie;
    int m_valeur;

public:
    enum position{BaremePos = 0,
                  CommentairePos = 1,
                  DatePos = 2,
                  NotePos = 3,
                  SaisiePos = 4,
                  ValeurPos = 5};

    Point() {}
    Point(int id) : Entity(id) {}
    Point(int bareme, int commentaire, const QDateTime & date, int note, bool saisie, int valeur, int id = 0) : Entity(id)
    {
        setBareme(bareme);
        setCommentaire(commentaire);
        setDate(date);
        setNote(note);
        setSaisie(saisie);
        setValeur(valeur);
    }
    Point(const Entity & entity):Entity(entity.id())
    {
        const Point & entityT = convert(entity);
        setBareme(entityT.bareme());
        setCommentaire(entityT.commentaire());
        setDate(entityT.date());
        setNote(entityT.note());
        setSaisie(entityT.saisie());
        setValeur(entityT.valeur());
    }
    ~Point()    {}
    int bareme() const                                  {return m_bareme;}
    int commentaire() const                             {return m_commentaire;}
    const QDateTime & date() const                      {return m_date;}
     //entityId idEntity() const                   {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_bareme > 0) && (m_commentaire) && (m_date.isValid()) && (m_note > 0) && (m_valeur >= -1);
    }
     int nbrValue() const                        {return NbrValue;}
    int note() const                                    {return m_note;}
    bool saisie() const                                 {return m_saisie;}
    void setBareme(int bareme)
    {
        if(bareme > 0)
        {
            m_bareme = bareme;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,BaremePos));
        }
    }
    void setCommentaire(int commentaire)
    {
        if(commentaire > 0)
        {
            m_commentaire = commentaire;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,CommentairePos));
        }
    }
    void setDate(const QDateTime &date)
    {
        if(date.isValid())
        {
            m_date = date;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,DatePos));
        }
    }
    void setNote(int note)
    {
        if(note > 0)
        {
            m_note = note;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NotePos));
        }
    }
    void setSaisie(bool saisie)                         {m_saisie = saisie;}
    void setValeur(int valeur)
    {
        if(valeur >= -1)
        {
            m_valeur = valeur;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ValeurPos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case BaremePos:
            setBareme(val.toInt());
            break;

        case CommentairePos:
            setCommentaire(val.toInt());
            break;

        case DatePos:
            setDate(val.toDateTime());
            break;

        case NotePos:
            setNote(val.toInt());
            break;

        case SaisiePos:
            setSaisie(val.toBool());
            break;

        case ValeurPos:
            setValeur(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int valeur() const                                  {return m_valeur;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case BaremePos:
            return QVariant(bareme());
            break;

        case CommentairePos:
            return QVariant(commentaire());
            break;

        case DatePos:
            return QVariant(date());
            break;

        case NotePos:
            return QVariant(note());
            break;

        case SaisiePos:
            return QVariant(saisie());
            break;

        case ValeurPos:
            return QVariant(valeur());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Point & entityT = convert(entity);
        setId(entity.id());
        setBareme(entityT.bareme());
        setCommentaire(entityT.commentaire());
        setDate(entityT.date());
        setNote(entityT.note());
        setSaisie(entityT.saisie());
        setValeur(entityT.valeur());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Point & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_bareme == entityT.bareme())
                 &&(m_commentaire == entityT.commentaire())
                 &&(m_date == entityT.date())
                 &&(m_note == entityT.note())
                 &&(m_saisie == entityT.saisie())
                 &&(m_valeur == entityT.valeur());
     }

     INCLUCE_METHODE(Point)
protected:
    /*void setInt1(int kk)                        {setBareme(kk);}
    void setInt2(int kk)                        {setCommentaire(kk);}
    void setDateTime(const QDateTime &  date)   {setDate(date);}
    void setInt3(int kk)                        {setNote(kk);}
    void setBool1(bool bb)                      {setSaisie(bb);}
    void setInt4(int kk)                        {setValeur(kk);}

    int valueInt1() const                       {return m_bareme;}
    int valueInt2() const                       {return m_commentaire;}
    const QDateTime & valueDateTime() const     {return m_date;}
    int valueInt3() const                       {return m_note;}
    bool valueBool1() const                     {return m_saisie;}
    int valueInt4() const                       {return m_valeur;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Point & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Point*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // POINT_H
