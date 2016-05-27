#include "samplingthread.h"
#include <QPoint>
//#include "signaldata.h"
//#include "curvedata.h"
//#include <QtMath>
#include <qwt_math.h>
#include <math.h>
#include <QDebug>

//class CurveData
//{
//public:
//    CurveData();
//    ~CurveData();
//    void run()
//    {
//        qDebug() << "QUIT.";
//    }
//};

#include "curvedata.h"
extern CurveData *m_curve0;



SamplingThread::SamplingThread(QObject *parent):
    QwtSamplingThread(parent)
{

}

void SamplingThread::sample(double elapsed)
{
//    const QPointF s(elapsed, value(elapsed));
    const QPointF s0(elapsed, 10);
//    CurveData::instance().append(s);
//    SignalData<CurveData>::getInstance().run();
//    SignalData<CurveData>::getInstance().append(s);
    m_curve0->values().append(s0);


//    qDebug() << s;

}

//void SamplingThread::setFrequency(double frequency)
//{
//    d_frequency = frequency;

//}

double SamplingThread::value( double timeStamp ) const
{
    double d_frequency = 5;
    double d_amplitude = 20;
    const double period = 1.0 / d_frequency;

    const double x = ::fmod( timeStamp, period );
    const double v = d_amplitude * qFastSin( x / period * 2 * M_PI );

    return v;
}


