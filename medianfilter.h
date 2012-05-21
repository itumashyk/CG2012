#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include "basefilter.h"

class MedianFilter : public BaseFilter
{
public:
    MedianFilter();
    MedianFilter(int aSize);
    virtual QImage process(QImage& image);
    int getMedianPixel(QImage & image, int x, int y);

private:
    int size;
    int mirror(int max, int cur);
};

#endif // MEDIANFILTER_H
