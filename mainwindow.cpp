#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include <QFont>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Configure the Serial Port
    serial = new QSerialPort(this);
    serial->setPortName("com1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    serial->write("Welcome to Pressure Detector.\n");

    // Add label widget to status bar, show serial status
    status = new QLabel(tr("Connected to %1 : Baud Rate %2, Data Bits %3, Parity %4, Stop Bits %5, Flow Control %6")
                        .arg(serial->portName())
                        .arg(serial->baudRate())
                        .arg(serial->dataBits())
                        .arg(serial->parity())
                        .arg(serial->stopBits())
                        .arg(serial->flowControl()));

    ui->statusBar->addWidget(status);

    // Add console widget(derived from QTextEdit)
    console = new Console;
    QFont consoleFont("Consolas", 10);
    console->setCurrentFont(consoleFont);
    //qDebug() << console->fontFamily();
    setCentralWidget(console);

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
