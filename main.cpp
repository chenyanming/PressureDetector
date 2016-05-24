#include "mainwindow.h"
#include <QApplication>
#include "samplingthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pressure Detector");
    w.setWindowIcon(QIcon("windowsicon.png"));
    w.resize( 1500, 400 );


    SamplingThread samplingThread;
    samplingThread.setInterval(10);//Derived from QwtSamplingThread function, 10ms, default 1s.

    w.show();
    samplingThread.start();
    w.start();

    bool ok = a.exec();

    samplingThread.stop();
    samplingThread.wait(1000);

    return ok;
}
