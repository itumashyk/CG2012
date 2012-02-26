#ifndef CGMAINWINDOW_H
#define CGMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class CGMainWindow;
}

class CGMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CGMainWindow(QWidget *parent = 0);
    ~CGMainWindow();

private slots:
    void on_actionOpen_activated();

    void on_actionSimple_Filter_activated();

private:
    Ui::CGMainWindow *ui;
};

#endif // CGMAINWINDOW_H
