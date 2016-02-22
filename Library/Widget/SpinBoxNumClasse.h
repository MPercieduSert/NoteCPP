#ifndef SPINBOXNUMCLASSE_H
#define SPINBOXNUMCLASSE_H

#include <QAbstractSpinBox>
#include <QLineEdit>
#include <QList>
#include "../Entities/Niveau.h"

class SpinBoxNumClasse : public QAbstractSpinBox
{
    Q_OBJECT
protected:
    Niveau::affiche_alpha m_alpha;
    QList<int> m_liste;
    int m_value;

public:
    explicit SpinBoxNumClasse(const QList<int> &liste, Niveau::affiche_alpha alpha, QWidget *parent = 0);
    void setListe(const QList<int> &liste);
    void stepBy(int steps);
    int value() const         {return m_value;}


protected:
    QAbstractSpinBox::StepEnabled stepEnabled() const;

signals:

public slots:
    void printValue();
};

#endif // SPINBOXNUMCLASSE_H
