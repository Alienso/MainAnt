#include "./headers/nodesHeaders/ForNode.h"

ForNode::ForNode() : Node("for", 4, 1,{"flow","init","condition","increment"})
{
    setMinimumSize(80,80);
    setMaximumSize(180, 120);
    setStyleSheet ("background-color: rgba(183, 46, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);");

    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
    layout->itemAtPosition(2,2)->widget()->hide();
    layout->itemAtPosition(3,2)->widget()->hide();
    layout->itemAtPosition(4,2)->widget()->hide();
}

QString ForNode::getCodeForNode()
{
    //TODO mora da se napise kode koji ce da vraca for node
    QString text = "";
    return text;
}
