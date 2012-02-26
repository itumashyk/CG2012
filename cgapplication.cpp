#include "cgapplication.h"
#include "cgmainwindow.h"

#ifdef TUMASHYK
#   include <QCleanlooksStyle>
#endif

CGApplication::CGApplication(int & argc, char ** argv):
    QApplication(argc, argv)
{

}

int CGApplication:: exec()
{
#ifdef TUMASHYK
    setStyle(new QCleanlooksStyle);
#endif
    CGMainWindow w;
    w.show();
    return QApplication::exec();
}
