#include "./headers/InputNode.h"

/*
 * Cvor koji omogucava input. Zapravo je samo text editor.
 * Nasledjuje klasu Node.
 * Ima izlaz koji se moze povezati sa printom, ili sa ulazom u neku drugu funkciju.
 * Ne sadrzi ulaze.
*/


InputNode::InputNode():Node("input", 0, 1, nullptr)
{
    setMinimumSize(80,80);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(98, 9, 77, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");

    QRadioButton* fileInputRadioButton = new QRadioButton("Input from file",nullptr);
    QRadioButton *manualInputRadioButton = new QRadioButton("Manula input",nullptr);

    QButtonGroup *choice = new QButtonGroup(nullptr);
    choice->addButton(fileInputRadioButton, 1);
    choice->addButton(manualInputRadioButton, 2 );
    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    layout->insertRow(2, fileInputRadioButton);
    layout->insertRow(3, manualInputRadioButton);

/*
    //Kreiranje text edita
    QTextEdit* edit = new QTextEdit();

    const QString* font = new QString("Courier New");
    const QString* placeHolder = new QString("Enter text here...");
    edit->setFontFamily(*font);
    edit->setPlaceholderText(*placeHolder);

    this->layout()->addWidget(edit);
*/

}
