#include "HeaderView.h"

void HeaderView::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
        emit mouseClikedRight(logicalIndexAt(e->pos()));
    QHeaderView::mousePressEvent(e);
}
