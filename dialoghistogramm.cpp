#include "dialoghistogramm.h"
#include "ui_dialoghistogramm.h"

DialogHistogramm::DialogHistogramm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistogramm)
{
    ui->setupUi(this);
}

QVector<int> DialogHistogramm:: data()
{
    return theData;
}

void DialogHistogramm::show(QVector<int> data)
{
     theData = data;
     ui->widget->loadData(data);
     QDialog::show();
}

DialogHistogramm::~DialogHistogramm()
{
    delete ui;
}
