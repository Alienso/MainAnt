#include "./headers/nodesHeaders/StackNode.h"

StackNode::StackNode() : Node("stack", 1, 1)
{
    setMinimumSize(180,150);
    setStyleSheet ("background-color: rgba(251, 170, 81, 1);"
                   "border: 1px solid rgba(88, 17, 87, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->StackName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter stack name...");
    this->StackName->setPlaceholderText(*placeHolderValue);


    this->varTypes = new QComboBox();
    this->varTypes->addItem("Int");
    this->varTypes->addItem("Float");
    this->varTypes->addItem("Double");
    this->varTypes->addItem("Bool");
    this->varTypes->addItem("Char");
    this->varTypes->addItem("String");

    layout->addWidget(this->varTypes, 3, 0);
    layout->addWidget(this->StackName, 4, 0);
}

QString StackNode::getCodeForNode()
{
    QString text = "stack<";

    if(this->varTypes->currentText() == QString::fromStdString("String")){
        text+= QString::fromStdString("std::string>");
    }else{
        text+= varTypes->currentText().toLower();
        text+= QString::fromStdString("> ");
    }

    text+= this->StackName->text();
    text+= QString::fromStdString(";\n");

    return text;

}

QString StackNode::getVarName() const
{
    QString text = this->StackName->text();
    return text;
}

