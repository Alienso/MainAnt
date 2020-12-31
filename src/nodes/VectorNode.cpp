#include "./headers/nodesHeaders/VectorNode.h"

VectorNode::VectorNode() : Node("vector", 1, 1)
{
    setMinimumSize(180,150);
    setStyleSheet ("background-color: rgba(38, 55, 114, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->vectorName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter vecotr name...");
    this->vectorName->setPlaceholderText(*placeHolderValue);

    this->capacity = new QLineEdit();
    const QString* placeHolderVarName = new QString("Set vector size...");
    this->capacity->setPlaceholderText(*placeHolderVarName);

    this->varTypes = new QComboBox();
    this->varTypes->addItem("Int");
    this->varTypes->addItem("Float");
    this->varTypes->addItem("Double");
    this->varTypes->addItem("Bool");
    this->varTypes->addItem("Char");
    this->varTypes->addItem("String");

    layout->addWidget(this->varTypes, 3, 0);
    layout->addWidget(this->vectorName, 4, 0);
    layout->addWidget(this->capacity, 5, 0);
}

QString VectorNode::getCodeForNode()
{
    QString text = "vector<";

    if(this->varTypes->currentText() == QString::fromStdString("String")){
        text+= QString::fromStdString("std::string>");
    }else{
        text+= varTypes->currentText().toLower();
        text+= QString::fromStdString("> ");
    }

    text+= this->vectorName->text();
    text+= QString::fromStdString(";\n");

    return text;

}

QString VectorNode::getVarName() const
{
    QString text = this->vectorName->text();
    return text;
}
