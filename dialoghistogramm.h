#ifndef DIALOGHISTOGRAMM_H
#define DIALOGHISTOGRAMM_H

#include <QDialog>

namespace Ui {
    class DialogHistogramm;
}

class DialogHistogramm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHistogramm(QWidget *parent = 0);
    ~DialogHistogramm();

private:
    Ui::DialogHistogramm *ui;
};

#endif // DIALOGHISTOGRAMM_H
