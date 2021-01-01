#include "../../headers/nodesHeaders/ReferenceNode.h"

ReferenceNode::ReferenceNode(QString name) :Node(name, 1, 1, {"flow"})
{
    this->reference = name;
    setStyleSheet ("background-color: rgba(189, 111, 113, 1);"
                   "border: 1px solid rgba(80, 196, 198, 1);"
                   "border-radius:5px;");
    setColors({'q', 'q'});
    QGridLayout* layout = static_cast<QGridLayout*>(this->layout());
    layout->itemAtPosition(1,2)->widget()->hide();
}

QString ReferenceNode::getCodeForNode()
{
    return this->reference;
}
