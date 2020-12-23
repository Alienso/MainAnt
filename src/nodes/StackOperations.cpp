#include "./headers/nodesHeaders/StackOperations.h"

StackOperations::StackOperations() : Node("stackOperations", 1, 1)
{
    setMinimumSize(120,120);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(225, 75, 44, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->operations = new QComboBox();
    this->operations->addItem("push");
    this->operations->addItem("pop");
    this->operations->addItem("size");
    this->operations->addItem("top");
    this->operations->addItem("empty");

    layout->addWidget(this->operations, 3, 0);
    layout->addWidget(this->value, 4, 0);
}

QString StackOperations::getCodeForNode()
{
    QString text = "";

    if(this->operations->currentText() == QString::fromStdString("push"))
    {
        text+= QString::fromStdString(".push(");
        text+= this->value->text();
        text+= QString::fromStdString(");\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("pop"))
    {
        text+= QString::fromStdString(".pop()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("size"))
    {
        text+= QString::fromStdString(".size()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("top"))
    {
        text+= QString::fromStdString(".top()");
        text+= QString::fromStdString(";\n");
    }else if(this->operations->currentText() == QString::fromStdString("empty"))
    {
        text+= QString::fromStdString(".empty()");
        text+= QString::fromStdString(";\n");
    }

    qDebug()<< text;
    return text;
}


