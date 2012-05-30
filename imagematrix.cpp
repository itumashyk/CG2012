#include "imagematrix.h"

ImageMatrix::ImageMatrix()
{

}

ImageMatrix::ImageMatrix(ImageMatrix &from, int x, int y, int width, int height)
{
    for (int i = 0; i < height; ++i)
    {
        QVector<bool> row;
        for (int j = 0; j < width; ++j)
        {
            row.append(from.matrix.at(y + i).at(x + j));
        }
        matrix.append(row);
    }
}

ImageMatrix::ImageMatrix(QImage image)
{
    for (int i = 0; i < image.height(); ++i)
    {
        QVector<bool> row;
        for (int j = 0; j < image.width(); ++j)
        {
            if (qGray(image.pixel(j, i)) == 0)
            {
                row.append(true);
            }
            else
            {
                row.append(false);
            }
        }
        matrix.append(row);
    }
}

double ImageMatrix::calculateDistance(const ImageMatrix &to)
{
    if (to.matrix.size() != matrix.size() || to.matrix.at(0).size() != matrix.at(0).size())
    {
        throw "Incorrect sizes!";
    }
    double dist = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.at(i).size(); ++j)
        {
            if (matrix.at(i).at(j) != to.matrix.at(i).at(j))
            {
                dist += 1.0;
            }
        }
    }

    return dist;
}

bool ImageMatrix::containLeftTopAlignedSymbol(int x, int y, int width, int height)
{
    // top
    bool contain = false;
    for (int i = x; i < x + width; ++i)
    {
        if (matrix[y][i])
        {
            contain = true;
            break;
        }
    }
    if (!contain)
    {
        return false;
    }

    // left
    for (int j = y; j < y + height; ++j)
    {
        if (matrix[j][x])
        {
            contain = true;
            break;
        }
    }
    return contain;
}
