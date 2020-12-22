#ifndef STACKNODE_H
#define STACKNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class StackNode : public Node
{
public:
    StackNode();

    QLineEdit* StackName;
    QComboBox* varTypes;

    QString getCodeForNode() override;
    QString getVarName() const override;
};

#endif // STACKNODE_H
