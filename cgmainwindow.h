#ifndef CGMAINWINDOW_H
#define CGMAINWINDOW_H

#include <QMainWindow>
#include <basefilter.h>
#include "dialoghistogramm.h"

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

    void on_actionGrayscale_activated();


    void on_actionInvert_Colors_activated();

    void on_actionShow_Histogram_activated();

<<<<<<< HEAD
    void on_actionTreshold_activated();

    void on_actionSave_activated();

=======
>>>>>>> c5b5148581fd6d72f20037cc03ec77b6b58dc003
private:
    Ui::CGMainWindow *ui;
    void applyFilter(BaseFilter *filter);
    DialogHistogramm* histogramDialog;
};

#endif // CGMAINWINDOW_H
