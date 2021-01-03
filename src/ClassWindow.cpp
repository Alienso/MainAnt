#include "./headers/ClassWindow.h"
#include "ui_ClassWindow.h"

ClassWindow::ClassWindow(QWidget *parent, int classId) :
    QMainWindow(parent),
    ui(new Ui::ClassWindow),
    p(new Parser),
    classId(classId),
    methodCounter(0)

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

    connect(this, SIGNAL(classAdded(QString, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>)),
            this->parent(),
            SLOT(classAdded(QString, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>, QVector<QString>)));

}

ClassWindow::~ClassWindow()
{
    delete ui;
}

int ClassWindow::getClassId()
{
    return this->classId;
}

int ClassWindow::getMethodCounter()
{
    setMethodCounter();
    return this->methodCounter;
}

void ClassWindow::setMethodCounter()
{
    //posto brigu o idju metoda zapravo vodi klass node, pre svakog pristupa methodId promenljivi moramo pozvati ovu set metodu!
    int m = this->classNode->getMethodId();
    methodCounter = m;
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

void ClassWindow::fillAtributes()
{
    QVector<ClassField*> attributes = classNode->getAttributes();

    for(auto &atr : attributes){
       if(atr->fieldAccessModifiers->currentText() == "public"){
            publicAttributes.push_back(atr);
            publicAttrCodes.push_back(atr->getCodeForNode());
       }else if(atr->fieldAccessModifiers->currentText() == "private"){
            privateAttributes.push_back(atr);
            privateAttrCodes.push_back(atr->getCodeForNode());
       }else if(atr->fieldAccessModifiers->currentText() == "protected"){
            protectedAttributes.push_back(atr);
            protectedAttrCodes.push_back(atr->getCodeForNode());
       }
    }
}


void ClassWindow::methodAdded(QString MethodName)
{
    if(MethodName!=""){
        new QListWidgetItem(MethodName, ui->MethodView);
        qDebug()<<MethodName;
        auto methStr=MethodName.split(" ");
        if(methStr[0]=="public"){
            this->stringsFromMethodView.push_back("   "+MethodName);
            this->classNode->publicMethods.push_back("   "+MethodName);
        }else if(methStr[0] == "private"){
            this->privateMethods.push_back(" " + MethodName);
            this->classNode->privateMethods.push_back("   "+MethodName);
        }else if(methStr[0] == "protected"){
            this->protectedMethods.push_back(" " + MethodName);
            this->classNode->protectedMethods.push_back("   "+MethodName);
        }else if(methStr[0] == "constructor"){
            this->constructors.push_back(" " + MethodName);

        }
    }
}

void ClassWindow::on_actionSave_triggered()
{
    int classNum = this->getClassId();
    QString name = classNode->ClassName->text();
    fillAtributes();
    int methods = getMethodCounter();
    QString p1 = p->crateClassCode(name, classNum, methods,stringsFromMethodView, privateMethods, protectedMethods, publicAttributes, privateAttributes, protectedAttributes, constructors);
    if(p1.compare(QString::fromStdString("Fali")) == 0){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

    //Generate .mant
    emit classAdded(this->classNode->ClassName->text(),this->stringsFromMethodView, this->privateMethods, this->protectedMethods,
                    this->publicAttrCodes, this->privateAttrCodes, this->protectedAttrCodes, this->constructors);

    this->destroy();
}
