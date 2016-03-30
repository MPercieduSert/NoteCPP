#ifndef SPINBOXNUMCLASSE_H
#define SPINBOXNUMCLASSE_H

#include <QAbstractSpinBox>
#include <QLineEdit>
#include <QList>
#include "../Entities/Classe.h"

class SpinBoxNumClasse : public QAbstractSpinBox
{
    Q_OBJECT
protected:
    Classe::affichage m_alpha;
    QList<int> m_liste;
    int m_value;

public:
    explicit SpinBoxNumClasse(const QList<int> &liste, Classe::affichage alpha, QWidget *parent = 0);
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
