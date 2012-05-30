#ifndef CHARACTERRECOGNIZATOR_H
#define CHARACTERRECOGNIZATOR_H
#include <QImage>
#include <QVector>
#include <imagematrix.h>

class CharacterRecognizator
{
public:
    CharacterRecognizator(QImage & image);
    QString recognize();
private:
    ImageMatrix matrix;
    QVector<ImageMatrix> ethalons;
    int width, height;
    bool isUnfilledArea(QVector<QVector<bool> > & filled, int left, int top, int w, int h);
    void fillArea(QVector<QVector<bool> > & filled, int left, int top, int w, int h);
};

#endif // CHARACTERRECOGNIZATOR_H
