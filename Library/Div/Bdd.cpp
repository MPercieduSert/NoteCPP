#include "Bdd.h"

QString Bdd::afficheClasse(const Classe & classe, Classe::affichage /*alpha*/)
{
    Niveau niveau(classe.idNiv());
    get(niveau);
    QString string(niveau.nom());
    /*if(classe.num() != 0)
    {
        switch (alpha)
        {
        case Classe::Sans:
            break;
        case Classe::Numeric:
            string.append(QString::number(classe.num()));
            break;
        case Classe::AlphabeticMaj:
            if(0 < classe.num() && classe.num() < 27)
            {
                string.append(QString("ABCDEFGHIJKLMOPQRSTUVWXYZ").at(classe.num()-1));
            }
            break;
        case Classe::AlphabeticMin:
            if(0 < classe.num() && classe.num() < 27)
            {
                string.append(QString("abcdefghijklmopqrstuvwxyz").at(classe.num()-1));
            }
            break;
        }
    }*/
    return string;
}
