#include "./headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , p(new Parser)
    , funcId(0)
    ,classId(0)
    ,classInstances({})
{
    ui->setupUi(this);
    setWindowTitle(":)");
    setWindowIcon(QIcon("./icon.ico")); //TODO program se izvrsava iz foldera buildmainant...

    functionsListInit(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->listVars, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putVar(QListWidgetItem*)));
    connect(ui->FunctionView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putFunction(QListWidgetItem*)));
    connect(ui->ClassView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putClassInstance(QListWidgetItem*)));
    connect(ui->VariablesView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putReference(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&MainWindow::filterFunctions);
    connect(ui->readVarNames, SIGNAL(clicked()), this, SLOT(onReadVariablesNames(void)));
    connect(ui->VisibleInstances, SIGNAL(clicked()), this, SLOT(addVisibleInstances(void)));


    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));
    filterFunctions(); //Zove se da bi sortirao listu node-ova

    StartNode* n = new StartNode();
    ui->StagingArea->addWidget(n);
    p->addNode(n, new QString("StartNode"));
    p->addNewStart(n);

    ReturnNode* r = new ReturnNode();
    ui->StagingArea->addWidget(r);
    p->addNode(r, new QString("ReturnNode"));
    p->setHeader("cstdio");
    r->move(550,0);
    r->setOldPos(QPoint(550,0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::putClassInstance(QListWidgetItem *item)
{
    QString construct = item->text();
    //qDebug()<<construct;
    if(construct.contains(":")){
        //to je red sa nazivom klase na to necemo da reagujemo
        return;
    }
    construct = construct.trimmed();
    QStringList list = construct.split(QRegExp("\\s+"));
    //qDebug()<<list;
    QString ClassName = list[0];
    QVector<QString> argNames = {"flow"};
    QVector<QString> argTypes = {" "};
    if(list.size() == 3){
        qDebug()<<"Here";
        //znaci da konstruktor nema argumenata
        ClassInstanceNode* n = new ClassInstanceNode(ClassName, argTypes, argNames);
        this->classInstances.push_back(n);
        ui->StagingArea->addWidget(n);
        p->addNode(n, new QString("ClassInstanceNode"));
        return;
    }else{
        int i =2;
        while(true){
            argTypes.push_back(list[i]);
            argNames.push_back(list[i+1]);

            if(list[i+2].compare(")") == 0){
                break;
            }
            //ako i+2 nije ) onda  je to , pa mozemo da ga prekocmo
            i +=3;
        }
    }
    ClassInstanceNode* n = new ClassInstanceNode(ClassName, argTypes, argNames);
    this->classInstances.push_back(n);
    ui->StagingArea->addWidget(n);
    p->addNode(n, new QString("ClassInstanceNode"));
}

void MainWindow::putFunction(QListWidgetItem *item)
{
    QString funcDeclaration = item->text();
    if(funcDeclaration.compare("private:") ==0 || funcDeclaration.compare("protected:") == 0 || funcDeclaration.compare("public:") == 0){
        return;
    }
    qDebug()<<"'OK";
    funcDeclaration = funcDeclaration.trimmed();
    QStringList list = funcDeclaration.split(QRegExp("\\s+"));

    QString retVal = list[0];
    QString funcName = list[1];
    //qDebug()<<funcName;

    QVector<QString> funcTypes = {" ",};
    QVector<QString> funcNames = {"flow"};

    int listSize = list.size();
    //qDebug()<<list;
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
            VariableReferenceNode* n = new VariableReferenceNode(item->text(), this->_inicializedVarsIds[i]);
            ui->StagingArea->addWidget(n);
            p->addNode(n, new QString("VariableReferenceNode"));
        }
    }
}

void MainWindow::putReference(QListWidgetItem *item)
{
    QString instance = item->text();
    instance = instance.trimmed();
    QStringList list = instance.split(QRegExp("\\s+"));

    QString varName = list[1];
    VariableReferenceNode* n = new VariableReferenceNode(varName, varName);
    ui->StagingArea->addWidget(n);
    p->addNode(n, new QString("VariableReferenceNode"));

}

void MainWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this);
}

void MainWindow::onDeletedReferencedNode(QString name)
{
    for(int i = 0; i < ui->listVars->count(); i++){
        if(this->_inicializedVarsIds[i] == name){
            QListWidgetItem* item = ui->listVars->item(i);
            delete item;
            this->_inicializedVarsIds.remove(i);
            this->_inicializedVars.remove(i);
        }
    }
}

void MainWindow::onDeletedStartNode(Node *start)
{
    p->removeStart(start);
}

void MainWindow::classAdded(QString ClassName, QVector<QString> publicMethods, QVector<QString> privateMethods, QVector<QString> protectedMethods,
                            QVector<QString> publicAtr, QVector<QString> priavteAtr, QVector<QString> protectedAtr,
                            QVector<QString> constructors)
{
    this->p->setHeader((ClassName + ".hpp").toUtf8().constData());
    this->_classInicializedList.push_back(ClassName);
    new QListWidgetItem(ClassName + ":", ui->ClassView);
    new QListWidgetItem("constructors: ", ui->ClassView);
    for(auto con : constructors){
        QStringList list = con.split(" ");
        QString code = "";
        for(int i = 3; i<list.size(); i++){
            code+=list[i];
            code+=" ";
        }
        new QListWidgetItem("\t" + code, ui->ClassView);
    }

    //FunctionView
    if(publicMethods.size() != 0){
        new QListWidgetItem("public: ", ui->FunctionView);
        for(auto met : publicMethods){
            QString out = makeStringForFunction(met, ClassName);
            new QListWidgetItem(out, ui->FunctionView);
        }
    }
    if(privateMethods.size() != 0){
        new QListWidgetItem("private: ", ui->FunctionView);
        for(auto met : privateMethods){
            QString out = makeStringForFunction(met, ClassName);
            new QListWidgetItem(out, ui->FunctionView);
        }
    }
    if(protectedMethods.size() != 0){
        new QListWidgetItem("protected: ", ui->FunctionView);
        for(auto met : protectedMethods){
            QString out = makeStringForFunction(met, ClassName);
            new QListWidgetItem(out, ui->FunctionView);
        }
    }

    //Class Attributes
    new QListWidgetItem("attributes: ", ui->ClassView);
    if(publicAtr.size() != 0){
        new QListWidgetItem("public: ", ui->ClassView);
        for(auto atr : publicAtr){
            new QListWidgetItem(atr, ui->ClassView);
        }
    }
    if(priavteAtr.size() != 0){
        new QListWidgetItem("private: ", ui->ClassView);
        for(auto atr : priavteAtr){
            new QListWidgetItem(atr, ui->ClassView);
        }
    }
    if(protectedAtr.size() != 0){
        new QListWidgetItem("proteceted: ", ui->ClassView);
        for(auto atr : protectedAtr){
            new QListWidgetItem(atr, ui->ClassView);
        }
    }
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

    //za prozor Methods and Functions
    QString metAndFunc="";
    for(int i = 0; i < ui->ClassView->count(); i++){
        QListWidgetItem* item = ui->ClassView->item(i);
        metAndFunc.append(item->text());
        metAndFunc.append("\n");
    }

    for(int i = 0; i < ui->FunctionView->count(); i++){
        QListWidgetItem* item = ui->FunctionView->item(i);
        metAndFunc.append(item->text());
        metAndFunc.append("\n");
    }
//Potrebno za poziv konstruktora FunctionWindow-a
QVector<QString> definedAttributes ={};
FunctionWindow *f=new FunctionWindow(this, "FunctionWindow", funcNum, 0, definedAttributes, metAndFunc);
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

QString MainWindow::makeStringForFunction(QString met, QString ClassName)
{
    met = met.trimmed();
    QStringList list = met.split(" ");
    //qDebug()<<list;
    QString code = "";
    for(int i = 2; i<list.size(); i++){
        code+=list[i];
        code+= " ";
    }
    QString out = list[1] + " ";
    out+=ClassName;
    out+= "::";
    out+=code;
    return out;
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
    // qDebug()<<"+Class";
    int classNum = getClassId();
    ClassWindow *c=new ClassWindow(this, classNum);
    QMessageBox msgBox;
    msgBox.setText("If you want your class to be saved you need to enter the name for the class. Class name must be one string either one word, or more words combined witn _.To save the changes you have made chose 'Build->Save'.");
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

void MainWindow::on_actionFormat_Code_triggered()
{
    QString fileTmp = QDir::currentPath();
    int i=fileTmp.lastIndexOf('/');
    QStringRef fileTmp2(&fileTmp, 0, i+1);
    QString file=fileTmp2.toUtf8()+"mainAntCode.cpp";
    QString fileFormat = fileTmp2.toUtf8()+"mainAntCodeFormat.cpp";

    std::ifstream currentFile;
    std::ofstream formatedFile;

    currentFile.open(file.toUtf8().constData());
    formatedFile.open(fileFormat.toUtf8().constData());

    if(currentFile.is_open() && formatedFile.is_open())
    {
        std::string format = "";
        std::string tmp;
        while(std::getline(currentFile, tmp)){
            if(tmp.find('}') != std::string::npos && tmp.find('{') == std::string::npos)
                format.pop_back();
            formatedFile << format << tmp <<"\n";
            if(tmp.find('{') != std::string::npos && tmp.find('}') == std::string::npos)
                format+="\t";
        }
        currentFile.close();
        formatedFile.close();
    }
}

void MainWindow::onVarNameEntered(){
    for(Node* n : *ui->StagingArea->getNodes()){
        for(QListWidgetItem* i : _inicializedVars){
            if (i->text().compare(n->getNodeId())==0){
                i->setText(n->getVarName());
                return;
            }
        }
    }
}

void MainWindow::addVisibleInstances()
{
    //Brisem sve sto je pisalo u View
    for(int i = 0; i < ui->VariablesView->count(); i++){
       QListWidgetItem* item = ui->listVars->item(i);
       delete item;

    }

    //Dodajem samo vidljive intance
    for(const auto &inst : this->classInstances){
        if(inst->visible){
            QString name = inst->instanceName->text();
            QString className = inst->getClassName();
            new QListWidgetItem(className + ":: " + name, ui->VariablesView);
        }
    }
}

void MainWindow::onReadVariablesNames()
{
    auto graphScene = this->p->getGraphScene();
    for(int i = 0; i<this->_inicializedVars.length(); i++)
    {
        qDebug() << this->_inicializedVarsIds[i];
        Node* reference = graphScene[this->_inicializedVarsIds[i]];
        this->_inicializedVars[i]->setText(reference->getVarName());
    }
}
