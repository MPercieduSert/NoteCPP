#include "FenMenu.h"
#include "FenPrincipale.h"


FenMenu::FenMenu(FenPrincipale *parent) : Fen(parent)
{
    QGridLayout * lt = new QGridLayout(this);
    QPushButton * buttonNote = new QPushButton("Notes");
    QPushButton * buttonExo = new QPushButton("Exercices");
    lt->addWidget(buttonNote,0,0);
    lt->addWidget(buttonExo,0,1);

    //connect(buttonNote,&QPushButton::clicked,parent,&FenPrincipale::execNote);
    //connect(buttonExo,&QPushButton::clicked,parent,&FenPrincipale::execExo);
}

