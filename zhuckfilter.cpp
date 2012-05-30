#include "zhuckfilter.h"

ZhuckFilter::ZhuckFilter()
{
}

QImage ZhuckFilter:: process(QImage& im)
{
   QImage resim(im);
    int w = im.width();
    int h = im.height();
    for(int i=1;i<w;++i)
    {
        //int fcolor = qGray(im.pixel(i,0));
        for(int j=0;j<h;++j)
        {
            if((qGray(im.pixel(i,j)) - qGray(im.pixel(i-1,j))) == 255 && qRed(resim.pixel(i,j))!=255)
                beattle_border(resim,i-1,j,false,11);
            else
            if((qGray(im.pixel(i,j)) - qGray(im.pixel(i-1,j))) == -255 && qRed(resim.pixel(i,j))!=255)
                beattle_border(resim,i,j,true,15);
        }
    }

    return resim;
}

void ZhuckFilter::beattle_border(QImage &im, int i, int j, bool white, int cameFrom)
{
    //  0   1   2
    //  7   x   3
    //  6   5   4
    int stx = i;
    int sty = j;
    if(im.pixel(i,j) == qRgb(255,0,0))
        return;
    while(true)
    {
        im.setPixel(i,j,qRgb(255,0,0));
        bool moved = false;
        for(int k=0;k<8;++k,cameFrom--)
        {
            if     (cameFrom%8 == 0 && i>0 &&qGray(im.pixel(i-1,j))==(white==true?0:255))
            {
                i--;
                cameFrom = 9;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 1 && j>0 && i>0 && qGray(im.pixel(i-1,j-1))==(white==true?0:255))
            {
                j--; i--;
                cameFrom = 11;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 2 && j>0 && qGray(im.pixel(i,j-1))==(white==true?0:255))
            {
                j--;
                cameFrom = 11;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 3 && i+1<im.width() && j>0 && qGray(im.pixel(i+1,j-1))==(white==true?0:255))
            {
                i++;j--;
                cameFrom = 13;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 4 && i+1<im.width() && qGray(im.pixel(i+1,j))==(white==true?0:255))
            {
                i++;
                cameFrom = 13;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 5 && i+1<im.width() && j+1<im.height() && qGray(im.pixel(i+1,j+1))==(white==true?0:255))
            {
                i++;j++;
                cameFrom = 15;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 6 && j+1<im.height() && qGray(im.pixel(i,j+1))==(white==true?0:255))
            {
                j++;
                cameFrom = 15;
                moved = true;
                break;
            }
            else if(cameFrom%8 == 7 && i>0 && j+1<im.height() && qGray(im.pixel(i-1,j+1))==(white==true?0:255))
            {
                j++;i--;
                cameFrom = 9;
                moved = true;
                break;
            }
        }
        if(!moved)
            break;
        if(i==stx && j == sty)
            break;
    }
}
