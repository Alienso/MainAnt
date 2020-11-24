#include "../headers/InputFromFile.h"

InputfromFile::InputfromFile():Node("InputFromFile", 0, 1, nullptr)
{
    setMinimumSize(80,80);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(98, 9, 77, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");


    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    QLineEdit* lineEdit = new QLineEdit();

    const QString* placeHolder = new QString("Enter text here...");
    lineEdit->setPlaceholderText(*placeHolder);
    layout->insertRow(2, lineEdit);
}
