#ifndef STACKOPERATIONS_H
#define STACKOPERATIONS_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class StackOperations : public Node
{
public:
    StackOperations();

    QLineEdit* value;
    QComboBox* operations;

    QString getCodeForNode() override;
};

#endif // STACKOPERATIONS_H
