#ifndef MDIELEMENT_H
#define MDIELEMENT_H

#include <QMdiSubWindow>
#include <QGraphicsPixmapItem>

namespace Ui {
    class MdiElement;
}

class MdiElement : public QWidget
{
    Q_OBJECT

public:
    explicit MdiElement(QWidget *parent = 0);
    ~MdiElement();

    QPixmap pixmap();
    void setPixmap(const QPixmap &pixmap);

protected:
    virtual void wheelEvent(QWheelEvent * event);

private:
    QGraphicsPixmapItem *curPixmap;
    static const qreal scaleFactor = 0.8;

private:
    Ui::MdiElement *ui;
};

#endif // MDIELEMENT_H
