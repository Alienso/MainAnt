#include "./headers/nodesHeaders/ForNode.h"

ForNode::ForNode() : Node("for", 4, 2,{"flow","init","condition","increment"})
{
    setStyleSheet ("background-color: rgba(183, 46, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");

    setColors({'q','q','b','q','q','q'});
    QFont f( "Arial", 6);
    QLabel* lbl = new QLabel("Body");
    lbl->setFixedSize(40,20);
    lbl->setFont(f);
    QLabel* lbl2 = new QLabel("Next");
    lbl2->setFixedSize(40,20);
    lbl2->setFont(f);
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->deleteLater();
    layout->itemAtPosition(2,2)->widget()->deleteLater();
    layout->itemAtPosition(4,2)->widget()->deleteLater();
    layout->addWidget(lbl,1,2);
    layout->addWidget(lbl2,2,2);
}

QString ForNode::getCodeForNode()
{
    return this->args[2]->toPlainText();
}
