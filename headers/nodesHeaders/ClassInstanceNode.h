#ifndef CLASSINSTANCENODE_H
#define CLASSINSTANCENODE_H

#include "../Node.h"
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>

class ClassInstanceNode: public Node
{
private:
    bool newInstance;
    QString ClassName;
    QMap<QString,QChar> inputTypes;
public:
    QLineEdit* instanceName;
    bool visible;
public:
    ClassInstanceNode(QString ClassName, QVector<QString> argTypes, QVector<QString> argNames);
    QString getCodeForNode() override;
};

#endif // CLASSINSTANCENODE_H
