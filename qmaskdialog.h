#ifndef QMASKDIALOG_H
#define QMASKDIALOG_H

#include <QDialog>
#include <QVector>
#include <QLineEdit>

namespace Ui {
class QMaskDialog;
}

class QMaskDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit QMaskDialog(int size, QWidget *parent);
    explicit QMaskDialog(QWidget *parent = 0);
    QVector<QVector<int> > getCoeff();
    ~QMaskDialog();
    
private:
    Ui::QMaskDialog *ui;
    int size;
    QVector<QVector<QLineEdit*> > table;
};

#endif // QMASKDIALOG_H
