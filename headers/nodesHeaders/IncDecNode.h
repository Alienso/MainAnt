#ifndef INCDECNODE_H
#define INCDECNODE_H

#include "./headers/Node.h"
#include <QComboBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>

class IncDecNode : public Node
{
public:
    IncDecNode();
    QGroupBox* prePostGroup;
    QRadioButton* isPre;
    QRadioButton* isPost;
    QLineEdit* operand;
    QComboBox* operatorType;

    QString getCodeForNode() override;
};

#endif // INCDECNODE_H
