#include "./headers/nodesHeaders/VarNode.h"

VarNode::VarNode() : Node("var", 1, 1)
{
    setMinimumSize(150,150);
    setStyleSheet ("background-color: rgba(78, 105, 104, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");

    setColors({'q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter var value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->varName = new QLineEdit();
    const QString* placeHolderVarName = new QString("Enter var name...");
    this->varName->setPlaceholderText(*placeHolderVarName);

    this->combo = new QComboBox();
    this->combo->addItem("Int");
    this->combo->addItem("Float");
    this->combo->addItem("Double");
    this->combo->addItem("Bool");
    this->combo->addItem("Char");
    this->combo->addItem("String");

    layout->addWidget(this->combo, 3, 0);
    layout->addWidget(this->varName, 4, 0);
    layout->addWidget(this->value, 5, 0);
}

QString VarNode::getCodeForNode()
{
    QString text = "";

    if(this->combo->currentText() == QString::fromStdString("String")){
        text+= QString::fromStdString("std::string ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");
        text+= QString::fromStdString("\"");
        text+= this->value->text();
        text+= QString::fromStdString("\";\n");
    }else{
        text+= this->combo->currentText().toLower();
        text+= QString::fromStdString(" ");
        text+= this->varName->text();
        text+= QString::fromStdString(" = ");

        if(this->combo->currentText() == QString::fromStdString("Char")){
            text+= QString::fromStdString("\"");
            text+= this->value->text();
            text+= QString::fromStdString("\"");
        }else if(this->combo->currentText() == QString::fromStdString("Bool")) {
            text+= this->value->text().toLower();
        }else{
            text+= this->value->text();
        }

        text+= QString::fromStdString(";\n");
    }
    //qDebug()<< text;
    return text;
}

QString VarNode::getVarName() const
{
    QString text = this->varName->text();
    return text;
}
