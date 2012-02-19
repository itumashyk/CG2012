#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPixmap* pixmap();
    void setPixmap(const QPixmap &pixmap);

private slots:
    void on_actionOpen_activated();

private:
    Ui::MainWindow *ui;
    QPixmap *curPixmap;
};

#endif // MAINWINDOW_H
