#include "../headers/ForInicializeNode.h"

ForInicializeNode::ForInicializeNode() : Node("ForInicializeNode", 1, 1, nullptr)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(153, 96, 36, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString ForInicializeNode::getCodeForNode()
{
    //TODO mora da se napise kode koji ce da vraca inicilaze for node
    QString text = "initisallize";
    return text;
}

