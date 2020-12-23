#include "./headers/nodesHeaders/QueueOperations.h"

QueueOperations::QueueOperations() : Node("queueOperations", 1, 1)
{
    setMinimumSize(120,120);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(62, 66, 115, 1);"
                   "border: 1px solid rgba(212, 44, 97, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->operations = new QComboBox();
    this->operations->addItem("push");
    this->operations->addItem("pop");
    this->operations->addItem("size");
    this->operations->addItem("front");
    this->operations->addItem("back");
    this->operations->addItem("empty");

    layout->addWidget(this->operations, 3, 0);
    layout->addWidget(this->value, 4, 0);
}

QString QueueOperations::getCodeForNode()
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
    else if(this->operations->currentText() == QString::fromStdString("front"))
    {
        text+= QString::fromStdString(".front()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("back"))
    {
        text+= QString::fromStdString(".back()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("empty"))
    {
        text+= QString::fromStdString(".empty()");
        text+= QString::fromStdString(";\n");
    }

    qDebug()<< text;
    return text;
}


