#include "./headers/FunctionWindow.h"
#include "ui_FunctionWindow.h"

FunctionWindow::FunctionWindow(QWidget *parent, QString title, int funcNum) :
    QMainWindow(parent)
  ,ui(new Ui::FunctionWindow)
  ,p(new Parser)
  ,funcId(funcNum)
{
    ui->setupUi(this);

    this->title=title;
    setWindowTitle(this->title);

    functionsListInit(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&FunctionWindow::filterFunctions);
    connect(ui->listVars, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putVar(QListWidgetItem*)));
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));

    if(this->title=="FunctionWindow"){
        FunctionNode* funct = new FunctionNode();
        this->func = funct;
        ui->StagingArea->addWidget(funct);
        p->addNode(funct, new QString("FunctionNode"));
        p->addNewFunction(funct);
        this->FunctionOrMethodName=funct->FunctionName;

        FunctionReturnNode* ret = new FunctionReturnNode();
        ui->StagingArea->addWidget(ret);
        p->addNode(ret, new QString("FunctionRteurnNode"));

        connect(this, SIGNAL(functionAdded(QString, int, QVector<QString>, QVector<QString>, QString)), this->parent(), SLOT(functionAdded(QString, int, QVector<QString>, QVector<QString>, QString)));
    }
    else{
        MethodNode* met = new MethodNode();
        this->method = met;
        ui->StagingArea->addWidget(method);
        p->addNode(method, new QString("MethodNode"));
        //p->addNewFunction(method);
        this->FunctionOrMethodName=method->MethodName;
        this->comboMethod=method->comboMethod;

        FunctionReturnNode* ret = new FunctionReturnNode();
        ui->StagingArea->addWidget(ret);
        p->addNode(ret, new QString("FunctionRteurnNode"));


        connect(this, SIGNAL(methodAdded(QString)), this->parent(), SLOT(methodAdded(QString)));
    }
}

FunctionWindow::~FunctionWindow()
{
    delete ui;
}

void FunctionWindow::putVar(QListWidgetItem *item)
{
    for(int i =0; i<_inicializedVars.size(); i++)
    {
        if(_inicializedVars[i] == item){
            VariableReferenceNode* n = new VariableReferenceNode(item->text());
            ui->StagingArea->addWidget(n);
            p->addNode(n, new QString("VariableReferenceNode"));
        }
    }
}


void FunctionWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this);
}

void FunctionWindow::on_actionSave_triggered()
{
    //Generate cpp
    int funcNum = getFuncId();
    QString p1 = p->createFunctionCode(funcNum);
    if(p1.compare(QString::fromStdString("Fali")) == 0){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

    //Generate .mant
    p->createFunctionBlueprint(ui->StagingArea->getNodes(), funcNum);
    if(this->title=="FunctionWindow"){
        QVector<QString> argNames;
        QVector<QString> argTypes;
        int n = this->func->getArgNum();
        for(int i=0; i<n; i++){
            argNames.push_back(this->func->argumentsNames[i]->text());
            argTypes.push_back(this->func->argumentsTypes[i]->currentText());
        }
        QString retVal = this->func->getRetVal();

        emit functionAdded(this->FunctionOrMethodName->text(), n, argNames, argTypes, retVal);
    }
    else{
       // this->comboMethod->currentText()+" "
        emit methodAdded(this->FunctionOrMethodName->text());
    }
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

int FunctionWindow::getFuncId()
{
    return this->funcId;
}
