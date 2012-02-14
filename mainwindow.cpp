#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
//    QString fileName("ussr.png");
//    QGraphicsScene scene;
//    scene.addPixmap(QPixmap(fileName));
//    delete ui->graphicsView;
//    ui->graphicsView = new QGraphicsView(&scene);
//    //QGraphicsPixmapItem item (pixmap);
//    //scene.addItem(&item);


//    qDebug() << ui->graphicsView->items().count();
//    ui->graphicsView->show();


    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsPixmapItem item(QPixmap("ussr.png"));
    scene.addItem(&item);
    view.show();

//   QGraphicsScene scene; scene.addPixmap(QPixmap(fileName)); QGraphicsView view(&scene); view.show()
}

MainWindow::~MainWindow()
{
    delete ui;
}
