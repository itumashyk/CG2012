#include "invertfilter.h"
#include <QDebug>

QImage InvertFilter:: process(QImage& image)
 {

    int height = image.height();
    int width = image.width();
    QImage res(image.size(), QImage::Format_ARGB32);
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
             res.setPixel(i, j, invert(image, i, j));
        }
    }

    return res;
 }

uint InvertFilter::invert(QImage &image, int x, int y)
{
    QRgb color = image.pixel(x, y);
    int blue = 255 - (color & 0x000000FF);
    int green = 255 - ((color & 0x0000FF00) >> 8);
    int red = 255 - ((color & 0x00FF0000) >> 16);

    uint res = (color & 0xFF000000) + (red << 16) + (green << 8) + blue;

    return res;
}

