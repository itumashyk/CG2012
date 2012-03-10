#include "cgmainwindow.h"
#include "ui_cgmainwindow.h"
#include "mdielement.h"
#include "QMdiSubWindow"
#include "mdielement.h"
#include "QFileDialog"
#include "bitmapfilter.h"
#include "grayscalefilter.h"
#include "invertfilter.h"
#include "cgalgorithm.h"

CGMainWindow::CGMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CGMainWindow)
{
    ui->setupUi(this);
    histogramDialog = NULL;

#   ifdef TUMASHYK
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
#   endif
}

CGMainWindow::~CGMainWindow()
{
    delete ui;
    delete histogramDialog;
}

void CGMainWindow::on_actionOpen_activated()
{
    QString file = QFileDialog::getOpenFileName(this,
     "Open Image", QString(), "Image Files (*.png *.jpg *.bmp)");

     if (!file.isNull())
     {


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
   BitmapFilter filter;
   applyFilter(&filter);
}

void CGMainWindow::on_actionGrayscale_activated()
{
    GrayscaleFilter filter;
    applyFilter(&filter);
}

void CGMainWindow::applyFilter(BaseFilter* filter)
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    if (active != NULL)
    {
        MdiElement* activeElement = dynamic_cast<MdiElement*> (active->widget());

        QImage image =  activeElement->pixmap().toImage();
        QImage result = filter->process(image);
        QPixmap pixmap = QPixmap::fromImage(result);
        activeElement->setPixmap(pixmap);
    }
}

void CGMainWindow::on_actionInvert_Colors_activated()
{
    InvertFilter filter;
    applyFilter(&filter);
}

void CGMainWindow::on_actionShow_Histogram_activated()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    if (active != NULL)
    {
        MdiElement* activeElement = dynamic_cast<MdiElement*> (active->widget());

        QImage image =  activeElement->pixmap().toImage();
        if (histogramDialog == NULL)
        {
            histogramDialog = new DialogHistogramm(this);
        }
        histogramDialog->show(CGAlgorithm::calculatePixels(image));
    }
}
