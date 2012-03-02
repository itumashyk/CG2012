#include "histogramwidget.h"
#include <QPainter>

HistogramWidget::HistogramWidget(QWidget *parent) :
    QWidget(parent)
{
}

void HistogramWidget:: paintEvent (QPaintEvent* event)
 {
     QPainter painter(this);
     painter.setPen(Qt::blue);
     painter.setFont(QFont("Arial", 30));
     painter.drawText(rect(), Qt::AlignCenter, "Qt");
 }
