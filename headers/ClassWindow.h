#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QMainWindow>
#include "headers/ReallyBigFunctionsThatYouDontNeedToSee.h"
#include "./headers/nodesHeaders/ClassNode.h"
#include "./headers/nodesHeaders/ClassField.h"

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
    int methodCounter;
    //Public metoddi klase
    QVector<QString> stringsFromMethodView;
    //private metodi klase
    QVector<QString> privateMethods;
    //protected methodi klase
    QVector<QString> protectedMethods;
    //Vektori u kojima se nalaze privatna i javna polja korisnicki definisanih klasa
    QVector<Node*> publicAttributes;
    QVector<Node*> privateAttributes;
    QVector<Node*> protectedAttributes;


public:
    explicit ClassWindow(QWidget *parent = nullptr, int classId=0);
    ~ClassWindow();
    int getClassId();
    int getMethodCounter();
    void setMethodCounter();
    QString methodsForMainWindow();
    QString variablesForMainWindow();
    void fillAtributes();

signals:
    void classAdded(QString ClassName, QString Methods, QString Variables);
public slots:
    void methodAdded(QString MethodName);
private slots:
    void on_actionSave_triggered();
};

#endif // CLASSWINDOW_H
