#include "grayscalefilter.h"
#include "QColor"

 QImage GrayscaleFilter:: process(QImage& image)
 {

    int height = image.height();
    int width = image.width();
    QImage res(image.size(), image.format());
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
             res.setPixel(i, j, getEverage(image, i, j));
        }
    }

    return res;
 }

int GrayscaleFilter::getEverage(QImage &image, int x, int y){
    int color = image.pixel(x, y);
    int grayVal = qGray(color);
    int res = grayVal;
    res <<= 8;
    res += grayVal;
    res <<=8;
    res +=grayVal;
    res += (qAlpha(color) << 24);

    return res;
}
