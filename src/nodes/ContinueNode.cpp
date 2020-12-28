#include "../../headers/nodesHeaders/ContinueNode.h"

ContinueNode::ContinueNode() : Node("continue", 1, 1)
{
    setMaximumWidth(100);
    setStyleSheet ("background-color: rgba(189, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    setColors({'q', 'q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,1)->widget()->hide();
}

QString ContinueNode::getCodeForNode()
{
    return QString::fromStdString("continue;\n");
}
