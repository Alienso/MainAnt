#ifndef FUNCTIONWINDOW_H
#define FUNCTIONWINDOW_H

#include "./headers/ReallyBigFunctionsThatYouDontNeedToSee.h"

namespace Ui {
class FunctionWindow;
}

class FunctionWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::FunctionWindow *ui;
    Parser *p;
    void functionsListInit();
    QLineEdit* FunctionName;

public:
    explicit FunctionWindow(QWidget *parent);
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::FunctionWindow* getUi();
    Parser* getParser();
    ~FunctionWindow();
signals:
    void functionAdded(QString FunctionName);
public slots:
    void putNode(QListWidgetItem* item);

private slots:
    void filterFunctions();
    void on_actionSave_Function_triggered();

private slots:
    void filterFunctions();
    //void on_actionSave_Function_triggered();
    void on_actionAddFunction_triggered();
public slots:
    void onPutNode(QListWidgetItem* item);
};

#endif // FUNCTIONWINDOW_H
