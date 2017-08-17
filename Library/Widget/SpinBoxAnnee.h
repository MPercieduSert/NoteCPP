/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/05/2016
 */
#ifndef SPINBOXANNEE_H
#define SPINBOXANNEE_H

#include <QAbstractSpinBox>
#include <QDate>
#include <QLineEdit>

/*! \defgroup groupeWidget Widgets
 * \brief Ensemble de widgets spécialisés.
 */

/*! \ingroup groupeWidget
 * \brief Spin Box pour les années scolaires.
 */
class SpinBoxAnnee : public QAbstractSpinBox
{
    Q_OBJECT
protected:
    int m_value;    //! Valeur courante

public:
    //! Constructeur.
    SpinBoxAnnee(int value = QDate::currentDate().year(), QWidget *parent = 0);

    //! Retourne la valeur selectionnée.
    int value() const         {return m_value;}

    //! incrémente de steps fois la valeur.
    void stepBy(int steps);

protected:
    QAbstractSpinBox::StepEnabled stepEnabled() const;
public slots:
    //! Affiche la valeur.
    void printValue();
};

#endif // SPINBOXANNEE_H
