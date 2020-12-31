#include "./headers/nodesHeaders/ConditionNode.h"

ConditionNode::ConditionNode() : Node("Condition", 1, 1)
{
    setStyleSheet ("background-color: rgba(253, 253, 98, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");
    setColors({'b','b'});
}

QString ConditionNode::getCodeForNode()
{
    if (args[0]->toPlainText().compare("") == 0) return "#0";
    if (args[0]->toPlainText().compare("true",Qt::CaseInsensitive) == 0) return "true";
    if (args[0]->toPlainText().compare("false",Qt::CaseInsensitive) == 0) return "false";
    return args[0]->toPlainText();
}
