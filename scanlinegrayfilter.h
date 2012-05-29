#ifndef SCANLINEGRAYFILTER_H
#define SCANLINEGRAYFILTER_H
#include "basefilter.h"

class ScanLineGrayFilter : public BaseFilter
{
public:
    ScanLineGrayFilter(int threshold);
    virtual QImage process(QImage &image);
private:
    int threshold;
};

#endif // SCANLINEGRAYFILTER_H
