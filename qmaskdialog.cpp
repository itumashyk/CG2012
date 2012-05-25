#include "qmaskdialog.h"
#include "ui_qmaskdialog.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTableWidget>

QMaskDialog::QMaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QMaskDialog)
{
    ui->setupUi(this);
}

QMaskDialog::QMaskDialog(int aSize, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QMaskDialog)
{
    ui->setupUi(this);

    size = aSize;
    for (int i = 0; i < size; ++i)
    {
        QVector<QLineEdit*> row;
        for (int j = 0; j < size; ++j)
        {
            QLineEdit * current = new QLineEdit(this);
            current->setFixedWidth(30);
            row.append(current);
        }
        table.append(row);
    }

//    QWidget * tabOrderWidget = table.at(0).at(0);
//    for (int i = 0; i < size; ++i)
//    {
//        for (int j = 0; j < size; ++j)
//        {
//            QWidget::setTabOrder(tabOrderWidget, table.at(i).at(j));
//            tabOrderWidget = table.at(i).at(j);
//        }
//    }

    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table.size(); ++j)
        {
            ui->gridLayout->addWidget(table.at(i).at(j), i, j);
        }
    }

    adjustSize();
}

QVector<QVector<int> > QMaskDialog::getCoeff()
{
    QVector<QVector<int> > result;
    for (int i = 0; i < size; ++i)
    {
        QVector<int> row;
        for (int j = 0; j < size; ++j)
        {
            row.append(table.at(i).at(j)->text().toInt());
        }
        result.append(row);
    }
    return result;
}

QMaskDialog::~QMaskDialog()
{
    delete ui;
}
