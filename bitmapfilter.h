#ifndef BITMAPFILTER_H
#define BITMAPFILTER_H

#include <basefilter.h>
#include <QtGui>

class BitmapFilter : public BaseFilter
{
public:
    BitmapFilter();
    virtual QImage process(QImage& image);
    int getBestPixel(QImage & image, int x, int y);
};

#endif // BITMAPFILTER_H
