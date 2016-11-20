#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class Plot; // use this statement so that we can declare it in the head file

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QLabel>
#include "console.h"
#include "plot.h"
#include "log.h"
#include "samplingthread.h"

#include <qprinter.h>
#include <qprintdialog.h>
#include <qprintpreviewdialog.h>
#include "energyExpenditure.h"

namespace Ui {
class MainWindow;
}

//class console;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void start();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QLabel *status;
//    Console *console;
//    Plot *d_plot;
	QString serialBuffer;
	QStringList serialList;
	QByteArray serialData;
	Log *consoleLog;
	int startIn, endIn;

    SamplingThread *samplingThread;

//    QPrinter printer;
//    QPrintPreviewDialog preview;

private slots:
    int readData();
    void dumpData();
    void start();
    void stop();
    void changeXInterval(int);
    int exportDocument();
	void curve();
	void curveNOW();

};

#endif // MAINWINDOW_H
