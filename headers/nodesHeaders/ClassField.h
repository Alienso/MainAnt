#ifndef CLASSFIELD_H
#define CLASSFIELD_H

#include <QLineEdit>
#include <QComboBox>

#include "./headers/Node.h"

class ClassField : public Node
{
public:
    ClassField();

    QLineEdit* fieldName;
    QComboBox* fieldType;
    QComboBox* fieldAccessModifiers;

    QString getCodeForNode() override;
};

#endif // CLASSFIELD_H
