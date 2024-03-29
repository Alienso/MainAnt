#include "./headers/FunctionWindow.h"
#include "ui_FunctionWindow.h"

FunctionWindow::FunctionWindow(QWidget *parent, QString title, int funcNum, int classId, QVector<QString>& argAttr, QString metAndFunc) :
    QMainWindow(parent)
  ,ui(new Ui::FunctionWindow)
  ,p(new Parser)
  ,funcId(funcNum)
  ,classId(classId)
  ,argInList({})
{
    ui->setupUi(this);

    this->title=title;
    setWindowTitle(this->title);

    functionsListInit(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onPutNode(QListWidgetItem*)));
    connect(ui->searchBar,&QLineEdit::textChanged,this,&FunctionWindow::filterFunctions);
    connect(ui->listVars, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putVar(QListWidgetItem*)));
    connect(ui->attributesArgumentsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(addReferenced(QListWidgetItem*)));
    connect(ui->readVarNames, SIGNAL(clicked()), this, SLOT(onReadVariablesNames(void)));
    connect(ui->MethodsFunctionsView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(putFunction(QListWidgetItem*)));
    //connect(ui->horizontalLayout_2->, SIGNAL(), this, SLOT(on_actionRun_triggered()));
    ui->StagingArea->setLayout(new CustomLayout(1));

    if(this->title=="FunctionWindow"){
        FunctionNode* funct = new FunctionNode();
        this->func = funct;
        ui->StagingArea->addWidget(funct);
        p->addNode(funct, new QString("FunctionNode"));
        p->addNewFunction(funct);

        FunctionReturnNode* ret = new FunctionReturnNode();
        ui->StagingArea->addWidget(ret);
        p->addNode(ret, new QString("FunctionRteurnNode"));
        ret->move(650,0);
        ret->setOldPos(QPoint(650,0));

        connect(this, SIGNAL(functionAdded(QString)), this->parent(), SLOT(functionAdded(QString)));
        connect(this->func->addToVisible, SIGNAL(clicked()), this, SLOT(argAdded()));

        if(metAndFunc!=""){
            QList<QString> things=metAndFunc.split("\n");
            for(auto thing: things){
                new QListWidgetItem(thing, ui->MethodsFunctionsView);
            }
        }

    }
    else{
        int n= argAttr.size();
        for(int i=0; i<n;i++){
            new QListWidgetItem(argAttr[i], ui->attributesArgumentsList);
        }

        MethodNode* met = new MethodNode();
        this->method = met;
        ui->StagingArea->addWidget(method);
        p->addNode(method, new QString("MethodNode"));
        p->addMethod(met);
        this->comboMethod=method->comboMethod;

        FunctionReturnNode* ret = new FunctionReturnNode();
        ui->StagingArea->addWidget(ret);
        p->addNode(ret, new QString("FunctionRteurnNode"));
        ret->move(650,0);
        ret->setOldPos(QPoint(650,0));


        connect(this, SIGNAL(methodAdded(QString)), this->parent(), SLOT(methodAdded(QString)));
        connect(this->method->addToVisible, SIGNAL(clicked()), this, SLOT(argAddedMethodNode()));

        if(metAndFunc!=""){
            QList<QString> things=metAndFunc.split("\n");
            for(auto thing: things){
                thing = thing.trimmed();
                QStringList list= thing.split(" ");
                QString code ="";
                for(int i =1; i<list.size(); i++){
                    code+=list[i];
                    code+=" ";
                }
                code = code.trimmed();
                new QListWidgetItem(code, ui->MethodsFunctionsView);

            }
        }
    }
}

FunctionWindow::~FunctionWindow()
{
    delete ui;
}

bool FunctionWindow::checkArrgument(QString argName)
{
    //Proveravmo da li se ovaj argumen vec nalazi u listi argumenata
    for(auto arg : argInList){
        if(argName.compare(arg) == 0){
            return true;
        }
    }
    return false;
}

void FunctionWindow::putVar(QListWidgetItem *item)
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

void FunctionWindow::argAdded()
{
    //int num = func->getArgNum();
    for(auto arg : func->argumentsNames){
        QString argName = arg->text();
        bool alreadyIn = checkArrgument(argName);
        if(!alreadyIn){
            argInList.push_back(argName);
            new QListWidgetItem(argName, ui->attributesArgumentsList);
        }
    }
}

void FunctionWindow::argAddedMethodNode()
{
    for(auto arg : method->argumentsNames){
        QString argName = arg->text();
        bool alreadyIn = checkArrgument(argName);
        if(!alreadyIn){
            argInList.push_back(argName);
            new QListWidgetItem(argName, ui->attributesArgumentsList);
        }
    }
}

void FunctionWindow::addReferenced(QListWidgetItem *item)
{
    ReferenceNode *rf=new ReferenceNode(item->text());
    ui->StagingArea->addWidget(rf);
    p->addNode(rf, new QString("RefNode"));
}


void FunctionWindow::onPutNode(QListWidgetItem* item){
    putNode(item,this);
}

void FunctionWindow::on_actionSave_triggered()
{
    //Generate cpp
    if(this->title == "FunctionWindow"){
        int funcNum = getFuncId();
        QString p1 = p->createFunctionCode(funcNum);
        if(p1.compare(QString::fromStdString("Fali")) == 0){
            qDebug() << "Fail";
        }
        else
            qDebug() << p1;
    }else{
        int methodId = getFuncId();
        QString p1 = p->createMethodCode(classId,methodId);
        if(p1.compare(QString::fromStdString("Fali")) == 0){
            qDebug() << "Fail";
        }
        else
            qDebug() << p1;
    }


    //Generate .mant
    p->createFunctionBlueprint(ui->StagingArea->getNodes(), funcId);
    if(this->title=="FunctionWindow"){
        QVector<QString> argNames;
        QVector<QString> argTypes;
        int n = this->func->getArgNum();
        for(int i=0; i<n; i++){
            argNames.push_back(this->func->argumentsNames[i]->text());
            argTypes.push_back(this->func->argumentsTypes[i]->currentText());
        }
        QString retVal = this->func->getRetVal();

        emit functionAdded(this->func->getCodeForNode());
    }
    else{
        emit methodAdded(this->method->getCodeForNode());
    }
    this->destroy();
}

void FunctionWindow::deleteArgumentFromList(QString nameOfArgumen)
{
    //brisemo iz polja
    for(int i = 0; i < ui->attributesArgumentsList->count(); i++){
        if(ui->attributesArgumentsList->item(i)->text()==nameOfArgumen){
            QListWidgetItem* item = ui->attributesArgumentsList->item(i);
            delete item;
        }
    }
    //brisemo iz liste argInList
    int i=0;
    for(auto arg : this->argInList){
        if(arg==nameOfArgumen){
            this->argInList.remove(i);
        }
        i++;
    }
}

void FunctionWindow::onReadVariablesNames()
{
    auto graphScene = this->p->getGraphScene();
    for(int i = 0; i<this->_inicializedVars.length(); i++)
    {
        qDebug() << this->_inicializedVarsIds[i];
        Node* reference = graphScene[this->_inicializedVarsIds[i]];
        this->_inicializedVars[i]->setText(reference->getVarName());
    }
}


void FunctionWindow::filterFunctions(){

    ui->listWidget->clear();
    for (int i=0;i<_functionList.length();i++)
        if (this->_functionList[i].text().contains(ui->searchBar->text(),Qt::CaseInsensitive))
            ui->listWidget->addItem(_functionList[i].text());
}
void FunctionWindow::onDeletedReferencedNode(QString name)
{
    for(int i = 0; i < ui->listVars->count(); i++){
        if(ui->listVars->item(i)->text()==name){
            QListWidgetItem* item = ui->listVars->item(i);
            delete item;
        }
    }
}

void FunctionWindow::onDeletedStartNode(Node *start)
{
    p->removeStart(start);
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

void FunctionWindow::putFunction(QListWidgetItem *item)
{
    QString funcDeclaration = item->text();
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
            //ako i+2 nije ) onda  je to , pa mozemo da ga preskocimo
            i +=3;
        }
    }

    FuncReferenceNode* n = new FuncReferenceNode(retVal, funcName, funcTypes, funcNames);
    ui->StagingArea->addWidget(n);
    p->addNode(n, new QString("FuncReferenceNode"));
}

void FunctionWindow::onVarNameEntered(){
    for(Node* n : *ui->StagingArea->getNodes()){
        for(QListWidgetItem* i : _inicializedVars){
            if (i->text().compare(n->getNodeId())==0){
                i->setText(n->getVarName());
                return;
            }
        }
    }
}
