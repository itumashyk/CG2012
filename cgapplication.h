#ifndef CGAPPLICATION_H
#define CGAPPLICATION_H

#include <QApplication>

class CGApplication : public QApplication
{
public:
    CGApplication(int & argc, char ** argv);
    static int exec();
};

#endif // CGAPPLICATION_H
