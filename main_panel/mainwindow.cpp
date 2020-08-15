#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* embench opengl window into mainwindow */
    fg=new FormGraph();
    lg=new layerDialog();
//    QWidget *container = QWidget::createWindowContainer(fg);
    ui->Layout->addWidget(fg,0,0,1,3);

    /* layer dialog */
    ui->Layout->addWidget(lg,0,4,1,1);


    /* signal and slot */
    connect(fg,SIGNAL(send_signal01(string)),this,SLOT(receive_signal01(string)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDemo_triggered()
{

}

void MainWindow::receive_signal01(string str)
{
    lg->printInfo(str);
}
