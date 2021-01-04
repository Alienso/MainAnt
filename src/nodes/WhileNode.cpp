#include "./headers/nodesHeaders/WhileNode.h"


WhileNode::WhileNode():Node("while",2,2,{"flow","condition"})
{
    setStyleSheet ("background-color: rgba(58, 95, 134, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");
    setColors({'q','b','q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    QFont f( "Arial", 6);
    QLabel* lbl = new QLabel("Body");
    lbl->setFixedSize(40,20);
    lbl->setFont(f);
    QLabel* lbl2 = new QLabel("Next");
    lbl2->setFixedSize(40,20);
    lbl2->setFont(f);
    layout->itemAtPosition(1,2)->widget()->deleteLater();
    layout->itemAtPosition(2,2)->widget()->deleteLater();
    layout->addWidget(lbl,1,2);
    layout->addWidget(lbl2,2,2);
}

QString WhileNode::getCodeForNode()
{
    //return this->args[1]->toPlainText();
    return "";
}
