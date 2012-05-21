#ifndef TRESHOLDFILTER_H
#define TRESHOLDFILTER_H
#include "basefilter.h"

class TresholdFilter : public BaseFilter
{
public:
    TresholdFilter(int treshold);
    virtual QImage process(QImage& image);
private:
    int treshold;
};

#endif // TRESHOLDFILTER_H
