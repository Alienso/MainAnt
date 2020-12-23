#ifndef QUEUEOPERATIONS_H
#define QUEUEOPERATIONS_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class QueueOperations : public Node
{
public:
    QueueOperations();

    QLineEdit* value;
    QComboBox* operations;

    QString getCodeForNode() override;
};

#endif // QUEUEOPERATIONS_H
