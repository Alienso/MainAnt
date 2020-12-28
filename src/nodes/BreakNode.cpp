#include "../../headers/nodesHeaders/BreakNode.h"

BreakNode::BreakNode() : Node("break", 1, 1)
{
    setMaximumWidth(100);
    setStyleSheet ("background-color: rgba(0, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    setColors({'q', 'q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
}

QString BreakNode::getCodeForNode()
{
    return QString::fromStdString("break;\n");
}
