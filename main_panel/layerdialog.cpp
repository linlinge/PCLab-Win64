#include "layerdialog.h"
#include "ui_layerdialog.h"

layerDialog::layerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::layerDialog)
{
    ui->setupUi(this);
}

layerDialog::~layerDialog()
{
    delete ui;
}

void layerDialog::printInfo(string str)
{
    ui->plainTextEdit->document()->setPlainText(QString::fromStdString(str));
}
