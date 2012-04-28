#include "cgalgorithm.h"
#include <QDebug>

namespace CGAlgorithm
{
    bool is_max(QVector<int> &data, int index);
    int find_min(int i1, int i2, QVector<int> &data);
}

int CGAlgorithm::automatic_binarasation_treshold(QVector<int> data)
{
    int imax1 = -1, imax2 = -1, imin;

    qDebug() << data;

    for (int i = 0; i < data.size(); i++)
    {
        if (is_max(data, i))
        {
            if(data[imax1] < data[i])
            {
                imax2 = imax1;
                imax1 = i;
            }
            else if (data[imax2] < data[i])
            {
                imax2 = i;
            }
        }
    }

    if (imax1 > imax2)
    {
        int temp = imax1;
        imax1 = imax2;
        imax2 = temp;
    }

    imin = find_min(imax1, imax2, data);

    return imin;
}

bool  CGAlgorithm::is_max(QVector<int> &data, int index)
{
    if (index == 0)
    {
        return data[0] >= data[1];
    }

    if (index == data.size()-1)
    {
        return data[index - 1] < data[index];
    }

    return (data[index - 1] < data[index]) &&
         (data[index] > data[index + 1]);
}

int CGAlgorithm::find_min(int imax1, int imax2, QVector<int> &data)
{
    int imin = imax1;

    for (int i = imax1; i <= imax2; i++)
    {
        if (data[imin] > data[i])
        {
            imin = i;
        }
    }
    return imin;
}
