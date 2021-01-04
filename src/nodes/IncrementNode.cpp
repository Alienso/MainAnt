#include "./headers/nodesHeaders/IncrementNode.h"

IncrementNode::IncrementNode() : Node("Increment", 1, 1)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(197, 89, 86, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");
    setColors({'q','q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
}

QString IncrementNode::getCodeForNode()
{
    QString text = "#0";
    return text;
}
