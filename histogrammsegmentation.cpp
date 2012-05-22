#include "histogrammsegmentation.h"
#include "cgalgorithm.h"
#include <QtGui>

HistogrammSegmentation::HistogrammSegmentation(int smoothingNumder)
{
    this->smoothingNumder = smoothingNumder;
}

QImage HistogrammSegmentation:: process(QImage& image)
{
    int num = smoothingNumder;

    QImage im = image;
    QVector<int> hs = CGAlgorithm::calculatePixels(im);
    for(int k=0;k<num;++k)
    {
        for(int i=1;i<254;++i)
        {
            hs[i] = (hs[i-1]+hs[i]+hs[i+1])/3;
        }
        hs[0] = (hs[0] + hs[1]*2)/3;
        hs[255] = (hs[255] + hs[254]*2)/3;

    }
    QVector<QPair<QPair<int,int>,int> > max_min;
    for(int i=1;i<255;++i)
    {
        if(hs[i-1]<=hs[i] && hs[i]>=hs[i+1] and !max_min.contains(QPair<QPair<int,int>,int>(QPair<int,int>(i-1,hs[i-1]),1)))
            max_min.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(i,hs[i]),1));
        else if(hs[i-1]>=hs[i] && hs[i]<=hs[i+1] and !max_min.contains(QPair<QPair<int,int>,int>(QPair<int,int>(i-1,hs[i-1]),0)))
            max_min.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(i,hs[i]),0));
    }
    QVector<QPair<QPair<int,int>,int> > promezhutki;
    if(max_min.at(0).second == 0)
    {
        int i=2;
        promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(0,max_min.at(i).first.first),max_min.at(i-1).first.first));
        for(i=4;i<max_min.size();i= i+2)
            promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(max_min.at(i-2).first.first,max_min.at(i).first.first),max_min.at(i-1).first.first));
        if(i==max_min.size()-2)
            promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(max_min.at(max_min.size()-2).first.first,255),max_min.at(max_min.size()-1).first.first));
        else
            promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(max_min.at(max_min.size()-2).first.first,255),max_min.at(max_min.size()-1).first.first));
   }
    else
    {
        int i=1;
        promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(0,max_min.at(i).first.first),max_min.at(i-1).first.first));
        for(i=3;i<max_min.size();i= i+2)
            promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(max_min.at(i-2).first.first,max_min.at(i).first.first),max_min.at(i-1).first.first));
        if(i==max_min.size()-2)
            promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(max_min.at(max_min.size()-2).first.first,255),max_min.at(max_min.size()-1).first.first));
        else
            promezhutki.push_back(QPair<QPair<int,int>,int> (QPair<int,int>(max_min.at(max_min.size()-2).first.first,255),max_min.at(max_min.size()-1).first.first));
    }
    int w = im.width();
    int h = im.height();
    QImage tmpim(im);
    for(int i=0; i<w;++i)
        for(int j=0;j<h;++j)
        {
            for(int k=0;k<promezhutki.size();++k)
            {
                int pix = qGray(im.pixel(i,j));
                if(pix>=promezhutki.at(k).first.first && pix<=promezhutki.at(k).first.second)
                {
                    int pp = promezhutki.at(k).second;
                    tmpim.setPixel(i,j,qRgb(pp,pp,pp));
                }
            }
        }

    return tmpim;
}


