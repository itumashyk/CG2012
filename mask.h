#ifndef MASK_H
#define MASK_H

#include <QVector>

class Mask
{
public:
    Mask();
    Mask(QVector<QVector<int> > &);
    int getSum();
    int getItem(int, int);
    int getSize();
    static Mask getAverageMask(int size);

private:
    QVector<QVector<int> > matrix;
    int sum;
    int size;
};

#endif // MASK_H
