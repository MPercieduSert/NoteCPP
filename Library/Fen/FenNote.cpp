#include "FenNote.h"
#include "FenPrincipale.h"

FenNote::FenNote(Bdd &bdd, FenPrincipale *parent) : Fen(parent), m_bdd(bdd)
{
    /* //Overture de la base de donnée
    FenFoundFile fen(&m_bdd,parent);
    QMap<QString,QString> atts;
    atts.insert("name","main");
    atts.insert("default","yes");
    fen.openInConf("conf/files/databases/database",atts);*/
}
