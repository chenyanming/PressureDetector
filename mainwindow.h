#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class Plot; // use this statement so that we can declare it in the head file

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QLabel>
#include "console.h"
#include "plot.h"

namespace Ui {
class MainWindow;
}

class console;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void start();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QLabel *status;
    Console *console;
    Plot *d_plot;

private slots:
    void readData();

};

#endif // MAINWINDOW_H
