#include "scanlinegrayfilter.h"

ScanLineGrayFilter::ScanLineGrayFilter(int aThreshold)
{
    threshold = aThreshold;
}

QImage ScanLineGrayFilter::process(QImage &image)
{
    int height = image.height();
    int width = image.width();
    QImage res(image.size(), QImage::Format_RGB32);

    for(int i = 0; i < width; ++i)
    {
        for(int j = 1; j < height; ++j)
        {
            if ((qGray(image.pixel(i, j - 1)) - qGray(image.pixel(i, j))) > threshold)
            {
                res.setPixel(i, j - 1, qRgb(255, 0, 0));
            }
            else if((qGray(image.pixel(i, j - 1)) - qGray(image.pixel(i, j))) < -threshold)
            {
                res.setPixel(i, j, qRgb(255, 0, 0));
            }
        }
    }

    for(int j = 0; j < height; ++j)
    {
        for(int i = 1; i < width; ++i)
        {
            if ((qGray(image.pixel(i - 1, j)) - qGray(image.pixel(i, j))) > threshold)
            {
                res.setPixel(i - 1, j, qRgb(255, 0, 0));
            }
            else if((qGray(image.pixel(i - 1, j)) - qGray(image.pixel(i, j))) < -threshold)
            {
                res.setPixel(i, j, qRgb(255, 0, 0));
            }
        }
    }

    return res;

}
