#include "../../headers/nodesHeaders/AssignNode.h"

AssignNode::AssignNode() : Node("Assign", 1, 1)
{
    setMinimumSize(150,150);
    setStyleSheet ("background-color: rgba(180, 0, 0, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    setColors({'q','q'});

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->varAssigne = new QLineEdit();
    const QString* placeHolderVarName = new QString("Enter value...");
    this->varAssigne->setPlaceholderText(*placeHolderVarName);

    this->combo = new QComboBox();
    this->combo->addItem("Number");
    this->combo->addItem("String");
    this->combo->addItem("Variable");

    layout->addWidget(this->combo, 3, 0);
    layout->addWidget(this->varAssigne, 4, 0);
    layout->addWidget(this->value, 5, 0);
}

QString AssignNode::getCodeForNode()
{
    QString text = "";

    if(this->combo->currentText() == QString::fromStdString("String"))
    {
        text+= this->varAssigne->text();
        text+= QString::fromStdString(" = \"");
        text+= this->value->text();
        text+= QString::fromStdString("\"");
        text+= QString::fromStdString(";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("Number"))
    {
        text+= this->varAssigne->text();
        text+= QString::fromStdString(" = ");
        text+= this->value->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->combo->currentText() == QString::fromStdString("Variable"))
    {
        text+= this->varAssigne->text();
        text+= QString::fromStdString(" = ");
        text+= this->value->text();
        text+= QString::fromStdString(";\n");
    }

    return text;
}
