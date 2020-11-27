#ifndef STARTNODE_H
#define STARTNODE_H

#include "./headers/Node.h"

class StartNode:public Node
{
public:
    StartNode();

    QString getCodeForNode() override;
    //Za potrebe testa za razvoj parsera ovo nije virtuelni metod ali ubuduce ce morati da bude:
    void run() const;
};

#endif // STARTNODE_H
