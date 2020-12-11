#ifndef ENDOFSTATEMENT_H
#define ENDOFSTATEMENT_H

#include "headers/Node.h"

class EndOfStatement :public Node
{
public:
    EndOfStatement();
    QString getCodeForNode() override;
};

#endif // ENDOFSTATEMENT_H
