#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QSlider>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     bool txtCh = false;
     void openRecentFile();
     void updateRecentFileActions();
     void setCurrentFile(const QString &fileName);
     void loadFile(const QString &fileName);

     QString strippedName(const QString &fullFileName);
         QSlider *slider;

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionNew_triggered();

    void on_edFile_textChanged();

    void on_actionRecent_triggered();

private:
    Ui::MainWindow *ui;
    enum { MaxRecentFiles = 5 };
    QAction *recentFileActs[MaxRecentFiles];
    QStringList recentFiles;
    QString curFile;
    QAction *separatorAct;

};

#endif // MAINWINDOW_H
