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
    rubberBandShown = true;
    event->accept();
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent * event)
{
    pressed = false;
    QPolygonF polygon = mapToScene(QRect(selectionStart, event->pos()));
    selectionRect = polygon.boundingRect();
    event->accept();
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent * event)
{
    if (pressed) {
        rubberBand->setGeometry(QRect(selectionStart, event->pos()).normalized());
        event->accept();
    }
}

void MyGraphicsView::hideRubberBand()
{
    rubberBand->hide();
    rubberBandShown = false;
}

bool MyGraphicsView::isRubberBandShown()
{
    return rubberBandShown;
}
