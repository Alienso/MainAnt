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

#include "./headers/ReallyBigFunctionsThatYouDontNeedToSee.h"

#include "./headers/nodesHeaders/BinaryFunction.h"
#include "./headers/Node.h"
#include "./headers/Parser.h"
#include "./headers/nodesHeaders/InputNode.h"
#include "./headers/nodesHeaders/PrintNode.h"
#include "./headers/nodesHeaders/ReturNode.h"
#include "./headers/nodesHeaders/StartNode.h"
#include "./headers/CustomGraphicsView.h"
#include "./headers/CustomLayout.h"
#include "./headers/SearchBar.h"
#include "./headers/nodesHeaders/IfNode.h"
#include "./headers/nodesHeaders/ConditionNode.h"
#include "./headers/nodesHeaders/ElseNode.h"
#include "./headers/nodesHeaders/BodyNode.h"
#include "./headers/nodesHeaders/ForNode.h"
#include "./headers/nodesHeaders/IncrementNode.h"
#include "./headers/nodesHeaders/ForInicializeNode.h"
#include "./headers/nodesHeaders/WhileNode.h"
#include "./headers/nodesHeaders/VarNode.h"
#include "./headers/nodesHeaders/VectorNode.h"
#include "./headers/nodesHeaders/VectorOperations.h"
#include "./headers/nodesHeaders/VariableReferenceNode.h"
#include "./headers/nodesHeaders/StackNode.h"
#include "./headers/nodesHeaders/StackOperations.h"
#include "./headers/nodesHeaders/QueueNode.h"
#include "./headers/nodesHeaders/QueueOperations.h"
#include "./headers/nodesHeaders/EndOfStatement.h"
#include "./headers/FunctionWindow.h"
#include "./headers/ClassWindow.h"
#include "./headers//nodesHeaders/AssignNode.h"

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

public:
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::MainWindow* getUi();
    Parser* getParser();
    int getFuncId();
    int getClassId();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void putFunction(QListWidgetItem* item);
    void putVar(QListWidgetItem* item);
    void functionAdded(QString FunctionName);
    void onPutNode(QListWidgetItem* item);
    void onDeletedReferencedNode(QString name);

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
};
#endif // MAINWINDOW_H
