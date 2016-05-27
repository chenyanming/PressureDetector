#include "plot.h"
#include "curvedata.h"
//#include "signaldata.h"
#include <qwt_plot_grid.h>

extern CurveData *m_curve0;

Plot::Plot(QWidget *parent):
    QwtPlot(parent),
    d_paintedPoints(0),
    d_interval(0.0, 10.0),
    d_timerId(-1)
{
    d_directPainter = new QwtPlotDirectPainter();

    setAutoReplot(false);

    setAxisTitle(QwtPlot::xBottom, "Time [s]");
    setAxisTitle(QwtPlot::yLeft, "y");
    setAxisScale(QwtPlot::xBottom, d_interval.minValue(), d_interval.maxValue());
    setAxisScale(QwtPlot::yLeft, -200.0, 200.0);

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setPen( Qt::gray, 0.0, Qt::DotLine );
    grid->enableX( true );
    grid->enableXMin( true );
    grid->enableY( true );
    grid->enableYMin( false );
    grid->attach( this );

    d_origin = new QwtPlotMarker();
    d_origin->setLineStyle( QwtPlotMarker::Cross );
    d_origin->setValue( d_interval.minValue() + d_interval.width() / 2.0, 0.0 );
    d_origin->setLinePen( Qt::gray, 0.0, Qt::DashLine );
    d_origin->attach( this );

    d_curve = new QwtPlotCurve();
    d_curve->setStyle(QwtPlotCurve::Lines);
    d_curve->setPen(QColor(0, 0, 255, 255), 2);
    d_curve->setData(m_curve0);
    d_curve->attach(this);

}

Plot::~Plot()
{
    delete d_directPainter;

}


void Plot::start()
{
    d_clock.start();
    d_timerId = startTimer(10); //in main(), we set the sampling interval time is 10ms

}

void Plot::replot()
{
    CurveData *data = static_cast<CurveData *>(d_curve->data());
    data->values().lock();

    QwtPlot::replot();
    d_paintedPoints = data->size();

    data->values().unlock();
}

void Plot::setIntervalLength( double interval )
{
    if ( interval > 0.0 && interval != d_interval.width() )
    {
        d_interval.setMaxValue( d_interval.minValue() + interval );
        setAxisScale( QwtPlot::xBottom,
            d_interval.minValue(), d_interval.maxValue() );

        replot();
    }
}

void Plot::updateCurve()
{
    CurveData *data = static_cast<CurveData *>(d_curve->data());
    data->values().lock();

    const int numPoints = data->size();
    if(numPoints > d_paintedPoints)
    {
        const bool doClip =!canvas()->testAttribute(Qt::WA_PaintOnScreen);
        if(doClip)
        {
            const QwtScaleMap xMap = canvasMap(d_curve->xAxis());
            const QwtScaleMap yMap = canvasMap(d_curve->yAxis());
            QRectF br = qwtBoundingRect(*data, d_paintedPoints - 1, numPoints - 1);
            const QRect clipRect = QwtScaleMap::transform(xMap, yMap, br).toRect();
            d_directPainter->setClipRegion(clipRect);
        }
        d_directPainter->drawSeries(d_curve, d_paintedPoints - 1, numPoints - 1);
        d_paintedPoints = numPoints;
    }
    data->values().unlock();

}

void Plot::incrementInterval()
{
    d_interval = QwtInterval(d_interval.maxValue(), d_interval.maxValue() + d_interval.width());
    CurveData *data = static_cast<CurveData *>(d_curve->data());
    data->values().clearStaleValues(d_interval.minValue());

    QwtScaleDiv scaleDiv = axisScaleDiv( QwtPlot::xBottom );
    scaleDiv.setInterval( d_interval );

    for ( int i = 0; i < QwtScaleDiv::NTickTypes; i++ )
    {
        QList<double> ticks = scaleDiv.ticks( i );
        for ( int j = 0; j < ticks.size(); j++ )
            ticks[j] += d_interval.width();
        scaleDiv.setTicks( i, ticks );
    }
    setAxisScaleDiv( QwtPlot::xBottom, scaleDiv );

    d_origin->setValue( d_interval.minValue() + d_interval.width() / 2.0, 0.0 );

    d_paintedPoints = 0;
    replot();

}




void Plot::timerEvent(QTimerEvent * event)
{
    if(event->timerId() == d_timerId)
    {
        updateCurve();
        const double elapsed = d_clock.elapsed() / 1000.0;
        if(elapsed > d_interval.maxValue())
            incrementInterval();
        return;
    }
    QwtPlot::timerEvent(event);
}

void Plot::resizeEvent( QResizeEvent *event )
{
    d_directPainter->reset();
    QwtPlot::resizeEvent( event );
}

void Plot::showEvent( QShowEvent * )
{
    replot();
}

bool Plot::eventFilter( QObject *object, QEvent *event )
{
    if ( object == canvas() &&
        event->type() == QEvent::PaletteChange )
    {
        d_curve->setPen( canvas()->palette().color( QPalette::WindowText ) );
    }

    return QwtPlot::eventFilter( object, event );
}
