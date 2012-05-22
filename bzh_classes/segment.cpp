#include "segment.h"
#include <QtAlgorithms>
#include <algorithm>

const int INIT = 0;
const int MASK = -2;
const int WSHED = -1;

mPixel::mPixel()
{
    x = -1;
    y = -1;
    height = -1000;
    label = -1000;
    distance = -1000;
}

mPixel::mPixel(int _x, int _y, int _h)
{
    x = _x;
    y = _y;
    height = _h;
    label = INIT;
    distance = 0;
}

segment::segment(QObject *parent) :
    QObject(parent)
{
}

segment::segment(QImage &_im, int numOfNieghb,int _porog, QObject *parent):
    QObject(parent)
{
    im = QImage(_im);
    w = _im.width();
    h = _im.height();
    porog = _porog;
    borderInWhite = true;
    numberOfNeighbours = numOfNieghb;
    fictPix = mPixel();
    curLable = 0;
    curDistance = 0;
    watershedPixelCount = 0;
    fifoQueue = new QQueue<mPixel>();
    heightSortedList = QVector<QVector<mPixel> >();

    int num = 256/porog;
    if(256%porog!=0)
        num++;
    for(int i=0; i<num;++i)
        heightSortedList.push_back(QVector<mPixel>());
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
        {
            mPixel p(i,j,qGray(im.pixel(i,j)));
            int ind = (qGray(im.pixel(i,j)))/porog;
            if(qGray(im.pixel(i,j))> porog*(num-1))
                ind = num-1;
            (heightSortedList[ind]).push_back(p);
        }
    labels = new int*[w];
    distances = new int*[w];
    for(int i=0;i<w;++i)
    {
        labels[i] = new int[h];
        distances[i] = new int[h];
        for(int j=0;j<h;++j)
        {
            labels[i][j] = INIT;
            distances[i][j] = -1;
        }
    }

}

QVector<mPixel> segment::getNeighbours(mPixel& centerPixel)
{
    QVector<mPixel> resvec;
    int x = centerPixel.x;
    int y = centerPixel.y;
    if(numberOfNeighbours == 8)
    {
        //  -1,-1
        if ((centerPixel.x - 1) >= 0 && (centerPixel.y - 1) >= 0)
            resvec.push_back(mPixel(x-1,y-1,qGray(im.pixel(x-1,y-1))));
        //  0, -1
        if ((centerPixel.y - 1) >= 0)
            resvec.push_back(mPixel(x,y-1,qGray(im.pixel(x,y-1))));
        //  1, -1
        if ((centerPixel.x + 1) < w && (centerPixel.y - 1) >= 0)
            resvec.push_back(mPixel(x+1,y-1,qGray(im.pixel(x+1,y-1))));
        // -1, 0
        if ((centerPixel.x - 1) >= 0)
            resvec.push_back(mPixel(x-1,y,qGray(im.pixel(x-1,y))));
        //  1, 0
        if ((centerPixel.x + 1) < w)
            resvec.push_back(mPixel(x+1,y,qGray(im.pixel(x+1,y))));
        // -1, 1
        if ((centerPixel.x - 1) >= 0 && (centerPixel.y + 1) < h)
            resvec.push_back(mPixel(x-1,y+1,qGray(im.pixel(x-1,y+1))));
        //  0, 1
        if ((centerPixel.y + 1) < h)
            resvec.push_back(mPixel(x,y+1,qGray(im.pixel(x,y+1))));
        //  1, 1
        if ((centerPixel.x + 1) < w && (centerPixel.y + 1) < h)
            resvec.push_back(mPixel(x+1,y+1,qGray(im.pixel(x+1,y+1))));
    }
    else
    {
        //  0, -1
        if ((centerPixel.y - 1) >= 0)
            resvec.push_back(mPixel(x,y-1,qGray(im.pixel(x,y-1))));
        // -1, 0
        if ((centerPixel.x - 1) >= 0)
            resvec.push_back(mPixel(x-1,y,qGray(im.pixel(x-1,y))));
        //  1, 0
        if ((centerPixel.x + 1) < w)
            resvec.push_back(mPixel(x+1,y,qGray(im.pixel(x+1,y))));
        //  0, 1
        if ((centerPixel.y + 1) < h)
            resvec.push_back(mPixel(x,y+1,qGray(im.pixel(x,y+1))));
    }
    return resvec;
}

mPixel segment::getFromQueue()
{
    mPixel p(fifoQueue->first());
    fifoQueue->pop_front();
    return p;
}

void segment::drawLines()
{
    if (watershedPixelCount == 0)
        return;

    int watershedColor = 255;

    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
            if( labels[i][j] == WSHED)
                im.setPixel(i,j,qRgb(watershedColor,255,255));
}

QImage segment::doSegment()
{
    for(int i=0;i<heightSortedList.size();++i)
    {
        for(int j=0;j<heightSortedList[i].size();++j)
        {
            mPixel p = heightSortedList[i][j];
            labels[p.x][p.y] = MASK;
            QVector<mPixel> neighbouringPixels = getNeighbours(heightSortedList[i][j]);
            for(int k=0;k<neighbouringPixels.size();++k)
            {
                if (labels[neighbouringPixels[k].x][neighbouringPixels[k].y] > 0 ||
                        labels[neighbouringPixels[k].x][neighbouringPixels[k].y] == WSHED)
                {
                    distances[p.x][p.y] = 1;
                    fifoQueue->push_back(heightSortedList[i][j]);
                    break;
                }
            }
        }
        curDistance = 1;
        fifoQueue->push_back(fictPix);
        while(true)
        {
            mPixel p = getFromQueue();
            if (p.x == fictPix.x && p.x == fictPix.y)
            {
                if (fifoQueue->isEmpty())
                    break;
                else
                {
                    fifoQueue->push_back(fictPix);
                    curDistance++;
                    p = getFromQueue();
                }
            }
            QVector<mPixel> neighbouringPixels = getNeighbours(p);
            for( int k=0;k<neighbouringPixels.size();++k)
            {
                int cdist = distances[neighbouringPixels[k].x][neighbouringPixels[k].y];
                int clable = labels[neighbouringPixels[k].x][neighbouringPixels[k].y];
                //int pdist = distances[p.x][p.y];
                int plbl = labels[p.x][p.y];
                if (cdist <= curDistance && (clable > 0 || clable == WSHED))
                {
                    if (clable > 0)
                    {
                        if (plbl == MASK)
                            labels[p.x][p.y] = clable;
                        else if ( plbl != clable)
                        {
                            labels[p.x][p.y] = WSHED;
                            watershedPixelCount++;
                        }
                    }
                    else if (plbl == MASK)
                    {
                        labels[p.x][p.y] = WSHED;
                        watershedPixelCount++;
                    }
                }
                // neighbouringPixel is plateau pixel
                else if (clable == MASK && cdist == 0)
                {
                    distances[neighbouringPixels[k].x][neighbouringPixels[k].y] = curDistance + 1;
                    fifoQueue->push_back(neighbouringPixels[k]);
                }
            }
        }
        for(int j=0;j<heightSortedList[i].size();++j)
        {
            distances[heightSortedList[i][j].x][heightSortedList[i][j].y] = 0;
            int hlable = labels[heightSortedList[i][j].x][heightSortedList[i][j].y];
            // if true then p is inside a new minimum
            if ( hlable == MASK)
            {
                curLable++;
                labels[heightSortedList[i][j].x][heightSortedList[i][j].y] = curLable;
                fifoQueue->push_back(heightSortedList[i][j]);
                while (!fifoQueue->isEmpty())
                {
                    mPixel q = getFromQueue();
                    QVector<mPixel> neighbouringPixels = getNeighbours(q);
                    for(int k=0;k<neighbouringPixels.size();++k)
                    {
                        if (labels[neighbouringPixels[k].x][neighbouringPixels[k].y] == MASK)
                        {
                            labels[neighbouringPixels[k].x][neighbouringPixels[k].y] = curLable;
                            fifoQueue->push_back(neighbouringPixels[k]);
                        }
                    }
                }
            }
        }
    }
    drawLines();
    QImage resim(im);
    return resim;
}












