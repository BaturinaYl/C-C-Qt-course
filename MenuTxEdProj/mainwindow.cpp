#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QSettings>
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

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", "", "*.cpp *.h" );
    ui->lbName->setText(filename);

    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream stream (&file);
    QString line = stream.readAll();

    file.close();
    ui->edFile->setText(line);
    txtCh = false;
}
//----------------------------------------------------------
void MainWindow::on_actionSave_triggered()
{
    QString filename =QFileDialog::getSaveFileName(this, tr("Сохранение файла"), QDir::currentPath() );
    ui->lbName->setText(filename);

    QFile file(filename);

        file.open(QIODevice::WriteOnly |QIODevice::Text);
        QTextStream out(&file);
        out << ui->edFile->toPlainText();
        file.close();
    txtCh = false;
}
//---------------------------------------------------------------------
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
//--------------------------------------------------------------------
void MainWindow::on_actionNew_triggered()
{

    if(txtCh)
    {
        // предложить сохраниться
    QMessageBox::StandardButton replay = QMessageBox::question(this,"Сохраниение файла",
                                         "Файл был изменен. Сохранить изменения?",QMessageBox::Yes |
                                           QMessageBox::No);
    if(replay ==QMessageBox::Yes) MainWindow::on_actionSave_triggered();

    }
    ui->lbName->setText("Безымянный");
    ui->edFile->clear();
    ui->edFile->setFocus();

}
//--------------------------------------------------------------------
void MainWindow::on_edFile_textChanged()
{
    txtCh = true;
}
//---------------------------------------------------------------------
void MainWindow::on_actionRecent_triggered()
{
    for (int i = 0; i < MaxRecentFiles; ++i) {
            recentFileActs[i] = new QAction(this);
            recentFileActs[i]->setVisible(false);
            connect(recentFileActs[i], SIGNAL(triggered()),
                    this, SLOT(openRecentFile()));
        }
}
//-----------------------------------------------------------------------
void MainWindow::openRecentFile(){ // открытие недавнего файла - пусть будет
    QAction *action = qobject_cast<QAction *>(sender());
    if (action){
        loadFile(action->data().toString());
    }
}
//-------------------------------------------------------------------------

void MainWindow::updateRecentFileActions(){ // обновить недавние файлы
    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);

    separatorAct->setVisible(numRecentFiles > 0);
}
//-------------------------------------------------------------------------
void MainWindow::setCurrentFile(const QString &fileName){ // сделать текущим файлом
    curFile = fileName;
    setWindowFilePath(curFile);

    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    settings.setValue("recentFileList", files);

    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin)
            mainWin->updateRecentFileActions();
    }
}
//------------------------------------------------------------------------
void MainWindow::loadFile(const QString &fileName){ // Загрузка файла
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Graph"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->edFile->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

//    lineText->setPlainText(fileName);
    ui->lbName->setText(fileName); // путь в lineText
    //doubArr = file.readAll();

    setCurrentFile(fileName); // название файла
    statusBar()->showMessage(tr("File loaded"), 5000); // на 5 сек выводим "File loaded"
}
//----------------------------------------------------------------------------------------
QString MainWindow::strippedName(const QString &fullFileName){
    return QFileInfo(fullFileName).fileName();
}
