#include "../../headers/ElseIfNode.h"

ElseIfNode::ElseIfNode():Node("elseIf", 2, 1, {"flow", "condition"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString ElseIfNode::getCodeForNode()
{
    return "else if(";
}
