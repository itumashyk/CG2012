#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "basefilter.h"

class GrayscaleFilter : public BaseFilter
{
public:
    virtual QImage process(QImage& image);
private:
    int getEverage(QImage &image, int x, int y);
};

#endif // GRAYSCALEFILTER_H
