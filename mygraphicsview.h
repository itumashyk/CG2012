#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QPoint>
#include <QRubberBand>
#include <QMouseEvent>
#include <QRectF>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView();

    MyGraphicsView(QWidget *parent = 0) : QGraphicsView(parent) {
        pressed = false;
        rubberBandShown = false;
    }

    void hideRubberBand();
    bool isRubberBandShown();

    QRectF selectionRect;
protected:
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
private:
    QPoint selectionStart;
    QRubberBand *rubberBand;
    bool rubberBandShown;
    bool pressed;

};

#endif // MYGRAPHICSVIEW_H
