#include "samplingthread.h"
#include <QPoint>
#include "signaldata.h"
//#include <QtMath>
#include <qwt_math.h>
#include <math.h>


SamplingThread::SamplingThread(QObject *parent):
    QwtSamplingThread(parent)
{

}

void SamplingThread::sample(double elapsed)
{
//    const QPointF s(elapsed, value(elapsed));
    const QPointF s(elapsed, 10);
    SignalData::instance().append(s);

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


