#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QtGui>
#include <QtCore>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <./headers/Node.h>
#include "../headers/InputNode.h"
#include "../headers/PrintNode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void putNode(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;

private slots:
    //void on_listWidget_itemDoubleClicked(QListWidgetItem *item);


    void on_actionOpen_triggered();
    void on_actionSave_triggered();
};
#endif // MAINWINDOW_H
