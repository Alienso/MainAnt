#include "../../headers/nodesHeaders/MapNode.h"

MapNode::MapNode() : Node("map", 1, 1)
{
    setMinimumSize(150,150);
    setStyleSheet ("background-color: rgba(120, 120, 0, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    this->mapName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter map name...");
    this->mapName->setPlaceholderText(*placeHolderValue);

    this->keyTypes = new QComboBox();
    this->keyTypes->addItem("Integer");
    this->keyTypes->addItem("Float");
    this->keyTypes->addItem("Double");
    this->keyTypes->addItem("Bool");
    this->keyTypes->addItem("Char");
    this->keyTypes->addItem("String");

    this->valueTypes = new QComboBox();
    this->valueTypes->addItem("Integer");
    this->valueTypes->addItem("Float");
    this->valueTypes->addItem("Double");
    this->valueTypes->addItem("Bool");
    this->valueTypes->addItem("Char");
    this->valueTypes->addItem("String");
    QLabel* keyLabel = new QLabel();
    QLabel* valueLabel = new QLabel();

    keyLabel->setText("Key type");
    valueLabel->setText("Value type");

    layout->addWidget(keyLabel, 2, 0);
    layout->addWidget(this->keyTypes, 3, 0);
    layout->addWidget(valueLabel, 4, 0);
    layout->addWidget(this->valueTypes, 5, 0);
    layout->addWidget(this->mapName, 6, 0);
}

QString MapNode::getCodeForNode()
{
    QString text = "std::map<";
    text+= keyTypes->currentText().toLower();
    text+= QString::fromStdString(", ");
    text+= valueTypes->currentText().toLower();
    text+= QString::fromStdString("> ");
    text+= this->mapName->text();
    text+= QString::fromStdString(";\n");

    return text;
}


