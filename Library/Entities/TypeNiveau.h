#ifndef TYPE_NIVEAU_H
#define TYPE_NIVEAU_H

#include "Entity.h"

class TypeNiveau : public Entity
{
public:
    static const entityId IdEntity = TypeNiveauId;
    static const int NbrValue = 1;
protected:
    QString m_nom;

public:
    enum position {NomPos = 0};

    TypeNiveau()    {}
    TypeNiveau(int id) : Entity(id) {}
    TypeNiveau(const QString & nom, int id) : Entity(id)    {setNom(nom);}
    TypeNiveau(const Entity & entity) : Entity(entity.id())
    {
        const TypeNiveau & entityT = convert(entity);
        setNom(entityT.nom());
    }
    ~TypeNiveau()   {}
    //entityId idEntity() const   {return IdEntity;}
    bool isValid() const        {return Entity::isValid() && (!m_nom.isEmpty());}
    int nbrValue() const        {return NbrValue;}
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

        case NomPos:
            return QVariant(nom());
            break;

        default:
            return QVariant();
        }
    }
    void operator << (const Entity & entity)
    {
        const TypeNiveau & entityT = convert(entity);
        setId(entity.id());
        setNom(entityT.nom());
    }
    bool operator == (const Entity & entity) const
    {
        const TypeNiveau & entityT = convert(entity);
        return (m_id == entity.id())
                &&(m_nom == entityT.nom());
    }

    INCLUCE_METHODE(TypeNiveau)
protected:
    /*void setString1(const QString & string) {setNom(string);}

    const QString & valueString1() const    {return m_nom;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const TypeNiveau & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((TypeNiveau*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // TYPE_NIVEAU_H
