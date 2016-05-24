#ifndef SIGNALDATA_H
#define SIGNALDATA_H
#include <QPointF>
#include <QRect>

// Singleton Pattern
class SignalData
{
public:
    static SignalData &instance();
    void append(const QPointF &pos);
    void clearStaleValues(double min);

    int size() const;
    QPointF value(int index) const;
    QRectF boundingRect() const;

    void lock();
    void unlock();

private:
    // big three
    SignalData();
    SignalData(const SignalData &);
    SignalData &operator=(const SignalData &);
    virtual ~SignalData();

    class PrivateData;
    PrivateData *d_data;// Composition

};

#endif // SIGNALDATA_H
