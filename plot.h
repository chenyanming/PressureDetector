#ifndef PLOT_H
#define PLOT_H

#include <qwt_plot.h>
#include <qwt_interval.h>
#include <qwt_system_clock.h>
#include <qwt_plot_curve.h>
#include <QTimerEvent>
#include <qwt_plot_directpainter.h>
#include <qwt_plot_marker.h>

class Plot : public QwtPlot
{
    Q_OBJECT

public:
    Plot(QWidget * = NULL);
    virtual ~Plot();

    void start();
    virtual void replot(); // need to define in cpp, if virtual
    virtual bool eventFilter(QObject *, QEvent *);

private:
    QwtInterval d_interval;
    int d_timerId;
    QwtSystemClock d_clock;

    QwtPlotCurve *d_curve;
    int d_paintedPoints;

    void updateCurve();
    void incrementInterval();

    QwtPlotDirectPainter *d_directPainter;

    QwtPlotMarker *d_origin;

protected:
    virtual void showEvent(QShowEvent *);
    virtual void timerEvent(QTimerEvent *);
    virtual void resizeEvent( QResizeEvent * );

public slots:
    void setIntervalLength(double);

};

#endif // PLOT_H
