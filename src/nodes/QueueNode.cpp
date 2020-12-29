#include "./headers/nodesHeaders/QueueNode.h"

QueueNode::QueueNode() : Node("queue", 1, 1)
{
    setMinimumSize(180,150);
    setStyleSheet ("background-color: rgba(137, 24, 102, 1);"
                   "border: 1px solid rgba(212, 44, 97, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->QueueName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter queue name...");
    this->QueueName->setPlaceholderText(*placeHolderValue);


    this->varTypes = new QComboBox();
    this->varTypes->addItem("Int");
    this->varTypes->addItem("Float");
    this->varTypes->addItem("Double");
    this->varTypes->addItem("Bool");
    this->varTypes->addItem("Char");
    this->varTypes->addItem("String");

    layout->addWidget(this->varTypes, 3, 0);
    layout->addWidget(this->QueueName, 4, 0);
}

QString QueueNode::getCodeForNode()
{
    QString text = "queue<";

    if(this->varTypes->currentText() == QString::fromStdString("String")){
        text+= QString::fromStdString("std::string>");
    }else{
        text+= varTypes->currentText().toLower();
        text+= QString::fromStdString("> ");
    }

    text+= this->QueueName->text();
    text+= QString::fromStdString(";\n");

    return text;


}

QString QueueNode::getVarName() const
{
    QString text = this->QueueName->text();
    return text;
}

