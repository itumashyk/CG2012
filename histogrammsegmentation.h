#ifndef HISTOGRAMMSEGMENTATION_H
#define HISTOGRAMMSEGMENTATION_H

#include "basefilter.h"

class HistogrammSegmentation : public BaseFilter
{
 private:
    int smoothingNumder;
public:
    HistogrammSegmentation(int smoothingNumder);
    QImage process(QImage& image);
};

#endif // HISTOGRAMMSEGMENTATION_H
