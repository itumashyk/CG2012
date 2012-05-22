#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>
#include <QImage>
#include <QPair>
#include <QQueue>

#ifndef MPIXEL
#define MPIXEL
class mPixel
{
public:
    mPixel();
    mPixel(int _x,int _y, int _h=-1000);
    int x;
    int y;
    int height;
    // labels the pixel as belonging to a unique basin or as a part of the watershed line
    int label;
    // Distance is a work image of distances
    int distance;
};
#endif

class segment : public QObject
{

    Q_OBJECT
public:
    explicit segment(QObject *parent = 0);
    explicit segment(QImage& im, int numOfNieghb = 8,int porog=1,QObject *parent = 0);
    QImage doSegment();
private:
    mPixel fictPix;
    int curLable;
    int curDistance;
    QQueue<mPixel>* fifoQueue;
    QVector<QVector<mPixel> > heightSortedList;
    QImage im;
    int** labels;
    int** distances;
    int watershedPixelCount;
    int numberOfNeighbours;
    bool borderInWhite;
    int w;
    int h;
    int porog;

    mPixel getFromQueue();
    QVector<mPixel> getNeighbours(mPixel& centerPixel);
    void drawLines();
signals:

public slots:

};

#endif // SEGMENT_H
