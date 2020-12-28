#ifndef BREAKNODE_H
#define BREAKNODE_H

#include "./headers/Node.h"

class BreakNode : public Node
{
public:
    BreakNode();

    QString getCodeForNode() override;

};

#endif // BREAKNODE_H
