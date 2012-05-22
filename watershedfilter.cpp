#include "watershedfilter.h"
#include "bzh_classes/segment.h"

WatershedFilter::WatershedFilter(int treshold)
{
    this->treshold = treshold;
}

QImage WatershedFilter:: process(QImage &image)
{
    segment seg(image, 8, treshold);
    return seg.doSegment();
}
