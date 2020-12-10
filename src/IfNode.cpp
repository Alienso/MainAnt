#include "../headers/IfNode.h"

IfNode::IfNode() : Node("if", 2, 1,{"","Condition"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(2,2)->widget()->hide();
    layout->itemAtPosition(1,1)->widget()->hide();

}

QString IfNode::getCodeForNode(){

    QString text = "";
    return text;

}
