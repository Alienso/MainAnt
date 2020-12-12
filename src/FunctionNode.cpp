#include "./headers/FunctionNode.h"

FunctionNode::FunctionNode() : Node("function", 1, 1)
{
    setMinimumSize(200,200);
    setMaximumWidth(300);
    setStyleSheet ("background-color: rgba(164, 13, 129, 1);"
                   "border: 1px solid rgba(137, 252, 255, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->addArg=new QPushButton("+arg");

    this->FunctionName = new QLineEdit();
    const QString* placeHolderVarName = new QString("Enter function name...");
    this->FunctionName->setPlaceholderText(*placeHolderVarName);

    this->combo = new QComboBox();
    this->combo->addItem("Integer");
    this->combo->addItem("Float");
    this->combo->addItem("Double");
    this->combo->addItem("Bool");
    this->combo->addItem("Char");
    this->combo->addItem("String");

    layout->addWidget(this->combo, 3, 0);
    layout->addWidget(this->FunctionName, 4, 0);
    layout->addWidget(this->addArg, 5, 0);

    //connect(this->addArg, SIGNAL(clicked()), this, SLOT(addArg(void)));
}

QString FunctionNode::getCodeForNode(){
    QString text="function";
    return text;
}

void FunctionNode::addAgrument()
{
    qDebug()<<"Dodajem argument";
}
