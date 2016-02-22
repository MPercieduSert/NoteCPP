#ifndef TYPECONTROLE_H
#define TYPECONTROLE_H

#include "Entity.h"

class TypeControle : public Entity
{
public:
    static const entityId IdEntity = TypeControleId;
    static const int NbrValue = 6;
protected:
    bool m_appreciation;
    int m_decimale;
    bool m_modifT;
    QString m_nc;
    QString m_nom;
    int m_total;

public:
    enum position{AppreciationPos = 0,
                  DecimalePos = 1,
                  ModifTPos = 2,
                  NcPos = 3,
                  NomPos = 4,
                  TotalPos = 5};

    TypeControle()  {}
    TypeControle(int id) : Entity(id)   {}
    TypeControle(bool appreciation, int decimale, bool modifT, const QString & nc, const QString & nom, int total, int id = 0) : Entity(id)
    {
        setAppreciation(appreciation);
        setDecimale(decimale);
        setModifT(modifT);
        setNc(nc);
        setNom(nom);
        setTotal(total);
    }
    TypeControle(const Entity & entity) : Entity(entity.id())
    {
        const TypeControle & entityT = convert(entity);
        setAppreciation(entityT.appreciation());
        setDecimale(entityT.decimale());
        setModifT(entityT.modifT());
        setNc(entityT.nc());
        setNom(entityT.nom());
        setTotal(entityT.total());
    }
    ~TypeControle() {}
    bool appreciation() const           {return m_appreciation;}
    int decimale() const                {return m_decimale;}
     //entityId idEntity() const   {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_decimale > 0) && (!m_nc.isEmpty()) && (!m_nom.isEmpty()) && (m_total > 0);
    }
    bool modifT() const                 {return m_modifT;}
     int nbrValue() const        {return NbrValue;}
    const QString & nc() const          {return m_nc;}
    const QString & nom() const         {return m_nom;}
    void setAppreciation(bool appreciation) {m_appreciation = appreciation;}
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
    void setModifT(bool modifT)         {m_modifT = modifT;}
    void setNc(const QString & nc)
    {
        if(!nc.isEmpty())
        {
            m_nc = nc;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NcPos));
        }
    }
    void setNom(const QString & nom)
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

        case DecimalePos:
            setDecimale(val.toInt());
            break;

        case ModifTPos:
            setModifT(val.toBool());
            break;

        case NcPos:
            setNc(val.toString());
            break;

        case NomPos:
            setNom(val.toString());
            break;

        case TotalPos:
            setTotal(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int total() const                   {return m_total;}
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

        case DecimalePos:
            return QVariant(decimale());
            break;

        case ModifTPos:
            return QVariant(modifT());
            break;

        case NcPos:
            return QVariant(nc());
            break;

        case NomPos:
            return QVariant(nom());
            break;

        case TotalPos:
            return QVariant(total());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const TypeControle & entityT = convert(entity);
        setId(entity.id());
        setAppreciation(entityT.appreciation());
        setDecimale(entityT.decimale());
        setModifT(entityT.modifT());
        setNc(entityT.nc());
        setNom(entityT.nom());
        setTotal(entityT.total());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const TypeControle & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_appreciation == entityT.appreciation())
                 &&(m_decimale == entityT.decimale())
                 &&(m_modifT == entityT.modifT())
                 &&(m_nc == entityT.nc())
                 &&(m_nom == entityT.nom())
                 &&(m_total == entityT.total());
     }

     INCLUCE_METHODE(TypeControle)
protected:
    /*void setBool1(bool bb)                      {setAppreciation(bb);}
    void setInt1(int kk)                        {setDecimale(kk);}
    void setBool2(bool bb)                      {setModifT(bb);}
    void setString1(const QString & string)     {setNc(string);}
    void setString2(const QString & string)     {setNom(string);}
    void setInt2(int kk)                        {setTotal(kk);}

    bool valueBool1() const                     {return m_appreciation;}
    int valueInt1() const                       {return m_decimale;}
    bool valueBool2() const                     {return m_modifT;}
    const QString & valueString1() const        {return m_nc;}
    const QString & valueString2() const        {return m_nom;}
    int valueInt2() const                       {return m_total;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const TypeControle & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((TypeControle*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // TYPECONTROLE_H
