#include "histogramwidget.h"
#include <QPainter>
#include "dialoghistogramm.h"
#include <QDebug>
#include <cmath>

HistogramWidget::HistogramWidget(QWidget *parent) :
    QWidget(parent)
{



}

void HistogramWidget:: loadData(QVector<int> intData)
{
    int sum = 0;
    for (int i = 0; i < 256; i++)
    {
        sum += intData[i];
    }
    data = QVector<double>(256);
    double max = 0.0;
    maxChanel = 0;
    for (int i = 0; i < 256; i++)
    {
        data[i] = static_cast<double> (intData[i]) / sum;
        if (data[i] > max)
        {
            max  = data[i];
            maxChanel = i;
        }
    }

    scaleFactor = 1.0 / max;

    for (int i = 0; i < 256; i++)
    {
        data[i] *= scaleFactor;
    }
}

void  HistogramWidget::paintEvent (QPaintEvent* event)
 {
     QPainter painter(this);

#    ifdef TUMASHYK
     QPen pen(Qt::blue);
     QBrush brush(Qt::blue);
#    else
     QPen pen (Qt::red);
     QBrush brush(Qt::red);
#    endif
     pen.setWidth(2);
     painter.setPen(pen);
     if (data.size() > 0)
     {
         int h = rect().height() - 10;
         int per1 = (int)std::floor((double) rect().width() / 256);
         int dx = (rect().width() - per1 * 256) / 2;
         for(int i = 0; i < 256; i++)
         {
            int x1 = per1 * i;

            //TODO: Unused variable.
            //int x2 = x1 + per1;
            int y = h - (int)(h * data[i]) + 5;
            painter.fillRect(x1 + dx, y, per1, (h * data[i]), brush);
         }
     }

     painter.setPen(Qt::black);
     painter.drawText(5, 10, "max = " + QString::number(maxChanel));
 }
