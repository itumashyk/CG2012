#ifndef ZHUCKFILTER_H
#define ZHUCKFILTER_H
#include "basefilter.h"

class ZhuckFilter : public BaseFilter
{
public:
    ZhuckFilter();
    QImage process(QImage& image);

private:
    void beattle_border(QImage &im, int i, int j, bool white, int cameFrom);
};

#endif // ZHUCKFILTER_H
