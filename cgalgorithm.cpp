#include "cgalgorithm.h"
#include <QtGui>

QVector<int> CGAlgorithm::calculatePixels(QImage &image)
{
    QVector<int> result(256);

    int height = image.height();
    int width = image.width();
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            int color = qBlue(image.pixel(i, j));
            result[color]++;
        }
    }

    return result;
}

