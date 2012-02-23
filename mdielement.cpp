#include "mdielement.h"
#include "ui_mdielement.h"
#include "QDebug"
#include <QFileDialog>
#include <bitmapfilter.h>

MdiElement::MdiElement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiElement)
{
    ui->setupUi(this);
    setPixmap(QPixmap(QString("ussr.png")));
    scale = 1.0;
    ZOOM_RATIO = 2.0;
}

MdiElement::~MdiElement()
{
    delete ui;
}

QGraphicsPixmapItem* MdiElement:: pixmap()
{
    return curPixmap;
}

void MdiElement::setPixmap(const QPixmap &pixmap)
{
    curPixmap = new QGraphicsPixmapItem(pixmap);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(curPixmap);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->invalidateScene();
}


void MdiElement::on_zoomIn_clicked()
{
    scale *= ZOOM_RATIO;
    curPixmap->setScale(scale);
}

void MdiElement::on_zoomOut_clicked()
{
    scale /= ZOOM_RATIO;
    if (scale < 1.0)
    {
        scale = 1.0;
    }
    curPixmap->setScale(scale);
    ui->graphicsView->invalidateScene();
}

