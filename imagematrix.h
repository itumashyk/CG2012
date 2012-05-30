#ifndef IMAGEMATRIX_H
#define IMAGEMATRIX_H
#include <QImage>
#include <QVector>
class ImageMatrix
{
public:
    ImageMatrix();
    ImageMatrix(QImage);
    ImageMatrix(ImageMatrix & from, int x, int y, int width, int height);
    double calculateDistance(const ImageMatrix & to);
    bool containLeftTopAlignedSymbol(int x, int y, int width, int height);
private:
    QVector<QVector<bool> > matrix;
};

#endif // IMAGEMATRIX_H
