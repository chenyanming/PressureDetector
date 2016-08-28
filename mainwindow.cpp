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
#include "data.h"

//#include <QSqlDatabase>
//#include <QSqlQuery>

//#include <QQuickWidget>
#include <QMessageBox>

// print
#include <qwt_plot_renderer.h>
#include <QFileDialog>

//double serialRev0 = 0; 
//double serialRev1 = 0;
//double serialRev2 = 0;
//double serialRev3 = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ! [0]
    // Configure the Serial Port
    serial = new QSerialPort(this);
    serial->setPortName("com3");
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
//    console = new Console;
    ui->console->setReadOnly(true);
	//console->resize(500, 200);
	//qDebug() << console->sizeHint();
    QFont consoleFont("Consolas", 10);
    ui->console->setCurrentFont(consoleFont);
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

    const double intervalLength = 100.0;

//    d_plot = new Plot(this);
    ui->d_plot->setIntervalLength(intervalLength);
    ui->d_plot->resize(500, 500);
//    (void) new QwtPlotMagnifier(d_plot->canvas());
//    (void) new QwtPlotPanner(d_plot->canvas());



//    QQuickWidget *view = new QQuickWidget;
//    view->setSource(QUrl::fromLocalFile("places_map.qml"));
//    ui->horizontalLayout->addWidget(view);


    // ! [5]
    // Layout of the central window
//    QWidget *window = new QWidget;
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(console);
//    layout->addWidget(d_plot);
//    window->setLayout(layout);
//    setCentralWidget(window);


    ui->openButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //ui->openButton->setIcon(QIcon(":/1465992334_folder_open_GPL.png"));
    ui->openButton->setEnabled(false);

    ui->printButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //ui->printButton->setIcon(QIcon(":/1465989469_print_printer_LGPL.png"));
    ui->printButton->setEnabled(false); // printButton is false at startup

    ui->closeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //ui->closeButton->setIcon(QIcon(":/1465992876_Vector-icons_free.png"));

    ui->exportButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //ui->exportButton->setIcon(QIcon(":/1465995014_pdf_LGPL.png"));
    ui->exportButton->setEnabled(false); // exportButton is false at startup

    ui->startButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //ui->startButton->setIcon(QIcon(":/1465993344_run_free.png"));

    ui->stopButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //ui->stopButton->setIcon(QIcon(":/1465993547_Pause_Icon_free.png"));
    ui->stopButton->setEnabled(false);

    ui->settingButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->settingButton->setEnabled(false);

    // Create Sample Thread
    samplingThread = new SamplingThread;
    samplingThread->setInterval(100);//Derived from QwtSamplingThread function, 10ms, default 1s.


	// init the serial buffer
	serialBuffer = "";
	// Create a log file
	consoleLog = new Log(this);

    connect(serial, SIGNAL(readyRead()), this, SLOT(dumpData()));
    connect(ui->startButton, SIGNAL(clicked(bool)), SLOT(start()));
    connect(ui->stopButton, SIGNAL(clicked(bool)), SLOT(stop()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->exportButton, SIGNAL(clicked()), this, SLOT(exportDocument()));
    connect(ui->intervalBox, SIGNAL(valueChanged(int)), this, SLOT(changeXInterval(int)));



}

MainWindow::~MainWindow()
{
    // Stop Sample Thread
    samplingThread->stop();
    samplingThread->wait(1000);
    delete ui;
}

void MainWindow::dumpData()
{
    serialData = serial->readAll();
}

int MainWindow::readData()
{
	// read serial data
    serialData = serial->readAll();
	// display in the console
    ui->console->serialReceived(serialData);
	// accumulate is good way
    serialBuffer += QString(serialData);
//    qDebug() << serialBuffer;
	startIn = serialBuffer.indexOf("START");
    serialBuffer = serialBuffer.mid(startIn); // Delete the characters before "START". It is very important!
	endIn = serialBuffer.indexOf("END");
//	qDebug() << endIn - startIn;
	//endIn = serialBuffer.indexOf("\r");
	//serialBuffer.remove(0, endIn);
	//qDebug() << serialData;
    if ((endIn - startIn) > 15) {
//    if (serialData == QString('\n')) {
        //qDebug() << (endIn - startIn); // it should be 22.
		// parse the four data
		//qDebug() << serialBuffer;
		serialList = serialBuffer.split(',');
//        qDebug() << serialList.size();
		if(serialList.size() == 6) {
			Data::getInstance().PressData.serialRev0 = serialList.at(1).toDouble();
			Data::getInstance().PressData.serialRev1 = serialList.at(2).toDouble();
			Data::getInstance().PressData.serialRev2 = serialList.at(3).toDouble();
			Data::getInstance().PressData.serialRev3 = serialList.at(4).toDouble();
            consoleLog->data[0] = Data::getInstance().PressData.serialRev0;
            consoleLog->data[1] = Data::getInstance().PressData.serialRev1;
            consoleLog->data[2] = Data::getInstance().PressData.serialRev2;
            consoleLog->data[3] = Data::getInstance().PressData.serialRev3;
            consoleLog->save();
        }
        else
        {
//            QMessageBox::warning(NULL, "Warning", "Please input your name.", QMessageBox::Yes);
        }
		//qDebug() << serialRev0;
		//qDebug() << serialRev1;
		//qDebug() << serialRev2;
		//qDebug() << serialRev3;
		//serialRev0 = serialBuffer.mid(startIn + 6, 3).toDouble();
		//serialRev1 = serialBuffer.mid(startIn + 10, 3).toDouble();
		//serialRev2 = serialBuffer.mid(startIn + 14, 3).toDouble();
		//serialRev3 = serialBuffer.mid(startIn + 18, 3).toDouble();
		//qDebug() << serialRev0 << " " << serialRev1 << " " << serialRev2 << " " << serialRev3 << "\n";
		// Save four sensors' data to the log file
		// clear 
		startIn = 0;
		endIn = 0;
		serialBuffer = "";
	}
    else
    {

    }
    return 0;
}

void MainWindow::start()
{
    // Start the Sample Thread and polting
    qDebug() << "Start......";
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
    disconnect(serial, SIGNAL(readyRead()), this, SLOT(dumpData()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    samplingThread->start();
    ui->d_plot->start();
}

void MainWindow::stop()
{
    qDebug() << "Stop!!";
    ui->stopButton->setEnabled(false);
    ui->exportButton->setEnabled(true);
    samplingThread->stop();
    ui->d_plot->stop();
    disconnect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(dumpData()));
}

int MainWindow::exportDocument()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as PDF..."), QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        // if suffix is empty, use .pdf as default value
        if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".pdf");
        QPrinter *printer = new QPrinter(QPrinter::HighResolution);
        printer->setPageOrientation(QPageLayout::Landscape);
        printer->setPaperSize(QPrinter::A4);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setOutputFileName(fileName);


        QPainter painter;
        if (!painter.begin(printer)) { // failed to open file
            qWarning("failed to open file, is it writable?");
            return 1;
        }
        painter.drawText(100, 100, "Pressure Detector Data Graph");


        QwtPlotRenderer renderer;

        qreal qwidth = printer->width();
        qreal qheight = printer->height();
        qreal x_plot = qwidth*0.1;
        qreal y_plot = qwidth*0.05;
        qreal w_plot = qwidth*0.8;
        qreal h_plot = qheight*0.8;
        //qDebug() << x_plot;
        //qDebug() << y_plot;
        //qDebug() << w_plot;
        //qDebug() << h_plot;
        renderer.render(ui->d_plot, &painter, QRectF(x_plot, y_plot, w_plot, h_plot));

        painter.end();
    }

    return 0;

}

void MainWindow::changeXInterval(int)
{
    //qDebug() << ui->intervalSlider->value();
    ui->d_plot->setIntervalLength(ui->intervalBox->value());
    //qDebug() << ui->intervalSlider->value();
//    ui->intervalBox->setValue(ui->intervalSlider->value());

}


