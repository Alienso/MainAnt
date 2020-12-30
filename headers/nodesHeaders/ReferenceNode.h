#ifndef REFERENCENODE_H
#define REFERENCENODE_H

#include "./headers/Node.h"

class ReferenceNode : public Node
{
public:
    QString reference;
public:
    ReferenceNode(QString name);

    QString getCodeForNode() override;
};

#endif // REFERENCENODE_H
