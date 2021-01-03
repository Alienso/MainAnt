#include "./headers/nodesHeaders/VectorOperations.h"

VectorOperations::VectorOperations() : Node("vectorOperations", 2, 1,{"Vector", "Value"})
{
    setMinimumSize(180,150);
    setStyleSheet ("background-color: rgba(78, 55, 114, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");
    setColors({'v','v','q'});

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
    layout->itemAtPosition(2,2)->widget()->hide();

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->operations = new QComboBox();
    this->operations->addItem("push_back");
    this->operations->addItem("pop_back");
    this->operations->addItem("[]");
    this->operations->addItem("size");

    layout->addWidget(this->operations, 3, 0, 1, 3);
    layout->addWidget(this->value, 4, 0, 1, 3);
}

QString VectorOperations::getCodeForNode()
{
    QString text = "";

    if(this->operations->currentText() == QString::fromStdString("push_back"))
    {
        text+= QString::fromStdString(".push_back(");
        if (this->value->text().compare("") != 0)
            text+= this->value->text();
        else text+="#1";
        text+= QString::fromStdString(");\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("pop_back"))
    {
        text+= QString::fromStdString(".pop_back()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("[]"))
    {

        text+= QString::fromStdString("[");
        if (this->value->text().compare("") != 0)
            text+= this->value->text();
        else text+="#1";
        text+= QString::fromStdString("];\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("size"))
    {
        text+= QString::fromStdString(".size()");
        text+= QString::fromStdString(";\n");
    }

    qDebug()<< text;
    return text;
}


