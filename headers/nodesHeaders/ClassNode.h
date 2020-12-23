#ifndef CLASSNODE_H
#define CLASSNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>

#include "./headers/Node.h"

class ClassNode : public Node
{
    Q_OBJECT
public:
    ClassNode();
    QLineEdit* ClassName;
    QPushButton *addMethod;
    QPushButton *addVariable;
    QString getCodeForNode() override;

};

#endif // CLASSNODE_H
