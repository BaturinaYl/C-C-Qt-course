#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    num = ui->slNum->value();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------
void MainWindow::on_slNum_valueChanged(int value)
{
   ui->lbNum->setText(QString::number(value));
   num = ui->slNum->value();
}
//----------------------------------------------

void MainWindow::on_rbFile_clicked(bool checked)
{
    ui->slNum->hide();

    if (checked){
    QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", "", "*.txt *.*" );
        varrX.clear();
        varrY.clear();
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QTextStream stream (&file);
        int n = -1;
        while (!stream.atEnd()){
              QStringList  list = stream.readLine().split(" ");
              if (list.empty())
                  continue;
              QChar ch =list.takeFirst().at(0);
              n++;
              foreach (const QString & s, list){
                   marr.insertMulti(n,s.toDouble());
                   varrY.insert(varrY.end(), s.toDouble());
                   varrX.insert(varrX.end(),n);
              }
        }

        file.close();
        num = n;
        ui->lbNum->setText(QString::number(num));
    }    

    double minY = varrY[0], maxY = varrY[0];
    for (int i = 1; i < varrY.count()-1; i++)
    {
        if (varrY[i] < minY) minY = varrY[i];
        if (varrY[i] > maxY) maxY = varrY[i];
    }
    ui->sbXto->setMaximum(varrX.last());
    ui->sbXfrom->setMinimum(varrX.first());
    ui->sbYfrom->setValue(minY);
    ui->sbYto->setValue(maxY);

    ui->sbXto->setValue(varrX.last());
    ui->sbXfrom->setValue(varrX.first());

    ui->sbYto->setValue(maxY);
    ui->sbYfrom->setValue(minY);


}
//------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{

        double b = ui->sbXto->value(); //Начало интервала, где рисуем график по оси Ox
        double a = ui->sbXfrom->value(); //Конец интервала, где рисуем график по оси Ox

           ui->widget->clearGraphs();//Если нужно, но очищаем все графики
           //Добавляем один график в widget
           ui->widget->addGraph();

           //Говорим, что отрисовать нужно график по нашим двум массивам x и y
           ui->widget->graph(0)->setData(varrX, varrY);

           //Установим область, которая будет показываться на графике
           ui->widget->xAxis->setRange(a, b);//Для оси Ox

           //Для показа границ по оси Oy сложнее, так как надо по правильному
           //вычислить минимальное и максимальное значение в векторах
            double minY = varrY[a], maxY = varrY[a];
           for (int i = a + 1; i < b; i++)
           {
               if (varrY[i] < minY) minY = varrY[i];
               if (varrY[i] > maxY) maxY = varrY[i];
           }
           ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy
           ui->sbYfrom->setValue(minY);
           ui->sbYto->setValue(maxY );

           //Подписываем оси Ox и Oy
           ui->widget->xAxis->setLabel("x");
           ui->widget->yAxis->setLabel("y");
           //Создаем легенду
           QString str = "";
           str = "Min ="+QString ::number(minY)+", Max = "+QString ::number(maxY);
           ui->widget->graph(0)->setName(str);
          // ui->widget->legend->clear();
           ui->widget->legend->setVisible(true);
           QPen p1 (Qt::green);
           ui->widget->legend->setBorderPen(p1);
           ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop);//Qt::AlignLeft|Qt::AlignBottom);

           //И перерисуем график на нашем widget
           ui->widget->replot();
}
//----------------------------------------------------------------------------------------------
void MainWindow::on_radioButton_3_clicked(bool checked)
{
    ui->slNum->setVisible(true);

    if (checked){
        num = ui->slNum->value();
        varrX.clear();
        varrY.clear();

           double h = (2 * 3.14)/ num;

           for (int i = 0; i<num; i++){
                varrY.insert(varrY.end(), sin(i*h));
                varrX.insert(varrX.end(),i);
           }


    double minY = varrY[0], maxY = varrY[0];
    for (int i = 1; i < varrY.count()-1; i++)
    {
        if (varrY[i] < minY) minY = varrY[i];
        if (varrY[i] > maxY) maxY = varrY[i];
    }

    ui->sbXto->setMaximum(varrX.last());
    ui->sbXfrom->setMinimum(varrX.first());
    ui->sbYfrom->setValue(minY);
    ui->sbYto->setValue(maxY);



    ui->sbXto->setValue(varrX.last());
    ui->sbXfrom->setValue(varrX.first());

    ui->sbYto->setValue(maxY);
    ui->sbYfrom->setValue(minY);


    }
}
//------------------------------------------------------------
void MainWindow::on_rbSqr_clicked(bool checked)
{
    ui->slNum->setVisible(true);

    if (checked){

         num = ui->slNum->value();
         varrX.clear();
         varrY.clear();


           for (int i = 0; i<num; i++){
                varrY.insert(varrY.end(), i*i);
                varrX.insert(varrX.end(),i);
           }


    double minY = varrY[0], maxY = varrY[0];
    for (int i = 1; i < varrY.count()-1; i++)
    {
        if (varrY[i] < minY) minY = varrY[i];
        if (varrY[i] > maxY) maxY = varrY[i];
    }
    ui->sbXto->setValue(varrX.last());
    ui->sbXfrom->setValue(varrX.first());

    ui->sbYto->setValue(maxY);
    ui->sbYfrom->setValue(minY);

    ui->sbXto->setMaximum(varrX.last());
    ui->sbXfrom->setMinimum(varrX.first());
    ui->sbYfrom->setValue(minY);
    ui->sbYto->setValue(maxY);
    }
}

