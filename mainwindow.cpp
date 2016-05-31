#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include <QFont>
#include <QDebug>
#include <QHBoxLayout>

#include <qwt_plot.h>
#include <qwt_legend.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_curve.h>
#include <QtMath>
#include <qwt_point_data.h>

#include "plot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ! [0]
    // Configure the Serial Port
    serial = new QSerialPort(this);
    serial->setPortName("com4");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    serial->write("Welcome to Pressure Detector.\n");

    // ! [1]
    // Add label widget to status bar, show serial status
    status = new QLabel(tr("Connected to %1 : Baud Rate %2, Data Bits %3, Parity %4, Stop Bits %5, Flow Control %6")
                        .arg(serial->portName())
                        .arg(serial->baudRate())
                        .arg(serial->dataBits())
                        .arg(serial->parity())
                        .arg(serial->stopBits())
                        .arg(serial->flowControl()));

    ui->statusBar->addWidget(status);

    // ! [2]
    // Add console widget(derived from QTextEdit)
    console = new Console;
    console->setReadOnly(true);
	//console->resize(500, 200);
	//qDebug() << console->sizeHint();
    QFont consoleFont("Consolas", 10);
    console->setCurrentFont(consoleFont);
    //qDebug() << console->fontFamily();


    // ! [3]
//    QwtPlot *plot = new QwtPlot(QwtText("Figure"));
//    plot->resize(600, 400);
//    plot->setAxisTitle(QwtPlot::xBottom, "x");
//    plot->setAxisTitle(QwtPlot::yLeft, "y");
//    plot->setAxisScale(QwtPlot::xBottom, 0.0, 10.0);
//    plot->setAxisScale(QwtPlot::yLeft, -1.0, 1.0);
//    plot->insertLegend(new QwtLegend(), QwtPlot::RightLegend);
//    (void) new QwtPlotMagnifier(plot->canvas());
//    (void) new QwtPlotPanner(plot->canvas());

//    QVector<double> xs, ys;
//    for (double x = 0; x < 15.0 ; x++)
//    {
//        xs.append(x);
//        ys.append(qSin(x));
//    }
    //qDebug() << ys;

    // ![4]
//    QwtPointArrayData *curveData = new QwtPointArrayData(xs, ys);
//    QwtPlotCurve *curve = new QwtPlotCurve("Sine");
//    curve->setData(curveData);
//    curve->setStyle(QwtPlotCurve::Lines);
//    curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
//    curve->setPen(QColor(0, 0, 255, 255), 2);
//    curve->attach(plot);

    const double intervalLength = 10.0;

    d_plot = new Plot(this);
    d_plot->setIntervalLength(intervalLength);
	d_plot->resize(500, 500);
//    (void) new QwtPlotMagnifier(d_plot->canvas());
//    (void) new QwtPlotPanner(d_plot->canvas());



    // ! [5]
    // Layout of the central window
    QWidget *window = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(console);
    layout->addWidget(d_plot);
    window->setLayout(layout);
    setCentralWidget(window);





    // Connect and make it work, read the serial
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    console->serialReceived(data);

}

void MainWindow::start()
{
    d_plot->start();
}
