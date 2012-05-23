#include "mdielement.h"
#include "ui_mdielement.h"
#include "QDebug"
#include <QFileDialog>
#include <bitmapfilter.h>
#include <mygraphicsview.h>

MdiElement::MdiElement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiElement)
{
    ui->setupUi(this);
    setPixmap(QPixmap(QString("ussr.png")));
}

MdiElement::~MdiElement()
{
    delete ui;
}

QPixmap MdiElement:: pixmap()
{
    return curPixmap->pixmap();
}

void MdiElement::setPixmap(const QPixmap &pixmap)
{
    curPixmap = new QGraphicsPixmapItem(pixmap);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(curPixmap);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->invalidateScene();
}

void MdiElement::hideRubberBand()
{
    ((MyGraphicsView*) ui->graphicsView)->hideRubberBand();
}

bool MdiElement::isRubberBandVisible()
{
    return ((MyGraphicsView*) ui->graphicsView)->isRubberBandShown();
}

void MdiElement:: wheelEvent(QWheelEvent * event)
{

    if(event->delta() > 0){
    ui->graphicsView->scale(scaleFactor, scaleFactor);
    } else{
    ui->graphicsView->scale(1/scaleFactor, 1/scaleFactor);
    }
    event->accept();
    //event->ignore();
}

QRectF MdiElement::getSelectionRect()
{
    return ((MyGraphicsView*) ui->graphicsView)->selectionRect;
}
