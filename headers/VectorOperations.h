#ifndef VECTOROPERATIONS_H
#define VECTOROPERATIONS_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class VectorOperations : public Node
{
public:
    VectorOperations();

    QLineEdit* value;
    QComboBox* operations;

    QString getCodeForNode() override;
};

#endif // VECTOROPERATIONS_H
