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

    QGraphicsPixmapItem* pixmap();
    void setPixmap(const QPixmap &pixmap);

private slots:

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

private:
    QGraphicsPixmapItem *curPixmap;
    qreal scale;
    qreal ZOOM_RATIO;

private:
    Ui::MdiElement *ui;
};

#endif // MDIELEMENT_H
