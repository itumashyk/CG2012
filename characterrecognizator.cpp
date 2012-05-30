#include "characterrecognizator.h"
#include <QPixmap>

CharacterRecognizator::CharacterRecognizator(QImage & aImage)
{
    matrix = ImageMatrix(aImage);
    width = aImage.width();
    height = aImage.height();
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        QPixmap pixmap("c:\\Users\\dev_il\\univer\\New_CG\\CG2012\\IMAGES\\" + QString(ch) + ".png");
        ethalons.append(ImageMatrix(pixmap.toImage()));
    }
}

QString CharacterRecognizator::recognize()
{
    const int wHeight = 11;
    const int wWidth = 11;
    QVector<QVector<bool> > filled;
    for (int i = 0; i < height; ++i)
    {
        QVector<bool> row;
        for (int j = 0; j < width; ++j)
        {
            row.append(false);
        }
        filled.append(row);
    }
    QString result = "";

    for (int j = 0; j + wWidth < width; ++j)
    {
        for (int i = 0; i + wHeight < height; ++i)
        {
            if (isUnfilledArea(filled, j, i, wWidth, wHeight))
            {
                if (matrix.containLeftTopAlignedSymbol(j, i, wWidth, wHeight))
                {
                    ImageMatrix current(matrix, j, i, wWidth, wHeight);
                    int index = -1;
                    double minDist = 100000;
                    for (int ind = 0; ind < ethalons.size(); ++ind)
                    {
                        double curDist = current.calculateDistance(ethalons.at(ind));
                        if (curDist < minDist)
                        {
                            minDist = curDist;
                            index = ind;
                        }
                    }

                    fillArea(filled, j, i, wWidth, wHeight);
                    result += QString ((char) ('a' + index));
                }
            }
        }
    }

    return result;
}

bool CharacterRecognizator::isUnfilledArea(QVector<QVector<bool> > & filled, int left, int top, int w, int h)
{
    for (int i = top; i < top + h; ++i)
    {
        for (int j = left; j < left + w; ++j)
        {
            if (filled.at(i).at(j))
            {
                return false;
            }
        }
    }

    return true;
}

void CharacterRecognizator::fillArea(QVector<QVector<bool> > &filled, int left, int top, int w, int h)
{
    for (int i = top; i < top + h; ++i)
    {
        for (int j = left; j < left + w; ++j)
        {
            filled[i][j] = true;
        }
    }
}
