#include "./headers/nodesHeaders/ConditionNode.h"

ConditionNode::ConditionNode() : Node("Condition", 1, 1, {"flow"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(253, 253, 98, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString ConditionNode::getCodeForNode()
{
    QString text = "";
    return text;
}

