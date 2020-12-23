#include "./headers/nodesHeaders/ClassNode.h"

ClassNode::ClassNode() : Node("Class", 1, 1)
{
    setMinimumSize(150,125);
    setMaximumWidth(300);
    setStyleSheet ("background-color: rgba(255, 187, 0, 1);"
                   "border: 1px solid rgba(127, 40, 254, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->addMethod=new QPushButton("+method");
    this->addVariable=new QPushButton("+variable");

    this->ClassName = new QLineEdit();
    const QString* placeHolderClassName = new QString("Enter class name...");
    this->ClassName->setPlaceholderText(*placeHolderClassName);

    layout->addWidget(this->ClassName, 3, 0);
    layout->addWidget(this->addMethod, 4, 0);
    layout->addWidget(this->addVariable, 5, 0);

    connect(this->addMethod, SIGNAL(clicked()), this, SLOT(addMethodSlot(void)));
}

QString ClassNode::getCodeForNode(){
    QString text="";
    return text;
}

void ClassNode::addMethodSlot()
{
    FunctionWindow *m=new FunctionWindow(qobject_cast<QWidget*>(this->parent()->parent()->parent()), "MethodWidnow", 0);
    QMessageBox msgBox;
    msgBox.setText("To save the changes you have made chose 'Build->Save'.");
    m->show();
    msgBox.exec();
}
