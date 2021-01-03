#include "../../headers/nodesHeaders/MapNode.h"

MapNode::MapNode() : Node("map", 1, 1)
{
    setMinimumSize(180,this->initialSize);
    setStyleSheet ("background-color: rgba(120, 120, 0, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});


    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->mapName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter map name...");
    this->mapName->setPlaceholderText(*placeHolderValue);

    this->inKey = new QLineEdit();
    const QString* placeHolderValueIn1 = new QString("Enter key value...");
    this->inKey->setPlaceholderText(*placeHolderValueIn1);

    this->inValue = new QLineEdit();
    const QString* placeHolderValueIn2 = new QString("Enter value...");
    this->inValue->setPlaceholderText(*placeHolderValueIn2);

    this->lastTwo = new QLineEdit();
    this->lastTwo->setReadOnly(true);

    this->keyTypes = new QComboBox();
    this->keyTypes->addItem("Int");
    this->keyTypes->addItem("Float");
    this->keyTypes->addItem("Double");
    this->keyTypes->addItem("Bool");
    this->keyTypes->addItem("Char");
    this->keyTypes->addItem("String");

    this->valueTypes = new QComboBox();
    this->valueTypes->addItem("Int");
    this->valueTypes->addItem("Float");
    this->valueTypes->addItem("Double");
    this->valueTypes->addItem("Bool");
    this->valueTypes->addItem("Char");
    this->valueTypes->addItem("String");
    QLabel* keyLabel = new QLabel();
    QLabel* valueLabel = new QLabel();

    keyLabel->setText("Key type");
    valueLabel->setText("Value type");

    this->initialize = new QRadioButton("Initialize",this);
    this->notInitialize = new QRadioButton("Declare", this);

    this->notInitialize->setChecked(true);

    this->choice = new QButtonGroup(this);
    this->choice->addButton(this->notInitialize, 1);
    this->choice->addButton(this->initialize, 2);

    this->addVar = new QPushButton("+");
    this->removeVar = new QPushButton("-");

    connect(this->choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            [=](){

        int choosen = this->choice->checkedId();
        if(choosen == 1){
            this->inKey->hide();
            this->inValue->hide();
            this->lastTwo->hide();
            this->addVar->hide();
            this->removeVar->hide();

            setMinimumSize(200, this->initialSize);
        }else if(choosen == 2){
            this->inKey->show();
            this->inValue->show();
            this->lastTwo->show();
            this->addVar->show();
            this->removeVar->show();

            setMinimumSize(200, this->initialSize + 60);
        }

    });

    layout->addWidget(keyLabel, 2, 0);
    layout->addWidget(this->keyTypes, 3, 0);
    layout->addWidget(valueLabel, 4, 0);
    layout->addWidget(this->valueTypes, 5, 0);
    layout->addWidget(this->mapName, 6, 0);
    layout->addWidget(this->notInitialize, 7, 0);
    layout->addWidget(this->initialize, 8, 0);
    layout->addWidget(this->inKey, 9, 0);
    layout->addWidget(this->inValue, 10, 0);
    layout->addWidget(this->lastTwo, 11, 0);
    layout->addWidget(this->addVar, 9, 1);
    layout->addWidget(this->removeVar, 11, 1);

    connect(this->addVar, SIGNAL(clicked()), this, SLOT(addVariable(void)));
    connect(this->removeVar, SIGNAL(clicked()), this, SLOT(removeVariable(void)));


    this->addVar->hide();
    this->lastTwo->hide();
    this->inKey->hide();
    this->inValue->hide();
    this->removeVar->hide();
    this->lastTwo->setText(this->lasTwoText);
}

QString MapNode::getCodeForNode()
{
    QString text = "std::map<";

    if(this->keyTypes->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("std::string");
    }else
    {
        text+= keyTypes->currentText().toLower();
    }

    text+= QString::fromStdString(", ");

    if(this->valueTypes->currentText() == QString::fromStdString("String"))
    {
        text+= QString::fromStdString("std::string");
    }else
    {
        text+= valueTypes->currentText().toLower();
    }

    text+= QString::fromStdString("> ");
    text+= this->mapName->text();

    if(this->choice->checkedId() == 2)
    {
        text+= QString::fromStdString(" = {");
        for(int i =0; i<this->initializedKeys.length(); i++)
        {
            text+= QString::fromStdString("{");
            if(this->keyTypes->currentText() == QString::fromStdString("String") )
            {
                text+= QString::fromStdString("\"");
                text+=this->initializedKeys[i];
                text+= QString::fromStdString("\", ");
            }else
            {
                text+=this->initializedKeys[i];
            }

            if(this->valueTypes->currentText() == QString::fromStdString("String") )
            {
                text+= QString::fromStdString("\"");
                text+=this->initializedVars[i];
                text+= QString::fromStdString("\"");
            }else
            {
                text+=this->initializedVars[i];
            }

            text+= QString::fromStdString("}");

            if(i < this->initializedVars.length()-1)
            {
                text+= QString::fromStdString(", ");
            }
        }
        text+= QString::fromStdString("}");
    }

    text+= QString::fromStdString(";\n");

    return text;
}

QString MapNode::getVarName() const
{
    QString text = this->mapName->text();
    return text;
}

void MapNode::addVariable()
{
    qDebug()<<"Usao sam";
    if(this->inKey->text() != QString::fromStdString("") && this->inValue->text() != QString::fromStdString("") ){

        if(this->keyTypes->currentText() != QString::fromStdString("String"))
        {
            this->initializedKeys.push_back(this->inKey->text().trimmed());
        }else
        {
            this->initializedKeys.push_back(this->inKey->text());
        }

        if(this->valueTypes->currentText() != QString::fromStdString("String"))
        {
            this->initializedVars.push_back(this->inValue->text().trimmed());
        }else
        {
            this->initializedVars.push_back(this->inValue->text());
        }
        this->inValue->setText("");
        this->inKey->setText("");
        this->genererateLastTwoText();
    }
}

void MapNode::removeVariable()
{

    if(this->initializedVars.empty() != true){
        this->initializedVars.pop_back();
        this->initializedKeys.pop_back();
    }
    this->genererateLastTwoText();
}

void MapNode::genererateLastTwoText()
{
    this->lasTwoText = "";
    if(this->initializedVars.length() > 2){
        for(int i= this->initializedVars.length() - 2; i<this->initializedVars.length(); i++){
            lasTwoText+=QString::fromStdString("{");
            lasTwoText+=this->initializedKeys[i];
            lasTwoText+=QString::fromStdString(" ");
            lasTwoText+=this->initializedVars[i];
            lasTwoText+=QString::fromStdString("}");
        }

    }else{
        for(int i= 0; i<this->initializedVars.length(); i++){
            lasTwoText+=QString::fromStdString("{");
            lasTwoText+=this->initializedKeys[i];
            lasTwoText+=QString::fromStdString(" ");
            lasTwoText+=this->initializedVars[i];
            lasTwoText+=QString::fromStdString("}");
        }
    }
    if(this->initializedVars.empty())
    {
        lasTwoText+=QString::fromStdString("empty map");
    }
    this->lastTwo->setText(this->lasTwoText);
}
