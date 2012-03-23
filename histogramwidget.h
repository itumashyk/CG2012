#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include <QWidget>

class HistogramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HistogramWidget(QWidget *parent = 0);

    void loadData(QVector<int> data);

protected:
    virtual void paintEvent (QPaintEvent* event);

signals:

public slots:

private:
    QVector<double> data;
    double scaleFactor;
    int maxChanel;


};

#endif // HISTOGRAMWIDGET_H
