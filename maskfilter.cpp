#include "maskfilter.h"
#include <stdexcept>

MaskFilter::MaskFilter()
{

}

MaskFilter::MaskFilter(const Mask& aMask)
{
    mask = aMask;
}

QImage MaskFilter::process(QImage& image)
{
    int height = image.height();
    int width = image.width();
    QImage res(image.size(), QImage::Format_ARGB32);
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
             res.setPixel(i, j, getMaskPixel(image, i, j));
        }
    }

    return res;
}

int MaskFilter::getMaskPixel(QImage &image, int x, int y)
{
    int delta = mask.getSize() / 2;
    long sum = 0;

    for (int dx = - delta; dx <= delta; ++dx)
    {
        for (int dy = delta; dy >= -delta; --dy)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < image.width() && ny >=0 && ny < image.height())
            {
                sum += (long) qGray(image.pixel(nx, ny));
            }
            else
            {
                sum += (long) qGray(image.pixel(mirror(image.width(), nx), mirror(image.height(), ny)));
            }
        }
    }

    int gray = sum / mask.getSum();
    return qRgb(gray, gray, gray);

}

int MaskFilter::mirror(int max, int cur)
{
    if (cur < 0)
    {
        return -cur;
    }
    else if (cur > max - 1)
    {
        return max - (cur - max + 1);
    }


    //TODO: no return statment.
    throw std::logic_error(
        "No return statment in MaskFilter::mirror");
    return 0;
}
