#include "./headers/nodesHeaders/QueueNode.h"

QueueNode::QueueNode(QVector<QString>& _inicializedClases) : Node("queue", 1, 1)
{
    setMinimumSize(200,this->initialSize);
    setStyleSheet ("background-color: rgba(137, 24, 102, 1);"
                   "border: 1px solid rgba(212, 44, 97, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();

    this->QueueName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter queue name...");
    this->QueueName->setPlaceholderText(*placeHolderValue);

    this->capacity = new QLineEdit();
    const QString* placeHolderVarName = new QString("Set queue size...");
    this->capacity->setPlaceholderText(*placeHolderVarName);

    this->in = new QLineEdit();
    const QString* placeHolderValueIn = new QString("Enter var value...");
    this->in->setPlaceholderText(*placeHolderValueIn);

    this->lastFive = new QLineEdit();
    this->lastFive->setReadOnly(true);

    this->varTypes = new QComboBox();
    this->varTypes->addItem("Int");
    this->varTypes->addItem("Float");
    this->varTypes->addItem("Double");
    this->varTypes->addItem("Bool");
    this->varTypes->addItem("String");

    for(auto clas : _inicializedClases)
    {
        this->varTypes->addItem(clas);
    }

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
            this->capacity->show();
            this->in->hide();
            this->lastFive->hide();
            this->addVar->hide();
            this->removeVar->hide();

            setMinimumSize(200, this->initialSize);
        }else if(choosen == 2){
            this->capacity->hide();
            this->in->show();
            this->lastFive->show();
            this->addVar->show();
            this->removeVar->show();

            setMinimumSize(200, this->initialSize + 40);
        }

    });

    layout->addWidget(this->varTypes, 3, 0);
    layout->addWidget(this->QueueName, 4, 0);
    layout->addWidget(this->capacity, 5, 0);
    layout->addWidget(this->notInitialize, 6, 0);
    layout->addWidget(this->initialize, 7, 0);
    layout->addWidget(this->in, 8, 0);
    layout->addWidget(this->lastFive, 9, 0);
    layout->addWidget(this->addVar, 8, 1);
    layout->addWidget(this->removeVar, 9, 1);

    connect(this->addVar, SIGNAL(clicked()), this, SLOT(addVariable(void)));
    connect(this->removeVar, SIGNAL(clicked()), this, SLOT(removeVariable(void)));

    this->addVar->hide();
    this->lastFive->hide();
    this->in->hide();
    this->removeVar->hide();
    this->lastFive->setText(this->lastFiveText);
}

QString QueueNode::getCodeForNode()
{
    QString text = "std::queue<";

    if(!this->varTypes->currentText().compare("String") && !this->varTypes->currentText().compare("Int") && !this->varTypes->currentText().compare("Double")
            && !this->varTypes->currentText().compare("Float") && !this->varTypes->currentText().compare("Bool"))
    {
        text += this->varTypes->currentText();
        text+=">;\n";
        return text;
    }

    if(this->varTypes->currentText() == QString::fromStdString("String")){
        text+= QString::fromStdString("std::string>");
    }else{
        text+= varTypes->currentText().toLower();
        text+= QString::fromStdString("> ");
    }

    text+= this->QueueName->text();

    if(this->choice->checkedId() == 1)
    {
        if(this->capacity->text().length() != 0){
            text+=QString::fromStdString("(");
            text+=this->capacity->text();
            text+=QString::fromStdString(")");
        }
    }else
    {
        if(this->varTypes->currentText() == QString::fromStdString("String"))
        {
            text+= QString::fromStdString("({");
            for(int i = 0; i<this->initializedVars.length(); i++){
                text+= QString::fromStdString("\"");
                text+= this->initializedVars[i];
                text+= QString::fromStdString("\"");
                if(i < this->initializedVars.length()-1)
                {
                    text+= QString::fromStdString(", ");
                }
            }
            text+= QString::fromStdString("})");
        }else
        {
            text+= QString::fromStdString("({");
            for(int i = 0; i<this->initializedVars.length(); i++){
                text+= this->initializedVars[i];
                if(i < this->initializedVars.length()-1)
                {
                    text+= QString::fromStdString(", ");
                }
            }
            text+= QString::fromStdString("})");
        }
    }

    text+= QString::fromStdString(";\n");

    return text;


}

QString QueueNode::getVarName() const
{
    QString text = this->QueueName->text();
    return text;
}

void QueueNode::addVariable()
{
    //qDebug()<<"Dodajem argument";
    if(this->in->text() != QString::fromStdString("")){

        if(this->varTypes->currentText() != QString::fromStdString("String"))
        {
            this->initializedVars.push_back(this->in->text().trimmed());
        }else
        {
            this->initializedVars.push_back(this->in->text());
        }
        this->in->setText("");
        this->genererateLastFiveText();
    }

}

void QueueNode::removeVariable()
{
    if(this->initializedVars.empty() != true){
        this->initializedVars.pop_back();
    }
    this->genererateLastFiveText();
}

void QueueNode::genererateLastFiveText()
{
    this->lastFiveText = "";
    if(this->initializedVars.length() > 5){
        for(int i= this->initializedVars.length() - 5; i<this->initializedVars.length(); i++){
            lastFiveText+=this->initializedVars[i];
            lastFiveText+=QString::fromStdString(" ");
        }

    }else{
        for(int i= 0; i<this->initializedVars.length(); i++){
            lastFiveText+=this->initializedVars[i];
            lastFiveText+=QString::fromStdString(" ");
        }
    }
    if(this->initializedVars.empty())
    {
        lastFiveText+=QString::fromStdString("empty queue");
    }
    this->lastFive->setText(this->lastFiveText);

}
