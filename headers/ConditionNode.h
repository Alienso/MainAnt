#ifndef CONDITIONNODE_H
#define CONDITIONNODE_H

#include "./headers/Node.h"

class ConditionNode : public Node
{
public:
    ConditionNode();
    QString getCodeForNode() override;

};

#endif // CONDITIONNODE_H
