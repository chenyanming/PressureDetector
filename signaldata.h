#ifndef SIGNALDATA_H
#define SIGNALDATA_H
#include <QPointF>


// Singleton Pattern
class SignalData
{
public:
    static SignalData &instance();
    void append(const QPointF &sample);

    void lock();
    void unlock();

private:
    SignalData();
    SignalData(const SignalData &);
    virtual ~SignalData();

    class PrivateData;
    PrivateData *d_data;// Composition

};

#endif // SIGNALDATA_H
