#include "samplingthread.h"
#include <QPoint>
#include "signaldata.h"

int FirFrequency;

SamplingThread::SamplingThread(QObject *parent):
    QwtSamplingThread(parent)
{

}

void SamplingThread::sample(double elapsed)
{
    const QPointF s(elapsed, double(FirFrequency));
    SignalData::instance().append(s);

}

void SamplingThread::setFrequency(double frequency)
{
    d_frequency = frequency;

}



