#include "../../headers/nodesHeaders/MapOperations.h"

MapOperations::MapOperations() : Node("mapOperations", 1, 1)
{
    setMinimumSize(180,150);
    setStyleSheet ("background-color: rgba(215, 175, 44, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->operations = new QComboBox();
    this->operations->addItem("[]");
    this->operations->addItem("empty");
    this->operations->addItem("size");

    layout->addWidget(this->operations, 3, 0);
    layout->addWidget(this->value, 4, 0);
}

QString MapOperations::getCodeForNode()
{
    QString text = "";

    if(this->operations->currentText() == QString::fromStdString("[]"))
    {
        text+= QString::fromStdString("[");
        text+= this->value->text();
        text+= QString::fromStdString("];\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("empty"))
    {
        text+= QString::fromStdString(".epmpty()");
        text+= QString::fromStdString(";\n");
    }
    else if(this->operations->currentText() == QString::fromStdString("size"))
    {
        text+= QString::fromStdString(".size()");
        text+= QString::fromStdString(";\n");
    }

    return text;
}
