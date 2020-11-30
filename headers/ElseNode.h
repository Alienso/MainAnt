#ifndef ELSENODE_H
#define ELSENODE_H

#include "./headers/Node.h"

class ElseNode :public Node
{
public:
    ElseNode();
    QString getCodeForNode() override;
};

#endif // ELSENODE_H
