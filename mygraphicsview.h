#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QPoint>
#include <QRubberBand>
#include <QMouseEvent>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView();
    MyGraphicsView(QWidget *parent = 0) : QGraphicsView(parent) {
        pressed = false;
    } ;

protected:
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
private:
    QPoint selectionStart;
    QRubberBand *rubberBand;
    bool pressed;

};

#endif // MYGRAPHICSVIEW_H
