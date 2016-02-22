#ifndef NIVEAU_H
#define NIVEAU_H

#include "Entity.h"

class Niveau : public Entity
{
public:
    static const entityId IdEntity = NiveauId;
    static const int NbrValue = 3;
protected:
    bool m_colle;
    QString m_nom;
    int m_type;

public:
    enum position {CollePos = 0,
                   NomPos = 1,
                   TypePos = 2};

    enum affiche_alpha {Sans = 0,
                        Numeric = 1,
                        AlphabeticMaj = 2,
                        AlphabeticMin = 3};

    Niveau()    {}
    Niveau(int id) : Entity(id) {}
    Niveau(bool colle, const QString & nom, int type, int id = 0) : Entity(id)
    {
        setColle(colle);
        setNom(nom);
        setType(type);
    }
    Niveau(const Entity & entity): Entity(entity.id())
    {
        const Niveau & entityT = convert(entity);
        setColle(entityT.colle());
        setNom(entityT.nom());
        setType(entityT.type());
    }

    ~Niveau()   {}
    bool colle() const                  {return m_colle;}
    //entityId idEntity() const   {return IdEntity;}
    bool isValid() const        {return Entity::isValid() && (!m_nom.isEmpty()) && (m_type >0);}
    int nbrValue() const        {return NbrValue;}
    const QString & nom() const         {return m_nom;}
    int type() const                    {return m_type;}
    void setColle(bool colle)           {m_colle = colle;}
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

        case CollePos:
            setColle(val.toBool());
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
    QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case CollePos:
            return QVariant(colle());
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
        const Niveau & entityT = convert(entity);
        setId(entity.id());
        setColle(entityT.colle());
        setNom(entityT.nom());
        setType(entityT.type());
        // return *this;
    }
    bool operator == (const Entity & entity) const
    {
        const Niveau & entityT = convert(entity);
        return (m_id == entity.id())
                &&(m_colle == entityT.colle())
                &&(m_nom == entityT.nom())
                &&(m_type == entityT.type());
    }

    INCLUCE_METHODE(Niveau)
    protected:
        /*void setBool1(bool bb)                  {setColle(bb);}
        void setString1(const QString & string) {setNom(string);}
        void setInt1(int kk)                    {setType(kk);}

        bool valueBool1() const                 {return m_colle;}
        const QString & valueString1() const    {return m_nom;}
        int valueInt1() const                   {return m_type;}*/
        /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
        const Niveau & verif(const Entity & entity) const
        {
            if(verifEntity(entity))
            {
                return *((Niveau*) &entity);
            }
            else
            {
                throw std::runtime_error("Mauvaise correspondance des Entity");
            }
        }*/
};

#endif // NIVEAU_H
