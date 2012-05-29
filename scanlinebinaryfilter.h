#ifndef SCANLINEBINARYFILTER_H
#define SCANLINEBINARYFILTER_H
#include "basefilter.h"

class ScanLineBinaryFilter : public BaseFilter
{
public:
    ScanLineBinaryFilter();
    virtual QImage process(QImage& image);
};

#endif // SCANLINEBINARYFILTER_H
