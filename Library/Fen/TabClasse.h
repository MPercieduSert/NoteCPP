#ifndef TABCLASSE_H
#define TABCLASSE_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../Entities/Classe.h"
#include "FenPrincipale.h"
#include "TabAbstractClasse.h"
#include "TabAbstractTableau.h"

class TabClasse : public TabAbstractClasse
{
    Q_OBJECT
protected:
    QPushButton * m_listeEleveButton;
    QPushButton * m_listeGroupeButton;
    QHBoxLayout * m_bouttonTabLayout;

public:
    TabClasse(int idClasse, Bdd * bdd, TabModule *parent = 0);
    ~TabClasse() {}
    void becomeCurrent() const;
public slots:
    void openListeEleve();
    void openListeGroupe();
};

#endif // TABCLASSE_H
