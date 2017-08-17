/*Auteur: PERCIE DU SERT Maxime
 *Date: 20/03/2017
 */
#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QHeaderView>
#include <QMouseEvent>

class HeaderView : public QHeaderView
{
    Q_OBJECT
public:
    using QHeaderView::QHeaderView;

    //! Réimplémentation de l'evenement cliquer sur l'entête.
    void mousePressEvent(QMouseEvent *e);

signals:
    void mouseClikedRight(int section);
};

#endif // HEADERVIEW_H
