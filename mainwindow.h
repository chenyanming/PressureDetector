#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class Plot; // use this statement so that we can declare it in the head file

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QLabel>
#include "console.h"
#include "plot.h"
#include "log.h"

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
	QString serialBuffer;
	QByteArray serialData;
	Log *consoleLog;
	int startIn, endIn;

private slots:
    int readData();

};

#endif // MAINWINDOW_H
