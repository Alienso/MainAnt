#ifndef FORNODE_H
#define FORNODE_H

#include "./headers/Node.h"

class ForNode :public Node
{
public:
    ForNode();
    QString getCodeForNode() override;
};

#endif // FORNODE_H
