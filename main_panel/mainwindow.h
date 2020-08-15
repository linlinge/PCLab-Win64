#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <formgraph.h>
#include <layerdialog.h>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    FormGraph* fg;
    layerDialog* lg;


private slots:
     void on_actionDemo_triggered();
     /* event */
     void receive_signal01(string str);
};

#endif // MAINWINDOW_H
