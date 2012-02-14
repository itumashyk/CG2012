#include "cgapplication.h"

int main(int argc, char *argv[])
{
    CGApplication a(argc, argv);
    return a.exec();
}
