#include "./headers/nodesHeaders/IncrementNode.h"

IncrementNode::IncrementNode() : Node("Increment", 1, 1)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(197, 89, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString IncrementNode::getCodeForNode()
{
    QString text = "";
    return text;
}
