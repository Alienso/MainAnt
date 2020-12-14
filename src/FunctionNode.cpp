#include "./headers/FunctionNode.h"

FunctionNode::FunctionNode() : Node("function", 1, 1)
{
    setMinimumSize(300,200);
    setMaximumWidth(300);
    setStyleSheet ("background-color: rgba(164, 13, 129, 1);"
                   "border: 1px solid rgba(137, 252, 255, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->addArg=new QPushButton("+argument");

    this->FunctionName = new QLineEdit();
    const QString* placeHolderFunctionName = new QString("Enter function name...");
    this->FunctionName->setPlaceholderText(*placeHolderFunctionName);

    this->combo = new QComboBox();
    this->combo->addItem("Integer");
    this->combo->addItem("Float");
    this->combo->addItem("Double");
    this->combo->addItem("Bool");
    this->combo->addItem("Char");
    this->combo->addItem("String");

    layout->addWidget(this->combo, 3, 1);
    layout->addWidget(this->FunctionName, 3, 0);
    layout->addWidget(this->addArg, 4, 0);

    connect(this->addArg, SIGNAL(clicked()), this, SLOT(addArgument(void)));
}

QString FunctionNode::getCodeForNode(){
    QString text="";

    if(this->combo->currentText() == QString::fromStdString("Integer"))
    {
        text+= QString::fromStdString("int ");
    }
    else if(this->combo->currentText() == QString::fromStdString("Float"))
    {
        text+= QString::fromStdString("float ");
    }
    else if(this->combo->currentText() == QString::fromStdString("Double"))
    {
        text+= QString::fromStdString("double ");
    }
    else if(this->combo->currentText() == QString::fromStdString("Bool"))
    {
        text+= QString::fromStdString("bool ");
    }
    else if(this->combo->currentText() == QString::fromStdString("Char"))
    {
        text+= QString::fromStdString("char ");
    }
    else if(this->combo->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("std::string ");
    }

    text+= this->FunctionName->text();
    text+= QString::fromStdString("(");
    int i=0;
    int n=this->argumentsTypes.length();
    for(i=0; i<n-1; i++){
        text+= this->argumentsTypes[i]->currentText();
        text+= QString::fromStdString(" ");
        text+= this->argumentsNames[i]->text();
        text+= QString::fromStdString(", ");
    }
    //da ne bi dodao zarez na poslednji argument
    text+= this->argumentsTypes.last()->currentText();
    text+= QString::fromStdString(" ");
    text+= this->argumentsNames.last()->text();

    text+= QString::fromStdString("){\n");
    qDebug()<< text;
    return text;
}

void FunctionNode::addArgument()
{
    qDebug()<<"Dodajem argument";
    this->argumentsNames.push_back(new QLineEdit());
    const QString* placeHolderArgName = new QString("Enter arg name...");
    this->argumentsNames.last()->setPlaceholderText(*placeHolderArgName);

    this->argumentsTypes.push_back(new QComboBox());
    this->argumentsTypes.last()->addItem("int");
    this->argumentsTypes.last()->addItem("float");
    this->argumentsTypes.last()->addItem("double");
    this->argumentsTypes.last()->addItem("bool");
    this->argumentsTypes.last()->addItem("char");
    this->argumentsTypes.last()->addItem("string");


    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());

    layout->addWidget(this->argumentsNames.last(), this->layoutK, 1);
    layout->addWidget(this->argumentsTypes.last(), this->layoutK, 0);

    this->layoutK++;
}
