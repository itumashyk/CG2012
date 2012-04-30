#include "medianfilter.h"
#include <QVector>
#include <QtAlgorithms>
#include <stdexcept>
MedianFilter::MedianFilter()
{
}

MedianFilter::MedianFilter(int aSize)
{
    size = aSize;
}

QImage MedianFilter::process(QImage& image)
{
    int height = image.height();
    int width = image.width();
    QImage res(image.size(), QImage::Format_ARGB32);
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
             res.setPixel(i, j, getMedianPixel(image, i, j));
        }
    }

    return res;
}

int MedianFilter::getMedianPixel(QImage &image, int x, int y)
{
    QVector<int> neighboors;
    int delta = size / 2;
    for (int dx = - delta; dx <= delta; ++dx)
    {
        for (int dy = delta; dy >= -delta; --dy)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < image.width() && ny >=0 && ny < image.height())
            {
                neighboors.push_back(qGray(image.pixel(nx, ny)));
            }
            else
            {
                neighboors.push_back(qGray(image.pixel(mirror(image.width(), nx), mirror(image.height(), ny))));
            }
        }
    }

    qSort(neighboors);
    int gray = neighboors[neighboors.size() / 2];
    return qRgb(gray, gray, gray);

}

int MedianFilter::mirror(int max, int cur)
{
    if (cur < 0)
    {
        return -cur;
    }
    else if (cur > max - 1)
    {
        return max - (cur - max + 1);
    }

    //TODO: No return statment.
    throw std::logic_error(
        "No return statment in MedianFilter::mirror");

    return 0;
}


