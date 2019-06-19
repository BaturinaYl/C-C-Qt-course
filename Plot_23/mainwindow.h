#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_slNum_valueChanged(int value);

    void on_rbFile_clicked(bool checked);

    void on_pushButton_clicked();

    void on_radioButton_3_clicked(bool checked);

    void on_rbSqr_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int num = 0;
  //     double h;
    QMap<int,double>marr;
    QVector <double> varrY;
    QVector <double> varrX;
};

#endif // MAINWINDOW_H
