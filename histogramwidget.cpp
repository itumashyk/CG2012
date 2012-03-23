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
<<<<<<< HEAD
    maxChanel = 0;
=======
>>>>>>> c5b5148581fd6d72f20037cc03ec77b6b58dc003
    for (int i = 0; i < 256; i++)
    {
        data[i] = static_cast<double> (intData[i]) / sum;
        if (data[i] > max)
        {
            max  = data[i];
<<<<<<< HEAD
            maxChanel = i;
=======
>>>>>>> c5b5148581fd6d72f20037cc03ec77b6b58dc003
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
<<<<<<< HEAD

#    ifdef TUMASHYK
     QPen pen(Qt::blue);
#    else
     QPen pen (Qt::red);
#    endif
     pen.setWidth(2);
     painter.setPen(pen);
=======
     painter.setPen(Qt::blue);
     //painter.setFont(QFont("Arial", 30));
     //painter.drawText(rect(), Qt::AlignCenter, "Qt");
>>>>>>> c5b5148581fd6d72f20037cc03ec77b6b58dc003
     if (data.size() > 0)
     {
         int h = rect().height() - 10;
         int per1 = (int)std::floor((double) rect().width() / 256);
<<<<<<< HEAD
         int dx = (rect().width() - per1 * 256) / 2;
=======
>>>>>>> c5b5148581fd6d72f20037cc03ec77b6b58dc003
         for(int i = 0; i < 256; i++)
         {
            int x1 = per1 * i;
            int x2 = x1 + per1;
            int y = h - (int)(h * data[i]) + 5;
<<<<<<< HEAD
            painter.drawLine(x1 + dx, y, x2 + dx, y);
         }
     }

     painter.setPen(Qt::black);
     painter.drawText(5, 10, "max = " + QString::number(maxChanel));
=======
            painter.drawLine(x1, y, x2, y);
         }
     }
>>>>>>> c5b5148581fd6d72f20037cc03ec77b6b58dc003
 }
