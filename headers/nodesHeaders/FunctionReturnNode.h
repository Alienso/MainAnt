#ifndef FUNCTIONRETURNNODE_H
#define FUNCTIONRETURNNODE_H

#include "./headers/Node.h"
#include "QLineEdit"
#include "QRadioButton"
#include "QButtonGroup"

class FunctionReturnNode : public Node
{
private:
    bool isVoid;
    QLineEdit* edit;
    bool consstructor;
    bool earlyReturn;
    QLineEdit* returnCode;

public:
    FunctionReturnNode();
    virtual QString getCodeForNode() override;
};

#endif // FUNCTIONRETURNNODE_H
