#include "./headers/FunctionWindow.h"
#include "ui_FunctionWindow.h"

FunctionWindow::FunctionWindow(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::FunctionWindow)
  ,p(new Parser)
{
    ui->setupUi(this);

    setWindowTitle("FunctionWindow");

    functionsListInit(this,"func");

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&FunctionWindow::filterFunctions);
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));
}

FunctionWindow::~FunctionWindow()
{
    delete ui;
}

/*
void FunctionWindow::on_actionSave_Function_triggered()
{
    QString p1 = p->createFunction();
    if(p1 == QString::fromStdString("Fali")){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;
}*/


void FunctionWindow::filterFunctions(){

    ui->listWidget->clear();
    for (int i=0;i<_functionList.length();i++)
        if (this->_functionList[i].text().contains(ui->searchBar->text(),Qt::CaseInsensitive))
            ui->listWidget->addItem(_functionList[i].text());
}

void FunctionWindow::on_actionAddFunction_triggered()
{
    QString p1 = p->createFunction();
    if(p1 == QString::fromStdString("Fali")){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;
}

void FunctionWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this,"");
}

Ui::FunctionWindow* FunctionWindow::getUi(){
    return ui;
}

Parser* FunctionWindow::getParser(){
    return p;
}

