#ifndef APPRECIATION_H
#define APPRECIATION_H

#include "Entity.h"

class Appreciation : public Entity
{
public:
    static const entityId IdEntity = AppreciationId;
    static const int NbrValue = 4;
protected:
    QDateTime m_date;
    int m_note;
    bool m_saisie;
    QString m_texte;

public:
    enum position{DatePos = 0,
                  NotePos = 1,
                  SaisiePos = 2,
                  TextePos = 3};

    Appreciation() : Entity() {}
    Appreciation(int id) : Entity(id) {}
    Appreciation(const QDateTime &date, int note, bool saisie, const QString &texte, int id = 0) : Entity(id)
    {
        setDate(date);
        setNote(note);
        setSaisie(saisie);
        setTexte(texte);
    }
    Appreciation(const Entity & entity) : Entity(entity.id())
    {
        const Appreciation & entityT = convert(entity);
        setDate(entityT.date());
        setNote(entityT.note());
        setSaisie(entityT.saisie());
        setTexte(entityT.texte());
    }
    ~Appreciation() {}
    const QDateTime & date() const                  {return m_date;}
     ////entityId idEntity() const               {return IdEntity;}
     bool isValid() const                    {return Entity::isValid() && (m_date.isValid()) && (m_note > 0);}
     int nbrValue() const                    {return NbrValue;}
    int note() const                                {return m_note;}
    bool saisie() const                             {return m_saisie;}
    void setDate(const QDateTime & date)
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
    void setSaisie(bool saisie)                     {m_saisie = saisie;}
    void setTexte(const QString &texte)             {m_texte = texte;}
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
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

        case TextePos:
            setTexte(val.toString());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    const QString & texte() const                   {return m_texte;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
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

        case TextePos:
            return QVariant(texte());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Appreciation & entityT = convert(entity);
        setId(entity.id());
        setDate(entityT.date());
        setNote(entityT.note());
        setSaisie(entityT.saisie());
        setTexte(entityT.texte());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Appreciation & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_date == entityT.date())
                 &&(m_note == entityT.note())
                 &&(m_saisie == entityT.saisie())
                 &&(m_texte == entityT.texte());
     }

     INCLUCE_METHODE(Appreciation)
     /*static Appreciation & verif(const Entity & entity)
     {
         if(verifEntity(entity))
         {
             return *((Appreciation*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     static Appreciation & verif(Entity *entity)
     {
         if(verifEntity(*entity))
         {
             return (Appreciation*) entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
    /*void setDateTime(const QDateTime &date)             {setDate(date);}
    void setInt1(int kk)                                {setNote(kk);}
    void setBool1(bool bb)                              {setSaisie(bb);}
    void setString1(const QString & string)             {setTexte(string);}

    const QDateTime & valueDateTime() const             {return m_date;}
    int valueInt1() const                               {return m_note;}
    bool valueBool1() const                             {return m_saisie;}
    const QString & valueString1() const                {return m_texte;}*/

};

#endif // APPRECIATION_H
