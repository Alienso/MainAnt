#include "./headers/nodesHeaders/ClassNode.h"

ClassNode::ClassNode() : Node("Class", 1, 1)
{
    setMinimumSize(300,200);
    setMaximumWidth(300);
    setStyleSheet ("background-color: rgba(164, 13, 129, 1);"
                   "border: 1px solid rgba(137, 252, 255, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->addMethod=new QPushButton("+method");
    this->addVariable=new QPushButton("+variable");

    this->ClassName = new QLineEdit();
    const QString* placeHolderClassName = new QString("Enter class name...");
    this->ClassName->setPlaceholderText(*placeHolderClassName);

    layout->addWidget(this->ClassName, 3, 0);
    layout->addWidget(this->addMethod, 4, 0);
    layout->addWidget(this->addVariable, 4, 1);
}

QString ClassNode::getCodeForNode(){
    QString text="";
    return text;
}
