#ifndef LAYERDIALOG_H
#define LAYERDIALOG_H

#include <QWidget>
#include <string>
using namespace std;
namespace Ui {
class layerDialog;
}

class layerDialog : public QWidget
{
    Q_OBJECT

public:
    explicit layerDialog(QWidget *parent = 0);
    ~layerDialog();
    void printInfo(string str);

private:
    Ui::layerDialog *ui;
};

#endif // LAYERDIALOG_H
