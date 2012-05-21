#include "bitmapfilter.h"

BitmapFilter::BitmapFilter()
{

}

QImage BitmapFilter::process(QImage &image)
{
    if (image.depth() != QImage::Format_Mono)
    {
        QMessageBox::warning(0, "Filter a bitmap", "Selected image isn't black\\white");
        return image;
    }
    int height = image.height();
    int width = image.width();
    QImage res(image.size(), QImage::Format_Mono);
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
             res.setPixel(i, j, getBestPixel(image, i, j));
        }
    }

    return res;
}

int BitmapFilter::getBestPixel(QImage &image, int x, int y)
{
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int zeros = 0, ones = 0;
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < image.width() && ny >=0 && ny < image.height())
        {
            if ((image.pixel(nx, ny) & 1) == 0)
                ++zeros;
            else
                ++ones;
        }
    }
    return zeros >= ones ? 0 : 1;
}
