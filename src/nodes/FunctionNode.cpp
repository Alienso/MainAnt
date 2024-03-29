#include "./headers/nodesHeaders/FunctionNode.h"

FunctionNode::FunctionNode() : Node("Function", 1, 1), argNum(0)
{
    setMinimumSize(300,currWidth);
    setStyleSheet ("background-color: rgba(164, 13, 129, 1);"
                   "border: 1px solid rgba(137, 252, 255, 1);"
                   "border-radius:5px;");

    setColors({'q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->addArg=new QPushButton("+argument");
    this->addToVisible = new QPushButton("Make arguments visible");

    this->FunctionName = new QLineEdit();
    const QString* placeHolderFunctionName = new QString("Enter function name...");
    this->FunctionName->setPlaceholderText(*placeHolderFunctionName);

    this->combo = new QComboBox();
    this->combo->addItem("void");
    this->combo->addItem("int");
    this->combo->addItem("float");
    this->combo->addItem("double");
    this->combo->addItem("bool");
    this->combo->addItem("char");
    this->combo->addItem("string");

    layout->addWidget(this->combo, 3, 0);
    layout->addWidget(this->FunctionName, 3, 1);
    layout->addWidget(this->addArg, 5, 0);
    layout->addWidget(this->addToVisible, 4, 0);

    connect(this->addArg, SIGNAL(clicked()), this, SLOT(addArgument(void)));
}

int FunctionNode::getArgNum() const
{
    return this->argNum;
}

QString FunctionNode::getRetVal() const
{
    QString text="";

    if(this->combo->currentText() == QString::fromStdString("string"))
    {
        text+= QString::fromStdString("std::string ");
    }else
    {
        text+=this->combo->currentText().toLower();
        text+= QString::fromStdString(" ");
    }

    return text;
}

QString FunctionNode::getCodeForNode(){
    QString text="";
    if(this->FunctionName->text()!=""){
        text+=getRetVal();

        text+= this->FunctionName->text();
        text+= QString::fromStdString(" ( ");
        int i=0;
        int n=this->argumentsTypes.length();
        if(n == 0){
            text += QString::fromStdString(")");
            return text;
        }
        for(i=0; i<n-1; i++){
            if(this->argumentsNames[i]->text()!=""){
                text+= this->argumentsTypes[i]->currentText();
                text+= QString::fromStdString(" ");
                text+= this->argumentsNames[i]->text();
                text+= QString::fromStdString(" , ");
            }
        }
        //da ne bi dodao zarez na poslednji argument
        if(this->argumentsNames[i]->text()!=""){
            text+= this->argumentsTypes.last()->currentText();
            text+= QString::fromStdString(" ");
            text+= this->argumentsNames.last()->text();
        }

        text+= QString::fromStdString(" )");
    }
    return text;
}

void FunctionNode::addArgument()
{
    //qDebug()<<"Dodajem argument";
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

    this->deleteButton.push_back(new QPushButton("X"));

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    connect(this->deleteButton.last(), SIGNAL(clicked()), this, SLOT(deleteArgument()));

    //za brisanje iz argInList i iz Arguments
    auto parentFunctionWindow=qobject_cast<QMainWindow*>(this->parent()->parent()->parent());
    connect(this, SIGNAL(deleteArgumentFromList(QString)), parentFunctionWindow, SLOT(deleteArgumentFromList(QString)));

    layout->addWidget(this->argumentsTypes.last(), this->layoutK, 0);
    layout->addWidget(this->argumentsNames.last(), this->layoutK, 1);
    layout->addWidget(this->deleteButton.last(), this->layoutK, 2);

    this->layoutK++;
    this->currWidth += 40;
    this->argNum += 1;
    setMinimumSize(300,currWidth);
}

void FunctionNode::deleteArgument()
{

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    QWidget* sender=qobject_cast<QWidget*>(this->sender());

    int indexDel=layout->indexOf(sender);
    int indexType=indexDel-2;
    int indexName=indexDel-1;

    layout->itemAt(indexType)->widget()->close();
    layout->itemAt(indexName)->widget()->close();
    sender->deleteLater();

    QString nameOfArgument="";
    int i=0;
    for (auto a: this->argumentsNames) {
        if(a==layout->itemAt(indexName)->widget()){
            this->argumentsNames.removeAt(i);
            this->argumentsTypes.removeAt(i);
            this->deleteButton.removeAt(i);
            nameOfArgument.append(a->text());
        }
        i++;
    }
    this->currWidth -= 40;
    setMinimumSize(300,currWidth);

    emit deleteArgumentFromList(nameOfArgument);
}
