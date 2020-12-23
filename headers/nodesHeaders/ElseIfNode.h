#ifndef ELSEIFNODE_H
#define ELSEIFNODE_H
#include "./headers/Node.h"

class ElseIfNode :public Node
{
public:
    ElseIfNode();
    QString getCodeForNode() override;
};

#endif // ELSEIFNODE_H
