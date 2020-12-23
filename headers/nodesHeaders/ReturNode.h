#ifndef RETURNNODE_H
#define RETURNNODE_H

#include <iostream>
#include "./headers/Node.h"

class ReturnNode : public Node
{
public:
    ReturnNode();
    virtual QString getCodeForNode() override;
};

#endif // RETURNNODE_H
