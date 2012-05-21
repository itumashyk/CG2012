#include "tresholdfilter.h"

TresholdFilter::TresholdFilter(int treshold)
{
    this->treshold = treshold;
}

QImage TresholdFilter:: process(QImage& image)
{
    int height = image.height();
    int width = image.width();
    QImage res(image.size(), QImage::Format_Mono);
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
             res.setPixel(i, j,
                qBlue(image.pixel(i, j)) > treshold ?
                1 : 0);
        }
    }

    return res;
}
