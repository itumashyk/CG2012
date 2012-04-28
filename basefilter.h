#ifndef BASEFILTER_H
#define BASEFILTER_H
#include <QtGui>

class BaseFilter
{
public:
    virtual QImage process(QImage& image) = 0;
};

#endif // BASEFILTER_H
