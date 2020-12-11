#include "./headers/StackNode.h"

StackNode::StackNode() : Node("stack", 1, 1)
{
    setMinimumSize(180,150);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(251, 170, 81, 1);"
                   "border: 1px solid rgba(88, 17, 87, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->StackName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter stack name...");
    this->StackName->setPlaceholderText(*placeHolderValue);


    this->varTypes = new QComboBox();
    this->varTypes->addItem("Integer");
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
    QString text = "";
    if(this->varTypes->currentText() == QString::fromStdString("Integer"))
    {
        text+= QString::fromStdString("stack<int> ");
        text+= this->StackName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Float"))
    {
        text+= QString::fromStdString("stack<float> ");
        text+= this->StackName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Double"))
    {
        text+= QString::fromStdString("stack<double> ");
        text+= this->StackName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Bool"))
    {
        text+= QString::fromStdString("stack<bool> ");
        text+= this->StackName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Char"))
    {
        text+= QString::fromStdString("stack<char> ");
        text+= this->StackName->text();
        text+= QString::fromStdString("\";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("stack<std::string> ");
        text+= this->StackName->text();
        text+= QString::fromStdString("\";\n");
    }

    qDebug()<<text;
    return text;

}

