#ifndef TABMENU_H
#define TABMENU_H

#include <QGridLayout>
#include <QMap>
#include <QPushButton>
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QWidget>
#include "FenPrincipale.h"
#include "TabAbstractModule.h"

class TabMenu : public TabAbstractModule
{
    Q_OBJECT
protected:
    QGridLayout *m_classeLayout;
    QPushButton *m_newClasseButton;
    QSignalMapper *m_classeMapper;
    QMap<int,QPushButton*> m_classeButtonMap;

public:
    explicit TabMenu(Bdd * bdd, TabModule *parent = 0);
    void becomeCurrent() const;
    void refreshClasse();

protected:
    void classeLayout();

signals:

public slots:
    void creerClasse();
};

#endif // TABMENU_H
