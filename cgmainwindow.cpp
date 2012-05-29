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
#include "tresholdfilter.h"
#include "maskfilter.h"
#include "medianfilter.h"
#include "automaticbinaryfilter.h"
#include "histogrammsegmentation.h"
#include "reducecolorcountfilter.h"
#include "scanlinebinaryfilter.h"
#include "scanlinegrayfilter.h"
#include "qmaskdialog.h"

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
        MdiElement* activeElement =
            dynamic_cast<MdiElement*> (active->widget());

        QImage image =  activeElement->pixmap().toImage();
        // TODO : add locale image processing
        QImage result;
        if (!activeElement->isRubberBandVisible()) {
            result = filter->process(image);
        } else {
            QRectF selection = activeElement->getSelectionRect();
            QRect boundingRect = QRect(selection.left(), selection.top(), selection.width(), selection.height());
            boundingRect = boundingRect.intersect(image.rect());
            QImage toProcess = image.copy(boundingRect);
            QImage areaResult = filter->process(toProcess);
            result = image;
            for (int i = boundingRect.left(); i < boundingRect.right(); ++i) {
                for (int j = boundingRect.top(); j < boundingRect.bottom(); ++j) {
                    result.setPixel(i, j, areaResult.pixel(i - boundingRect.left(), j - boundingRect.top()));
                }
            }
            activeElement->hideRubberBand();

        }
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
        MdiElement* activeElement =
            dynamic_cast<MdiElement*> (active->widget());

        QImage image =  activeElement->pixmap().toImage();
        if (histogramDialog == NULL)
        {
            histogramDialog = new DialogHistogramm(this);
        }
        histogramDialog->show(CGAlgorithm::calculatePixels(image));
    }
}

void CGMainWindow::on_actionTreshold_activated()
{
    bool ok;
    int treshold = QInputDialog::getInt(this, "Treshold", "Enter treshold", 0,
        0, 255, 1, &ok);
    if (ok)
    {
        TresholdFilter filter(treshold);
        applyFilter(&filter);
    }
}

void CGMainWindow::on_actionSave_activated()
{
    QMdiSubWindow *active = ui->mdiArea->activeSubWindow();
    if (active != NULL)
    {
        QString path = QFileDialog::getSaveFileName(this, QString(), QString(),
        "PNG (*.png);; JPG (*.jpg);; BMP(*.bmp);; JPEG(*.jpeg);; TIFF (*.tiff);; PPM (*.ppm)");
        if (path != "")
        {
            MdiElement* activeElement = dynamic_cast<MdiElement*> (active->widget());
            int comressionLevel = QInputDialog::getInt(this,
                "Compression Level", "Choose compession level", 50,
                0, 100, 1);
            activeElement->pixmap().save(path, 0, 100 - comressionLevel);
        }
    }

}

void CGMainWindow::on_actionAverage_Filter_activated()
{
    MaskFilter filter(Mask::getAverageMask(3));
    applyFilter(&filter);
}

void CGMainWindow::on_actionAverage_Filter_with_size_activated()
{
    bool ok;
    int size = QInputDialog::getInt(this, "Size", "Enter size of average filter mask", 0,
        0, 255, 1, &ok);
    if (ok)
    {
        MaskFilter filter(Mask::getAverageMask(size));
        applyFilter(&filter);
    }
}

void CGMainWindow::on_actionMedian_Filter_activated()
{
    MedianFilter filter(3);
    applyFilter(&filter);
}

void CGMainWindow::on_actionMedian_Filter_with_size_activated()
{
    bool ok;
    int size = QInputDialog::getInt(this, "Size", "Enter size of median filter mask", 0,
        0, 255, 1, &ok);
    if (ok)
    {
        MedianFilter filter(size);
        applyFilter(&filter);
    }
}

void CGMainWindow::on_actionAutomatic_Treshold_activated()
{
    AutomaticBinaryFilter automaticBinaryFilter;
    applyFilter(&automaticBinaryFilter);
}

void CGMainWindow::on_actionHistogramm_segmentation_activated()
{
    bool ok;
    int result = QInputDialog::getInt(this, "Histogramm smoothing number",
        "Histogramm smoothing number", 0, 1, 51, 1,&ok);

    if (ok)
    {
        HistogrammSegmentation filter(result);
        applyFilter(&filter);
    }
}

void CGMainWindow::on_actionReduce_color_count_activated()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Color count",
        "Color count:", 0, 1, 51, 1,&ok);
    if (ok)
    {
        ReduceColorCountFilter filter(num);
        applyFilter(&filter);
    }
}

void CGMainWindow::on_actionFilter_by_mask_activated()
{
    bool ok;
    int num = QInputDialog::getInt(this, "Mask size",
        "Mask size:", 3, 3, 51, 2, &ok);
    if (ok)
    {
        QMaskDialog * dialog = new QMaskDialog(num, this);
        if (dialog->exec())
        {
            Mask mask(dialog->getCoeff());
            MaskFilter filter(mask);
            applyFilter(&filter);
        }

    }
}

void CGMainWindow::on_actionScan_line_for_binary_activated()
{
    ScanLineBinaryFilter scanLineBinFilter;
    applyFilter(&scanLineBinFilter);
}

void CGMainWindow::on_actionScan_line_for_gray_activated()
{
    bool ok;
    int threshold = QInputDialog::getInt(this, "Threshold for scan line",
                                         "Threshold:", 100, 1, 255, 1, &ok);
    if (ok)
    {
        ScanLineGrayFilter filter(threshold);
        applyFilter(&filter);
    }
}
