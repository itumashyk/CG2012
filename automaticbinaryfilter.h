#ifndef AUTOMATICBINARYFILTER_H
#define AUTOMATICBINARYFILTER_H
#include "basefilter.h"


class AutomaticBinaryFilter : public BaseFilter
{
public:
    virtual QImage process(QImage& image);
};

#endif // AUTOMATICBINARYFILTER_H
