#include "mygraphicsview.h"
#include <QRectF>
#include <QPolygonF>

MyGraphicsView::MyGraphicsView()
{
    pressed = false;
}

void MyGraphicsView::mousePressEvent(QMouseEvent * event)
{
    pressed = true;
    selectionStart = event->pos();
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);//new rectangle band
    rubberBand->setGeometry(QRect(selectionStart, QSize()));
    rubberBand->show();
    event->accept();
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent * event)
{
    pressed = false;
    QPolygonF polygon = mapToScene(QRect(selectionStart, event->pos()));
   // int i = polygon.count();
//    rubberBand->hide();
    event->accept();
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent * event)
{
    if (pressed) {
        rubberBand->setGeometry(QRect(selectionStart, event->pos()).normalized());
        event->accept();
    }
}
