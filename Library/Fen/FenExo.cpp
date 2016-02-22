#include "FenExo.h"
#include "FenPrincipale.h"

FenExo::FenExo(FenPrincipale *parent) : Fen(parent)
{
    bool bb=true;
    int n = 10;
    QDate d(2015,4,15);
    QVariant Q(d);
    QMessageBox::critical(this,"aaa",Q.toString());
}

