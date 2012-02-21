#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGraphicsPixmapItem* pixmap();
    void setPixmap(const QPixmap &pixmap);

private slots:
    void on_actionOpen_activated();

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsPixmapItem *curPixmap;
    qreal scale;
    qreal ZOOM_RATIO;
};

#endif // MAINWINDOW_H
