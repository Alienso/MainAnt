#include "./headers/nodesHeaders/IfNode.h"

IfNode::IfNode() : Node("if", 2, 1,{"flow","Condition"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
    setColors({'q','q','q'});

}

QString IfNode::getCodeForNode(){

    if (this->args[1]->toPlainText().compare("") == 0)
        return "#1";
    return "";

}
