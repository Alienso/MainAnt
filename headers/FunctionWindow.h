#ifndef FUNCTIONWINDOW_H
#define FUNCTIONWINDOW_H

#include "./headers/ReallyBigFunctionsThatYouDontNeedToSee.h"
#include "./headers/nodesHeaders/ReferenceNode.h"

namespace Ui {
class FunctionWindow;
}

class FunctionWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::FunctionWindow *ui;
    Parser *p;
    //QLineEdit* FunctionOrMethodName;
    QString title;
    int funcId;
    int classId;
    //samo za method
    QComboBox* comboMethod;
    //POtrebno za slanje informacija mainwindowu, setuju se u konstruktoru
    FunctionNode* func;
    MethodNode* method;
    QVector<QString> argInList;

public:
    QVector<QString> _classInicializedList;
    explicit FunctionWindow(QWidget *parent, QString title, int funcNum, int classId, QVector<QString>& argAttr, QString metAndFunc="");
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    QVector<QString> _inicializedVarsIds;
    Ui::FunctionWindow* getUi();
    Parser* getParser();
    int getFuncId();
    ~FunctionWindow();

private:
    bool checkArrgument(QString argName);
public slots:
    void putVar(QListWidgetItem* item);
    void argAdded();
    void argAddedMethodNode();
    void addReferenced(QListWidgetItem *item);
    void onDeletedReferencedNode(QString name);
    void onDeletedStartNode(Node *start);
    void onVarNameEntered();
signals:
    void functionAdded(QString FunctionName);
    void methodAdded(QString MethodName);

private slots:
    void filterFunctions();
    void onPutNode(QListWidgetItem* item);
    void on_actionSave_triggered();
    void deleteArgumentFromList(QString nameOfArgumen);
    void onReadVariablesNames();
public slots:
    void putFunction(QListWidgetItem *item);

};

#endif // FUNCTIONWINDOW_H
