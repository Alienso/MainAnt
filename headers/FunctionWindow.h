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
    //samo za method
    QComboBox* comboMethod;

public:
    explicit FunctionWindow(QWidget *parent, QString title);
    QVector<QListWidgetItem> _functionList;
    QVector<QListWidgetItem*> _inicializedVars;
    Ui::FunctionWindow* getUi();
    Parser* getParser();
    ~FunctionWindow();
signals:
    void functionAdded(QString FunctionName);
    void methodAdded(QString MethodName);

private slots:
    void filterFunctions();
    void onPutNode(QListWidgetItem* item);
    void on_actionSave_triggered();

};

#endif // FUNCTIONWINDOW_H
