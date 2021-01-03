#ifndef RETURNNODE_H
#define RETURNNODE_H

#include <iostream>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLineEdit>
#include "./headers/Node.h"

class ReturnNode : public Node
{
private:
    bool earlyEnd;
    QLineEdit *returncCode;
public:
    ReturnNode();
    virtual QString getCodeForNode() override;
};

#endif // RETURNNODE_H
