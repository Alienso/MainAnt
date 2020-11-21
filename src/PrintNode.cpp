#include "./headers/PrintNode.h"

/*
 * Cvor koji omogucava ispis. ON je zapravo sacinjen od text editora u koji ne moze da se pise iz aplikacije.
 * Sadrzi place holder, a sadrzaj teksta se moze iz koda menjati korestieci metod setText("Neki string").
 * Nasledjuje klasu Node.
 * Sadrzi jedan ulaz.
*/

PrintNode::PrintNode() : Node("print", 1, 1, nullptr)
{
    setMinimumSize(100,100);
    setMaximumWidth(200);
    setStyleSheet ("background-color: rgba(105, 50, 129, 1);"
                   "border: 1px solid rgba(194, 145, 211, 1);");
    QTextEdit* edit = new QTextEdit();

    const QString* font = new QString("Courier New");
    const QString* placeHolder = new QString("Output...");
    edit->setFontFamily(*font);
    edit->setPlaceholderText(*placeHolder);
    edit->setReadOnly(true);
    //edit->setText("Danas je lep dan");

    QFormLayout* layout = static_cast<QFormLayout*>(this->layout());
    layout->insertRow(2,edit);
}
