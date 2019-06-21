#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtTest/QTest>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Base(){

    int t0[9];
      for (int i = 0; i < 9; i++)
        t0[i]= i+1;
    int n = 0;
        for(int i = 0; i < 9; i++)
            maintab[n][i] = t0[i];

    int t1[9];
          for (int i=0; i<3; i++)
            t1[i+6]=t0[i];
          for (int j = 0; j<6; j++)
            t1[j] = t0[j+3];
          n++;
          for(int i = 0; i < 9; i++)
             maintab[n][i] = t1[i];
    int t2[9];
          for (int i=0; i<3; i++)
            t2[i+6]=t1[i];
            for (int j = 0; j<6; j++)
               t2[j] = t1[j+3];
            n++;
            for(int i = 0; i < 9; i++)
               maintab[n][i] = t2[i];

    int t3[9];
      int tmp = t0[0];
        for (int i = 0; i < 8; i++)
              t3[i]= t0[i+1];
        t3[8] = tmp;
        n++;
        for(int i = 0; i < 9; i++)
           maintab[n][i] = t3[i];
    int t4[9];
        for (int i=0; i<3; i++)
           t4[i+6]=t3[i];
        for (int j = 0; j<6; j++)
           t4[j] = t3[j+3];
        n++;
        for(int i = 0; i < 9; i++)
           maintab[n][i] = t4[i];
    int t5[9];
            for (int i=0; i<3; i++)
               t5[i+6]=t4[i];
            for (int j = 0; j<6; j++)
               t5[j] = t4[j+3];
            n++;
            for(int i = 0; i < 9; i++)
               maintab[n][i] = t5[i];

    int t6[9];
       tmp = t3[0];
        for (int i = 0; i < 8; i++)
           t6[i]= t3[i+1];
        t6[8] = tmp;
        n++;
        for(int i = 0; i < 9; i++)
           maintab[n][i] = t6[i];

   int t7[9];
             for (int i=0; i<3; i++)
                 t7[i+6]=t6[i];
             for (int j = 0; j<6; j++)
                 t7[j] = t6[j+3];
             n++;
             for(int i = 0; i < 9; i++)
                maintab[n][i] = t7[i];
   int t8[9];
     for (int i=0; i<3; i++)
         t8[i+6]=t7[i];
         for (int j = 0; j<6; j++)
           t8[j] = t7[j+3];
         n++;
         for(int i = 0; i < 9; i++)
            maintab[n][i] = t8[i];

}
void MainWindow::Tranc(){
    //транспонирование нач. формы trantab[i][j] = maintab[j][i];


        for(int i = 0; i <9; i++){
            for(int j = 0; j<9; j++)
                trantab[i][j] = maintab[j][i];
        }
}
void MainWindow::SwapRow(){
    //обмен 2-х строк в пределах одного района swrowtab[][]

    int  row = 0;
    for(int i = 0; i < 9; i++){

         switch (i){
             case 0: row = 2;break;
             case 1: row = 1;break;
             case 2: row = 0; break;
             case 3: row = 5;break;
             case 4: row = 4;break;
             case 5: row = 3;break;
             case 6: row = 8;break;
             case 7: row = 7;break;
             case 8: row = 6;break;
         }
         for(int j = 0; j<9; j++){
           swrowtab[i][j] = trantab[row][j];
      }
    }
}
void MainWindow::SwapCol(){
    //обмен 2-х столб в пределах одного района swcoltab[][]

    int  col = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9; j++){
         switch (j){
             case 0: col = 2;break;
             case 1: col = 1;break;
             case 2: col = 0; break;
             case 3: col = 5;break;
             case 4: col = 4;break;
             case 5: col = 3;break;
             case 6: col = 8;break;
             case 7: col = 7;break;
             case 8: col = 6;break;
         }

           swcoltab[i][j] = swrowtab[i][col];
      }
    }
}
void MainWindow::SwapHz(){
    //обмен 2-х районов по гориз. swhztab[][]

    int  row = 0;
    for(int i = 0; i < 9; i++){

         switch (i){
             case 0: row = 3;break;
             case 1: row = 4;break;
             case 2: row = 5; break;
             case 3: row = 0;break;
             case 4: row = 1;break;
             case 5: row = 2;break;
             case 6: row = 6;break;
             case 7: row = 7;break;
             case 8: row = 8;break;
         }
         for(int j = 0; j<9; j++){
           swhztab[i][j] = swcoltab[row][j];
      }
    }
}
void MainWindow::SwapVt(){
    //обмен 2-х районов по вертикале swvttab[][]

    int  col = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9; j++){
         switch (j){
             case 0: col = 0;break;
             case 1: col = 1;break;
             case 2: col = 2; break;
             case 3: col = 6;break;
             case 4: col = 7;break;
             case 5: col = 8;break;
             case 6: col = 3;break;
             case 7: col = 4;break;
             case 8: col = 5;break;
         }

           swvttab[i][j] = swhztab[i][col];
      }
    }
}


//------------------------------------------------------------------
void MainWindow::on_tbW_7_cellChanged(int row, int column)
{
 last_row = row;
 last_column = column;
  //  ui->tbW_7->item(row,column)->setFont(QFont("Times", 14));
   /*QTableWidgetItem *item = new QTableWidgetItem();
item = ui->tbW_7->item(row, column);
   QString str = item->text();

    ui->lb->setText(str);*/
}
//-------------------------------------------------------------------
void MainWindow::on_pbOk_clicked()
{
    int emp;  // количество пустых ячеек от 4 до 7
    int num;  // номер ячейки в строке для очистки

    Base();
    Tranc();
    SwapRow();
    SwapCol();
    SwapHz();
    SwapVt();



    srand(time(NULL));

    for(int k = 0; k < 9; k++){
       for (int l =0;l<9;l++){
           QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
           item->setText(QString("%1").arg(swvttab[k][l])); // вставляем текст
           ui->tbW_7->setItem(k, l, item); // вставляем ячейку
           ui->tbW_7->item(k,l)->setBackgroundColor(Qt::yellow);
           ui->tbW_7->item(k,l)->setFont(QFont("Times", 12));
           ui->tbW_7->item(k,l)->setTextColor(Qt::blue);
           ui->tbW_7->item(k,l)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
           ui->tbW_7->item(k,l)->setFlags(item->flags());//& (~Qt::ItemIsEditable));
       }
    }

        for (int m = 0; m < 9; m++){
            emp = 0 + rand()%3;
            emp = emp + 3; // количество пустых ячеек в данном ряду

            for (int i = 0; i < emp; i++){

                for(;;){
                     //QTest::qWait(30);
                     num = 0 + rand()%9;
                     QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
                     item = ui->tbW_7->item(m,num);
                     QString str = item->text();
                     if (str==QString("")) break;
                     else {
                         QTableWidgetItem *item1 = new QTableWidgetItem();
                         item1->setText (QString(""));
                         ui->tbW_7->setItem(m,num, item1);
                          ui->tbW_7->item(m,num)->setBackgroundColor(Qt::white);
                          ui->tbW_7->item(m,num)->setFont(QFont("Times", 16));
                         // ui->tbW_7->item(m,num)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                        //  ui->tbW_7->item(m,num)->setFlags( Qt::ItemIsEditable);
                     }
                }

            }
      }
}
//----------------------------------------------------------------------------------

void MainWindow::on_tbW_7_cellEntered(int row, int column)
{   
}
//--------------------------------------------------------------------------------
void MainWindow::on_pbLast_clicked()
{
       QTableWidgetItem *item1 = new QTableWidgetItem();
       item1 = ui->tbW_7->item(last_row, last_column);
       QString str = item1->text();
       if (str != QString::number(swvttab[last_row][last_column])){
          QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
          item->setText(QString("%1").arg(swvttab[last_row][last_column])); // вставляем текст
          ui->tbW_7->setItem(last_row, last_column, item); // вставляем ячейку
          ui->tbW_7->item(last_row,last_column)->setBackgroundColor(Qt::white);
          ui->tbW_7->item(last_row,last_column)->setFont(QFont("Times", 12));
          ui->tbW_7->item(last_row,last_column)->setTextColor(Qt::red);
          ui->tbW_7->item(last_row,last_column)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
          ui->tbW_7->item(last_row,last_column)->setFlags(item->flags());
       }
}
//--------------------------------------------------------------------------------------
void MainWindow::on_pbCheck_all_clicked()
{
   for (int i=0; i<9; i++){
       for (int j=0; j<9; j++){
           QTableWidgetItem *item1 = new QTableWidgetItem();
           item1 = ui->tbW_7->item(i, j);
           QString str = item1->text();
           if (str != QString::number(swvttab[i][j])){
              QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
              item->setText(QString("%1").arg(swvttab[i][j])); // вставляем текст
              ui->tbW_7->setItem(i, j, item); // вставляем ячейку
              ui->tbW_7->item(i,j)->setBackgroundColor(Qt::white);
              ui->tbW_7->item(i,j)->setFont(QFont("Times", 12));
              ui->tbW_7->item(i,j)->setTextColor(Qt::red);
              ui->tbW_7->item(i,j)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
              ui->tbW_7->item(i,j)->setFlags(item->flags());
           }
       }
   }
}
//-------------------------------------------------------------------------------------
