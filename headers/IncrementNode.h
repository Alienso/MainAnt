#ifndef INCREMENTNODE_H
#define INCREMENTNODE_H

#include "./headers/Node.h"

class IncrementNode : public Node
{
public:
    IncrementNode();
    QString getCodeForNode() override;
};

#endif // INCREMENTNODE_H
