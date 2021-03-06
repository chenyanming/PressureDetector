#ifndef SAMPLINGTHREAD_H
#define SAMPLINGTHREAD_H

#include <qwt_sampling_thread.h>
#include <qwt_series_data.h>

class SamplingThread : public QwtSamplingThread
{
    //Q_OBJECT

public:
    SamplingThread(QObject *parent = NULL);

//public slots:
//    void setFrequency(double);

protected:
    virtual void sample(double elapsed); // sample is pure virtual, in milliseconds

private:
    virtual double value(double timeStamp) const;
//    double d_frequency;
	std::vector<double> sum;

};

#endif // SAMPLINGTHREAD_H
