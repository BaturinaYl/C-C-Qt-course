#include "mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QtGui>
#include "keypress.h"
#include <qwt_plot>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_directpainter.h>
#include <qwt_series_data.h>
#include <QPointF>
#include <scrollzoomer.h>
#include <scrollBar.h>
#include "realtimeplot.h"

double x = 0;
double y = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;

    KeyPress *keyPress = new KeyPress();
        keyPress->show();
        timer =new QTimer(this);
        plot = new RealTimePlot();
        this ->setCentralWidget(plot);
        connect(timer, SIGNAL(timeout(),plot,SLOT(timerHandle()));
        timer->start(25);


  //  w.show();

    return a.exec();
}
