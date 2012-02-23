#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>
#include <bitmapfilter.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPixmap(QPixmap(QString("ussr.png")));
    scale = 1.0;
    ZOOM_RATIO = 2.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QGraphicsPixmapItem* MainWindow:: pixmap()
{
    return curPixmap;
}

void MainWindow::setPixmap(const QPixmap &pixmap)
{
    curPixmap = new QGraphicsPixmapItem(pixmap);
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(curPixmap);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->invalidateScene();
}

void MainWindow::on_actionOpen_activated()
{
    QString file = QFileDialog::getOpenFileName(this,
     "Open Image", QString(), "Image Files (*.png *.jpg *.bmp)");

    QImage image(file);
    BitmapFilter filter;
    QImage result = filter.process(image);

     if (!file.isNull()) {
         QPixmap pixmap = QPixmap::fromImage(result);
         setPixmap(pixmap);
     }
}

void MainWindow::on_zoomIn_clicked()
{
    scale *= ZOOM_RATIO;
    curPixmap->setScale(scale);
}

void MainWindow::on_zoomOut_clicked()
{
    scale /= ZOOM_RATIO;
    if (scale < 1.0)
    {
        scale = 1.0;
    }
    curPixmap->setScale(scale);
    ui->graphicsView->invalidateScene();
}
