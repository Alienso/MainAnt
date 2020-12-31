#include "./headers/nodesHeaders/BodyNode.h"

BodyNode::BodyNode():Node("Body", 1, 1)
{
    setStyleSheet ("background-color: rgba(140, 114, 114, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    setColors({'q','q'});
}

QString BodyNode::getCodeForNode(){
    return "";
}
