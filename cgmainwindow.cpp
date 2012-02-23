#include "cgmainwindow.h"
#include "ui_cgmainwindow.h"
#include "mdielement.h"
#include "QMdiSubWindow"
#include "mdielement.h"
#include "QFileDialog"
#include "bitmapfilter.h"

CGMainWindow::CGMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGMainWindow)
{
    ui->setupUi(this);


#   ifdef TUMASHYK
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
#   endif
}

CGMainWindow::~CGMainWindow()
{
    delete ui;
}

void CGMainWindow::on_actionOpen_activated()
{
    QString file = QFileDialog::getOpenFileName(this,
     "Open Image", QString(), "Image Files (*.png *.jpg *.bmp)");

    QImage image(file);
    BitmapFilter filter;
    QImage result = filter.process(image);

     if (!file.isNull()) {

         QPixmap pixmap = QPixmap::fromImage(result);
         MdiElement* element = new MdiElement();
         element->setPixmap(pixmap);
         ui->mdiArea->addSubWindow(element);
         element->show();
     }
}
