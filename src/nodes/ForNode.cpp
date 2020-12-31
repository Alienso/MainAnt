#include "./headers/nodesHeaders/ForNode.h"

ForNode::ForNode() : Node("for", 4, 1,{"flow","init","condition","increment"})
{
    setStyleSheet ("background-color: rgba(183, 46, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");

    setColors({'q','q','b','q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
    layout->itemAtPosition(2,2)->widget()->hide();
    layout->itemAtPosition(4,2)->widget()->hide();
}

QString ForNode::getCodeForNode()
{
    return this->args[2]->toPlainText();
}
