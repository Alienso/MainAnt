#include "./headers/nodesHeaders/ClassNode.h"

ClassNode::ClassNode(int classNum) : Node("Class", 1, 0), methodId(0), classId(classNum)
{
    setMinimumSize(150,125);
    setMaximumWidth(300);
    setStyleSheet ("background-color: rgba(255, 187, 0, 1);"
                   "border: 1px solid rgba(127, 40, 254, 1);"
                   "border-radius:5px;");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    setColors({'q'});

    this->addMethod=new QPushButton("+method");
    this->addVariable=new QPushButton("+variable");

    this->ClassName = new QLineEdit();
    const QString* placeHolderClassName = new QString("Enter class name...");
    this->ClassName->setPlaceholderText(*placeHolderClassName);

    layout->addWidget(this->ClassName, 3, 0);
    layout->addWidget(this->addMethod, 4, 0);
    layout->addWidget(this->addVariable, 5, 0);

    connect(this->addMethod, SIGNAL(clicked()), this, SLOT(addMethodSlot(void)));
    connect(this->addVariable, SIGNAL(clicked()), this, SLOT(addFieldSlot(void)));
}

int ClassNode::getMethodId()
{
    return this->methodId;
}

QString ClassNode::getCodeForNode(){
    QString text="class " + this->ClassName->text() + "{\n";
    return text;
}

void ClassNode::addMethodSlot()
{
    methodId+=1;
    fillDefinedAttributes();
    //za prozor Methods and Functions view
    QString metAndFunc="";
    for(auto met : this->publicMethods){
        metAndFunc.append(met);
        metAndFunc.append("\n");
    }

    for(auto met : this->privateMethods){
        metAndFunc.append(met);
        metAndFunc.append("\n");
    }

    for(auto met : this->protectedMethods){
        metAndFunc.append(met);
        metAndFunc.append("\n");
    }

    FunctionWindow *m=new FunctionWindow(qobject_cast<QWidget*>(this->parent()->parent()->parent()), "MethodWidnow", methodId, classId, definedAttributes, metAndFunc);
    QMessageBox msgBox;
    msgBox.setText("To save the changes you have made chose 'Build->Save'.");
    m->show();
    msgBox.exec();
}

void ClassNode::addFieldSlot()
{
    ClassField* field = new ClassField();
    this->fields.push_back(field);
    auto StagingAreaCopy=qobject_cast<QGraphicsView*>(this->parent());
    QGridLayout* layout = static_cast<QGridLayout*>(StagingAreaCopy->layout());
    layout->addWidget(field);
}

void ClassNode::fillDefinedAttributes()
{
    definedAttributes = {};
    for(ClassField* attr : fields){
        QString name = attr->fieldName->text();
        definedAttributes.push_back(name);
    }
}

QVector<ClassField *>& ClassNode::getAttributes()
{
    return this->fields;
}
