#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include <QWidget>

class HistogramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HistogramWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent (QPaintEvent* event);

signals:

public slots:

};

#endif // HISTOGRAMWIDGET_H
