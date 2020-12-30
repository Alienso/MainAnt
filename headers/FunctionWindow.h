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
    explicit FunctionWindow(QWidget *parent, QString title, int funcNum, int classId, QVector<QString>& argAttr);
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::FunctionWindow* getUi();
    Parser* getParser();
    int getFuncId();
    ~FunctionWindow();

private:
    bool checkArrgument(QString argName);
public slots:
    void putVar(QListWidgetItem* item);
    void argAdded();
    void addReferenced(QListWidgetItem *item);
signals:
    void functionAdded(QString FunctionName);
    void methodAdded(QString MethodName);

private slots:
    void filterFunctions();
    void onPutNode(QListWidgetItem* item);
    void on_actionSave_triggered();

};

#endif // FUNCTIONWINDOW_H
