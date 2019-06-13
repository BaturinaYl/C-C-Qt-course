#include "keypress.h"

#include <QApplication>
#include <QKeyEvent>

KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent)
{
    myLabel = new QLabel("LABEL");
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(myLabel);
    setLayout(mainLayout);

}




void KeyPress::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
       y = y -0.1;

        //myLabel->setText("Go Up!");
    }

    if(event->key() == Qt::Key_Down)
    {
        y = y +0.1;
        //myLabel->setText("Go Down!");
    }

    if(event->key() == Qt::Key_Left)
    {
        x = x-0.1
        //myLabel->setText("Go Left!");
    }

    if(event->key() == Qt::Key_Right)
    {
        x = x +0.1;
        //myLabel->setText("Go Right!");
    }

    QPointF newPoint = QPoint(this->x[this->counter],this->y[this->counter]);
    this->counter++;
    RealTimePlot::appendGraphPoint(newPoint);
}

void KeyPress::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        myLabel->setText("Go Up!");
    }

    if(event->key() == Qt::Key_Down)
    {
        myLabel->setText("Go Down!");
    }

    if(event->key() == Qt::Key_Left)
    {
        myLabel->setText("Go Left!");
    }

    if(event->key() == Qt::Key_Right)
    {
        myLabel->setText("Go Right!");
    }
}
