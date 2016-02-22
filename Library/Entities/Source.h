#ifndef SOURCE_H
#define SOURCE_H

#include "Entity.h"

class Source : public Entity
{
public:
    static const entityId IdEntity = SourceId;
    static const int NbrValue = 2;

protected:
    QString m_nom;
    int m_type;

public:
    enum position {NomPos = 0,
                  TypePos = 1};

    Source()    {}
    Source(int id) : Entity(id) {}
    Source(const QString & nom, int type, int id) : Entity(id)
    {
        setNom(nom);
        setType(type);
    }
    Source(const Entity & entity) : Entity(entity.id())
    {
        const Source & entityT = convert(entity);
        setNom(entityT.nom());
        setType(entityT.type());
    }
    ~Source()   {}
     //entityId idEntity() const                   {return IdEntity;}
     bool isValid() const        {return Entity::isValid() && (!m_nom.isEmpty()) && (m_type >= 0);}
     int nbrValue() const                        {return NbrValue;}
    const QString & nom() const         {return m_nom;}
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
    void setType(int type)
    {
        if(type >= 0)
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

        case NomPos:
            setNom(val.toString());
            break;

        case TypePos:
            setType(val.toInt());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int type() const                    {return m_type;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case NomPos:
            return QVariant(nom());
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
        const Source & entityT = convert(entity);
        setId(entity.id());
        setNom(entityT.nom());
        setType(entityT.type());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Source & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_nom == entityT.nom())
                 &&(m_type == entityT.type());
     }

     INCLUCE_METHODE(Source)
protected:
    /*void setString1(const QString & string)     {setNom(string);}
    void setInt1(int kk)                        {setType(kk);}

    const QString & valueString1() const        {return m_nom;}
    int valueInt1() const                       {return m_type;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Source & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Source*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // SOURCE_H
