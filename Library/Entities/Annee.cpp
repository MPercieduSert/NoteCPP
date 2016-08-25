#include "Annee.h"

QString Annee::affiche() const
{
    return an() == 0 ? QString("Sans") : QString::number(an())+"-"+QString::number(an()+1);
}
