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

#include "./headers/ReallyBigFunctionsThatYouDontNeedToSee.h"

#include "./headers/BinaryFunction.h"
#include "./headers/Node.h"
#include "./headers/Parser.h"
#include "./headers/InputNode.h"
#include "./headers/PrintNode.h"
#include "./headers/ReturNode.h"
#include "./headers/StartNode.h"
#include "./headers/CustomGraphicsView.h"
#include "./headers/CustomLayout.h"
#include "./headers/SearchBar.h"
#include "./headers/IfNode.h"
#include "./headers/ConditionNode.h"
#include "./headers/ElseNode.h"
#include "./headers/BodyNode.h"
#include "./headers/ForNode.h"
#include "./headers/IncrementNode.h"
#include "./headers/ForInicializeNode.h"
#include "./headers/WhileNode.h"
#include "./headers/VarNode.h"
#include "./headers/VectorNode.h"
#include "./headers/VectorOperations.h"
#include "./headers/VariableReferenceNode.h"
#include "./headers/StackNode.h"
#include "./headers/StackOperations.h"
#include "./headers/QueueNode.h"
#include "./headers/QueueOperations.h"
#include "./headers/EndOfStatement.h"
#include "./headers/FunctionWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Parser *p;

public:
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::MainWindow* getUi();
    Parser* getParser();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void putVar(QListWidgetItem* item);
    void functionAdded(QString FunctionName);
    void onPutNode(QListWidgetItem* item);

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionQuit_triggered();
    void on_actionRun_triggered();
    void filterFunctions();
    void on_AddFunction_clicked();
};
#endif // MAINWINDOW_H
