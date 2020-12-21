#include "./headers/FunctionWindow.h"
#include "ui_FunctionWindow.h"

FunctionWindow::FunctionWindow(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::FunctionWindow)
  ,p(new Parser)
{
    ui->setupUi(this);

    setWindowTitle("FunctionWindow");

    functionsListInit(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&FunctionWindow::filterFunctions);
    connect(this, SIGNAL(functionAdded(QString)), this->parent(), SLOT(functionAdded(QString)));
    connect(ui->listVars, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putVar(QListWidgetItem*)));
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));

    FunctionNode* funct = new FunctionNode();
    ui->StagingArea->addWidget(funct);
    p->addNode(funct, new QString("FunctionNode"));
    p->addNewFunction(funct);
    this->FunctionName=funct->FunctionName;

    FunctionReturnNode* ret = new FunctionReturnNode();
    ui->StagingArea->addWidget(ret);
    p->addNode(ret, new QString("FunctionRteurnNode"));

}

FunctionWindow::~FunctionWindow()
{
    delete ui;
}


void FunctionWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this);
}

void FunctionWindow::on_actionSave_Function_triggered()
{
    //Generate cpp
    QString p1 = p->createFunctionCode();
    if(p1.compare(QString::fromStdString("Fali")) == 0){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

    //Generate .mant
    p->createFunctionBlueprint(ui->StagingArea->getNodes());
    emit functionAdded(this->FunctionName->text());
    this->destroy();
}


void FunctionWindow::filterFunctions(){

    ui->listWidget->clear();
    for (int i=0;i<_functionList.length();i++)
        if (this->_functionList[i].text().contains(ui->searchBar->text(),Qt::CaseInsensitive))
            ui->listWidget->addItem(_functionList[i].text());
}



Ui::FunctionWindow* FunctionWindow::getUi(){
    return ui;
}
Parser* FunctionWindow::getParser(){
    return p;
}
