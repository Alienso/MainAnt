#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include <QLineEdit>
#include <QComboBox>

#include "./headers/Node.h"

class AssignNode : public Node
{
public:
    AssignNode();
    QLineEdit* varAssigne;
    QLineEdit* value;
    QComboBox* combo;

    QString getCodeForNode() override;
};

#endif // ASSIGNNODE_H
