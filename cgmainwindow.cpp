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

//    QImage image(file);
//    BitmapFilter filter;
//    QImage result = filter.process(image);

     if (!file.isNull())
     {

         //QPixmap pixmap = QPixmap::fromImage(result);

         QPixmap pixmap(file);
         MdiElement* element = new MdiElement();
         element->setPixmap(pixmap);
         element->setWindowTitle(file);
         ui->mdiArea->addSubWindow(element)->setAttribute(Qt::WA_DeleteOnClose);
         element->show();
     }
}

void CGMainWindow::on_actionSimple_Filter_activated()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    if (active != NULL)
    {
        MdiElement* activeElement = dynamic_cast<MdiElement*> (active->widget());

        QImage image =  activeElement->pixmap().toImage();
        BitmapFilter filter;
        QImage result = filter.process(image);
        QPixmap pixmap = QPixmap::fromImage(result);
        activeElement->setPixmap(pixmap);
    }
}
