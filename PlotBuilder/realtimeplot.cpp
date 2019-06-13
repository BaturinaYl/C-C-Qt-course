#include "realtimeplot.h"

RealTimePlot::RealTimePlot()
{
    counter = 0;

    painter = new QwtPlotDirectPainter(this);

    this->setAxisScale(QwtPlot::xBottom, -1, 1);

    this->setAxisScale(QwtPlot::yLeft, 0, 1);

    curve = new QwtPlotCurve("y(x)");

    curve->setStyle(QwtPlotCurve::NoCurve);

    curve->setData( new CurveData() );

    curve->setSymbol( new QwtSymbol(QwtSymbol::Ellipse,
    Qt::NoBrush,

    QPen(Qt::red), QSize(1, 1) ) );

    curvev->attach(this);

    setAutoReplot(false);
}


void appendDatePoint(const QPointF &point)
{
    counter +=point;

}

void RealTimePlot::timerHandle()
{
    QPointF newPoint = QPoint(this->x[this->counter],this->y[this->counter]);
    this->counter++;
    RealTimePlot::appendGraphPoint(newPoint);

}
void RealTmePlot:: appendGraphPoint(QPointF point)
{
    CurveData *data = staic_cast(curve->data());
    data->appendDataPoint(point);
    painter->drawSeries(curve, o, data->size() -1);

}
