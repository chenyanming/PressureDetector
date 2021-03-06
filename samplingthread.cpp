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
#include "data.h"
extern CurveData *m_curve0;
extern CurveData *m_curve1;
extern CurveData *m_curve2;
extern CurveData *m_curve3;
extern CurveData *m_curve4;

//extern double serialRev0;
//extern double serialRev1;
//extern double serialRev2;
//extern double serialRev3;

SamplingThread::SamplingThread(QObject *parent):
    QwtSamplingThread(parent)
{

}

void SamplingThread::sample(double elapsed)
{
//    const QPointF s(elapsed, value(elapsed));
    //const QPointF s0(elapsed, serialRev0);
    //const QPointF s1(elapsed, serialRev1);
    //const QPointF s2(elapsed, serialRev2);
    //const QPointF s3(elapsed, serialRev3);

	const QPointF s0(elapsed, Data::getInstance().PressData.serialRev0);
	const QPointF s1(elapsed, Data::getInstance().PressData.serialRev1);
	const QPointF s2(elapsed, Data::getInstance().PressData.serialRev2);
	const QPointF s3(elapsed, Data::getInstance().PressData.serialRev3);

//    CurveData::instance().append(s);
//    SignalData<CurveData>::getInstance().run();
//    SignalData<CurveData>::getInstance().append(s);
    m_curve0->values().append(s0);
    m_curve1->values().append(s1);
    m_curve2->values().append(s2);
    m_curve3->values().append(s3);

	// standev
	sum.push_back(s0.y() + s1.y() + s2.y() + s3.y());
	static int index = 0;
	if (sum.size() >= 100) {
		//qDebug() << sum;
		double mean = std::accumulate(sum.begin()+index, sum.begin()+index+99, 0.0) / 100;
		std::vector<double> diff(sum.size());
		std::transform(sum.begin()+index, sum.begin()+index+99, diff.begin(), [mean](double x) { return x - mean; });
		double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
		double stdev = std::sqrt(sq_sum / 100);
		// energy expenditure
		Data::getInstance().PressData.ev = 0.282423 + stdev * 0.00044;
		index++;
		//qDebug() << ev;
	}
	
	// line 5: energy expenditure
	const QPointF s4(elapsed, Data::getInstance().PressData.ev);
    m_curve4->values().append(s4);

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


