#include "../../headers/nodesHeaders/MapOperations.h"

MapOperations::MapOperations() : Node("mapOperations", 2, 1,{"Map","Value"})
{
    setMinimumSize(180,160);
    setStyleSheet ("background-color: rgba(215, 175, 44, 1);"
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
    this->operations->addItem("[]");
    this->operations->addItem("empty");
    this->operations->addItem("size");

    layout->addWidget(this->operations, 3, 0, 1, 3);
    layout->addWidget(this->value, 4, 0, 1, 3);
}

QString MapOperations::getCodeForNode()
{
    QString text = "";

    if(this->operations->currentText() == QString::fromStdString("[]"))
    {
        text+= QString::fromStdString("[");
        if (this->value->text().compare("") != 0)
            text+= this->value->text();
        else text+="#1";
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
