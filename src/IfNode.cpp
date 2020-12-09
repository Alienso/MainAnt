#include "../headers/IfNode.h"

IfNode::IfNode() : Node("if", 2, 1,{"","Condition"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");



}

QString IfNode::getCodeForNode(){

    QString text = "";
    return text;

}
