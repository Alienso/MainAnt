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
private:
    int methodId;
    int classId;
public:
    ClassNode(int classNum);
    QLineEdit* ClassName;
    QPushButton *addMethod;
    QPushButton *addVariable;
    QVector<ClassField*> fields;
    QVector<QString> definedAttributes;


    int getMethodId();

    QString getCodeForNode() override;
public slots:
    void addMethodSlot();
    void addFieldSlot();
    void fillDefinedAttributes();
    QVector<ClassField *>& getAttributes();
};

#endif // CLASSNODE_H
