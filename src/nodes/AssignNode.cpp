#include "../../headers/nodesHeaders/AssignNode.h"

AssignNode::AssignNode() : Node("Assign", 2, 1)
{
    setMinimumSize(150,170);
    setStyleSheet ("background-color: rgba(180, 0, 0, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    layout->itemAtPosition(2,1)->widget()->hide();
    setColors({'q', 'v','q'});

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
        text+= QString::fromStdString(" = ");
        if(this->value->text().compare("") != 0)
        {
            text+= QString::fromStdString("\"");
            text+= this->value->text();
            text+= QString::fromStdString("\"");
        }else
        {
            text+="#1";
        }
        text+= QString::fromStdString(";\n");
    }
    else
    {
        text+= this->varAssigne->text();
        text+= QString::fromStdString(" = ");
        if(this->value->text().compare("") != 0)
        {
            text+= this->value->text();
        }
        else
        {
            text+="#1";
        }
        text+= QString::fromStdString(";\n");
    }

    return text;
}
