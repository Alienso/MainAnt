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
    ClassNode *classNode;
    Parser *p;
    int classId;
    int methodId;
    //Public metoddi klase
    QVector<QString> stringsFromMethodView;
    //private metodi klase
    QVector<QString> privateMethods;
    //protected methodi klase
    QVector<QString> protectedMethods;
public:
    explicit ClassWindow(QWidget *parent = nullptr, int classId=0);
    ~ClassWindow();
    int getClassId();
    int getMethodId();
    QString methodsForMainWindow();
    QString variablesForMainWindow();
signals:
    void classAdded(QString ClassName, QString Methods, QString Variables);
public slots:
    void methodAdded(QString MethodName);
private slots:
    void on_actionSave_triggered();
};

#endif // CLASSWINDOW_H
