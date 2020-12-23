#include "./headers/nodesHeaders/BodyNode.h"

BodyNode::BodyNode():Node("Body", 1, 1,{"flow"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(140, 114, 114, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");
}

QString BodyNode::getCodeForNode(){
    QString text = "";
    return text;
}
