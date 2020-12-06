#include "../headers/VarNode.h"

VarNode::VarNode() : Node("var", 1, 1, nullptr)
{
    setMinimumSize(100,100);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(78, 105, 104, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");

    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter var value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->varName = new QLineEdit();
    const QString* placeHolderVarName = new QString("Enter var name...");
    this->varName->setPlaceholderText(*placeHolderVarName);

    this->combo = new QComboBox();
    this->combo->addItem("Integer");
    this->combo->addItem("Float");
    this->combo->addItem("Double");
    this->combo->addItem("Bool");
    this->combo->addItem("Char");
    this->combo->addItem("String");

    layout->insertRow(3, this->combo);
    layout->insertRow(4, this->varName);
    layout->insertRow(5, this->value);
}

QString VarNode::getCodeForNode()
{
    QString text = "";

    if(this->combo->currentText() == QString::fromStdString("Integer"))
    {
        text+= QString::fromStdString("int ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= this->value->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("Float"))
    {
        text+= QString::fromStdString("float ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= this->value->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("Double"))
    {
        text+= QString::fromStdString("double ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= this->value->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("Bool"))
    {
        text+= QString::fromStdString("bool ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= this->value->text().toLower();
        text+= QString::fromStdString(";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("Char"))
    {
        text+= QString::fromStdString("char ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= QString::fromStdString("\"");
        text+= this->value->text();
        text+= QString::fromStdString("\";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("std::string ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= QString::fromStdString("\"");
        text+= this->value->text();
        text+= QString::fromStdString("\";\n");
    }
    qDebug()<< text;
    return text;
}
