#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "Entity.h"

class Attribut : public Entity
{

public:
    static const entityId IdEntity = AttributId;
    static const int NbrValue = 6;
protected:
    bool m_feuille;
    int m_niveau;
    QString m_nom;
    int m_num;
    int m_pere;
    QString m_nc;

public:
    enum position{FeuillePos = 0,
                  NiveauPos = 1,
                  NomPos = 2,
                  NumPos = 3,
                  PerePos = 4,
                  NcPos = 5};

    Attribut() {}
    Attribut(int id) : Entity(id)   {}
    Attribut(bool feuille, int niveau, const QString & nom, int num, int pere, int id = 0, const QString & nc = QString()): Entity(id)
    {
        setFeuille(feuille);
        setNc(nc);
        setNiveau(niveau);
        setNom(nom);
        setNum(num);
        setPere(pere);
    }
    Attribut(const Entity & entity): Entity(entity.id())
    {
        const Attribut & entityT = convert(entity);
        setFeuille(entityT.feuille());
        setNc(entityT.nc());
        setNiveau(entityT.niveau());
        setNom(entityT.nom());
        setNum(entityT.num());
        setPere(entityT.pere());
    }
    ~Attribut() {}
    bool feuille() const                    {return m_feuille;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const            {return Entity::isValid() && (!m_nom.isEmpty()) && (m_niveau >= 0) && (m_pere >= 0);}
     int nbrValue() const            {return NbrValue;}
    const QString & nc() const              {return m_nc;}
    int niveau() const                      {return m_niveau;}
    const QString & nom() const             {return m_nom;}
    int num() const                         {return m_num;}
    int pere() const                        {return m_pere;}
    void setFeuille(bool feuille)           {m_feuille = feuille;}
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
    void setNiveau(int niveau)
    {
        if(niveau >= 0)
        {
            m_niveau = niveau;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NiveauPos));
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
    void setNum(int num)
    {
        if(num >= 0)
        {
            m_num = num;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NumPos));
        }
    }
    void setPere(int pere)
    {
        if(pere >= 0)
        {
            m_pere = pere;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,PerePos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case FeuillePos:
            setFeuille(val.toBool());
            break;

        case NiveauPos:
            setNiveau(val.toInt());
            break;

        case NomPos:
            setNom(val.toString());
            break;

        case NumPos:
            setNum(val.toInt());
            break;

        case PerePos:
            setPere(val.toInt());
            break;

        case NcPos:
            setNc(val.toString());
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

        case FeuillePos:
            return QVariant(feuille());
            break;

        case NiveauPos:
            return QVariant(niveau());
            break;

        case NomPos:
            return QVariant(nom());
            break;

        case NumPos:
            return QVariant(num());
            break;

        case PerePos:
            return QVariant(pere());
            break;

        case NcPos:
            return QVariant(nc());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Attribut & entityT = convert(entity);
        setId(entity.id());
        setFeuille(entityT.feuille());
        setNc(entityT.nc());
        setNiveau(entityT.niveau());
        setNom(entityT.nom());
        setNum(entityT.num());
        setPere(entityT.pere());
        //return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Attribut & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_feuille == entityT.feuille())
                 &&(m_nc == entityT.nc())
                 &&(m_niveau == entityT.niveau())
                 &&(m_nom == entityT.nom())
                 &&(m_num == entityT.num())
                 &&(m_pere == entityT.pere());
     }
    INCLUCE_METHODE(Attribut)
     /*const Attribut & verif(const Entity & entity) const
     {
         if(verifEntity(entity))
         {
             return *((Attribut*) &entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
     const Attribut & verif(Entity * entity) const
     {
         if(verifEntity(*entity))
         {
             return (Attribut*) entity);
         }
         else
         {
             throw std::runtime_error("Mauvaise correspondance des Entity");
         }
     }
    bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
protected:
    /*void setBool1(bool bb)                      {setFeuille(bb);}
    void setString1(const QString & string)     {setNc(string);}
    void setInt1(int kk)                        {setNiveau(kk);}
    void setString2(const QString & string)     {setNom(string);}
    void setInt2(int kk)                        {setNum(kk);}
    void setInt3(int kk)                        {setPere(kk);}

    bool valueBool1() const                     {return m_feuille;}
    const QString & valueString1() const        {return m_nc;}
    int valueInt1() const                       {return m_niveau;}
    const QString & valueString2() const        {return m_nom;}
    int valueInt2() const                       {return m_num;}
    int valueInt3() const                       {return m_pere;}*/
};

#endif // ATTRIBUT_H
