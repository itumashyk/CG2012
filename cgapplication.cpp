#include "cgapplication.h"
#include "mainwindow.h"

CGApplication::CGApplication(int & argc, char ** argv):
    QApplication(argc, argv)
{

}

int CGApplication:: exec()
{
    MainWindow w;
    w.show();
    return QApplication::exec();
}
