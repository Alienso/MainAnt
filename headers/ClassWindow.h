#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QMainWindow>

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
};

#endif // CLASSWINDOW_H
