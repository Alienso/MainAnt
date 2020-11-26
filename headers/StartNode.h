#ifndef STARTNODE_H
#define STARTNODE_H
#include "./headers/Node.h"

class StartNode:public Node
{
public:
    StartNode();
    virtual QString getCodeForNode() override;
};

#endif // STARTNODE_H
