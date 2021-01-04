#include "./headers/nodesHeaders/QueueOperations.h"

QueueOperations::QueueOperations() : Node("queueOperations", 2, 1,{"Queue","Value"})
{
    setMinimumSize(180,150);
    setStyleSheet ("background-color: rgba(62, 66, 115, 1);"
                   "border: 1px solid rgba(212, 44, 97, 1);"
                   "border-radius:5px");
    setColors({'v','v','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
    layout->itemAtPosition(2,2)->widget()->hide();

    this->value = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter value...");
    this->value->setPlaceholderText(*placeHolderValue);

    this->operations = new QComboBox();
    this->operations->addItem("push");
    this->operations->addItem("pop");
    this->operations->addItem("size");
    this->operations->addItem("front");
    this->operations->addItem("back");
    this->operations->addItem("empty");

    layout->addWidget(this->operations, 3, 0, 1, 3);
    layout->addWidget(this->value, 4, 0, 1, 3);
}

QString QueueOperations::getCodeForNode()
{
    QString text = "";

    if(this->operations->currentText() == QString::fromStdString("push"))
    {
        text+= QString::fromStdString("#0.push(");
        if (this->value->text().compare("") != 0)
            text+= this->value->text();
        else text+="#1";
        text+= QString::fromStdString(")");
    }
    else if(this->operations->currentText() == QString::fromStdString("pop"))
    {
        text+= QString::fromStdString("#0.pop()");
    }
    else if(this->operations->currentText() == QString::fromStdString("size"))
    {
        text+= QString::fromStdString("#0.size()");
    }
    else if(this->operations->currentText() == QString::fromStdString("front"))
    {
        text+= QString::fromStdString("#0.front()");
    }
    else if(this->operations->currentText() == QString::fromStdString("back"))
    {
        text+= QString::fromStdString("#0.back()");
    }
    else if(this->operations->currentText() == QString::fromStdString("empty"))
    {
        text+= QString::fromStdString("#0.empty()");
    }

    //qDebug()<< text;
    return text;
}


