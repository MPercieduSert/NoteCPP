#ifndef EXERCICE_H
#define EXERCICE_H

#include "Entity.h"

class Exercice : public Entity
{
public:
    static const entityId IdEntity = ExerciceId;
    static const int NbrValue = 9;
protected:
    QString m_enonce;
    bool m_feuille;
    int m_niveau;
    int m_num;
    int m_pere;
    int m_version;
    QString m_correction;
    int m_source;
    QString m_titre;

public:
    enum position{EnoncePos = 0,
                  FeuillePos = 1,
                  NiveauPos = 2,
                  NumPos = 3,
                  PerePos = 4,
                  VersionPos = 5,
                  CorrectionPos = 6,
                  SourcePos = 7,
                  TitrePos = 8};
    Exercice()  {}
    Exercice(int id) : Entity(id)  {}
    Exercice(const QString & enonce, bool feuille, int niveau, int num, int pere, int version, int id = 0, const QString & correction = QString(), int source = 0, const QString & titre = QString()) : Entity(id)
    {
        setEnonce(enonce);
        setFeuille(feuille);
        setNiveau(niveau);
        setNum(num);
        setPere(pere);
        setVersion(version);
        setCorrection(correction);
        setSource(source);
        setTitre(titre);

    }
    Exercice(const Entity & entity): Entity(entity.id())
    {
        const Exercice & entityT = convert(entity);
        setEnonce(entityT.enonce());
        setFeuille(entityT.feuille());
        setNiveau(entityT.niveau());
        setNum(entityT.num());
        setPere(entityT.pere());
        setVersion(entityT.version());
        setCorrection(entityT.correction());
        setSource(entityT.source());
        setTitre(entityT.titre());
    }
    ~Exercice() {}
    const QString & correction() const      {return m_correction;}
    const QString & enonce() const          {return m_enonce;}
    bool feuille() const                    {return m_feuille;}
     //entityId idEntity() const       {return IdEntity;}
     bool isValid() const
    {
        return Entity::isValid() && (!m_enonce.isEmpty()) && (m_niveau >= 0) && (m_num >= 0) && (m_pere >= 0) && (m_version >= 0);
    }
     int nbrValue() const            {return NbrValue;}
    int niveau() const                      {return m_niveau;}
    int num() const                         {return m_num;}
    int pere() const                        {return m_pere;}
    void setCorrection(const QString & correction)  {m_correction = correction;}
    void setEnonce(const QString & enonce)
    {
        if(!enonce.isEmpty())
        {
            m_enonce = enonce;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,EnoncePos));
        }
    }
    void setFeuille(bool feuille)           {m_feuille = feuille;}
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
    void setSource(int source)
    {
        if(source >= 0)
        {
            m_source = source;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,SourcePos));
        }
    }
    void setTitre(const QString & titre)    {m_titre = titre;}
    void setVersion(int version)
    {
        if(version >= 0)
        {
            m_version = version;
        }
        else
        {
            m_erreurs.append(QPair<int,int>(m_id,VersionPos));
        }
    }
     void setValue(int pos, const QVariant & val)
    {
        switch (pos)
        {
        case IdPos:
            setId(val.toInt());
            break;

        case EnoncePos:
            setEnonce(val.toString());
            break;

        case FeuillePos:
            setFeuille(val.toBool());
            break;

        case NiveauPos:
            setNiveau(val.toInt());
            break;

        case NumPos:
            setNum(val.toInt());
            break;

        case PerePos:
            setPere(val.toInt());
            break;

        case VersionPos:
            setVersion(val.toInt());
            break;

        case CorrectionPos:
            setCorrection(val.toString());
            break;

        case SourcePos:
            setSource(val.toInt());
            break;

        case TitrePos:
            setTitre(val.toString());
            break;

        default:
            m_erreurs.append(QPair<int,int>(m_id,PosPos));
        }
    }
    int source() const                      {return m_source;}
    const QString & titre() const           {return m_titre;}
     QVariant value(int pos) const
    {
        switch (pos)
        {
        case IdPos:
            return QVariant(id());
            break;

        case EnoncePos:
            return QVariant(enonce());
            break;

        case FeuillePos:
            return QVariant(feuille());
            break;

        case NiveauPos:
            return QVariant(niveau());
            break;

        case NumPos:
            return QVariant(num());
            break;

        case PerePos:
            return QVariant(pere());
            break;

        case VersionPos:
            return QVariant(version());
            break;

        case CorrectionPos:
            return QVariant(correction());
            break;

        case SourcePos:
            return QVariant(source());
            break;

        case TitrePos:
            return QVariant(titre());
            break;

        default:
            return QVariant();
        }
    }
    int version() const                     {return m_version;}
     void operator << (const Entity & entity)
    {
        const Exercice & entityT = convert(entity);
        setId(entity.id());
        setEnonce(entityT.enonce());
        setFeuille(entityT.feuille());
        setNiveau(entityT.niveau());
        setNum(entityT.num());
        setPere(entityT.pere());
        setVersion(entityT.version());
        setCorrection(entityT.correction());
        setSource(entityT.source());
        setTitre(entityT.titre());
        // return *this;
    }
     bool operator == (const Entity & entity) const
     {
         const Exercice & entityT = convert(entity);
         return (m_id == entity.id())
                 &&(m_enonce == entityT.enonce())
                 &&(m_feuille == entityT.feuille())
                 &&(m_niveau == entityT.niveau())
                 &&(m_num == entityT.num())
                 &&(m_pere == entityT.pere())
                 &&(m_version == entityT.version())
                 &&(m_correction == entityT.correction())
                 &&(m_source == entityT.source())
                 &&(m_titre == entityT.titre());
     }

     INCLUCE_METHODE(Exercice)
protected:
    /*void setString1(const QString & string)     {setEnonce(string);}
    void setBool1(bool bb)                      {setFeuille(bb);}
    void setInt1(int kk)                        {setNiveau(kk);}
    void setInt2(int kk)                        {setNum(kk);}
    void setInt3(int kk)                        {setPere(kk);}
    void setInt4(int kk)                        {setVersion(kk);}
    void setString2(const QString & string)     {setCorrection(string);}
    void setInt5(int kk)                        {setSource(kk);}
    void setString3(const QString & string)     {setTitre(string);}

    const QString & valueString1() const        {return m_enonce;}
    bool valueBool1() const                     {return m_feuille;}
    int valueInt1() const                       {return m_niveau;}
    int valueInt2() const                       {return m_num;}
    int valueInt3() const                       {return m_pere;}
    int valueInt4() const                       {return m_version;}
    const QString & valueString2() const        {return m_correction;}
    int valueInt5() const                       {return m_source;}
    const QString & valueString3() const        {return m_titre;}*/
    /*bool verifEntity(const Entity & entity) const {return IdEntity == entity.idEntity();}
    const Exercice & verif(const Entity & entity) const
    {
        if(verifEntity(entity))
        {
            return *((Exercice*) &entity);
        }
        else
        {
            throw std::runtime_error("Mauvaise correspondance des Entity");
        }
    }*/
};

#endif // EXERCICE_H
