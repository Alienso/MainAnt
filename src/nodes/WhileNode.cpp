#include "./headers/nodesHeaders/WhileNode.h"


WhileNode::WhileNode():Node("while",2,1,{"flow","condition"})
{
    setStyleSheet ("background-color: rgba(58, 95, 134, 1);"
                   "border: 1px solid rgba(255, 150, 132, 1);"
                   "border-radius:5px;");
    setColors({'q','b','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
}

QString WhileNode::getCodeForNode()
{
    return this->args[1]->toPlainText();
}
