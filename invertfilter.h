#ifndef INVERTFILTER_H
#define INVERTFILTER_H
#include "basefilter.h"

class InvertFilter : public BaseFilter
{
public:
    virtual QImage process(QImage& image);
private:
    uint invert(QImage & image, int x, int y);
};

#endif // INVERTFILTER_H
