#ifndef SPINBOXANNEE_H
#define SPINBOXANNEE_H

#include <QAbstractSpinBox>
#include <QDate>
#include <QLineEdit>

class SpinBoxAnnee : public QAbstractSpinBox
{
    Q_OBJECT
protected:
    int m_value;

public:
    SpinBoxAnnee(int value = QDate::currentDate().year(), QWidget *parent = 0);
    int value() const         {return m_value;}
    void stepBy(int steps);

protected:
    QAbstractSpinBox::StepEnabled stepEnabled() const;
public slots:
    void printValue();
};

#endif // SPINBOXANNEE_H
