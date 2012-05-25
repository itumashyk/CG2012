#ifndef MASKFILTER_H
#define MASKFILTER_H
#include "basefilter.h"
#include "mask.h"

class MaskFilter : public BaseFilter
{
public:
    MaskFilter();
    MaskFilter(Mask aMask);
    virtual QImage process(QImage& image);
    int getMaskPixel(QImage & image, int x, int y);
    int mirror(int max, int cur);

private:
    Mask mask;

};

#endif // MASKFILTER_H
