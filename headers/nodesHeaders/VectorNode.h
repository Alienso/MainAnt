#ifndef VECTORNODE_H
#define VECTORNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>

#include "./headers/Node.h"

class VectorNode : public Node
{       
public:
    VectorNode();

    QLineEdit* vectorName;
    QLineEdit* capacity;
    QComboBox* varTypes;

    QString getCodeForNode() override;
    QString getVarName() const override;
};

#endif // VECTORNODE_H
