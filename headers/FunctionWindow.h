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

public:
    explicit FunctionWindow(QWidget *parent = nullptr);
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::FunctionWindow* getUi();
    Parser* getParser();
    ~FunctionWindow();

private slots:
    void filterFunctions();
    //void on_actionSave_Function_triggered();
    void on_actionAddFunction_triggered();
public slots:
    void onPutNode(QListWidgetItem* item);
};

#endif // FUNCTIONWINDOW_H
