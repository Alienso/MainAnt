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


    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());

    QRadioButton* fileInputRadioButton = new QRadioButton("Input from file",this);
    QRadioButton *manualInputRadioButton = new QRadioButton("Manula input",this);

    QButtonGroup *choice = new QButtonGroup(this);
    choice->addButton(fileInputRadioButton, 1);
    choice->addButton(manualInputRadioButton, 2 );

    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
        [=](){
        int choosen = choice->checkedId();
        if(choosen == 1){
            QLineEdit* lineEdit = new QLineEdit();
            const QString* placeHolder = new QString("Enter file name here...");
            //QString input = lineEdit->text();
            //this->fileName = new QString(input);
            lineEdit->setPlaceholderText(*placeHolder);
            this->layout()->addWidget(lineEdit);
        }
    });
    connect(choice, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
        [=](){
        int choosen = choice->checkedId();
        if(choosen == 2){
            QTextEdit* edit = new QTextEdit();
            const QString* font = new QString("Courier New");
            const QString* placeHolder = new QString("Enter text here...");
            edit->setFontFamily(*font);
            edit->setPlaceholderText(*placeHolder);
            this->layout()->addWidget(edit);
        }
    });
    layout->insertRow(2, fileInputRadioButton);
    layout->insertRow(3, manualInputRadioButton);

}
