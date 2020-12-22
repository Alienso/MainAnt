#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QMainWindow>
#include "headers/ReallyBigFunctionsThatYouDontNeedToSee.h"
#include "./headers/ClassNode.h"

namespace Ui {
class ClassWindow;
}

class ClassWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClassWindow(QWidget *parent = nullptr);
    ~ClassWindow();

private:
    Ui::ClassWindow *ui;
    QLineEdit* ClassName;
    Parser *p;

};

#endif // CLASSWINDOW_H
