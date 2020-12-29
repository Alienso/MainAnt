#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , p(new Parser)
    , funcId(0)
    ,classId(0)
{
    ui->setupUi(this);
    setWindowTitle(":)");
    setWindowIcon(QIcon("./icon.ico")); //TODO program se izvrsava iz foldera buildmainant...

    functionsListInit(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->listVars, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putVar(QListWidgetItem*)));
    connect(ui->FunctionView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putFunction(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&MainWindow::filterFunctions);
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));
    filterFunctions(); //Zove se da bi sortirao listu node-ova

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putFunction(QListWidgetItem *item)
{
    QString funcDeclaration = item->text();
    QStringList list = funcDeclaration.split(QRegExp("\\s+"));

    QString retVal = list[0];
    QString funcName = list[1];

    QVector<QString> funcTypes = {" ",};
    QVector<QString> funcNames = {"flow"};

    int listSize = list.size();
    qDebug()<<list;
    if(listSize == 4){
        FuncReferenceNode* n = new FuncReferenceNode(retVal, funcName, funcTypes, funcNames);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("FuncReferenceNode"));
        return;
    }else{
        int i =3;
        while(true){
            funcTypes.push_back(list[i]);
            funcNames.push_back(list[i+1]);

            if(list[i+2].compare(")") == 0){
                break;
            }
            //ako i+2 nije ) onda  je to , pa mozemo da ga prekocmo
            i +=3;
        }
    }

    FuncReferenceNode* n = new FuncReferenceNode(retVal, funcName, funcTypes, funcNames);
    ui->StagingArea->addWidget(n);
    p->addNode(n, new QString("FuncReferenceNode"));
    \
}

void MainWindow::putVar(QListWidgetItem *item)
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

void MainWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this);
}

void MainWindow::on_actionRestart_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::on_actionOpen_Code_triggered()
{
    QProcess process;
    QString fileTmp = QDir::currentPath();
    int i=fileTmp.lastIndexOf('/');
    QStringRef fileTmp2(&fileTmp, 0, i+1);
    QString file=fileTmp2.toUtf8()+"mainAntCode.cpp";

    if(QFile::exists(file)){
        QDesktopServices::openUrl(QUrl(file));
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Can't find mainAntCode.cpp file. Make sure you first Compile or Run your program.");
        msgBox.exec();
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionRun_triggered()
{
    int funcNum = this->getFuncId();
    QString p1 = p->compileAndRun(funcNum);
    if(p1 == QString::fromStdString("Fali")){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

}

void MainWindow::filterFunctions(){

    ui->listWidget->clear();
    for (int i=0;i<_functionList.length();i++)
        if (this->_functionList[i].text().contains(ui->searchBar->text(),Qt::CaseInsensitive))
            ui->listWidget->addItem(_functionList[i].text());
}


void MainWindow::on_AddFunction_clicked()
{
    this->funcId = this->funcId +1;
    int funcNum = this->getFuncId();
    FunctionWindow *f=new FunctionWindow(this, "FunctionWindow", funcNum, 0);
    QMessageBox msgBox;
    msgBox.setText("To save the changes you have made chose 'Build->Save'.");
    f->show();
    msgBox.exec();
}

void MainWindow::functionAdded(QString FunctionName)
{
    if(FunctionName!=""){
        new QListWidgetItem(FunctionName, ui->FunctionView);
    }
}

Ui::MainWindow* MainWindow::getUi(){
    return ui;
}

Parser* MainWindow::getParser(){
    return p;
}

int MainWindow::getFuncId()
{
    return this->funcId;
}

int MainWindow::getClassId()
{
    return this->classId;
}

void MainWindow::on_AddClass_clicked()
{
    qDebug()<<"+Class";
    int classNum = getClassId();
    ClassWindow *c=new ClassWindow(this, classNum);
    QMessageBox msgBox;
    msgBox.setText("If you want you class to be saved you nedd to enter the name. Class name most be one string either one word, or more words combined witn _.To save the changes you have made chose 'Build->Save'.");
    c->show();
    msgBox.exec();
}
void MainWindow::classAdded(QString ClassName, QString Methods, QString Variables)
{
    if(ClassName!=""){
        new QListWidgetItem(ClassName, ui->ClassView);
        if(Methods!=""){
            new QListWidgetItem(Methods, ui->ClassView);
        }
        if(Variables!=""){
            new QListWidgetItem(Variables, ui->VariablesView);
        }
    }
}

void MainWindow::on_actionCompile_triggered()
{
    int funNum = this->getFuncId();
    qDebug()<<p->compile(funNum);
}
