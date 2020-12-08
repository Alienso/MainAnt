#ifndef BODYNODE_H
#define BODYNODE_H

#include "./headers/Node.h"

class BodyNode :public Node
{
public:
    BodyNode();
    QString getCodeForNode() override;
};

#endif // BODYNODE_H
