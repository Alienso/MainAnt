#include "../headers/ForNode.h"

ForNode::ForNode() : Node("for", 4, 1, nullptr)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 120);
    setStyleSheet ("background-color: rgba(183, 46, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString ForNode::getCodeForNode()
{
    //TODO mora da se napise kode koji ce da vraca for node
    QString text = "";
    return text;
}
