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
    QLineEdit* capacity;
    QComboBox* varTypes;

    QString getCodeForNode() override;
};

#endif // STACKNODE_H
