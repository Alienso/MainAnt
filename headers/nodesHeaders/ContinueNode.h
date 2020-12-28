#ifndef CONTINUENODE_H
#define CONTINUENODE_H

#include "./headers/Node.h"

class ContinueNode : public Node
{
public:
    ContinueNode();

    QString getCodeForNode() override;
};

#endif // CONTINUENODE_H
