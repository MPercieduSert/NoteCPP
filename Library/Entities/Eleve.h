#ifndef ELEVE_H
#define ELEVE_H

#include "Entity.h"

class Eleve : public Entity
{
public:
    static const entityId IdEntity = EleveId;
    static const int NbrValue = 6;
protected:
    int m_classe;
    bool m_fille;
    QDate m_naissance;
    QString m_nom;
    QString m_prenom;
    QDate m_abandon;

public:
    enum position{ClassePos = 0,
                  FillePos = 1,
                  NaissancePos = 2,
                  NomPos = 3,
                  PrenomPos = 4,
                  AbandonPos = 5};

    Eleve() {}
    Eleve(int id) : Entity(id)  {}
    Eleve(int classe, bool fille, const QDate & naissance, const QString &nom, const QString &prenom, int id = 0, const QDate &abandon = QDate()) : Entity(id)
    {
        setClasse(classe);
        setFille(fille);
        setNaissance(naissance);
        setNom(nom);
        setPrenom(prenom);
        setAbandon(abandon);
    }
    Eleve(const Entity & entity) : Entity(entity.id())
    {
        const Eleve & entityT = convert(entity);
        setClasse(entityT.classe());
        setFille(entityT.fille());
        setNaissance(entityT.naissance());
        setNom(entityT.nom());
        setPrenom(entityT.prenom());
        setAbandon(entityT.abandon());
    }
    ~Eleve()    {}
    const QDate & abandon() const                   {return m_abandon;}
    int classe() const                              {return m_classe;}
    QChar afficheFille() const                      {return m_fille ? QChar('F'): QChar('M');}
    bool fille() const                              {return m_fille;}
     //entityId idEntity() const               {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (m_classe > 0) && (!m_nom.isEmpty()) && (!m_prenom.isEmpty());
    }
    const QDate & naissance() const                 {return m_naissance;}
    const QString & nom() const                     {return m_nom;}
    const QString & prenom() const                  {return m_prenom;}
    void setAbandon(const QDate & abandon)          {m_abandon = abandon;}
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
    void setFille(bool fille)                        {m_fille = fille;}
    void setNaissance(const QDate & naissance)
    {
        if(naissance.isValid())
        {
            m_naissance = naissance;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,NaissancePos));
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
    void setPrenom(const QString &prenom)
    {
        if(!prenom.isEmpty())
        {
            m_prenom = prenom;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,PrenomPos));
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

        case FillePos:
            setFille(val.toBool());
            break;

        case NomPos:
            setNom(val.toString());
            break;

        case PrenomPos:
            setPrenom(val.toString());
            break;

        case AbandonPos:
            setAbandon(val.toDate());
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

        case ClassePos:
            return QVariant(classe());
            break;

        case FillePos:
            return QVariant(fille());
            break;

        case NomPos:
            return QVariant(nom());
            break;

        case PrenomPos:
            return QVariant(prenom());
            break;

        case AbandonPos:
            return QVariant(abandon());
            break;

        default:
            return QVariant();
        }
    }
     void operator << (const Entity & entity)
    {
        const Eleve & entityT = convert(entity);
        setId(entity.id());
        setClasse(entityT.classe());
        setFille(entityT.fille());
        setNaissance(entityT.naissance());
        setNom(entityT.nom());
        setPrenom(entityT.prenom());
        setAbandon(entityT.abandon());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Eleve & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_classe == entityT.classe())
                 &&(m_fille == entityT.fille())
                 &&(m_naissance == entityT.naissance())
                 &&(m_nom == entityT.nom())
                 &&(m_prenom == entityT.prenom())
                 &&(m_abandon == entityT.abandon());
     }

     INCLUCE_METHODE(Eleve)
protected:
    /*void setInt1(int kk)                                {setClasse(kk);}
    void setBool1(bool bb)                              {setFille(bb);}
    void setDate1(const QDate &  date)                  {setNaissance(date);}
    void setString1(const QString & string)             {setNom(string);}
    void setString2(const QString & string)             {setPrenom(string);}
    void setDate2(const QDate &  date)                  {setAbandon(date);}

    int valueInt1() const                               {return m_classe;}
    bool valueBool1() const                             {return m_fille;}
    const QDate & valueDate1() const                    {return m_naissance;}
    const QString & valueString1() const                {return m_nom;}
    const QString & valueString2() const                {return m_prenom;}
    const QDate & valueDate2() const                    {return m_abandon;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Eleve & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Eleve*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // ELEVE_H
