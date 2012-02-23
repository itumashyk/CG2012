#include "cgapplication.h"
#include "cgmainwindow.h"

CGApplication::CGApplication(int & argc, char ** argv):
    QApplication(argc, argv)
{

}

int CGApplication:: exec()
{
    CGMainWindow w;
    w.show();
    return QApplication::exec();
}
