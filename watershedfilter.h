#ifndef WATERSHEDFILTER_H
#define WATERSHEDFILTER_H
#include "basefilter.h"

class WatershedFilter: public BaseFilter
{
private:
    int treshold;
public:
    WatershedFilter(int treshold);
    QImage process(QImage &image);
};

#endif // WATERSHEDFILTER_H
