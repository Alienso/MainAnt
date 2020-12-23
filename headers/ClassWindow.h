#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QMainWindow>
#include "headers/ReallyBigFunctionsThatYouDontNeedToSee.h"
#include "./headers/nodesHeaders/ClassNode.h"

namespace Ui {
class ClassWindow;
}

class ClassWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::ClassWindow *ui;
    QLineEdit* ClassName;
    Parser *p;
    int classId;
    int methodId;

public:
    explicit ClassWindow(QWidget *parent = nullptr, int classId=0);
    ~ClassWindow();
    int getClassId();
    int getMethodId();
signals:
    void classAdded(QString ClassName);
public slots:
    void methodAdded(QString MethodName);

private slots:
    void on_actionSave_triggered();
};

#endif // CLASSWINDOW_H
