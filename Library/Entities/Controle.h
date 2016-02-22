#ifndef CONTROLE_H
#define CONTROLE_H

#include "Entity.h"

class Controle : public Entity
{
public:
    static const entityId IdEntity = ControleId;
    static const int NbrValue = 8;
protected:
    int m_classe;
    QDate m_date;
    int m_decimale;
    int m_minima;
    QString m_nom;
    bool m_saisie;
    int m_total;
    int m_type;

public:
    enum position{ClassePos = 0,
                  DatePos = 1,
                  DecimalePos = 2,
                  MinimaPos = 3,
                  NomPos = 4,
                  SaisiePos = 5,
                  TotalPos = 6,
                  TypePos = 7};
    Controle()  {}
    Controle(int id) : Entity(id)   {}
    Controle(int classe, const QDate &date, int decimale, int minima, const QString &nom, bool saisie, int total, int type, int id = 0) : Entity(id)
    {
        setClasse(classe);
        setDate(date);
        setDecimale(decimale);
        setMinima(minima);
        setNom(nom);
        setSaisie(saisie);
        setTotal(total);
        setType(type);
    }
    Controle(const Entity & entity) : Entity(entity.id())
    {
        const Controle & entityT = convert(entity);
        setClasse(entityT.classe());
        setDate(entityT.date());
        setDecimale(entityT.decimale());
        setMinima(entityT.minima());
        setNom(entityT.nom());
        setSaisie(entityT.saisie());
        setTotal(entityT.total());
        setType(entityT.type());
    }
    ~Controle()     {}
    int classe() const                  {return m_classe;}
    const QDate & date() const          {return m_date;}
    int decimale() const                {return m_decimale;}
     //entityId idEntity() const   {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_classe > 0) && (m_date.isValid()) && (m_decimale > 0)
                && (m_minima >= 0) && (!m_nom.isEmpty()) && (m_total > 0) && (m_type > 0);
    }
    int minima() const                  {return m_minima;}
     int nbrValue() const        {return NbrValue;}
    const QString & nom() const         {return m_nom;}
    bool saisie() const                 {return m_saisie;}
    void setClasse(int classe)
    {
        if(classe > 0)
        {
            m_classe = classe;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,ClassePos));
        }
    }
    void setDate(const QDate &date)
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
    void setDecimale(int decimale)
    {
        if(decimale > 0)
        {
            m_decimale = decimale;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,DecimalePos));
        }
    }
    void setMinima(int minima)
    {
        if(minima >= 0)
        {
            m_minima = minima;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,MinimaPos));
        }
    }
    void setNom(const QString &nom)
    {
        if(!nom.isEmpty())
        {
            m_nom = nom;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NomPos));
        }
    }
    void setSaisie(bool saisie)         {m_saisie = saisie;}
    void setTotal(int total)
    {
        if(total > 0)
        {
            m_total = total;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,TotalPos));
        }
    }
    void setType(int type)
    {
        if(type > 0)
        {
            m_type = type;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,TypePos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case ClassePos:
            setClasse(val.toInt());
            break;

        case DatePos:
            setDate(val.toDate());
            break;

        case DecimalePos:
            setDecimale(val.toInt());
            break;

        case MinimaPos:
            setMinima(val.toInt());
            break;

        case NomPos:
            setNom(val.toString());
            break;

        case SaisiePos:
            setSaisie(val.toBool());
            break;

        case TotalPos:
            setTotal(val.toInt());
            break;

        case TypePos:
            setType(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int total() const                   {return m_total;}
    int type() const                    {return m_type;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case ClassePos:
            return QVariant(classe());
            break;

        case DatePos:
            return QVariant(date());
            break;

        case DecimalePos:
            return QVariant(decimale());
            break;

        case MinimaPos:
            return QVariant(minima());
            break;

        case NomPos:
            return QVariant(nom());
            break;

        case SaisiePos:
            return QVariant(saisie());
            break;

        case TotalPos:
            return QVariant(total());
            break;

        case TypePos:
            return QVariant(type());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Controle & entityT = convert(entity);
        setId(entity.id());
        setClasse(entityT.classe());
        setDate(entityT.date());
        setDecimale(entityT.decimale());
        setMinima(entityT.minima());
        setNom(entityT.nom());
        setSaisie(entityT.saisie());
        setTotal(entityT.total());
        setType(entityT.type());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Controle & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_classe == entityT.classe())
                 &&(m_date == entityT.date())
                 &&(m_decimale == entityT.decimale())
                 &&(m_minima == entityT.minima())
                 &&(m_nom == entityT.nom())
                 &&(m_saisie == entityT.saisie())
                 &&(m_total == entityT.total())
                 &&(m_type == entityT.type());
     }

     INCLUCE_METHODE(Controle)
protected:
    /*void setInt1(int kk)                            {setClasse(kk);}
    void setDate1(const QDate &  date)              {setDate(date);}
    void setInt2(int kk)                            {setDecimale(kk);}
    void setInt3(int kk)                            {setMinima(kk);}
    void setString1(const QString & string)         {setNom(string);}
    void setBool1(bool bb)                          {setSaisie(bb);}
    void setInt4(int kk)                            {setTotal(kk);}
    void setInt5(int kk)                            {setType(kk);}

    int valueInt1() const                           {return m_classe;}
    const QDate & valueDate1() const                {return m_date;}
    int valueInt2() const                           {return m_decimale;}
    int valueInt3() const                           {return m_minima;}
    const QString & valueString1() const            {return m_nom;}
    bool valueBool1() const                         {return m_saisie;}
    int valueInt4() const                           {return m_total;}
    int valueInt5() const                           {return m_type;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Controle & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Controle*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // CONTROLE_H
