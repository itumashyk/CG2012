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
    for (int i = 0; i < 256; i++)
    {
        data[i] = static_cast<double> (intData[i]) / sum;
        if (data[i] > max)
        {
            max  = data[i];
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
     painter.setPen(Qt::blue);
     //painter.setFont(QFont("Arial", 30));
     //painter.drawText(rect(), Qt::AlignCenter, "Qt");
     if (data.size() > 0)
     {
         int h = rect().height() - 10;
         int per1 = (int)std::floor((double) rect().width() / 256);
         for(int i = 0; i < 256; i++)
         {
            int x1 = per1 * i;
            int x2 = x1 + per1;
            int y = h - (int)(h * data[i]) + 5;
            painter.drawLine(x1, y, x2, y);
         }
     }
 }
