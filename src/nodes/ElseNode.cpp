#include "../../headers/ElseNode.h"

ElseNode::ElseNode():Node("Else", 1, 1)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString ElseNode::getCodeForNode()
{
    QString text = "else";
    return text;
}
