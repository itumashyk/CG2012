#include "dialoghistogramm.h"
#include "ui_dialoghistogramm.h"

DialogHistogramm::DialogHistogramm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistogramm)
{
    ui->setupUi(this);
}

DialogHistogramm::~DialogHistogramm()
{
    delete ui;
}
