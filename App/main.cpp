
#include "../Library/Fen/FenPrincipale.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenPrincipale w(QDir::homePath()+"/notecpp");
    w.show();

    return a.exec();
}
