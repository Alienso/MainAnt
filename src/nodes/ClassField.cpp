#include "../../headers/nodesHeaders/ClassField.h"

ClassField::ClassField() : Node("ClassField", 1, 0)
{
    setMinimumSize(170,150);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(98, 190, 164, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    setColors({'q'});

    this->fieldName = new QLineEdit();
    const QString* placeHolderValue = new QString("Enter field name...");
    this->fieldName->setPlaceholderText(*placeHolderValue);

    this->fieldType = new QComboBox();
    this->fieldType->addItem("Int");
    this->fieldType->addItem("Float");
    this->fieldType->addItem("Double");
    this->fieldType->addItem("Bool");
    this->fieldType->addItem("Char");
    this->fieldType->addItem("String");

    this->fieldAccessModifiers = new QComboBox();
    this->fieldAccessModifiers->addItem("public");
    this->fieldAccessModifiers->addItem("private");
    this->fieldAccessModifiers->addItem("protected");

    layout->addWidget(this->fieldAccessModifiers, 3, 0);
    layout->addWidget(this->fieldType, 4, 0);
    layout->addWidget(this->fieldName, 5, 0);
}

QString ClassField::getCodeForNode()
{
    QString text = "";

    if(this->fieldName->text()!=""){

        if(this->fieldType->currentText() == QString::fromStdString("String"))
        {
            text+= "std::string ";
        }else{
            text+=this->fieldType->currentText().toLower();
        }
        text+=" ";
        text+=this->fieldName->text();
    }

    return text;
}


