#include "./headers/ClassWindow.h"
#include "ui_ClassWindow.h"

ClassWindow::ClassWindow(QWidget *parent, int classId) :
    QMainWindow(parent),
    ui(new Ui::ClassWindow),
    p(new Parser),
    classId(classId),
    methodId(0)

{
    ui->setupUi(this);

    setWindowTitle("ClassWindow");
    ui->StagingArea->setLayout(new CustomLayout(1));

    int classNum = this->getClassId();
    ClassNode* c = new ClassNode(classNum);
    ui->StagingArea->addWidget(c);
    p->addNode(c, new QString("ClassNode"));
    p->addNewClass(c);
    this->classNode=c;

    connect(this, SIGNAL(classAdded(QString, QString, QString)), this->parent(), SLOT(classAdded(QString, QString, QString)));

}

ClassWindow::~ClassWindow()
{
    delete ui;
}

int ClassWindow::getClassId()
{
    return this->classId;
}

int ClassWindow::getMethodId()
{
    return this->methodId;
}

QString ClassWindow::methodsForMainWindow()
{
    QString text="";
    for(auto str : this->stringsFromMethodView){
        text+=str;
        text+="\n";
    }
    return text;
}

QString ClassWindow::variablesForMainWindow()
{
    QString text="";
    for(auto fields : this->classNode->fields){
        QString varText=fields->getCodeForNode();
        if(varText!="" and fields->exist==true){
            auto varStr=varText.split(" ");
            if(varStr[0]=="public"){
                text+=this->classNode->ClassName->text();
                text+=":: ";
                text+=fields->getCodeForNode();
                text+="\n";}
        }
    }
    return text;
}

void ClassWindow::methodAdded(QString MethodName)
{
    if(MethodName!=""){
        new QListWidgetItem(MethodName, ui->MethodView);
        auto methStr=MethodName.split(" ");
        if(methStr[0]=="public"){
            this->stringsFromMethodView.push_back("   "+MethodName);
        }else if(methStr[0] == "private"){
            this->privateMethods.push_back(" " + MethodName);
        }else if(methStr[0] == "protected"){
            this->protectedMethods.push_back(" " + MethodName);
        }
    }
}

void ClassWindow::on_actionSave_triggered()
{
    int classNum = this->getClassId();
    QString name = classNode->ClassName->text();
    QString p1 = p->crateClassCode(name, classNum, stringsFromMethodView, privateMethods, protectedMethods);
    if(p1.compare(QString::fromStdString("Fali")) == 0){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

    //Generate .mant
    emit classAdded(this->classNode->ClassName->text(), this->methodsForMainWindow(), this->variablesForMainWindow());

    this->destroy();
}
