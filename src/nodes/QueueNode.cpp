#include "./headers/QueueNode.h"

QueueNode::QueueNode() : Node("queue", 1, 1)
{
    setMinimumSize(180,150);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(137, 24, 102, 1);"
                   "border: 1px solid rgba(212, 44, 97, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->QueueName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter queue name...");
    this->QueueName->setPlaceholderText(*placeHolderValue);


    this->varTypes = new QComboBox();
    this->varTypes->addItem("Integer");
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
    QString text = "";
    if(this->varTypes->currentText() == QString::fromStdString("Integer"))
    {
        text+= QString::fromStdString("queue<int> ");
        text+= this->QueueName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Float"))
    {
        text+= QString::fromStdString("queue<float> ");
        text+= this->QueueName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Double"))
    {
        text+= QString::fromStdString("queue<double> ");
        text+= this->QueueName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Bool"))
    {
        text+= QString::fromStdString("queue<bool> ");
        text+= this->QueueName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Char"))
    {
        text+= QString::fromStdString("queue<char> ");
        text+= this->QueueName->text();
        text+= QString::fromStdString("\";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("queue<std::string> ");
        text+= this->QueueName->text();
        text+= QString::fromStdString("\";\n");
    }

    qDebug()<<text;
    return text;

}

