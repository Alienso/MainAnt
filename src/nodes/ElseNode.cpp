#include "./headers/nodesHeaders/ElseNode.h"

ElseNode::ElseNode():Node("else", 1, 1,{"flow"})
{
    setStyleSheet ("background-color: rgba(193, 66, 66, 1);"
                   "border: 1px solid rgba(237, 48, 194, 1);"
                   "border-radius:5px;");
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
    setColors({'q','q'});
}

QString ElseNode::getCodeForNode()
{
    QString text = "else ";
    return text;
}
