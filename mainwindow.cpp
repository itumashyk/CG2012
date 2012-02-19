#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPixmap(QPixmap(QString("ussr.png")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPixmap* MainWindow:: pixmap()
{
    return curPixmap;
}

void MainWindow::setPixmap(const QPixmap &pixmap)
{
    curPixmap = const_cast<QPixmap*>(&pixmap);
    ui->mainLabel->setPixmap(pixmap);
}

void MainWindow::on_actionOpen_activated()
{
    QString file = QFileDialog::getOpenFileName(this,
     "Open Image", QString(), "Image Files (*.png *.jpg *.bmp)");

     if (!file.isNull()) {
         setPixmap(QPixmap(file));
     }
}
