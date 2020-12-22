#include "./headers/ClassWindow.h"
#include "ui_ClassWindow.h"

ClassWindow::ClassWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClassWindow)
{
    ui->setupUi(this);
}

ClassWindow::~ClassWindow()
{
    delete ui;
}
