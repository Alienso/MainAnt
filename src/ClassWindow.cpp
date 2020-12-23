#include "./headers/ClassWindow.h"
#include "ui_ClassWindow.h"

ClassWindow::ClassWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClassWindow),
    p(new Parser)
{
    ui->setupUi(this);

    setWindowTitle("ClassWindow");
    ui->StagingArea->setLayout(new CustomLayout(1));

    ClassNode* c = new ClassNode();
    ui->StagingArea->addWidget(c);
    p->addNode(c, new QString("ClassNode"));
    //p->addNewFunction(c);
    this->ClassName=c->ClassName;
}

ClassWindow::~ClassWindow()
{
    delete ui;
}
