#include "mainwindow.h"
#include <QApplication>
//#include "signaldata.h"
#include "curvedata.h"


CurveData *m_curve0 = new CurveData();
CurveData *m_curve1 = new CurveData();
CurveData *m_curve2 = new CurveData();
CurveData *m_curve3 = new CurveData();
CurveData *m_curve4 = new CurveData();

int run_main(int argc, char **argv);

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pressure Detector");
    w.setWindowIcon(QIcon(":/windowsicon.png"));
//    w.resize( 850, 500 );

//    SignalData<CurveData>::getInstance().run();
		
	

	


    w.show();

    bool ok = a.exec();


    return ok;
}

