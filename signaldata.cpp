#include "signaldata.h"
#include <QVector>
#include <QRect>
#include <QMutex>
#include <QReadWriteLock>


class SignalData::PrivateData
{
public:
    PrivateData():
        boundingRect(1.0, 1.0, -2.0, -2.0)
    {
        values.reserve(1000);

    }

    inline void append(const QPointF &sample) // inline
    {
        values.append(sample);
        if (boundingRect.width() < 0 || boundingRect.height() < 0)
        {
            boundingRect.setRect(sample.x(), sample.y(), 0.0, 0.0);
        }
        else
        {
            boundingRect.setRight(sample.x());
            if (sample.y() > boundingRect.bottom())
                boundingRect.setBottom(sample.y());
            if (sample.y() < boundingRect.top())
                boundingRect.setTop(sample.y());
        }

    }


    QReadWriteLock lock;

    QVector<QPointF> values;
    QRectF boundingRect;

    QMutex mutex;
    QVector<QPointF> pendingValues;


};

SignalData::SignalData()
{
    d_data = new PrivateData();
}

SignalData::~SignalData()
{
    delete d_data;

}

void SignalData::lock()
{
    d_data->lock.lockForRead();
}

void SignalData::unlock()
{
    d_data->lock.unlock();
}


SignalData &SignalData::instance()
{
    static SignalData valueVector;
    return valueVector;
}

void SignalData::append(const QPointF &sample)
{
    d_data->mutex.lock();
    d_data->pendingValues += sample;

    const int isLocked = d_data->lock.tryLockForWrite();
    if (isLocked)
    {
        const int numValues = d_data->pendingValues.size();
        const QPointF *pendingValues = d_data->pendingValues.data();

        for( int i = 0; i < numValues; i++)
            d_data->append(pendingValues[i]);

        d_data->pendingValues.clear();
        d_data->lock.unlock();
    }

    d_data->mutex.unlock();

}
