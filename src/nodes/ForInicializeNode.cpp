#include "./headers/nodesHeaders/ForInicializeNode.h"

ForInicializeNode::ForInicializeNode() : Node("ForInitializeNode", 1, 1)
{
    setMinimumSize(80,80);
    setMaximumSize(180, 100);
    setStyleSheet ("background-color: rgba(153, 96, 36, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
    setColors({'q','q'});
}

QString ForInicializeNode::getCodeForNode()
{
    QString text = "#0";
    return text;
}

