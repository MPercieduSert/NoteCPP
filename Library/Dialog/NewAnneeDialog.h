#ifndef NEWANNEEDIALOG_H
#define NEWANNEEDIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "../Widget/SpinBoxAnnee.h"

class NewAnneeDialog : public QDialog
{
    Q_OBJECT
protected:
    QLabel *m_label;
    QPushButton *m_creerBouton;
    QPushButton *m_cancelBouton;
    SpinBoxAnnee *m_box;
    QCheckBox *m_check;
    QVBoxLayout *m_vLayout;
    QHBoxLayout *m_hLayout;

public:
    NewAnneeDialog(QWidget *parent = 0);
    bool isChecked() const;

public slots:
    void accept();
};

#endif // NEWANNEEDIALOG_H
