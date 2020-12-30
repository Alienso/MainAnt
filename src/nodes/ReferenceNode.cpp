#include "../../headers/nodesHeaders/ReferenceNode.h"

ReferenceNode::ReferenceNode(QString name) :Node(name, 1, 1, {"flow"})
{
    this->reference = name;
}

QString ReferenceNode::getCodeForNode()
{
    return this->reference;
}
