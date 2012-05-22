#include "reducecolorcountfilter.h"

ReduceColorCountFilter::ReduceColorCountFilter(int count)
{
    this->count = count;
}

QImage ReduceColorCountFilter:: process(QImage& image)
{
    int hint = 256 / count;
    int w = image.width();
    int h = image.height();
    for(int i=0; i<w; ++i)
    {
        for(int j=0; j < h; ++j)
        {
            int pix1 = qRed(image.pixel(i,j));
            int pix2 = qGreen(image.pixel(i,j));
            int pix3 = qBlue(image.pixel(i,j));
            pix1 = pix1/hint*hint + hint/2;
            pix2 = pix2/hint*hint + hint/2;
            pix3 = pix3/hint*hint + hint/2;
            image.setPixel(i,j,qRgb(pix1,pix2,pix3));
        }
    }
    return image;
}
