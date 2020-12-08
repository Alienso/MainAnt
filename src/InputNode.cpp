#include "./headers/InputNode.h"

/*
 * Cvor koji omogucava input. Zapravo je samo text editor.
 * Nasledjuje klasu Node.
 * Ima izlaz koji se moze povezati sa printom, ili sa ulazom u neku drugu funkciju.
 * Ne sadrzi ulaze.
*/


InputNode::InputNode():Node("input", 1, 1)
{
    setMinimumSize(80,80);
    setMaximumSize(150, 120);
    //setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(98, 9, 77, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");

   QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
   QLineEdit* lineEdit = new QLineEdit(nullptr);
   this->input = lineEdit;
   layout->addWidget(lineEdit,2,0);
}


QString InputNode::getCodeForNode()
{
    QString t = this->input->text();
    this->text = t;
    return t;
}

QString InputNode::getText() const
{
    return text;
}
