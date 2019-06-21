#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pb_clicked();

    void on_pbTranc_clicked();

    void on_pushButton_clicked();

    void on_pbswcol_clicked();

    void on_pbswhz_clicked();

    void on_pbswvt_clicked();

    void on_tbW_7_cellChanged(int row, int column);

    void on_pbOk_clicked();

    void on_tbW_7_cellEntered(int row, int column);

    void on_pbLast_clicked();

    void on_pbCheck_all_clicked();

private:
    Ui::MainWindow *ui;
    void Base();
    void Tranc();
    void SwapRow();
    void SwapCol();
    void SwapHz();
    void SwapVt();

    int maintab[9][9];
    int trantab[9][9];
    int swrowtab[9][9];
    int swcoltab[9][9];
    int swhztab[9][9];
    int swvttab[9][9];
    int last_row;
    int last_column;
};

#endif // MAINWINDOW_H
