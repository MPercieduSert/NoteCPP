#ifndef NOTE_H
#define NOTE_H

#include "Entity.h"

class Note : public Entity
{
public:
    static const entityId IdEntity = NoteId;
    static const int NbrValue = 6;
protected:
    bool m_appreciation;
    int m_controle;
    QDateTime m_date;
    int m_eleve;
    bool m_saisie;
    int m_valeur;

public:
    enum position{AppreciationPos = 0,
                  ControlePos = 1,
                  DatePos = 2,
                  ElevePos = 3,
                  SaisiePos = 4,
                  ValeurPos = 5};

    Note() {}
    Note(int id) : Entity(id) {}
    Note(bool appreciation, int controle, const QDateTime &date, int eleve, bool saisie, int valeur, int id = 0) : Entity(id)
    {
        setAppreciation(appreciation);
        setControle(controle);
        setDate(date);
        setEleve(eleve);
        setSaisie(saisie);
        setValeur(valeur);
    }
    Note(const Entity & entity) : Entity(entity.id())
    {
        const Note & entityT = convert(entity);
        setAppreciation(entityT.appreciation());
        setControle(entityT.controle());
        setDate(entityT.date());
        setEleve(entityT.eleve());
        setSaisie(entityT.saisie());
        setValeur(entityT.valeur());
    }

    ~Note() {}
    bool appreciation() const                   {return m_appreciation;}
    int controle() const                        {return m_controle;}
    const QDateTime &date() const               {return m_date;}
    int eleve() const                           {return m_eleve;}
     //entityId idEntity() const           {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_controle > 0) && (m_date.isValid()) && (m_eleve > 0) && (m_valeur >= -1);
    }
     int nbrValue() const                {return NbrValue;}
    bool saisie() const                        {return m_saisie;}
    void setAppreciation(bool appreciation)     {m_appreciation = appreciation;}
    void setControle(int controle)
    {
        if(controle > 0)
        {
            m_controle = controle;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ControlePos));
        }
    }
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
    void setEleve(int eleve)
    {
        if(eleve > 0)
        {
            m_eleve = eleve;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ElevePos));
        }
    }
    void setSaisie(bool saise)                  {m_saisie = saise;}
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

        case AppreciationPos:
            setAppreciation(val.toBool());
            break;

        case ControlePos:
            setControle(val.toInt());
            break;

        case DatePos:
            setDate(val.toDateTime());
            break;

        case ElevePos:
            setEleve(val.toInt());
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
    int valeur() const                          {return m_valeur;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case AppreciationPos:
            return QVariant(appreciation());
            break;

        case ControlePos:
            return QVariant(controle());
            break;

        case DatePos:
            return QVariant(date());
            break;

        case ElevePos:
            return QVariant(eleve());
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
        const Note & entityT = convert(entity);
        setId(entity.id());
        setAppreciation(entityT.appreciation());
        setControle(entityT.controle());
        setDate(entityT.date());
        setEleve(entityT.eleve());
        setSaisie(entityT.saisie());
        setValeur(entityT.valeur());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Note & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_appreciation == entityT.appreciation())
                 &&(m_controle == entityT.controle())
                 &&(m_date == entityT.date())
                 &&(m_eleve == entityT.eleve())
                 &&(m_saisie == entityT.saisie())
                 &&(m_valeur == entityT.valeur());
     }

     INCLUCE_METHODE(Note)
protected:
    /*void setBool1(bool bb)                          {setAppreciation(bb);}
    void setInt1(int kk)                            {setControle(kk);}
    void setDateTime(const QDateTime &  date)       {setDate(date);}
    void setInt2(int kk)                            {setEleve(kk);}
    void setBool2(bool bb)                          {setSaisie(bb);}
    void setInt3(int kk)                            {setValeur(kk);}

    bool valueBool1() const                         {return m_appreciation;}
    int valueInt1() const                           {return m_controle;}
    const QDateTime & valueDateTime() const         {return m_date;}
    int valueInt2() const                           {return m_eleve;}
    bool valueBool2() const                         {return m_saisie;}
    int valueInt3() const                           {return m_valeur;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Note & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Note*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // NOTE_H
