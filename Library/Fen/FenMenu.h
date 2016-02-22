#ifndef FENMENU_H
#define FENMENU_H

#include <QGridLayout>
#include <QPushButton>
#include "Fen.h"

class FenPrincipale;

class FenMenu : public Fen
{
public:
    FenMenu(FenPrincipale *parent = 0);
};

#endif // FENMENU_H
