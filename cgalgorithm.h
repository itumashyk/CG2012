#ifndef CGALGORITHM_H
#define CGALGORITHM_H

#include <QtCore>


namespace CGAlgorithm
{
    int automatic_binarasation_treshold(QVector<int> data);
    QVector<int> calculatePixels(QImage &image);
}

#endif // CGALGORITHM_H
