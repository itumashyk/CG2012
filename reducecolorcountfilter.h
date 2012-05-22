#ifndef REDUCECOLORCOUNTFILTER_H
#define REDUCECOLORCOUNTFILTER_H

#include "basefilter.h"

class ReduceColorCountFilter: public BaseFilter
{
private:
    int count;

public:
    ReduceColorCountFilter(int count);
    QImage process(QImage& image);
};

#endif // REDUCECOLORCOUNTFILTER_H
