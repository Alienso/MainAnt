#ifndef QUEUENODE_H
#define QUEUENODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class QueueNode : public Node
{
public:
    QueueNode();

    QLineEdit* QueueName;
    QComboBox* varTypes;

    QString getCodeForNode() override;
};

#endif // QUEUENODE_H
