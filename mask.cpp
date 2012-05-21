#include "mask.h"

Mask::Mask(){

}

Mask::Mask(QVector<QVector<int> > & aMatrix)
{
    matrix = aMatrix;
    sum = 0;
    size = matrix.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sum += matrix[i][j];
        }
    }
}

int Mask::getSum() {
    return sum;
}

int Mask::getItem(int i, int j) {
    return matrix[i][j];
}

int Mask::getSize() {
    return size;
}

Mask Mask::getAverageMask(int size)
{
    QVector<QVector<int> > v;
    QVector<int> item;
    for (int i = 0; i < size; ++i) item.push_back(1);
    for (int i = 0; i < size; ++i) v.push_back(item);
    return Mask(v);
}
