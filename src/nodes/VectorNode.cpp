#include "./headers/nodesHeaders/VectorNode.h"

VectorNode::VectorNode() : Node("vector", 1, 1)
{
    setMinimumSize(180,150);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(38, 55, 114, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    this->vectorName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter vecotr name...");
    this->vectorName->setPlaceholderText(*placeHolderValue);

    this->capacity = new QLineEdit();
    const QString* placeHolderVarName = new QString("Set vector size...");
    this->capacity->setPlaceholderText(*placeHolderVarName);

    this->varTypes = new QComboBox();
    this->varTypes->addItem("Integer");
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
    QString text = "";

    if(this->varTypes->currentText() == QString::fromStdString("Integer"))
    {
        text+= QString::fromStdString("vector<int> ");
        text+= this->vectorName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Float"))
    {
        text+= QString::fromStdString("vector<float> ");
        text+= this->vectorName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Double"))
    {
        text+= QString::fromStdString("vector<double> ");
        text+= this->vectorName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Bool"))
    {
        text+= QString::fromStdString("vector<bool> ");
        text+= this->vectorName->text();
        text+= QString::fromStdString(";\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("Char"))
    {
        text+= QString::fromStdString("vector<char> ");
        text+= this->vectorName->text();
        text+= QString::fromStdString("\;\n");
    }
    else if(this->varTypes->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("vector<std::string> ");
        text+= this->vectorName->text();
        text+= QString::fromStdString("\";\n");
    }
    qDebug()<< text;
    return text;

}

QString VectorNode::getVarName() const
{
    QString text = this->vectorName->text();
    return text;
}
