#ifndef FENNOTE_H
#define FENNOTE_H

#include <QLabel>
#include <QMap>
#include <QSqlDatabase>
#include <QString>
#include "Fen.h"
#include "../Div/Bdd.h"
#include "../Entities/Annee.h"

class FenPrincipale;

class FenNote : public Fen
{
protected :
    Bdd  & m_bdd;
public:
    FenNote(Bdd & bdd,FenPrincipale *parent = 0);

};

#endif // FENNOTE_H
