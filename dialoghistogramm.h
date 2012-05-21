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

    QVector<int> data();
    void show(QVector<int> data);

private:
    Ui::DialogHistogramm *ui;
    QVector<int> theData;
};

#endif // DIALOGHISTOGRAMM_H
