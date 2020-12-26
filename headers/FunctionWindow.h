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
    QLineEdit* FunctionOrMethodName;
    QString title;
    int funcId;
    //samo za method
    QComboBox* comboMethod;

public:
    explicit FunctionWindow(QWidget *parent, QString title, int funcNum);
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::FunctionWindow* getUi();
    Parser* getParser();
    int getFuncId();
    ~FunctionWindow();
public slots:
    void putVar(QListWidgetItem* item);
signals:
    void functionAdded(QString FunctionName);
    void methodAdded(QString MethodName);

private slots:
    void filterFunctions();
    void onPutNode(QListWidgetItem* item);
    void on_actionSave_triggered();

};

#endif // FUNCTIONWINDOW_H
