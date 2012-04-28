#include "automaticbinaryfilter.h"
#include "grayscalefilter.h"
#include "cgalgorithm.h"
#include "tresholdfilter.h"

QImage AutomaticBinaryFilter:: process(QImage& image)
{
    GrayscaleFilter grayscaleFilter;
    QImage grayScale = grayscaleFilter.process(image);
    QVector<int> vector = CGAlgorithm::calculatePixels(grayScale);
    int treshold = CGAlgorithm::automatic_binarasation_treshold(vector);
    TresholdFilter tresholdFilter(treshold);
    return tresholdFilter.process(grayScale);
}
