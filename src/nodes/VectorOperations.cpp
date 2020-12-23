#include "./headers/nodesHeaders/VectorOperations.h"

VectorOperations::VectorOperations() : Node("vectorOperations", 1, 1)
{
    setMinimumSize(120,120);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(78, 55, 114, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->operations = new QComboBox();
    this->operations->addItem("push_back");
    this->operations->addItem("pop_back");
    this->operations->addItem("[]");
    this->operations->addItem("size");

    layout->addWidget(this->operations, 3, 0);
    layout->addWidget(this->value, 4, 0);
}

QString VectorOperations::getCodeForNode()
{
    QString text = "";

    if(this->operations->currentText() == QString::fromStdString("push_back"))
    {
        text+= QString::fromStdString(".push_back(");
        text+= this->value->text();
        text+= QString::fromStdString(");\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("pop_back"))
    {
        text+= QString::fromStdString(".pop_back()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("[]"))
    {
        //TODO treba videti kako ce ovo da se ukolpi u parser
        text+= QString::fromStdString("[]");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("size"))
    {
        text+= QString::fromStdString(".size()");
        text+= QString::fromStdString(";\n");
    }

    qDebug()<< text;
    return text;
}


