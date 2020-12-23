#ifndef FORINICIALIZENODE_H
#define FORINICIALIZENODE_H

#include "./headers/Node.h"

class ForInicializeNode : public Node
{
public:
    ForInicializeNode();
    QString getCodeForNode() override;
};

#endif // FORINICIALIZENODE_H
