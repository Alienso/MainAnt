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

    ClassNode* c = new ClassNode();
    ui->StagingArea->addWidget(c);
    p->addNode(c, new QString("ClassNode"));
    //p->addNewFunction(c);
    this->ClassName=c->ClassName;

    connect(this, SIGNAL(classAdded(QString)), this->parent(), SLOT(classAdded(QString)));

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

void ClassWindow::methodAdded(QString MethodName)
{
    if(MethodName!=""){
        new QListWidgetItem(MethodName, ui->MethodView);}
}

void ClassWindow::on_actionSave_triggered()
{
    int classNum = this->getClassId();
    int methodNum = this->getMethodId();
    QString p1 = p->createMethodCode(classNum, methodNum);
    if(p1.compare(QString::fromStdString("Fali")) == 0){
        qDebug() << "Fail";
    }
    else
        qDebug() << p1;

    //Generate .mant
    emit classAdded(this->ClassName->text());

    this->destroy();
}
