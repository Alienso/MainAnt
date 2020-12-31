#include "./headers/nodesHeaders/ElseIfNode.h"

ElseIfNode::ElseIfNode():Node("elseIf", 2, 1, {"flow", "condition"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px");
    setColors({'q','b','q'});

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
}

QString ElseIfNode::getCodeForNode()
{
    //return "else if(";
    if (this->args[1]->toPlainText().compare("") == 0)
        return "else if(#1";
    return "else if(" + this->args[1]->toPlainText();
}
