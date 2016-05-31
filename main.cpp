#include "mainwindow.h"
#include <QApplication>
#include "samplingthread.h"
//#include "signaldata.h"
#include "curvedata.h"


CurveData *m_curve0 = new CurveData();
CurveData *m_curve1 = new CurveData();
CurveData *m_curve2 = new CurveData();
CurveData *m_curve3 = new CurveData();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pressure Detector");
    w.setWindowIcon(QIcon("windowsicon.png"));
    w.resize( 850, 500 );

//    SignalData<CurveData>::getInstance().run();
		
	

	

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
