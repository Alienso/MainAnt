#ifndef IFNODE_H
#define IFNODE_H

#include "./headers/Node.h"

class IfNode : public Node
{
public:
    IfNode();
    QString getCodeForNode() override;
};

#endif // IFNODE_H
