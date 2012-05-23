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

    void on_actionTreshold_activated();

    void on_actionSave_activated();

    void on_actionAverage_Filter_activated();

    void on_actionAverage_Filter_with_size_activated();

    void on_actionMedian_Filter_activated();

    void on_actionMedian_Filter_with_size_activated();
    void on_actionAutomatic_Treshold_activated();

    void on_actionHistogramm_segmentation_activated();

    void on_actionReduce_color_count_activated();

private:
    Ui::CGMainWindow *ui;
    void applyFilter(BaseFilter *filter);
    DialogHistogramm* histogramDialog;
};

#endif // CGMAINWINDOW_H
