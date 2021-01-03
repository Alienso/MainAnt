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
#include <QPoint>
#include <QDebug>
#include <QList>
#include <QProcess>
#include <QApplication>
#include <fstream>
#include <string>
#include <iostream>

#include "./headers/ReallyBigFunctionsThatYouDontNeedToSee.h"

#include "./headers/Node.h"
#include "./headers/Parser.h"
#include "./headers/CustomGraphicsView.h"
#include "./headers/CustomLayout.h"
#include "./headers/SearchBar.h"
#include "./headers/FunctionWindow.h"
#include "./headers/ClassWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Parser *p;
    int funcId;
    int classId;
    QVector<ClassInstanceNode*> classInstances;
private:
    QString makeStringForFunction(QString met, QString ClassName);

public:
    QVector<QString> _classInicializedList;
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    QVector<QString> _inicializedVarsIds;
    Ui::MainWindow* getUi();
    Parser* getParser();
    int getFuncId();
    int getClassId();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void putClassInstance(QListWidgetItem* item);
    void putFunction(QListWidgetItem* item);
    void putVar(QListWidgetItem* item);
    void putReference(QListWidgetItem* item);
    void functionAdded(QString FunctionName);
    void onPutNode(QListWidgetItem* item);
    void onDeletedReferencedNode(QString name);
    void onDeletedStartNode(Node *start);
    void onVarNameEntered();
    void addVisibleInstances();
    void classAdded(QString ClassName, QVector<QString> publicMethods, QVector<QString> privateMethods, QVector<QString> protectedMethods,
    QVector<QString> publicAtr, QVector<QString> priavteAtr, QVector<QString> protectedAtr, QVector<QString> constructors);

private slots:
    void on_actionQuit_triggered();
    void on_actionRun_triggered();
    void on_actionRestart_triggered();
    void on_actionOpen_Code_triggered();
    void filterFunctions();
    void on_AddFunction_clicked();
    void on_AddClass_clicked();
    void on_actionCompile_triggered();
    void classAdded(QString ClassName, QString Methods, QString Variables);
    void on_actionFormat_Code_triggered();
    void onReadVariablesNames();
};
#endif // MAINWINDOW_H
