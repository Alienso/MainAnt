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

private slots:
    void filterFunctions();
    void onPutNode(QListWidgetItem* item);
    void on_actionSave_Function_triggered();

};

#endif // FUNCTIONWINDOW_H
