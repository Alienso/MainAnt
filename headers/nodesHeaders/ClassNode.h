#ifndef CLASSNODE_H
#define CLASSNODE_H

#include <QLineEdit>
#include <QComboBox>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>

#include "./headers/Node.h"
#include "./headers/FunctionWindow.h"
#include "./headers/nodesHeaders/ClassField.h"

class ClassNode : public Node
{
    Q_OBJECT
public:
    ClassNode();
    QLineEdit* ClassName;
    QPushButton *addMethod;
    QPushButton *addVariable;
    QVector<ClassField*> fields;

    QString getCodeForNode() override;
public slots:
    void addMethodSlot();
    void addFieldSlot();
};

#endif // CLASSNODE_H
